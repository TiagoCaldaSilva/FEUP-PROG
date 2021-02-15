#pragma once

#define TILES 143
#define TEXT_COLOR 15
#define ERROR_COLOR 4

#include "Funcs.h"
#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <set>


class Player
{
public:
	friend bool operator==(const Player& left, const Player& right);
	Player();

	void setName(int number_player);
	void setHand(const std::multiset<char>& hand);
	void setScore(int score);

	std::multiset<char> getHand() const;
	std::string getName() const;
	int getLength() const;
	int getScore() const;

	void addScore(int score);
	void addHand(const std::vector<char> &x);
	void addtoHand(char x);

	void clearHand();
	bool isValid(char x) const;
	void tileChoosed(char x);
	void showHand() const;
	void resetPlayer();

private:
	std::string _name;
	std::multiset<char> _hand;
	int _score;
};