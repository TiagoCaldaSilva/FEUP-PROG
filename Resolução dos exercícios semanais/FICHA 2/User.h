#pragma once
#include <string>
#include "Date.h"
#include <vector>
#include "Books.h"

using namespace std;


class User
{
public:
	User();
	User(string name, vector<Books> books, char state);
	void setName(string name);
	void setVBooks(vector<Books> books);
	void setState(char state);
	string getName() const;
	vector<Books> getBooks() const;
	char getState() const;
	void AddBook(Books book);
private:
	string name;
	vector<Books> books;
	char state; //A, N
};

