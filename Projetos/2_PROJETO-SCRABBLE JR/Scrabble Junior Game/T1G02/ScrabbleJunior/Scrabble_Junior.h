#pragma once
#include <list>
#include "Board.h"
#include "Pool.h"

class Scrabble_Junior
{
public:
	void setPool(const Board &board);
	int tiles_perPlayer(int number_players);
	void hand(Player& player, int n);
	void addPlayer(const Player &p);
	void generateOrder();


	Player nextTurn();
	void showScore(const Player &p) const;
	void showPlayersHand(Player &p) const;
	bool validHand(const Player &p, Board &board) const;
	void changeTile(Player &p, char l);
	void refreshHand(Player &p);
	void updatePlayer(const Player &p);


	bool emptyPool() const;
	std::vector<Player> endGame() const;
	void reset(Board &board);

private:
	Pool pool;
	std::list<Player> players;
};
