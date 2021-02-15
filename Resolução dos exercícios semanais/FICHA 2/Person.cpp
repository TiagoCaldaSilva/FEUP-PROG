#include "Person.h"
#include <iostream>
#include "Date.h"

using namespace std;

Person::Person()
{
	Date date;
	name = "";
	gender = ' ';
	d = date;
}

Person::Person(string name, char gender, Date date)
{
	this->name = name;
	this->gender = gender;
	this->d = date;
}
