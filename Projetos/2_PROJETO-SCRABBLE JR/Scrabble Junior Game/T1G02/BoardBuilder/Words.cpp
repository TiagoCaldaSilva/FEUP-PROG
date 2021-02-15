#include "Words.h"

using namespace std;

Words::Words() {	//Words's constructor
	num_words = 0;
	words.clear();
}


bool Words::addWord(string coordinates, char orientation, string word) {	//Add a word object into the vector words
	if (checkWord(word)) {													//If the word is on the dictionary
		words.push_back(Word(int(coordinates[1]) - (A_LOWERCASE_ASCII_NUM - 1), int(coordinates[0]) - (A_UPPERCASE_ASCII_NUM - 1), word, coordinates, orientation));
		num_words++;
		return true;
	}
	return false;
}


bool Words::checkWord(string wordToFind) {									//Check if a word with more than 1 letter is on the dictionary
	ifstream in;
	in.open(WORDS_FILE);
	string file_word;
	if (wordToFind.size() >= MIN_WORD_SIZE) {
		while (in >> file_word) 
			if (file_word == wordToFind) 
				return true;
	}
	return false;
}


bool Words::removeLastWord() {												//Remove the last word of the list of words that the user gives
	if (num_words > 0) {
		words.resize(--num_words);
		return true;
	}
	return false;
}


bool Words::resetWords() {													//Remove all words from the list
	if (num_words > 0) {
		words.clear();
		num_words = 0;
		return true;
	}
	return false;
}
