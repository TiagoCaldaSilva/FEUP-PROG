#pragma once
#include <string>
#include <iostream>

class Feup_person
{
public:
	Feup_person();
	Feup_person(int id, std::string name, std::string adress);
	virtual void showRecord();
	void changeAdress(std::string newAdress);
protected:
	int id;
	std::string name, adress;
};

