#pragma once

#include <string>

class Word {
public:

	Word();																				//Word's constructor

	Word(int _x, int _y, std::string _word, std::string _coordinates, char _orientation);


	void setX(int _x) {x = _x; };														//Set the abcess of the object Word equals to _x

	void setY(int _y) {x = _y; };														//Set the ordinate of the object Word equals to _y

	void setWord(std::string _word) {word = _word; }; 									//Set the word of the object Word equal to _word

	void setCoordinates(std::string _coordinates) {coordinates = _coordinates; };		//Set the coordinates of the object Word equals to _coordinates

	void setOrientation(char _orientation) {orientation = _orientation; };				//Set the orientation of the object Word equals to _orientation



	int getX() const {return x; };														//Returns the abciss of the object Word

	int getY() const {return y; };														//Returns the ordinate of the object Word

	std::string getCoordinates() const {return coordinates; };							//Returns the coordinates of the object Word

	char getOrientation() const {return orientation; };									//Returns the orientation of the object Word

	std::string getWord() const {return word; };										//Returns the word of the object Word



	void appendLetterWord(char _letter) {word.append(1, _letter);}						//Append one char to the word of the object Word

	void clearWord() {word.clear(); };													//Clear the word of the object Word

private:

	int x, y;																			//Coordinates
	std::string word, coordinates;
	char orientation;
};
