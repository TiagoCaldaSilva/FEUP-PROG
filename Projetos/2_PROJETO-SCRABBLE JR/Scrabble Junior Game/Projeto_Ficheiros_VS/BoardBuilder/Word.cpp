#include "Word.h"

Word::Word() {	//Word's constructor
	x = 0;
	y = 0;
	word.clear();
	coordinates.clear();
	orientation = ' ';
}


Word::Word(int _x, int _y, std::string _word, std::string _coordinates, char _orientation) {
	x = _x;
	y = _y;
	word = _word;
	coordinates = _coordinates;
	orientation = _orientation; 
}