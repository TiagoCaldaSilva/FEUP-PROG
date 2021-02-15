#include "_Class.h"

_Class::_Class()
{
	name = "";
}

_Class::_Class(std::string name)
{
	this->name = name;
}

std::string _Class::getName() const
{
	return name;
}