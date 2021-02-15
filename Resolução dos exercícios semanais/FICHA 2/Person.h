#pragma once
#include "Person.h"
#include <iostream>
#include "Date.h"

using namespace std;

class Person
{
public:
	Person();
	Person(string name, char gender, Date date);
private:
	string name;
	char gender;
	Date d;
};

