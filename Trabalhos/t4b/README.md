### t4b - cores III

Altere o programa do t3 para ficar mais interativo.
Em vez de pedir para o usuário digitar os 3 valores dos componentes da cor, ele deve alterar os valores usando as setas.
Uma das barras de cor (vermelho, verde ou azul) é a barra corrente. 
As setas direita e esquerda alteram o valor da barra corrente.
As setas para cima e para baixo selecionam outra barra.
Enter encerra a partida.
A partida encerra automaticamente após 20 segundos.

As cores devem ser atualizadas para refletir os valores das barras.
A pontuação é como no t3, acrescida de um bônus de 5% dos pontos para cada segundo de antecipação do final da partida.

Os arquivos tela.h e tela.c contêm um conjunto de funções para controlar a tela.
O arquivo cassa.c contém um exemplo de uso dessas funções.
Os arquivos foram alterados em relação ao t4.

O programa deve salvar o registro de recordes em um arquivo, que deve ser lido no início da execução e gravado ao final de cada partida, se a pontuação for suficiente. Além dos pontos, deve ser registrado um nome (de pelo menos 3 letras), pedido ao usuário no final da partida.

O programa deve ser organizado com uma variável do tipo registro, mantida na main e passada por referência para as funções auxiliares. Essa variável deve possuir todo o estado da partida em desenvolvimento.

Nenhuma função deve ter mais de 25 linhas.
Nenhuma linha deve ter mais de um comando.
Todo comando composto (if, for etc) deve usar chaves no bloco que controla.
Todo '}' deve estar em uma linha exclusiva.
