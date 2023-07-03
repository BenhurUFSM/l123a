### t5 - efe

Você deve implementar o jogo **efe**, conforme descrito a seguir.

O jogo é constituído por um tabuleiro quadrado, de 5x5 posições.
Cada posição pode estar vazia ou preenchida por uma letra de 'A' a 'F'.
Em uma jogada, pode-se mover as peças em uma das 4 direções, usando as setas do teclado.
Ao se movimentarem, as peças podem se combinar, gerando novas letras.
O objetivo é gerar a letra 'F'.

No início do jogo, 2 casas são automaticamente preenchidas; após cada jogada, uma casa vazia é preenchida.
A casa a ser preenchida automaticamente, e a letra usada para preenchê-la são escolhidas pelo programa de forma aleatória. 
A letra usada para preencher pode ser 'A' ou 'B', com 3 vezes mais chance de ser 'A' do que de ser 'B'.

O jogo acaba quando for gerado um 'F' ou quando não houver jogada possível.

Uma jogada consiste em um movimento em uma das 4 direções. Todas as peças devem se deslocar o máximo possível na direção considerada.
Caso 3 peças iguais fiquem juntas na direção do movimento, elas são combinadas em uma peça com a letra seguinte.
Se o movimento for horizontal, somente peças de uma mesma linha podem se combinar. Se for vertical, de uma mesma coluna.
Podem acontecer várias combinações em uma mesma jogada.

Por exemplo, considerando movimento de uma linha para a direita ou esquerda:

| antes | direita | esquerda |
| :---: | :----: | :----: |
| -A--- | ----A | A---- |
| --B-A | ---BA | BA--- |
| A-AA- | ----B | B---- |
| CCBC- | -CCBC | CCBC- |
| BCCCC | --BCD | BDC-- |
| AAABB | --BBB | C---- |
| BBAAA | ----C | BBB-- |

Esses são os movimentos feitos pelo jogo 243. No nosso caso, os 2 últimos movimentos podem realizar as 2 combinações nas 2 direções, resultando em "C".

Cada letra que se mexe vale um ponto.
Cada combinação vale a soma das 3 letras combinadas (cada 'A' vale 10, combinam num 'B' vale 30; combinando 3 'B' em um 'C' vale 90 etc).

Deve ser mantido em arquivo as 5 maiores pontuações com a identificação de quem pontuou.
Caso o arquivo não exista, o programa deve considerar que ninguém pontuou ainda.

O desenho do tabuleiro deve ser colorido, com uma combinação de cor diferente para cada conteúdo possível em uma posição (vazia, 'A' a 'F').
Deve ser mostrado na tela, além do tabuleiro, pelo menos a pontuação atual.

Deve ser implementado usando um dos tela.h + tela.c (textual, do t4 ou [gráfico](tela)), que não devem ser alterados.

O jogo é baseado no [243](https://hgentry.github.io/81/).

#### Dicas

Os movimentos de uma linha ou coluna são independentes das demais, e são os mesmos em qualquer direção. 
É mais fácil implementar uma função para fazer o movimento em uma linha, para uma das direções, e usar essa função várias vezes em um movimento, copiando cada linha ou coluna, de frente pra trás ou de trás pra frente para um vetor auxiliar, chamando a função de movimentação, e copiando o resultado de volta para a matriz.

Não misture desenho com alteração de estado.
Melhor: não misture entrada, saída, alteração de estado.

Cada função deve ter um objetivo bem definido, e um nome que corresponde à esse objetivo.

Uma função deve fazer uma coisa, possivelmente de forma parametrizada. Quando se precisar que essa coisa seja feita, deve-se chamar essa função.

Uma forma relativamente simples de implementar o movimento de uma linha é separando em 2 partes, movimentação e junção:
1. A movimentação pode ser feita, por exemplo, achando cada espaço da linha e movendo a próxima letra da 
   linha para ele, até que não tenha letra para mover ou que não tenha mais espaço.
   Por exemplo, se a linha for "A--BA":
   - o 1º caractere não é espaço, deixa ele
   - o 2º caractere é espaço, move a 1ª letra à direita para ele: "AB--A"
   - o 3º caractere é espaço, move a 1ª letra à direita para ele: "ABA--"
   - o 4º caractere é espaço, não tem letra à direita dele: termina
3. a junção é procurar 3 caracteres consecutivos que tenham a mesma letra, e substituir o primeiro deles pela letra seguinte e os demais por espaço.

Fazendo movimentação, junção, movimentação, junção em uma linha qualquer vai produzir a linha resultado. 
