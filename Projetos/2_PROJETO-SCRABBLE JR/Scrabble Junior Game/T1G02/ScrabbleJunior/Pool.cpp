#include "Pool.h"

using namespace std;

Pool::Pool()
{
	_pool.resize(0);
}

/*=================|INITIAL FUNCTIONS|=================*/
//Functions that are only used in the beginning of the game

void Pool::setPool(const vector<char>& pool)					//Function used to assign a vector of tiles to the pool attribute
{
	_pool = pool;
}

void Pool::giveHand(Player& player, int x)						//Function used in the beginning of the game to assign some tiles of the pool to a player
{
	shufflePool();
	vector<char> hand(_pool.begin(), _pool.begin() + x);		//The player will have x tiles in the hand to play
	_pool.erase(_pool.begin(), _pool.begin() + x);
	player.addHand(hand);
}

int Pool::getSize() const
{
	return int(_pool.size());
}

/*=================|MID FUNCTIONS|=================*/
//Functions that are used in the course of the game

void Pool::addToPool(char x)					//Function used to add a tile to the pool
{
	_pool.push_back(x);
}

char Pool::giveTile()							//This function returns a random tile from the pool
{
	char x;
	shufflePool();								//Shuffle the pool
	x = _pool.back();							//Catch the last element of the pool
	_pool.pop_back();							//Removes the tile catched
	return x;
}

bool Pool::emptyPool() const					//Return true if the pool is empty, false otherwise
{
	return (_pool.size() == 0);
}


/*=================|OTHER FUNCTIONS|=================*/

void Pool::shufflePool()						//Function used to shuffle the pool
{
	random_shuffle(_pool.begin(), _pool.end());
}
