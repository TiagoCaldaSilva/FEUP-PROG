#pragma once

#define WORDS_FILE "WORDS.txt"
#define A_UPPERCASE_ASCII_NUM 65
#define A_LOWERCASE_ASCII_NUM 97
#define MIN_WORD_SIZE 2

#include "Word.h"
#include <fstream>
#include <vector>


class Words {
public:

	Words();																	//Words's constructor


	Word getWordFromWords(int i) {return words[i]; }		 					//Returns the word on index i of the words vector

	int getNumWords() const {return num_words; }; 								//Returns the number of words in the board


	bool addWord(std::string coordinates, char orientation, std::string word);	//Add an object word into the vector words


	bool checkWord(std::string wordToFind); 									//Check if a word is on the dictionary

	bool removeLastWord();														//Remove the last word of the list of words that the user gives

	bool resetWords();															//Remove all words of the list of words

private:
	
	int num_words;
	std::vector<Word> words;

};
