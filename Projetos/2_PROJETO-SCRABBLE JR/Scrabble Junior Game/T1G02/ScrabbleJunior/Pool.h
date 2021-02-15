#pragma once

#define HAND_MAXSIZE 7

#include "Player.h"
#include <algorithm> //random_shuffle


class Pool
{
public:
	Pool();
	void setPool(const std::vector<char> &pool);
	void giveHand(Player& player, int x);
	int getSize() const;

	void addToPool(char x);
	char giveTile();
	bool emptyPool() const;

private:
	void shufflePool();
	std::vector<char> _pool;
};
