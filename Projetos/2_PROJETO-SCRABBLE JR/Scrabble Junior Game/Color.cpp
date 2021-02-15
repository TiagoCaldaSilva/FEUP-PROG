
#include "Color.h"
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <iostream>

using namespace std;

Color::Color()
{
	vector<string> s = { "NCM", "NCMB", "NCTM", "P1", "P2", "P3", "P4", "LT", "PT", "GBL" };
	vector<int> n = { 7,1,4,10,15,9,2,3,5, 4 };
	for (size_t i = 0; i < s.size(); i++)
	{
		x.insert(pair<string, int>(s[i], n[i]));
		def.insert(pair<string, int>(s[1], n[1]));
	}
}

Color::Color(vector<string> name, vector<int> n)
{
	for (size_t i = 0; i < name.size(); i++)
	{
		x.insert(pair<string, int>(name[i], n[i]));
	}
}

bool Color::isValid(string name) const
{
	//for (map<string, int>::const_iterator it = x.begin(); it != x.end(); ++it)
	//{
	//	if (it->first == name)
	//		return true;
	//}
	//return false;
	if (x.find(name) != x.end())
		return true;
	return false;
}

bool Color::addColor(string name, int nc)
{
	if (isValid(name))
	{
		x.insert(pair<string, int>(name, nc));
		return true;
	}
	else
		return false;
}

void Color::changeColor(string name, int nc)
{
	//for (map<string, int>::iterator it = x.begin(); it != x.end();++it)
	//{
	//	if (it->first == name)
	//		it->second = nc;
	//}
	if (nc != 16) //user choice
		x.find(name)->second = nc;
	else  //default
		x.find(name)->second = def.find(name)->second;
}

int Color::getColor(string name) const
{
	/*for (map<string, int>::const_iterator it = x.begin(); it != x.end(); ++it)
	{
		if (it->first == name)
			return it->second;
	}*/
	return x.find(name)->second;
}

string Color::getName(int nc) const
{
	for (map<string, int>::const_iterator it = x.begin(); it != x.end(); ++it)
	{
		if (it->second == nc)
			return it->first;
	}
	return " ";
}
