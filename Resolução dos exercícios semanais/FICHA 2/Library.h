#pragma once
#include "User.h"
#include <string>
#include <vector>

using namespace std;

class Library
{
public:
	Library();
	Library(string file_write, string file_read);
	Library(vector<User> users, string file_write, string file_read);
	void SaveLibraryData() const;
	void ReadLibraryData();
	void AddUser(User u);
	void ShowLibrary() const;
	void ChangeName(int index, string name);
	void ChangeState(int index, char s);
	void ChangeBookName(int index, int n, string b);
	void ChangeBookState(int index, int n, char b);
	void ChangeBookDate(int index, int n, Date b);
	void AddBook(int index, Books b);
private:
	vector<User> users;
	string file_write, file_read;
};

