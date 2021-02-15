Grupo T1G02
Fernando Rego - up201905951 - Desenvolvimento do Board builder - 50%
Tiago Silva - up201906045 - Desenvolvimento do programa Scrabble Junior-50%

No decorrer deste projeto, fomos deparados com vários obstáculos , nomeadamente o desenvolvimento em sistemas operativos diferentes.
No entanto, tentamos sempre apoiar-nos um ao outro acabando por desenvolver o projeto para windows, elaborando ambos os programas com uma
estética equivalente (cor do Board, cor dos erros, etc).
Para além disso, tentamos desenvolver o projeto de forma mais simples e compacta possível:
	- Desenvolvimento de classes que apoiam o programa;
	- Separação de funções que processam os dados de funções que tratam o input/output do user;
	- Desenvolvimento de programas flexíveis, na medida em que permitem ao utilizador:
		- Voltar atrás um movimento;
		- Limpar completamente o board;
		- Adicionar palavras iguais ao board;
		- Substituir palavras já utilizadas no board se as letras das palavras coincidirem (exemplo: escrever CADET e tentar escrever
CADETS na mesma posição inicial);
		- Decidir se prefere jogar com um board pré-definido ou com um board elaborado pelo board builder;
		- Decidir executar alguma função do jogo (jogar, ir à pool, etc) e voltar atrás na decisão através de CTRL-Z;
		- Ver as letras que os outros jogadores têm para jogar;
		- Analisar as regras do jogo através do menu.
Quanto às regras, optamos por utilizar as regras do jogo tradicional acrescentando ainda:
	- Mínimo 2 jogadores, máximo 4;
	- Board com dimensões máximas de 20 x 20;
	- Limite mínimo à quantidade de letras do board (6 letras de forma a que cada jogador (mínimo 2, máximo 4) tenha 3 letras na mão no início do jogo).
Deste modo, acreditamos que conseguimos atingir todos os objetivos que traçamos no início do desenvolvimento do projeto.