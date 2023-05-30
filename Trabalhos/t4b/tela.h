// tela.h
// ------
// implementa uma abstração do terminal de texto
// trata caracteres lidos do teclado e controla a impressão na tela
//

#ifndef TELA_H
#define TELA_H

#include <stdbool.h>

// tipo que representa uma posição na tela
typedef struct {
  int linha;
  int coluna;
} posicao;

// tipo que representa uma cor
typedef struct {
  int vermelho;
  int verde;
  int azul;
} cor;

// inicializa a tela e o teclado
void tela_cria(void);

// volta a tela ao normal
void tela_destroi(void);

// limpa a tela
void tela_limpa(void);

// posiciona o cursor (0,0 é o canto superior esquerdo)
void tela_posiciona(posicao pos);

// retorna a altura da tela (número de linhas)
int tela_nlin(void);

// retorna a largura da tela (número de colunas)
int tela_ncol(void);

// cor normal para as próximas impressões
void tela_cor_normal(void);

// seleciona a cor das letras nas próximas impressões
void tela_cor_letra(cor c);

// seleciona a cor do fundo nas próximas impressões
void tela_cor_fundo(cor c);

// seleciona se o cursor aparece ou não
void tela_mostra_cursor(bool mostra);

// retorna o próximo caractere da entrada, que pode ser um caractere unicode
//   ou um caractere especial de controle (com código negativo)
//   ou 'c_none' se não houver caractere disponível na entrada
// (caracteres unicode não estão implementados, está retornando sequências
//   utf8 para caracteres de código superior a 127)
int tela_le_char(void);

// caracteres especiais retornados por tela_le_char
enum {
  c_none = -1000,  // não tem caractere na entrada
  c_resize,        // a janela mudou de tamanho (não é um caractere digitado)
  c_enter,
  c_back,
  c_del,
  c_pgup,
  c_pgdn,
  c_home,
  c_end,
  c_left,
  c_right,
  c_up,
  c_down,
  c_primeiro_unicode = 0,
  c_ultimo_unicode = 0x10FFFF,
};

// retorna o número de segundos desde algum momento no passado
double tela_relogio(void);
#endif // TELA_H
