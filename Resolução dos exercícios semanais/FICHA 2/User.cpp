#include "User.h"
#include <string>
#include <vector>
#include "Date.h"
#include "Books.h"

using namespace std;

User::User()
{
	name = ""; books.resize(0); state = ' ';
}

User::User(string name, vector<Books> books, char state)
{
	this->name = name; this->books = books; this->state = state;
}

void User::setName(string name)
{
	this->name = name;
}

void User::setVBooks(vector<Books> books)
{
	this->books = books;
}

void User::setState(char state)
{
	this->state = state;
}

string User::getName() const
{
	return name;
}

vector<Books> User::getBooks() const
{
	return books;
}

char User::getState() const
{
	return state;
}

void User::AddBook(Books book)
{
	books.push_back(book);
}