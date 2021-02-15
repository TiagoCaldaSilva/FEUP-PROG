#include "Feup_person.h"

Feup_person::Feup_person()
{
	id = 0;
	name = "";
	adress = "";
}

Feup_person::Feup_person(int id, std::string name, std::string adress)
{
	this->id = id;
	this->name = name;
	this->adress = adress;
}

void Feup_person::showRecord()
{
	std::cout << "//--------------------------------------\\\\\n";
	std::cout << "Name\t:" << name << std::endl;
	std::cout << "ID\t:" << id << std::endl;
	std::cout << "Adress\t:" << adress << std::endl;
}

void Feup_person::changeAdress(std::string newAdress)
{
	adress = newAdress;
}