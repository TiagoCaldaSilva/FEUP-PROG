#pragma once
#include <string>
using namespace std;

class Client
{
public:
	Client();
	Client(string name, string adress, string zipcode, string city);
	string getName();
	string getAdress();
	string getZipCode();
	string getCity();
	void setName(string x);
	void setAdress(string x);
	void setZipCode(string x);
	void setCity(string x);
private:
	string name, adress, zipcode, city;
};

