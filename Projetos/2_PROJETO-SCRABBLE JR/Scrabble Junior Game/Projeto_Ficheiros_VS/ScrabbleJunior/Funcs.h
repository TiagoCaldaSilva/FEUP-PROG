#pragma once

#define STD_OUTPUT_HANDLE ((DWORD)-11)	//setColor
#define ASCII_A 65
#define ASCII_a 97

#include <windows.h>	//setColor
#include <string>
#include <utility>


void toUpper(std::string& text);

void setColor(int value);

void clrscr(void);

std::pair<int, int> newPair(char line, char column);