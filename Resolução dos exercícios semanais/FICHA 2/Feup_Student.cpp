#include "Feup_Student.h"

Feup_Student::Feup_Student() :Feup_person()
{
	year = 0;
	course = "";
	classes.clear();
}

Feup_Student::Feup_Student(int id, std::string name, std::string adress, int year, std::string course) :Feup_person(id, name, adress)
{
	this->year = year;
	this->course = course;
}

void Feup_Student::addNewClass(_Class* _class)
{
	classes.push_back(_class);
}

void Feup_Student::showRecord()
{
	std::cout << "//--------------------------------------\\\\\n";
	std::cout << "Name\t:" << name << std::endl;
	std::cout << "ID\t:" << id << std::endl;
	std::cout << "Adress\t:" << adress << std::endl;
	std::cout << "Course\t:" << course << std::endl;
	std::cout << "Classes\t:" << std::endl;
	for (size_t i = 0; i < classes.size(); i++)
	{
		std::cout << classes[i]->getName() << std::endl;
	}
}

void Feup_Student::changeCourse(std::string newCourse)
{
	course = newCourse;
}