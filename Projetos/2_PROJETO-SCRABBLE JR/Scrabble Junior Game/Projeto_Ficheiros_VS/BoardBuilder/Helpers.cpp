#include "Helpers.h"

void Helpers::clearInput() {
	//This function avoids input errors
	if (std::cin.eof()) 
		exit(0);
	std::cin.clear();
}


void Helpers::reverseString(std::string& s) {				//Reverse one string. Example "abcde" to "edcba"
	std::string a;
	for (auto i = s.rbegin(); i != s.rend(); ++i) 
		a.append(1, char(*i));
	s = a;
}


std::string Helpers::coordinatesToString(int x, int y) {	//Given the x and y coordinates, returns a string "Zz" (Z -> y and z -> x)
	std::string res;
	res.append(1, char(A_UPPERCASE_ASCII_NUM - 1 + y));
	res.append(1, char(A_LOWERCASE_ASCII_NUM - 1 + x));
	return res;
}


std::string Helpers::toUpper(std::string text){				//Uppercase a string
	for (size_t i = 0; i < text.length(); i++)
		text[i] = (char)toupper(text[i]);
	return text;
}
