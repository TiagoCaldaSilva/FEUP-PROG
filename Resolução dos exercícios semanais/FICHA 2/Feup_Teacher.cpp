#include "Feup_Teacher.h"

Feup_Teacher::Feup_Teacher():Feup_person()
{
	rank = "";
	course = "";
	classes.clear();
}

Feup_Teacher::Feup_Teacher(int id, std::string name, std::string adress, std::string rank, std::string course) : Feup_person(id, name, adress)
{
	this->rank = rank;
	this->course = course;
}

void Feup_Teacher::showRecord()
{
	std::cout << "//--------------------------------------\\\\\n";
	std::cout << "Name\t:" << name << std::endl;
	std::cout << "ID\t:" << id << std::endl;
	std::cout << "Adress\t:" << adress << std::endl;
	std::cout << "Rank\t:" << rank << std::endl;
	std::cout << "Course\t:" << course << std::endl;
	std::cout << "Classes\t:" << std::endl;
	for (size_t i = 0; i < classes.size(); i++)
	{
		std::cout << classes[i]->getName() << std::endl;
	}
}

void Feup_Teacher::addNewClass(_Class* _class)
{
	classes.push_back(_class);
}

void Feup_Teacher::changeCourse(std::string newCourse)
{
	course = newCourse;
}
void Feup_Teacher::showCourse()
{
	std::cout << course << std::endl;
}