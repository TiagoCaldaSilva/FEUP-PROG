#include "Client.h"
#include <iostream>
#include <string>

using namespace std;

Client::Client()
{
	name = "";
	adress = "",
	zipcode = "";
	city == "";
}

Client::Client(string name, string adress, string zipcode, string city)
{
	this->name = name;
	this->adress = adress;
	this->zipcode = zipcode;
	this->city = city;
}

string Client::getName()
{
	return name;
}

void Client::setName(string x)
{
	name = x;
}

void Client::setAdress(string x)
{
	adress = x;
}

void Client::setZipCode(string x)
{
	zipcode = x;
}

void Client::setCity(string x)
{
	city = x;
}

string Client::getAdress()
{
	return adress;
}

string Client::getZipCode()
{
	return zipcode;
}

string Client::getCity()
{
	return city;
}