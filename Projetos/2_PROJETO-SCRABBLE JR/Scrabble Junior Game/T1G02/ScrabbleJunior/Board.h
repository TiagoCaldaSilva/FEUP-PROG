#pragma once

#define DEFAULT_FILE "DEFAULT.txt"
#define EDGES 3
#define GAMEBOARD 143
#define LETTERS_PLAYED 132
#define TEXT_COLOR 15

#include "Funcs.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iostream>
#include <iterator>


class Board
{
public:

	Board();							//default board
	void setBoard(const std::string file);


	int getLines() const;
	int getColumn() const;
	std::vector<char> getPool() const;
	int getNumberLetters() const;


	bool isValid(const char l);
	bool validMove(const std::pair<int, int> position, const char l);


	int modifyHVMap(std::map<std::pair<int, int>, std::string>& modify, std::pair<int, int> position, const std::pair<int, int> sum);
	int crossedWords(std::map<std::pair<int, int>, std::string>& modify, std::pair<int, int> position, const std::pair<int, int> sum, const int lim);
	int update(const std::pair<int, int> position);


	void showBoard();
	bool endGame() const;

private:
	void addLetters(std::pair<int, int> postion, const std::string word, std::vector<char>& pool, const std::pair<int, int> sum);
	void resizeALL();


	std::map<std::pair<int, int>, std::string> wordsH, wordsV;
	std::map<std::pair<int, int>, char> letters, colouredLetters;
	int lines, columns;
	std::vector<char> initialLetters;
};
