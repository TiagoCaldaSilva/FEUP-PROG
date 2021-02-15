#pragma once
#include <string>

using namespace std;

class Product
{
public:
	Product();
	Product(string name, double price);
	string getname();
	double getPrice();
private:
	string name;
	double price;
};

