#include "tela.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Programa exemplo do uso das funções de tela.[ch]
// Além deste arquivo, necessita de tela.h e tela.c
//
// Para compilar:
//   gcc -Wall -o pong pong.c tela.c
//
// tente manter a bolinha na tela


// tipo de dados que define o estado do jogo
typedef struct {
  // posição e velocidade da bola (em float para evitar erros no cálculo)
  posicao pos_bola;
  float x_bola;
  float y_bola;
  float vx_bola;
  float vy_bola;
  double data_mov;
  // raquetes
  posicao raq_esq;
  posicao raq_dir;
  // pontuação
  int pontos_esq;
  int pontos_dir;
  // indicação de final de partida
  bool terminou;
} pong;


// globais

cor vermelho = { 200, 80, 80 };
cor azul = { 80, 80, 200 };
cor branco = { 200, 200, 200 };

#define ALT_RAQUETE 5


// funções de inicialização

void inicializa_tela(void)
{
  srand(time(0));
  tela_cria();
  tela_limpa();
  tela_mostra_cursor(false);
}

void inicializa_posicoes(pong *p)
{
  p->x_bola = tela_ncol()/2;
  p->y_bola = tela_nlin()/2;
  p->pos_bola.linha = p->y_bola;
  p->pos_bola.coluna = p->x_bola;
  p->vx_bola = 0;
  p->vy_bola = 0;
  p->raq_esq.linha = p->raq_dir.linha = tela_nlin()/2;
  p->raq_esq.coluna = 3;
  p->raq_dir.coluna = tela_ncol()-2;
}

void inicializa_partida(pong *p)
{
  inicializa_posicoes(p);
  p->pontos_dir = 0;
  p->pontos_esq = 0;
  p->terminou = false;
}


// funções para desenho da tela

void desenha_placar(int pe, int pd)
{
  posicao placar = { 1, tela_ncol()/2-2 };
  tela_cor_letra(azul);
  tela_posiciona(placar);
  printf("%d - %d", pe, pd);
}

void desenha_raquete(posicao p)
{
  posicao pc = p;
  pc.linha -= ALT_RAQUETE/2;
  tela_cor_fundo(branco);
  for (int i=0; i<ALT_RAQUETE; i++) {
    tela_posiciona(pc);
    putchar(' ');
    pc.linha++;
  }
}

void desenha_quadra(void)
{
  posicao p = { 2, 2 };
  tela_cor_letra(azul);
  tela_posiciona(p);
  for (int i=0; i<tela_ncol()-2; i++) {
    putchar('=');
  }
  p.linha = tela_nlin()-1;
  tela_posiciona(p);
  for (int i=0; i<tela_ncol()-2; i++) {
    putchar('=');
  }
  p.linha++;
  tela_posiciona(p);
  printf(" controles: az l. y enter");
}

void desenha_bola(posicao p)
{
  tela_cor_normal();
  tela_posiciona(p);
  putchar('O');
}

void desenha_tela(pong *p)
{
  tela_cor_normal();
  tela_limpa();
  desenha_quadra();
  desenha_placar(p->pontos_esq, p->pontos_dir);
  desenha_raquete(p->raq_esq);
  desenha_raquete(p->raq_dir);
  desenha_bola(p->pos_bola);
}


// funções auxiliares

int menor(int a, int b)
{
  return a<b ? a : b;
}

int maior(int a, int b)
{
  return a>b ? a : b;
}


// funções para alterar o estado do jogo

void sobe_raquete(posicao *raq)
{
  raq->linha = maior(raq->linha-1, 3+ALT_RAQUETE/2);
}

void desce_raquete(posicao *raq)
{
  raq->linha = menor(raq->linha+1, tela_nlin()-2-ALT_RAQUETE/2);
}

void trata_teclado(pong *p)
{
  int tecla = tela_le_char();
  switch (tecla) {
    case 'a':
      sobe_raquete(&p->raq_esq);
      break;
    case 'z':
      desce_raquete(&p->raq_esq);
      break;
    case 'l':
      sobe_raquete(&p->raq_dir);
      break;
    case '.':
      desce_raquete(&p->raq_dir);
      break;
    case 'y':
      p->terminou = true;
      break;
    case c_enter:
      p->vy_bola = rand()%19-9;
      p->vx_bola = rand()%25-12;
      break;
  }
}

void move_bola(pong *p)
{
  double agora = tela_relogio();
  double delta_t = agora - p->data_mov;

  p->x_bola += delta_t * p->vx_bola;
  p->y_bola += delta_t * p->vy_bola;

  // ricocheteia em y
  float ymin = 3;
  if (p->y_bola < ymin) {
    p->y_bola += 2 * (ymin - p->y_bola);
    p->vy_bola *= -1;
  } 
  float ymax = tela_nlin() - 1;
  if (p->y_bola > ymax) {
    p->y_bola -= 2 * (p->y_bola - ymax);
    p->vy_bola *= -1;
  } 
  p->pos_bola.linha = p->y_bola;
  p->pos_bola.coluna = p->x_bola;

  p->data_mov = agora;
}

bool y_na_raquete(posicao bola, posicao raq)
{
  if (bola.linha < raq.linha-ALT_RAQUETE/2) return false;
  if (bola.linha > raq.linha+ALT_RAQUETE/2) return false;
  return true;
}

void verifica_raquetada(pong *p)
{
  int xmin = 4;
  if (p->x_bola < xmin && p->vx_bola < 0) {
    if (y_na_raquete(p->pos_bola, p->raq_esq)) {
      p->x_bola += 2 * (xmin - p->x_bola);
      p->pos_bola.coluna = p->x_bola;
      p->vx_bola *= -1;
    } else {
      p->pontos_dir++;
      inicializa_posicoes(p);
    }
  }

  int xmax = tela_ncol() - 2;
  if (p->x_bola > xmax && p->vx_bola > 0) {
    if (y_na_raquete(p->pos_bola, p->raq_dir)) {
      p->x_bola -= 2 * (p->x_bola - xmax);
      p->pos_bola.coluna = p->x_bola;
      p->vx_bola *= -1;
    } else {
      p->pontos_esq++;
      inicializa_posicoes(p);
    }
  }
}

void avanca_jogo(pong *p)
{
  trata_teclado(p);
  move_bola(p);
  verifica_raquetada(p);
  if (p->pontos_dir > 2 || p->pontos_esq > 2) {
    p->terminou = true; 
  }
}


void desenha_tela_final(pong *p)
{
  tela_cor_normal();
  tela_posiciona((posicao){tela_nlin()-2, 1});
  if (p->pontos_esq > p->pontos_dir) {
    printf("Parabéns ESQ");
  } else if (p->pontos_esq < p->pontos_dir) {
    printf("Parabéns DIR");
  } else {
    printf("Empate");
  }
  printf("\ntecle enter ");
  tela_mostra_cursor(true);
  while (tela_le_char() != c_enter)
    ;  // não faz nada enquanto espera
}

int main()
{
  pong jogo;
  inicializa_tela();
  inicializa_partida(&jogo);

  do {
    avanca_jogo(&jogo);
    desenha_tela(&jogo);
  } while (!jogo.terminou);

  desenha_tela_final(&jogo);

  tela_destroi();
  printf("tchau\n");
}
