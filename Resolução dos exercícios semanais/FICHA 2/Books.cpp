#include "Books.h"
#include <string>
#include "Date.h"

using namespace std;

Books::Books()
{
	this->name = "";
	this->state = ' ';
	//Date já está definida
}

Books::Books(string name, Date d, char state)
{
	this->name = name; this->d = d; this->state = state;
}

void Books::setName(string name)
{
	this->name = name;
}

void Books::setDate(Date d)
{
	this->d = d;
}

void Books::setState(char state)
{
	this->state = state;
}

string Books::getName() const
{
	return name;
}

Date Books::getDate() const
{
	return d;
}

char Books::getState() const
{
	return state;
}