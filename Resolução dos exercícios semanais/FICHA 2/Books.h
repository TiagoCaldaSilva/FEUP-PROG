#pragma once
#include <string>
#include "Date.h"

using namespace std;

class Books
{
public:
	Books();
	Books(string name, Date d, char state);
	void setName(string name);
	void setDate(Date d);
	void setState(char state);
	string getName() const;
	Date getDate() const;
	char getState() const;
private:
	Date d;
	string name;
	char state; //E, L, A
};

