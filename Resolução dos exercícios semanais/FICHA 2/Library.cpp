#include "Library.h"
#include <string>
#include <vector>
#include "User.h"
#include <fstream>

using namespace std;

Library::Library()
{
	users.resize(0);
	file_write = "LibraryProgram.txt";
	file_read = "LibraryProgram.txt";
}

Library::Library(string file_write, string file_read)
{
	this->file_read = file_read; this->file_write = file_write;
	ReadLibraryData();
}

Library::Library(vector<User> users, string file_write, string file_read)
{
	this->users = users; this->file_write = file_write; this->file_read = file_read;
}

void Library::SaveLibraryData() const	
{
	ofstream str_out;
	str_out.open(file_write);
	for (size_t i = 0; i < users.size(); i++)
	{
		str_out << "Name: " << users[i].getName() << ", State: " << users[i].getState() << endl;
		for (size_t k = 0; k < users[i].getBooks().size(); k++)
		{
			str_out << "- " << users[i].getBooks()[k].getName() << ", Date: ";
			users[i].getBooks()[k].getDate();
			str_out << ", State: " << users[i].getBooks()[k].getState() << endl;
		}
		str_out << "|--------------------------------------------------------------------------------|" << endl;
	}
	str_out.close();
}

void Library::ReadLibraryData()
{
	ifstream str_in;
	string text;
	User x;
	Books b;
	int ind;
	str_in.open(file_read);
	if (!str_in.is_open())
	{
		cerr << "Invalid file opening used. "; exit(1);
	}
	while (getline(str_in, text, '\n'))
	{
		if (text[0] != '|' && text[0] != '-')
		{
			text.erase(0, 6);
			ind = text.find(',');
			x.setName(text.substr(0, ind));
			text.erase(0, ind + 9);
			x.setState(text[0]);
		}
		else if (text[0] != '|')
		{
			ind = text.find(',');
			b.setName(text.substr(1, ind - 1));
			text.erase(0, ind + 8);
			ind = text.find(',');
			Date d(text.substr(0, ind-1));
			b.setDate(d);
			text.erase(0, ind + 9);
			b.setState(text[0]);
			x.AddBook(b);
		}
		else
		{
			AddUser(x);
			x.setVBooks({});
		}
	}
	str_in.close();
}

void Library::AddUser(User u)
{
	users.push_back(u);
}

void Library::ShowLibrary() const
{
	for (size_t i = 0; i < users.size(); i++)
	{
		cout << i+1 << "-Name: " << users[i].getName() << ", State: " << users[i].getState() << endl;
		for (size_t k = 0; k < users[i].getBooks().size(); k++)
		{
			cout << "- " << users[i].getBooks()[k].getName() << ", Date: ";
			users[i].getBooks()[k].getDate().show();
			cout << ", State = " << users[i].getBooks()[k].getState() << endl;
		}
		cout << "|--------------------------------------------------------------------------------|" << endl;
	}
}

void Library::ChangeName(int index, string name)
{
	users[index].setName(name);
}

void Library::ChangeState(int index, char s)
{
	users[index].setState(s);
}

void Library::ChangeBookName(int index, int n, string b)
{
	vector<Books> x;
	x = users[index].getBooks();
	x[n].setName(b);
	users[index].setVBooks(x);
}

void Library::ChangeBookState(int index, int n, char b)
{
	vector<Books> x;
	x = users[index].getBooks();
	x[n].setState(b);
	users[index].setVBooks(x);
}

void Library::ChangeBookDate(int index, int n, Date b)
{
	vector<Books> x;
	x = users[index].getBooks();
	x[n].setDate(b);
	users[index].setVBooks(x);
}

void Library::AddBook(int index, Books b)
{
	users[index].AddBook(b);
}