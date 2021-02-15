#pragma once
#include <string>

class _Class
{
public:
	_Class();
	_Class(std::string name);
	std::string getName() const;
private:
	std::string name;
};

