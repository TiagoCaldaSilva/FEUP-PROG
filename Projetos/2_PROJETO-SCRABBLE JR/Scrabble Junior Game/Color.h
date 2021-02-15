#pragma once
#include <string>
#include <vector>
#include <map>


class Color
{
public:
	Color();
	Color(std::vector<std::string> name, std::vector<int> n);
	bool isValid(std::string name) const;
	bool addColor(std::string name, int nc);
	void changeColor(std::string name, int nc);
	int getColor(std::string name) const;
	std::string getName(int nc) const;
private:
	std::map<std::string, int> x, def;
};
