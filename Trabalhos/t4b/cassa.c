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

void desenha_tela(posicao pj, posicao pi, double tempo, int dist)
{
  posicao topo = { 1, 1 };
  cor cj = { max(0, 255-dist*10), 30, 80 };
  tela_cor_normal();
  tela_limpa();
  tela_posiciona(topo);
  printf("%d %.1lf", dist, tempo);
  tela_cor_letra(cj);
  tela_posiciona(pj);
  putchar('@');
  tela_cor_normal();
  tela_posiciona(pi);
  putchar('#');
}

// atualiza a posição do inimigo, em direção ao jogador
void move_inimigo(posicao *pi, posicao pj)
{
  if (pi->coluna < pj.coluna) pi->coluna += rand()%2;
  if (pi->coluna > pj.coluna) pi->coluna -= rand()%2;
  if (pi->linha < pj.linha) pi->linha += rand()%2;
  if (pi->linha > pj.linha) pi->linha -= rand()%2;
}

// atualiza a posição do jogador, se foi teclada alguma tecla de movimentação
void move_jogador(posicao *pj)
{
  int tecla = tela_le_char();
  switch (tecla) {
    case c_up:
      if (pj->linha > 1) pj->linha--;
      break;
    case c_down:
      if (pj->linha < tela_nlin()) pj->linha++;
      break;
    case c_left:
      if (pj->coluna > 1) pj->coluna--;
      break;
    case c_right:
      if (pj->coluna < tela_ncol()) pj->coluna++;
      break;
  }
}

int calc_dist(posicao p, posicao q)
{
  return max(abs(p.linha - q.linha), abs(p.coluna - q.coluna));
}

void desenha_tela_final(bool ganhou)
{
  tela_cor_normal();
  tela_posiciona((posicao){tela_nlin()-2, 1});
  if (ganhou) {
    printf("Parabéns\n");
  } else {
    printf("Não foi desta vez!\n");
  }
  printf("tecle enter ");
  tela_mostra_cursor(true);
  while (tela_le_char() != c_enter)
    ;  // não faz nada enquanto espera
}

int main()
{
  srand(time(0));
  tela_cria();    // sempre tem que ser a primeira função de tela a ser chamada
  tela_limpa();
  tela_mostra_cursor(false);

  // variáveis que definem o estado do jogo.
  //   (deveriam estar em uma struct e ter uma função de inicialização)
  // posição do jogador e do inimigo
  posicao pos_j = { tela_nlin()/2, tela_ncol()/2 };
  posicao pos_i = { rand()%tela_nlin()+1, rand()%tela_ncol()+1 };

  double inicio = tela_relogio();  // marca a hora de início do programa
  double tempo;   // há quanto tempo o programa tá rodando
  int dist;
  do {
    move_jogador(&pos_j);
    move_inimigo(&pos_i, pos_j);
    tempo = tela_relogio() - inicio;
    dist = calc_dist(pos_j, pos_i);
    desenha_tela(pos_j, pos_i, tempo, dist);
  } while (tempo < 10 && dist > 0);

  desenha_tela_final(tempo >= 10);

  tela_destroi();
  printf("tchau\n");
}
