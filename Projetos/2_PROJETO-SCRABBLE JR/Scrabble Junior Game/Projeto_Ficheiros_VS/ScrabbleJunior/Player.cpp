#include "Player.h"

using namespace std;

bool operator==(const Player& left, const Player& right) //operator used to compare 2 players
{
	if (left.getName() != right.getName())				//compare their names
		return false;
	else if (left.getScore() != right.getScore())		//compare their scores
		return false;
	else if (left.getHand() != right.getHand())			//compare their hands
		return false;
	return true;										//return true if the two players are equal
}

Player::Player()
{
	_hand.clear();
	_score = 0;
	_name = "";
}


/*=================|SET FUNCTIONS|=================*/
//The following functions are used to assign values to the class atributtes

void Player::setHand(const multiset<char>& hand)
{
	_hand = hand;
}

void Player::setName(int number_player)
{
	bool validName;
	cout << "Please give the name of the Player " << number_player << ": ";
	do
	{
		validName = true;
		getline(cin, _name, '\n');
		if (cin.fail())
		{
			setColor(ERROR_COLOR);
			cin.clear();
			validName = false;
			cout << "#ERROR# - Invalid input. Please try again. ";
			setColor(TEXT_COLOR);
		}
	} while (!validName);
}

void Player::setScore(int score)
{
	_score = score;
}


/*=================|GET FUNCTIONS|=================*/
//The following functions are used to return the class attributes and the number of the tiles of the player

multiset<char> Player::getHand() const
{
	return _hand;
}

string Player::getName() const
{
	return _name;
}

int Player::getScore() const
{
	return _score;
}

int Player::getLength() const
{
	return _hand.size();
}


/*=================|ADD FUNCTIONS|=================*/

void Player::addHand(const vector<char> &x)		//Function used to add more than one tile to the player hand
{
	for (size_t i = 0; i < x.size(); i++)
	{
		_hand.insert(x[i]);
	}
}

void Player::addtoHand(char x)				//Function used to add a tile to the player's hand
{
	_hand.insert(x);
}

void Player::addScore(int score)			//Funtion used to increase the score
{
	_score += score;
}


/*=================|OTHER FUNCTIONS|=================*/

void Player::clearHand()					//Funtion used to remove all the tiles of the player's hand
{
	_hand.clear();
}

bool Player::isValid(char x) const			//Verifies if the player has the tile that wants to play
{
	if (_hand.find(x) == _hand.end())
		return false;
	return true;							//If the player has the tile, the function returns true
}

void Player::tileChoosed(char x)			//Function used to remove a tile that has already been played
{
	auto it = _hand.find(x);
	_hand.erase(it);
}

void Player::showHand()	const				//Shows on the screen the hand of the player
{
	auto it = _hand.begin();
	for (it; it != _hand.end(); ++it)		//Shows one tile at the time
	{
		setColor(TILES);
		cout << ' ' << *it << ' ';
		setColor(TEXT_COLOR);
		cout << ' ';
	}
	cout << '\n';
}

void Player::resetPlayer()					//To clear all the information of the player
{
	_score = 0;
	_name = "";
	_hand.clear();
}