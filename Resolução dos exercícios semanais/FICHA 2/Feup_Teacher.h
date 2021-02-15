#pragma once
#include "Feup_person.h"
#include "_Class.h"
#include <vector>

class Feup_Teacher :
	public Feup_person
{
public:
	Feup_Teacher();
	Feup_Teacher(int id, std::string name, std::string adress, std::string rank, std::string course);
	virtual void showRecord();
	void addNewClass(_Class* _class);
	void changeCourse(std::string newCourse);
	void showCourse();
private:
	std::string rank;
	std::string course;
	std::vector<_Class*> classes;
};

