#include "Product.h"
#include <iostream>
#include <string>

using namespace std;

Product::Product()
{
	name = "";
	price = 0;
}

Product::Product(string name, double price)
{
	this->name = name;
	this->price = price;
}

string Product::getname()
{
	return name;
}

double Product::getPrice()
{
	return price;
}