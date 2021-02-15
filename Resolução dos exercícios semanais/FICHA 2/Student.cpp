#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int	Student::weightShortExam = 20;
int Student::weightProject = 30;
int Student::weightExam = 50;

void Student::setGrades(double shortExam, double project, double exam)
{
	this->shortExam = shortExam; this->project = project; this->exam = exam;
	double result;
	result = shortExam * (weightShortExam * 0.01) + project * (weightProject * 0.01) + exam * (weightExam * 0.01);
	finalGrade = round(result);
	//utiliza-se o static para estas variáveis só terem um life time do programa, ou seja, quando o programa acaba o valor a variavel volta ao valor que tinha antes de o iniciar
}

Student::Student()
{
	name = "";
	code = "";
	shortExam = 0;
	project = 0;
	exam = 0;
	finalGrade = 0;
}

Student::Student(const string& code, const string& name)
{
	this->code = code; this->name = name;
}

string Student::getCode() const
{
	return code;
}

string Student::getName() const
{
	return name;
}

int Student::getShortExam() const
{
	return shortExam;
}

int Student::getProject() const
{
	return project;
}

int Student::getExam() const
{
	return exam;
}

int Student::getFinalGrade() const
{
	return finalGrade;
}

bool Student::isApproved() const
{
	if (finalGrade >= 10)
		return true;
	else
		return false;
}

void Student::readStudentData()
{
	string text;
	bool invalid, ignore;
	unsigned int n;
	cout << "Student Code? ";
	do
	{
		invalid = false;
		getline(cin, text, '\n');
		if (cin.fail())
		{
			cin.clear();
			invalid = true;
		}
		else if (text[0] != 'u' || text[1] != 'p' || text.length() != 11)
			invalid = true;
		else
		{
			for (int i = 2; i <= 10; i++)
			{
				if (text[i] < 48 || text[i] > 57)
				{
					invalid = true;
					break;
				}
			}
		}
		if (invalid)
			cout << "Invalid input. Please try again. ";
		else
			code = text;
	} while (invalid);
	cout << "Student name? ";
	do
	{
		invalid = false;
		getline(cin, text, '\n');
		if (cin.fail())
		{
			cin.clear();
			invalid = true;
		}
		else
			name = text;
	} while (invalid);
	cout << "Short exame grade? ";
	do
	{
		ignore = false;
		invalid = false;
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			invalid = true;
		}
		else if (n > 20 || n < 0)
			invalid = true;
		if (cin.peek() != '\n')
		{
			invalid = true;
			ignore = true;
		}
		if (ignore)
			cin.ignore(1000000, '\n');
		if (invalid)
			cout << "Invalid input. ";
		else
			shortExam = n;
	} while (invalid);
	cout << "Project grade? ";
	do
	{
		ignore = false;
		invalid = false;
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			invalid = true;
		}
		else if (n > 20 || n < 0)
			invalid = true;
		if (cin.peek() != '\n')
		{
			invalid = true;
			ignore = true;
		}
		if (ignore)
			cin.ignore(1000000, '\n');
		if (invalid)
			cout << "Invalid input. ";
		else
			project = n;
	} while (invalid);
	cout << "Exam grade? ";
	do
	{
		ignore = false;
		invalid = false;
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			invalid = true;
		}
		else if (n > 20 || n < 0)
			invalid = false;
		if (cin.peek() != '\n')
		{
			invalid = true;
			ignore = true;
		}
		if (ignore)
			cin.ignore(1000000, '\n');
		if (invalid)
			cout << "Invalid input. ";
		else
			exam = n;
	} while (invalid);
	cin.ignore();	//'\n'
	finalGrade = (shortExam * weightShortExam + project * weightProject + exam * weightExam);
}
