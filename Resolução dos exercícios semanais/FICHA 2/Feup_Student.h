#pragma once
#include "Feup_person.h"
#include "_Class.h"
#include <vector>


class Feup_Student :
	public Feup_person
{
public:
	Feup_Student();
	Feup_Student(int id, std::string name, std::string adress, int year,std::string course);
	void addNewClass(_Class* _class);
	virtual void showRecord();
	void changeCourse(std::string newCourse);
private:
	int year;
	std::string course;
	std::vector<_Class*> classes;
};

