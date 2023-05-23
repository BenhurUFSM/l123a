#include "tela.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Programa exemplo do uso das funções de tela.[ch]
// Além deste arquivo, necessita de tela.h e tela.c
//
// Para compilar:
//   gcc -Wall -o cassa cassa.c tela.c
//
// tente sobreviver à cerquinha assassina durante 10s

// funções auxiliares
int max(int a, int b)
{
  return a>b ? a : b;
}

int abs(int a)
{
  return a<0 ? -a : a;
}

int main()
{
  srand(time(0));
  tela_cria();    // sempre tem que ser a primeira função de tela a ser chamada
  tela_limpa();
  tela_mostra_cursor(false);

  // posição do jogador
  int lj = tela_nlin()/2;
  int cj = tela_ncol()/2;
  // posição do inimigo
  int li = rand()%tela_nlin()+1;
  int ci = rand()%tela_ncol()+1;

  double inicio = tela_relogio();  // marca a hora de início do programa
  double tempo;   // há quanto tempo o programa tá rodando
  int dist;
  do {
    tempo = tela_relogio() - inicio;
    dist = max(abs(lj-li), abs(cj-ci));
    // desenha a tela
    tela_cor_normal();
    tela_limpa();
    tela_lincol(1, 1);
    printf("%d %.1lf", dist, tempo);
    tela_cor_letra(max(0, 255-dist*10), 30, 80);
    tela_lincol(lj, cj);
    putchar('@');
    tela_cor_normal();
    tela_lincol(li, ci);
    putchar('#');

    // atualiza a posição do jogador, se foi teclada alguma tecla de movimentação
    int tecla = tela_le_char();
    switch (tecla) {
      case c_up:
        if (lj>1) lj--;
        break;
      case c_down:
        if (lj<tela_nlin()) lj++;
        break;
      case c_left:
        if (cj>1) cj--;
        break;
      case c_right:
        if (cj<tela_ncol()) cj++;
        break;
    }
    // atualiza a posição do inimigo, em direção ao jogador
    if (ci < cj) ci += rand()%2;
    if (ci > cj) ci -= rand()%2;
    if (li < lj) li += rand()%2;
    if (li > lj) li -= rand()%2;
  } while (tempo < 10 && dist > 0);

  tela_cor_normal();
  tela_lincol(tela_nlin()-2, 1);
  if (tempo <= 0) {
    printf("Parabéns\n");
  } else {
    printf("Não foi desta vez!\n");
  }
  printf("tecle enter ");
  tela_mostra_cursor(true);
  while (tela_le_char() != c_enter);
  tela_destroi();
  printf("tchau\n");
}
