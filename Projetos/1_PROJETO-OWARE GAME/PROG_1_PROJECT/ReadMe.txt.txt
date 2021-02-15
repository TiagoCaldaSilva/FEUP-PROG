Tiago Caldas da Silva		up201906045		01MIEIC01

-OWARE GAME-

Na resolução deste projeto debrocei-me principalmente na sua apresentação, ou seja, para além das funcionalidades de jogo do programa, procurei desenvolver uma boa estética com
algumas funcionalidades extra de modo a torná-lo mais apelativo.
Deste modo, comecei por implementar um menu com opções para um jogo casual entre 2 jogadores, jogo entre um jogador e um bot (fácil ou difícil) (todos estes cronometrados, sendo que a duração do
jogo é exibida no final do mesmo) e ainda umas definições que apresentam as regras do jogo e que dão a possibilidade de mudar as cores por todo o programa.
Quanto ao jogo em si, optei pelas regras tradicionais em que:
- Um jogador apenas pode escolher um buraco (com feijões, não vazio) do seu lado do board;
- Só é possível capturar feijões do lado do board do oponente;
- Se o oponente não tiver nenhum buraco com peças, a jogada terá de ser de forma a permitir o mesmo de jogar a seguir (colocando-lhe feijões do seu lado do campo).
  Em caso de não haverem jogadas válidas, o jogo termina e cada jogador recolhe os feijões do seu lado adicionando-os ao seu score;
- Não é permitido o grand slam, ou seja, um jogador não pode capturar todas os feijões do adversário;
- Caso o jogo chegue a um total de 50, 80 jogadas (25 ou 40 rondas), surge uma mensagem a perguntar se os jogadores pretendem terminar o jogo, de forma a prevenir os ciclos
  infinitos (Se a resposta for sim, cada jogador recolhe os feijões do seu lado e soma-os à sua pontuação);
- O máximo de jogadas por jogo é 100 (um total de 50 rondas);
- Ganha o jogador que chegar primeiro aos 25 feijões capturados (em caso de terminar o jogo por ter chegado a um número de jogadas indicado em cima surge a hipótese de empate).
Quanto ao bot implementei duas possibilidades:
- Fácil: o bot escolhe aleatoriamente as jogadas;
- Difícil: o bot escolhe a jogada que pontua mais (no caso de haver mais do que uma escolhe aleatoriamente entre essas). Caso não seja possível este vai optar por defender e tentar
  jogar para os buracos que possuam 2 feijões, de forma a tentar prevenir a pontuação do oponente (se houver mais do que uma opção escolhe aleatoriamente). No caso de nenhuma 
  jogada corresponder a estas condições o bot escolhe aleatoriamente uma jogada válida.
Por fim, ainda implementei um menu de pausa durante o jogo, que permite sair do jogo (sendo que o tempo para de contar e apenas retoma quando se sai do menu de pausa, continuando o jogo).
Penso que consegui atingir todos os objetivos estabelecidos para este programa, porém ambiciono conseguir desenvolver um cronómetro que atualiza dentro do campo de jogo em vez de apresentar
a duração do mesmo apenas no final.