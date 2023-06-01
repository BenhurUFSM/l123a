#include "tela.h"

// implementado usando
//   - sequências de escape ANSI para controlar a saída (cursor, cores)
//   - termios para alterar o modo de entrada do terminal
//   - ioctl para descobrir o tamanho do terminal
//   - signal para ser sinalizado quando o terminal mudar de tamanho


#include <stdio.h>
#include <stdbool.h>

#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <time.h>


// muda o processamento de caracteres de entrada pelo terminal
// se 'cru' for true, coloca em leitura de caracteres individuais;
// se for false, devolve o estado que estava quando foi chamado com true.
// deve ser chamado com true antes de ser chamado com false
static void tela_altera_modo_entrada(bool cru)
{
  static struct termios estado_original;
  if (cru) {
    // lê e guarda o estado atual do terminal
		tcgetattr(1, &estado_original);
    // altera o estado do terminal para não ecoar o que é digitado
    //   nem esperar <enter>
		struct termios t = estado_original;
		t.c_lflag &= (~ECHO & ~ICANON);
    t.c_cc[VMIN] = 0; // pode retornar de uma leitura sem nenhum caractere
    t.c_cc[VTIME] = 1; // espera até tantos décimos de segundo antes de retornar
		tcsetattr(1, TCSANOW, &t);
  } else {
    // recoloca o terminal no estado original
    tcsetattr(1, TCSANOW, &estado_original);
  }
}

static void tela_altera_modo_saida(void)
{
  // faz com que os caracteres impressos sejam enviados diretamente
  // para a tela, sem serem mantidos em um buffer em memória
  setvbuf(stdout, NULL, _IONBF, 0);
}

void tela_mostra_cursor(bool mostra)
{
  if (mostra) {
    printf("\e[?25h");
  } else {
    printf("\e[?25l");
  }
}

static void tela_seleciona_tela_alternativa(bool alt)
{
  if (alt) {
    printf("\e[?1049h");
  } else {
    printf("\e[?1049l");
  }
}

static void tela_le_nlincol(int);

void tela_cria(void)
{
  tela_altera_modo_entrada(true);
  tela_altera_modo_saida();
  tela_seleciona_tela_alternativa(true);
  // chama tela_le_nlincol se tela mudar de tamanho
  signal(SIGWINCH, tela_le_nlincol);
  tela_le_nlincol(0);
  tela_limpa();
}

void tela_destroi(void)
{
  tela_limpa();
  tela_altera_modo_entrada(false);
  tela_seleciona_tela_alternativa(false);
  tela_mostra_cursor(true);
}

void tela_limpa(void)
{
  printf("\e[2J");
}

void tela_posiciona(posicao pos)
{
  printf("\e[%d;%dH", pos.linha, pos.coluna);
}

static int nlin, ncol; 
static bool tela_foi_redimensionada = false;

static void tela_le_nlincol(int nada)
{
  struct winsize tam;
  ioctl(1, TIOCGWINSZ, &tam);
  nlin = tam.ws_row;
  ncol = tam.ws_col;
  tela_limpa();
  tela_foi_redimensionada = true;
}

int tela_nlin(void)
{
  return nlin;
}

int tela_ncol(void)
{
  return ncol;
}

void tela_cor_normal(void)
{
  printf("\e[m");
}

void tela_cor_letra(cor c)
{
  printf("\e[38;2;%d;%d;%dm", c.vermelho, c.verde, c.azul);
}

void tela_cor_fundo(cor c)
{
  printf("\e[48;2;%d;%d;%dm", c.vermelho, c.verde, c.azul);
}

static int trata_esc(void);

int tela_le_char(void)
{
  if (tela_foi_redimensionada) {
    tela_foi_redimensionada = false;
    return c_resize;
  }
  char a;
  if (read(1, &a, 1) != 1) {
    return c_none;
  }
  switch (a) {
    case 127:  return c_back;
    case '\n': return c_enter;
    case '\e': return trata_esc();
    default:   return a;
  }
}

static int trata_esc(void)
{
  char c;
  if (read(1, &c, 1) != 1) {
    return '\e';
  }
  if (c == '[') {
    if (read(1, &c, 1) != 1) {
      return c_none;
    }
    switch(c) {
      case 'A': return c_up;
      case 'B': return c_down;
      case 'C': return c_right;
      case 'D': return c_left;
      case 'F': return c_end;
      case 'H': return c_home;
    }
  }
  return c_none;
}


double tela_relogio(void)
{
  struct timespec agora;
  clock_gettime(CLOCK_REALTIME, &agora);
  return agora.tv_sec + agora.tv_nsec*1e-9;
}
