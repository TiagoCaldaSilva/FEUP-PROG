#include "Scrabble_Junior.h"

using namespace std;

/*=================|INITIAL FUNCTIONS|=================*/
//Functions that are only used in the beginning of the game

void Scrabble_Junior::setPool(const Board &board)
{
	pool.setPool(board.getPool());
}

int Scrabble_Junior::tiles_perPlayer(int number_players)			//Depending on the size of the initial pool, returns the number of tiles that should be given per player in the beginning of the game
{
	if ((pool.getSize() / number_players) >= HAND_MAXSIZE)			//If the pool is able to give 7 or more tiles per player, only will be given 7 tiles, because it's the player's hand maximum size
		return HAND_MAXSIZE;
	return (pool.getSize() / number_players);						//Else, returns the maximum number of tiles that can be given equally to all the players
}

void Scrabble_Junior::hand(Player& player, int n)					//Distribute x tiles to the player
{
	player.clearHand();
	pool.giveHand(player, n);
}

void Scrabble_Junior::addPlayer(const Player &p)
{
	players.push_back(p);
}

void Scrabble_Junior::generateOrder()								//Generate a random order for the turns
{
	vector<Player> temp(players.begin(), players.end());
	random_shuffle(temp.begin(), temp.end());						//Shuffle the players
	copy(temp.begin(), temp.end(), players.begin());				//The first in the list is who starts playing
}


/*=================|GAME FUNCTIONS|=================*/
//Functions used to play the game

Player Scrabble_Junior::nextTurn()									//Decides who is going to play next
{
	Player p;
	p = players.front();											//The first player of the list is chosen
	players.pop_front();											//Delete and add him in the last position of the list
	players.push_back(p);											//The player will play again when everyone else played
	return p;
}

void Scrabble_Junior::showScore(const Player &p) const										//Shows on the screen the score of all the players, in the order of who plays first
{
	cout << "\n\t\t\t\t" << p.getName() << "- "											//The last player of the list is the player who is playing
		<< p.getScore() << endl;
	auto player = players.begin();														//The order that the players will appear on the screen is the order of playing
	auto last_player = players.end();
	--last_player;																		//The player that is playing already has been showed on the screen
	for (player; player != last_player; ++player)
	{
		cout << "\t\t\t\t" << (*player).getName() << "- " << (*player).getScore() << endl;
	}
}

void Scrabble_Junior::showPlayersHand(Player &p)	const			//Shows the tiles of each player
{
	cout << "Your hand: "; p.showHand();
	auto player = players.begin();
	auto player_end = players.end();
	--player_end;													//The player that is playing is the last player of the list
	for (player; player != player_end; ++player)
	{
		cout << (*player).getName() << ": ";
		(*player).showHand();
	}
}

bool Scrabble_Junior::validHand(const Player &p, Board &board) const			//Verifies if the player has some tile available to play
{
	multiset<char> player_hand = p.getHand();
	for (auto elem : player_hand)
	{
		if (board.isValid(elem))
			return true;														//If the player has tiles to play, return true
	}
	return false;
}

void Scrabble_Junior::changeTile(Player& p, char l)								//Function used to change a tile with the pool
{
	p.tileChoosed(l);
	p.addtoHand(pool.giveTile());
	pool.addToPool(l);
}

void Scrabble_Junior::refreshHand(Player &p)									//The player gets a tile from the pool
{
	char l;
	l = pool.giveTile();
	p.addtoHand(l);
}

void Scrabble_Junior::updatePlayer(const Player &p)									//Update the player in the list
{
	auto it = players.rbegin();													//The player that played in this turn is the last player in the list
	*(it) = p;
}


bool Scrabble_Junior::emptyPool() const											//Returns true if the pool is empty
{
	return pool.emptyPool();
}

vector<Player> Scrabble_Junior::endGame() const									//Function that returns a vector with the winner/s of the game
{
	Player p;																	//The constructor of Player puts score = 0, this object is used to compare
	vector<Player> v_players;
	for (auto player : players)
	{
		if (player.getScore() > p.getScore())									//If the score of the list element is bigger than p, the vector with the winners is updated
		{
			p = player;
			v_players.clear();
			v_players.push_back(player);
		}
		else if (player.getScore() == p.getScore())								//Else, if it is equal, add the player to the list
		{
			v_players.push_back(player);
		}
	}
	return v_players;
}

void Scrabble_Junior::reset(Board&board)
{
	players.clear();
	board.setBoard(DEFAULT_FILE);
}
