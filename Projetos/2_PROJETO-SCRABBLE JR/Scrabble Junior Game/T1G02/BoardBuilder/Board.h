#pragma once

#include "Words.h"
#include "Helpers.h"


#define SPACE_ASCII_NUM 32
#define ASCII_0 48
#define ASCII_9 57
#define A_UPPERCASE_ASCII_NUM 65
#define A_LOWERCASE_ASCII_NUM 97
#define MIN_WORD_SIZE 2
#define MIN_BOARD_SIZE 1
#define MAX_SIZE_LIMIT 20
#define DARKGRAY "\033[1;100m"
#define NO_COLOR "\033[0m"
#define CYAN "\033[0;36m"
#define RED "\033[0;31m"
#define YELLOW "\033[1;33m"
#define MIN_LETTERS 6
#define WHITE "\033[1;37m"


class Board
{
public:

	Board();


	int inputValue() const;


	char getWordOrientation();

	void getDimension();

	std::string getWord();	

	std::string getWordCoordinates();	

	bool getAllGeneratedWords();


	void initVectors();


	void showBoardLetters();

	void showMessage();


	bool addNewWord();

	bool fillBoardLettersWithWords();

	void newWords();

	void numberLettersBoard();

	void updateAllGeneratedWordsCopy();

	void fileOut();

private:

	int height, width, num_letters_board;
	std::vector<std::vector<char>> board_letters;
	std::vector<Word> all_generated_words;
	std::vector<Word> all_generated_words_copy;
	std::string message, message_type;
	Words words;

};
