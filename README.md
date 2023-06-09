# l123a
Laboratório 1 de Programação, primeiro semestre de 2023


ELC1065 DLSC/CT/UFSM\
professor: Benhur Stein 
([benhur+l123a@inf.ufsm.br](mailto:benhur%2bl123a@inf.ufsm.br))\
terças e quintas, 14h30\
sala 334, prédio 7 (principal do CT)

## Desenvolvimento da disciplina

Os canais de comunicação entre o professor e os alunos são as aulas presenciais, esta página (<https://github.com/BenhurUFSM/l123a>), e-mail (ver acima). Caso queira conversar fora desses canais, manda um mail que marcamos.

O e-mail pode ser usado para o envio de perguntas, exercícios, reclamações, sugestões, críticas e o que mais for, durante todo o período em que durar a disciplina.

Esta página concentrará os assuntos vistos em aula, a descrição de exercícios e trabalhos, avaliações, etc. Ela estará sendo aumentada/atualizada durante todo o semestre. Ela é o canal mais oficial de informações sobre a disciplina.

A disciplina de Laboratório I de Programação é bastante prática, e exige que os alunos se dediquem bastante e desenvolvam trabalhos práticos.
O objetivo da disciplina, aprender a programar computadores, envolve conceitos que podem levar um tempo razoável para serem adquiridos.
A prática de programação é essencial nesse aprendizado.
Para realizar essa prática, é necessário acesso a um computador e a um ambiente de desenvolvimento de programas.
A universidade dispõe de laboratórios com computadores para acesso aos alunos, com todo o software necessário instalado; consulte o NCC caso necessite.

Em um computador pessoal, pode-se instalar um ambiente de desenvolvimento localmente ou usar um dos vários que existem gratuitamente online.
O que se necessita como ambiente de desenvolvimento para a disciplina é o mais básico, basta um editor de textos e um compilador da linguagem "C".
Exemplos de ambiente gratuito online: [replit](https://www.replit.com), [onlineGDB](https://www.onlinegdb.com).
Os exercícios e trabalhos da disciplinas podem ser desenvolvidos nesses ambientes.

Meu ambiente pessoal de trabalho é no sistema linux, e nesse sistema posso auxiliá-los na instalação e uso de um compilador.
Não tenho nenhuma experiência pessoal gratificante com windows, não vou poder auxiliá-lo com problemas diretamente relacionados ao uso desse ambiente.

Por ser uma disciplina prática, a principal forma de avaliação dos alunos será através de exercícios, principalmente o desenvolvimento de pequenos programas de computador, a serem enviados para o professor. No final do semestre, deve ser desenvolvido um trabalho final um pouco mais complexo.
A descrição desses exercícios e programas, bem como a forma de entrega dos mesmos será disponibilizada nesta página.

Os trabalhos entregues não serão imediatamente pontuados, mas comentados de forma individual ou coletiva.
Espera-se que esses comentários sejam aproveitados para gerar novas e melhores versões dos programas, como forma de aprendizagem. 
Os programas podem ser alterados e reenviados ao professor, caso restem dúvidas.

A avaliação será realizada no final do semestre. Para isso, cada aluno deverá entregar a versão final de um subconjunto dos trabalhos desenvolvidos (a ser definido), juntamente com uma auto-avaliação descrevendo o seu desenvolvimento durante o semestre, contendo uma sugestão de nota.
O aluno deverá participar de uma encontro individual com o professor no final do semestre, como parte da avaliação.

Para quem não alcançar a nota suficiente (7), haverá uma prova escrita de recuperação (chamada exame).

Não deixem dúvidas acumularem.
Quanto mais cedo conseguirmos nos comunicar para apontar problemas, expor sugestões, melhores vão ser nossas chances de sucesso.

##  Aulas 

Os assuntos vistos em aula serão listados aqui.

|    N |   data | assunto
| ---: | -----: | :--------
|    1 |  21mar | [introdução; um computador simplificado](Aulas/01.md)
|    2 |  23mar | [implementação de números](Aulas/02.md)
|    3 |  28mar | [primeiro programa C](Aulas/03.md)
|    4 |  30mar | [primeiro programa C, com funções](Aulas/04.md)
|    5 |   4abr | [dígitos](Aulas/05.md)
|    6 |   6abr | [dígitos, com if e while](Aulas/06.md)
|    7 |  11abr | exercícios
|    8 |  13abr | [mais exercícios](Aulas/08.md)
|    9 |  18abr | exercícios e [operadores](Aulas/09.md)
|   10 |  20abr | [comando for](Aulas/10.md) e triângulos
|   11 |  25abr | [exercícios, t2](Aulas/11.md)
|   12 |  27abr | exercícios
|   13 |   2mai | [t2](Aulas/13.md)
|   14 |   4mai | [passagem de argumentos por referência, vetores](Aulas/14.md)
|   15 |   9mai | [exercicios, t3](Aulas/15.md)
|   16 |  11mai | exercícios, definição de data e atualização da descrição do t3
|   17 |  16mai | [strings](Aulas/17.md)
|   18 |  18mai | exercícios com strings
|   19 |  23mai | [arquivos](Aulas/19.md)
|   20 |  25mai | [registros](Aulas/20.md)
|   21 |  30mai | exercícios, troca do t4 para t4b
|   22 |   1jun | exercícios, adição de programa exemplo no t4b
|   23 |   6jun | [alocação dinâmica de memória](Aulas/23.md)
|   24 |   8jun | t5
|   25 |  13jun | t5
|   26 |  15jun | t5
|   27 |  20jun | t5
|   28 |  22jun | t5
|   29 |  27jun | t5
|   30 |  29jun | t5
|   31 |   4jul | t5


## Exercícios, trabalhos, provas

|     N |    prazo | descrição
| ----: | -------: | :-----------
|    T1 |     4abr | Dígitos (ver final da aula 4)
|    T2 |    27abr | calculadora (ver aula 11)
|    T3 |    23mai | cores (a15)
|  ~T4~ |   ~1jun~ | ~[cores II](Trabalhos/t4)~ cancelado
|   T4b |     8jun | [cores III](Trabalhos/t4b)
|   T5  |     8jul | [efe](Trabalhos/t5)<br>21jun - código atualizado para processar teclas especiais
| final |    10jul |
| Exame |    20jul, <12h |

## Entrega final

Crie um diretório (*folder*), chamado "l1-nome" ("nome" é uma string que permita te identificar na chamada).
Coloque nesse diretório:
- versão final dos últimos dois trabalhos implementados (programas fonte)
- texto com a nota de auto-avaliação (0 a 10), com justificativa.

Pode também conter avaliação sobre como a disciplina foi conduzida pelo professor, sugestões, e o que mais o aluno considerar pertinente.

Você pode criar sub-diretórios se achar conveniente.
Comprima esse diretório, criando um arquivo zip ou tgz ou 7z ou rar, que quando descomprimido recria o diretório e seu conteúdo.

Envie um mail, antes do meio dia de 10 de julho, para benhur+l1@inf.ufsm.br, com esse arquivo anexado.
Caso tenha preferência para conversar no dia 11 ou 13, ou alguma outra restrição, coloca no mail.
No dia 11 de manhã eu envio uma mensagem com o horário de conversa de cada um.
A conversa é obrigatória.

A nota deve medir duas coisas, mais ou menos com mesmo peso: 
- os trabalhos (todos os 5, peso +- 1,1,1,2,4)
  - foi feito o que foi pedido?
  - funciona?
  - serviu para aprender os conceitos relacionados?
- a aprendizagem do conteúdo da disciplina (coloquei 10 conceitos abaixo, dá pra pensar neles +- com o mesmo peso).
Para cada conceito, reflita:
  - sabe o que é?
  - sabe pra que serve?
  - sabe como usar?

Os principais conceitos da disciplina são:
- tipos básicos de dados (char, int, bool, float, etc)
- variáveis
- entrada e saída no terminal (scanf, printf)
- seleção (if, switch)
- laços (for, while, do-while)
- funções (modularização, passagem de parâmetros por valor e referência)
- vetores e strings
- registros
- arquivos
- alocação dinâmica de memória



## Ementa

Ver [aqui](https://www.ufsm.br/ementario/disciplinas/ELC1065/).

## Material Auxiliar

[Apostila de C da UFPR](http://www.inf.ufpr.br/cursos/ci067/Docs/NotasAula.pdf)

[Curso de programação C da UFMG](http://www2.dcc.ufmg.br/disciplinas/pc/source/introducao_c_renatocm_deeufmg.pdf)

[Apostila de programação da UFPR](https://www.inf.ufpr.br/marcos/livro_alg1/livro_alg1.pdf)

Capítulos iniciais do livro "Introdução a Estruturas de Dados - Com Técnicas de Programação em C - Waldemar Celes".
Esse livro está disponível no [minha biblioteca](https://www.ufsm.br/orgaos-suplementares/biblioteca/e-books-2/), acessível aos alunos da UFSM.

Ajude o robozinho a iluminar o mundo (ajuda no desenvolvimento de lógica de programação, fundamental para o conteúdo da disciplina) [lightbot](http://lightbot.com).

Ajude o passarinho a detonar o porco (semelhante ao anterior) [code.org](http://studio.code.org/hoc/1)

Os grupos PET geralmente oferecem tópicos de apoio a disciplinas iniciais.

