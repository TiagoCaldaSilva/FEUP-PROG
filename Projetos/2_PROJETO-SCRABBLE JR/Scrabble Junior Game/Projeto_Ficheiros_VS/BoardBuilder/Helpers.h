#pragma once

#include <string>
#include <iostream>

#define A_UPPERCASE_ASCII_NUM 65
#define A_LOWERCASE_ASCII_NUM 97

class Helpers {
public:

	static void clearInput();

	static void reverseString(std::string& s);

	static std::string coordinatesToString(int x, int y);

	static std::string toUpper(std::string text);
		
};
