#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <time.h>
#include "Date.h" //EXercício 1
#include "Student.h"
#include <fstream>
#include <sstream>
#include "Invoice.h"
#include "Library.h"
#include <list>
#include <iterator>
#include "Inventory.h"
#include "ProductEX6.h"
#include <set>
#include <algorithm>
#include <map>
#include "Vector.h"
#include "Feup_person.h"
#include "Feup_Student.h"
#include "Feup_Teacher.h"
#include "SpreadsheetCell.h"
#include "SpreadsheetCellString.h"
#include "SpreadsheetCellDouble.h"
#include "Date_exep.h"
#include "InvalidDate.h"

using namespace std;

/*
class Date
{
public:
	Date();
	Date(unsigned int year, unsigned int month, unsigned int day);
	Date(string yearMonthDay); // yearMonthDay must be in format "yyyy/mm/dd"
	void setYear(unsigned int year);
	void setMonth(unsigned int month);
	void setDay(unsigned int day);
	void setDate(unsigned int year, unsigned int month, unsigned int day);
	unsigned int getYear() const;
	unsigned int getMonth() const;
	unsigned int getDay() const;
	string getDate() const; // returns the date in format "yyyy/mm/dd"
	void show() const; // shows the date on the screen in format "yyyy/mm/dd"

	bool isValid() const;
	bool isEqualTo(const Date& date) const;
	bool isNotEqualTo(const Date& date) const;
	bool isAfter(const Date& date) const;
	bool isBefore(const Date& date) const;
private:
	bool Year() const; //retorna se o ano é ou não é bissexto
	int DaysOfMonth() const; //retorna os dias do mês
	unsigned int year;
	unsigned int month;
	unsigned int day;
};

Date::Date()
{
	time_t mytime = time(0);
	struct tm data_atual;
	localtime_s(&data_atual, &mytime);
	this->year = data_atual.tm_year + 1900; this->month = data_atual.tm_mon + 1; this->day = data_atual.tm_mday;
}

Date::Date(unsigned int year, unsigned int month, unsigned int day)
{
	this->year = year; this->month = month; this->day = day;
}

Date::Date(string yearMonthDay)
{
	this->year = stoi(yearMonthDay.substr(0, 4));
	this->month = stoi(yearMonthDay.substr(5, 2));
	this->day = stoi(yearMonthDay.substr(8, 2));
}

void Date::setYear(unsigned int year)
{
	this->year = year;
}

void Date::setMonth(unsigned int month)
{
	this->month = month;
}

void Date::setDay(unsigned int day)
{
	this->day = day;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day)
{
	this->year = year; this->month = month; this->day = day;
}

unsigned int Date::getYear() const
{
	return this->year;
}

unsigned int Date::getMonth() const
{
	return this->month;
}

unsigned int Date::getDay() const
{
	return this->day;
}

string Date::getDate() const
{
	string y = to_string(year), m = to_string(month), d = to_string(day);
	while (y.length() != 4)
	{
		y = '0' + y;
	}
	while (m.length() != 2)
	{
		m = '0' + m;
	}
	while (d.length() != 2)
	{
		d = '0' + d;
	}
	return y + "/" + m + "/" + d;
}

void Date::show() const
{
	cout << setfill('0');
	cout << setw(4) << year << "/" << setw(2) << month << "/" << setw(2) << day << endl;
}

bool Date::Year() const
{
	//cin >> x;
	if ((year % 4 == 0) && (year % 100 != 0))
		return true;
	else if (year % 400 == 0)
		return true;
	else
		return false;
}

int Date::DaysOfMonth() const
{
	bool ValidOperation = true;
	switch (month)
	{
	case (1):
		return 31;
	case (3):
		return 31;
	case (4):
		return 30;
	case (5):
		return 31;
	case (6):
		return 30;
	case (7):
		return 31;
	case (8):
		return 31;
	case (9):
		return 30;
	case (10):
		return 31;
	case (11):
		return 30;
	case (12):
		return 31;
	}
	if (month == 2)
	{
		if (Year())
			return 29;
		else
			return 28;
	}
}

bool Date::isValid() const
{
	if (year < 0)
		return false;
	else if (month > 12 || month < 1)
		return false;
	else if (day < 0 || day > DaysOfMonth())
		return false;
	else return true;
}

bool Date::isEqualTo(const Date& date) const
{
	if (this->year == int(date.getYear()) && this->month == int(date.getMonth()) && this->day == int(date.getDay()))
		return true;
	else
		return false;
}

bool Date::isNotEqualTo(const Date& date) const
{
	return !isEqualTo(date);
}

bool Date::isAfter(const Date& date) const
{
	if (year != date.getYear())
	{
		if (year > date.getYear())
			return true;
		else
			return false;
	}
	else if (month != date.getMonth())
	{
		if (month > date.getMonth())
			return true;
		else
			return false;
	}
	else if (day != date.getDay())
	{
		if (day > date.getDay())
			return true;
		else
			return false;
	}
	else
		return 0;
}

bool Date::isBefore(const Date& date) const
{
	return !isAfter(date);
}
*/

void F3EX1E()
{
	cout << "Because don't exist a method that can build a Date without parameters." << endl;
}

void showAboveAverageStudents(vector<Student> v, ofstream& str_out)  //2.d)
{
	double res = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		res += v[i].getFinalGrade();
	}
	res /= v.size();
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i].getFinalGrade() > res) {
			str_out << "Student name- " << v[i].getName() << endl;
			str_out << "Student code- " << v[i].getCode() << endl;
			str_out << "Short exam grade- " << v[i].getShortExam() << endl;
			str_out << "Project grade-	" << v[i].getProject() << endl;
			str_out << "Exam grade- " << v[i].getExam() << endl;
			str_out << "Final grade- " << v[i].getFinalGrade() << endl;
			str_out << "-----------------------------" << endl;
		}
	}
}

void coutshowAboveAverageStudents(vector<Student> v)  //2.e)
{
	double res = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		res += v[i].getFinalGrade();
	}
	res /= v.size();
	system("cls");
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i].getFinalGrade() > res) {
			cout << "Student name- " << v[i].getName() << endl;
			cout << "Student code- " << v[i].getCode() << endl;
			cout << "Short exam grade- " << v[i].getShortExam() << endl;
			cout << "Project grade-	" << v[i].getProject() << endl;
			cout << "Exam grade- " << v[i].getExam() << endl;
			cout << "Final grade- " << v[i].getFinalGrade() << endl;
			cout << "-----------------------------" << endl;
		}
	}
}

void ReadAndShow()  //2.e)
{
	int n;
	bool invalid;
	vector<Student> v;
	Student d;
	cout << "How many students are you going to define? ";
	do
	{
		invalid = false;
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			invalid = true;
		}
		else if (n < 0)
			invalid = true;
		if (cin.peek() != '\n')
		{
			cin.ignore(100000, '\n');
			invalid = true;
		}
		if (invalid)
			cout << "invalid input. Please try again. ";
	} while (invalid);
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "-----------" << i + 1 << "--------------" << endl;
		d.readStudentData();
		v.push_back(d);
	}
	coutshowAboveAverageStudents(v);
}

void F2EX2S(string& text, char c, string& res) //2.f)
{
	int ind;
	ind = text.find(c);
	res = text.substr(0, ind);
	text.erase(0, ind + 1);
}
void F2EX2I(string& text, char c, unsigned int& res)
{
	int ind;
	ind = text.find(c);
	res = stoi(text.substr(0, ind));
	text.erase(0, ind + 1);
}
void ReadandShowfile(string file2 /*, string file1))*/) //2.f
{
	//unsigned int se, p, e;
	//size_t ind;
	//ifstream str_in;
	ofstream str_out;
	//string text, name, code;
	//vector<Student> v;
	//str_in.open(file1);
	//if (!str_in.is_open())
	//{
	//	cerr << "invalid file opening input. ";
	//	exit(1);
	//}
	//while (getline(str_in, text, '\n'))
	//{
	//	F2EX2S(text, ';', name);
	//	F2EX2S(text, ';', code);
	//	F2EX2I(text, ';', se);
	//	F2EX2I(text, ';', p);
	//	F2EX2I(text, ';', e);
	//	Student st(name, code);
	//	st.setGrades(se, p, e);
	//	v.push_back(st);
	//}
	int n;
	bool invalid;
	vector<Student> v;
	Student d;
	cout << "How many students are you going to define? ";
	do
	{
		invalid = false;
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			invalid = true;
		}
		else if (n < 0)
			invalid = true;
		if (cin.peek() != '\n')
		{
			cin.ignore(100000, '\n');
			invalid = true;
		}
		if (invalid)
			cout << "invalid input. Please try again. ";
	} while (invalid);
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "-----------" << i + 1 << "--------------" << endl;
		d.readStudentData();
		v.push_back(d);
	}
	str_out.open(file2);
	for (size_t i = 0; i < v.size(); i++)
	{
		str_out << v[i].getCode() << ';' << v[i].getName() << ';' << v[i].getShortExam() << ';' << v[i].getProject() << ';' << v[i].getExam() << '\n';
	}
	//str_in.close();
	str_out.close();
}

void cart() //4
{
	Client y;
	string x, text;
	cout << "What is your name? "; getline(cin, x, '\n');
	y.setName(x);
	cout << "What is your street? "; getline(cin, x, '\n');
	cout << "Number of the door? "; getline(cin, text, '\n');
	x += " " + text;
	y.setAdress(x);
	cout << "And what is your zip-code? "; getline(cin, text, '\n');
	y.setZipCode(text);
	cout << "City? "; getline(cin, x, '\n');
	y.setCity(x);
	Invoice xx(y);
	xx.AddToCart();
	xx.showInvoice();
}

void Libraary() //5
{
	bool end;
	int n, nn, nnn;
	string text;
	char s;
	User u;
	Books b;
	Date d;
	Library l("ResultadoLibrary.txt", "library.txt");
	do
	{
		end = false;
		cout << "\n\n\tLibrary:" << endl;
		cout << "\t1. Users & Books\n\t2. Add an user\n\t3. Edit an user\n\t4. Save\n\t5. Add a book\n";
		cin >> n;
		if (cin.fail())
			break;
		cin.ignore();
		switch (n)
		{
		case(1):
			system("cls");
			l.ShowLibrary();
			system("pause");
			system("cls");
			break;
		case(2):
			system("cls");
			cout << "Name: "; getline(cin, text, '\n');
			u.setName(text);
			cout << "State: "; cin >> s;
			u.setState(s);
			cin.ignore();
			end = true;
			while (end)
			{
				cout << "Book: "; getline(cin, text, '\n');
				b.setName(text);
				cout << "State: "; cin >> s;
				b.setState(s);
				cout << "Year: "; cin >> n;
				d.setYear(n);
				cout << "Month: "; cin >> n;
				d.setMonth(n);
				cout << "Day: "; cin >> n;
				d.setDay(n);
				cin.ignore();
				b.setDate(d);
				u.AddBook(b);
				cout << "Other? ";
				cin >> s;
				cin.ignore();
				if (s == 'N')
					end = false;
			}
			l.AddUser(u);
			system("cls");
			l.SaveLibraryData();
			break;
		case(3):
			system("cls");
			l.ShowLibrary();
			cout << "What is the number? "; cin >> n;
			cout << "And what do you want to change? [N, S, B] "; cin >> s;
			cin.ignore();
			switch (s)
			{
			case('N'):
				cout << "Name: "; getline(cin, text, '\n');
				l.ChangeName(n - 1, text);
				system("cls");
				break;
			case('S'):
				cout << "State: "; cin >> s;
				l.ChangeState(n - 1, s);
				system("cls");
				break;
			case('B'):
				cout << "What is the number of the book? "; cin >> nn;
				cout << "And what do you want to change? [N, S, D] "; cin >> s; cin.ignore();
				switch (s)
				{
				case('N'):
					cout << "Name: "; getline(cin, text, '\n');
					l.ChangeBookName(n - 1, nn - 1, text);
					break;
				case('S'):
					cout << "State: "; cin >> s;
					cin.ignore();
					l.ChangeBookState(n - 1, nn - 1, s);
					break;
				case('D'):
					cout << "Year: "; cin >> nnn;
					d.setYear(n);
					cout << "Month: "; cin >> nnn;
					d.setMonth(n);
					cout << "Day: "; cin >> nnn;
					d.setDay(n);
					cin.ignore();
					l.ChangeBookDate(n - 1, nn - 1, d);
					break;
				}
				system("cls");
				break;
			}
		case(4):
			l.SaveLibraryData();
			cout << "\n\tSaved..."; system("pause"); system("cls");
			break;
		case(5):
			system("cls");
			l.ShowLibrary();
			cout << "What is the number? "; cin >> nn; cin.ignore();
			cout << "Book: "; getline(cin, text, '\n');
			b.setName(text);
			cout << "State: "; cin >> s;
			b.setState(s);
			cout << "Year: "; cin >> n;
			d.setYear(n);
			cout << "Month: "; cin >> n;
			d.setMonth(n);
			cout << "Day: "; cin >> n;
			d.setDay(n);
			cin.ignore();
			b.setDate(d);
			l.AddBook(nn - 1, b);
			cout << "Other? ";
			cin >> s;
			cin.ignore();
			system("cls");
		}
	} while (!end);
}

/*
template <typename T>
void ShowList(list<T> x)
{
	list<int>::iterator	it;
	cout << "\n{";
	for (it = x.begin(); it != x.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << "}\n";
	//
	//for(auto elem: x)
	//{
	//	cout << elem << " ";
	//}
	//
}
*/

void Orders() //6
{
	bool end;
	int n;
	char s;
	string text;
	Inventory inv;
	ProductEX6 p;
	do
	{
		cout << "\n\n\tInventory:" << endl;
		cout << "\t1. Order an product.\n\t2. Add a Product.\n\t3. Show the order.\n\t4. Show the store.\n\n"; cin >> n; cin.ignore();
		if (cin.fail())
			break;
		switch (n)
		{
		case(1):
			system("cls");
			do
			{
				end = false;
				cout << "ID: ";
				do
				{
					getline(cin, text, '\n');
					p.setID(stoi(text));
					if (!p.isValid())
						cout << "Invalid input, please try again. ";
				} while (!p.isValid());
				p.setID(stoi(text));
				inv.processOrder(p);
				cout << "Do you want to add another? "; cin >> s; cin.ignore();
				if (s == 'Y')
					end = true;
				cout << end << endl;
			} while (end);
			system("cls");
			break;
		case(2):
			system("cls");
			do
			{
				end = false;
				do
				{
					cout << "ID: ";
					getline(cin, text, '\n');
					p.setID(stoi(text));

				} while (!p.isValid());
				p.setID(stoi(text));
				cout << "Quantity? "; cin >> n;
				p.setQuantity(n);
				inv.AddTotal(p);
				cout << "Do you want to add another? "; cin >> s; cin.ignore();
				if (s == 'Y')
					end = true;
			} while (end);
			system("cls");
			break;
		case(3):
			system("cls");
			inv.Showlist();
			system("pause");
			system("cls");
			break;
		case(4):
			system("cls");
			inv.ShowTotal();
			system("pause");
			system("cls");
			break;
		}
	} while (1);
}

template <typename T>
void maxminValue(vector<T> v, T& max, T& min) //7
{
	max = v[0]; min = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > max)
			max = v[i];
		else if (v[i] < min)
			min = v[i];
	}
	/*
	vector<int> x = { 1,2,3,4,5,7,4,2,4,7,111,-2 ,23 };
	int max = 0, min = 0;
	maxminValue(x, max, min);
	cout << max << ", " << min;
	*/
}

void removeduplicates(string file1) // 9.a)
{
	set<string> order;
	string text;
	ifstream str_in;
	ofstream str_out;
	vector<string> v;
	str_in.open(file1);
	if (!str_in.is_open())
	{
		cerr << "Invalid opening file input. " << endl;
		exit(1);
	}
	while (getline(str_in, text, '\n'))
	{
		v.push_back(text);
		order.insert(text);
	}
	str_out.open(file1);
	for (size_t i = 0; i < v.size(); i++)
	{
		if (order.find(v[i]) != order.end())
		{
			str_out << v[i] << endl;;
			order.erase(order.find(v[i]));
		}
	}
	str_in.close();
	str_out.close();
}

void rremoveduplicates(string file1)//9.b
{
	vector<string>::iterator it;
	string text;
	ifstream str_in;
	ofstream str_out;
	vector<string> v;
	str_in.open(file1);
	if (!str_in.is_open())
	{
		cerr << "Invalid opening file input. " << endl;
		exit(1);
	}
	while (getline(str_in, text, '\n'))
	{
		v.push_back(text);
	}
	str_out.open(file1);
	sort(v.begin(), v.end());
	it = unique (v.begin(), v.end());
	v.resize(distance(v.begin(), it)); //distance dá a distancia entre os dois iterators
	str_out.open(file1);
	for (size_t i = 0; i < v.size(); i++)
	{
		str_out << v[i] << endl;;
	}
	str_in.close();
	str_out.close();
}

void rrremoveduplicates(string file1) //10
{
	string text;
	ifstream str_in;
	ofstream str_out;
	list<string> lst;
	str_in.open(file1);
	if (!str_in.is_open())
	{
		cerr << "Invalid opening file input. " << endl;
		exit(1);
	}
	while (getline(str_in, text, '\n'))
	{
		lst.push_back(text);
	}
	str_out.open(file1);
	lst.sort();
	lst.unique();
	auto it = lst.begin();
	for(it; it != lst.end(); ++it)
	{
		str_out << *it << endl;
	}
	str_in.close();
	str_out.close();
}

bool comparator1(Student a, Student b) //11
{
	return a.getFinalGrade() > b.getFinalGrade();
}

bool comparator2(Student a, Student b) //11
{
	return ((a.getName()) < (b.getName()));
}

void ShowAboveAverageStudents(vector<Student> v, ofstream& str_out) //11
{
	char s;
	double res = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		res += v[i].getFinalGrade();
	}
	res /= v.size();
	cout << "Do you want to order the students by names or by grades? [N, G] "; cin >> s;
	switch (s)
	{
	case('G'):
		sort(v.begin(), v.end(), comparator1);
		break;
	case('N'):
		sort(v.begin(), v.end(), comparator2);
		break;
	}
	system("cls");
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i].getName() << endl;
	}
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i].getFinalGrade() > res) {
			str_out << "Student name- " << v[i].getName() << endl;
			str_out << "Student code- " << v[i].getCode() << endl;
			str_out << "Short exam grade- " << v[i].getShortExam() << endl;
			str_out << "Project grade-	" << v[i].getProject() << endl;
			str_out << "Exam grade- " << v[i].getExam() << endl;
			str_out << "Final grade- " << v[i].getFinalGrade() << endl;
			str_out << "-----------------------------" << endl;
		}
	}
	str_out.close();
}

void ReadandShowfilee(string file2 /*, string file1))*/) //2.f
{
	//unsigned int se, p, e;
	//size_t ind;
	//ifstream str_in;
	ofstream str_out;
	//string text, name, code;
	//vector<Student> v;
	//str_in.open(file1);
	//if (!str_in.is_open())
	//{
	//	cerr << "invalid file opening input. ";
	//	exit(1);
	//}
	//while (getline(str_in, text, '\n'))
	//{
	//	F2EX2S(text, ';', name);
	//	F2EX2S(text, ';', code);
	//	F2EX2I(text, ';', se);
	//	F2EX2I(text, ';', p);
	//	F2EX2I(text, ';', e);
	//	Student st(name, code);
	//	st.setGrades(se, p, e);
	//	v.push_back(st);
	//}
	int n;
	bool invalid;
	vector<Student> v;
	Student d;
	cout << "How many students are you going to define? ";
	do
	{
		invalid = false;
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			invalid = true;
		}
		else if (n < 0)
			invalid = true;
		if (cin.peek() != '\n')
		{
			cin.ignore(100000, '\n');
			invalid = true;
		}
		if (invalid)
			cout << "invalid input. Please try again. ";
	} while (invalid);
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "-----------" << i + 1 << "--------------" << endl;
		d.readStudentData();
		v.push_back(d);
	}
	str_out.open(file2);
	ShowAboveAverageStudents(v, str_out);
}

void eurokey()
{
	vector<int> numbers, stars;
	srand((unsigned int)time(NULL));
	for (int i = 1; i < 51; i++)
	{
		numbers.push_back(i);
		if (i <= 12)
			stars.push_back(i);
	}
	random_shuffle(numbers.begin(), numbers.end());
	random_shuffle(stars.begin(), stars.end());
	cout << "Main numbers: ";
	for (int i = 0; i < 5; i++)
	{
		cout << numbers[i] << ' ';
	}
	cout << "\nStars: " << stars[0] << " " << stars[1] << endl;
}

void eurokeyy()
{
	srand((unsigned int)time(NULL));
	set<int> main, stars;
	while (main.size() < 5)
	{
		main.insert(1 + rand() % 50);
	}
	while (stars.size() < 2)
	{
		stars.insert(1 + rand() % 12);
	}
	cout << "Main numbers: ";
	set<int>::iterator it = main.begin();
	for (it; it != main.end() ; ++it)
	{
		cout << *it << ' ';
	}
	cout << "\nStars: ";
	set<int>::iterator itt = stars.begin();
	for (itt; itt != stars.end(); ++itt)
	{
		cout << *itt << ' ';
	}
}

void ex13_a() //3.a
{
	srand((unsigned int)time(NULL));
	int n;
	vector<int> numbers, stars, tip_n, tip_s, key;
	vector<vector<int>> tips;
	for (int i = 1; i < 51; i++)
	{
		numbers.push_back(i);
	}
	stars.assign(numbers.begin(), numbers.begin() + 12);
	cout << "How many tips do you want to create? "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		random_shuffle(numbers.begin(), numbers.end());
		random_shuffle(stars.begin(), stars.end());
		tip_n.assign(numbers.begin(), numbers.begin() + 5);
		tip_s.assign(stars.begin(), stars.begin() + 2);
		sort(tip_n.begin(), tip_n.end());
		sort(tip_s.begin(), tip_s.end());
		tips.push_back(tip_n);
		tips.push_back(tip_s);
	}
	/*
	*Generate the key
	*/
	random_shuffle(numbers.begin(), numbers.end());
	random_shuffle(stars.begin(), stars.end());
	key.assign(numbers.begin(), numbers.begin() + 5);
	sort(key.begin(), key.end());
	key.push_back(stars[0]); key.push_back(stars[1]);
	sort(key.begin() + 5, key.end());
	cout << "The key is:";
	for (size_t i = 0; i < key.size(); i++)
	{
		if (i == 5)
			cout << ",";
		cout << " " << key[i];
	}
	cout << endl
		 << "TIPS: " << endl;
	for (size_t i = 0; i < tips.size(); i+=2)
	{
		tip_n.clear();
		tip_s.clear();
		cout << i + 1 << '-';
		for (size_t j = 0; j < tips[i].size(); j++)
			cout << " " << tips[i][j];
		cout << ',';
		for (size_t j = 0; j < tips[i + 1].size(); j++)
			cout << ' ' << tips[i + 1][j];
		set_intersection(tips[i].begin(), tips[i].end(), key.begin(), key.begin() + 5, back_inserter(tip_n));
		set_intersection(tips[i+1].begin(), tips[i+1].end(), key.begin()+6, key.begin() + 7, back_inserter(tip_s));
		cout << "----> Numbers:";
		for (size_t j = 0; j < tip_n.size(); j++)
			cout << ' ' << tip_n[j];
		cout << "| stars:";
		for (size_t j = 0; j < tip_s.size(); j++)
			cout << ' ' << tip_s[j];
		cout << endl;
	}
}

void ex13_b()	//13.b
{
	srand((unsigned int)time(NULL));
	int n;
	vector<int> numbers, stars;
	set<int>  tip_n, tip_s, key_n, key_s;
	vector<set<int>> tips;
	for (int i = 1; i < 51; i++)
	{
		numbers.push_back(i);
	}
	stars.assign(numbers.begin(), numbers.begin() + 12);
	cout << "How many tips do you want to create? "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		random_shuffle(numbers.begin(), numbers.end());
		random_shuffle(stars.begin(), stars.end());
		for (int i = 0; i < 5; i++)
		{
			tip_n.insert(numbers[i]);
			if (i < 2)
				tip_s.insert(stars[i]);
		}
		tips.push_back(tip_n);
		tips.push_back(tip_s);
	}
	/*
	*Generate the key
	*/
	random_shuffle(numbers.begin(), numbers.end());
	random_shuffle(stars.begin(), stars.end());
	for (int i = 0; i < 5; i++)
	{
		key_n.insert(numbers[i]);
		if (i < 2)
			key_s.insert(stars[i]);
	}
	cout << "The key is:";
	for (auto i = key_n.begin(); i != key_n.end(); ++i)
	{
		cout << " " << *i;
	}
	cout << ',';
	for (auto elem : key_s)
	{
		cout << ' ' << elem;
	}
	cout << endl
		<< "TIPS: " << endl;
	for (size_t i = 0; i < tips.size(); i += 2)
	{
		tip_n.clear();
		tip_s.clear();
		for (auto elem: tips[i])
			cout << " " << elem;
		cout << ',';
		for (auto elem: tips[i+1])
			cout << ' ' << elem;
		set_intersection(tips[i].begin(), tips[i].end(), key_n.begin(), key_n.end(), inserter(tip_n, tip_n.begin()));
		set_intersection(tips[i + 1].begin(), tips[i + 1].end(), key_s.begin(), key_s.end(), inserter(tip_s, tip_s.begin()));
		cout << "----> Numbers:";
		for (auto elem: tip_n)
			cout << ' ' << elem;
		cout << "| stars:";
		for (auto elem: tip_s)
			cout << ' ' << elem;
		cout << endl;
	}
}

void ex14_a()
{
	cout << "I choose the map container because i can save a string as the key and a vector<int> with the numbers of the lines where the string saved on the key appears.";
}

void ToUpper(string& word)
{
	for (size_t i = 0; i < word.length(); i++)
	{
		word[i] = toupper(word[i]);
	}
}
void ex14_b()
{
	string str, word;
	fstream str_in;
	set<string> words;
	map<string, set<int>> text_file;
	vector<string> text;
	bool validInput;
	int line = 1;
	cout << "Please give the name of thw file with the words: "; getline(cin, str, '\n');
	str_in.open(str);
	if (!str_in.is_open())
	{
		cout << "invalid file opening input.";
		exit(1);
	}
	while (getline(str_in, str, '\n'))
	{
		istringstream x(str);
		x >> word;
		ToUpper(word);
		words.insert(word);
	}
	str_in.close();
	cout << "Now, give the name of the file with the text. "; getline(cin, str, '\n');
	str_in.open(str);
	if (!str_in.is_open())
	{
		cout << "invalid file opening input.";
		exit(1);
	}
	while (getline(str_in, str, '\n'))
	{
		text.push_back(str);
		for (size_t i = 0; i < str.length(); i++)
		{
			if (!isalpha(str[i]))
			{
				str[i] = ' ';
			}
		}
		istringstream x(str);
		while (x.good())
		{
			x >> word;
			ToUpper(word);
			text_file[word].insert(line);
		}
		line++;
	}
	str_in.close();
	do
	{
		validInput = false;
		cout << "What is the word that you want to search? "; getline(cin, str, '\n');
		if (cin.fail())
		{
			if (!cin.eof())
				cout << "Invalid input. " << endl;
			else
				validInput = true;
			cin.clear();
		}
		else
		{
			ToUpper(str);
			if (words.find(str) != words.end())
			{	
				if (text_file.find(str) != text_file.end())
				{
					cout << "RESULTS:" << endl;
					for (auto elem: text_file[str])
					{
						cout << '\t' << elem << ": " << text[elem-1] << endl;
					}
				}
				else
					cout << str << " - " << "------";
			}
			else
			{
				cout << "Invalid word. " << endl;
			}
		}
	} while (!validInput);
}

bool neg(int n)
{
	return (n < 0);
}
void ex16_a(vector<int>::iterator beg, vector<int>::iterator &end)
{
	end = remove_if(beg, end, neg);
	/*
	vector<int> v = { 1,-2,-3,4,-12, 0 };
	auto p = v.end();
	ex16_a(v.begin(),p);
	for (auto pb = v.begin(); p != pb; ++pb)
	{
		cout << *pb << endl;
	}
	*/
}

class Pred //ex 16 b)
{
public:
	Pred(int limInf, int limSup)
	{
		limI = limInf;
		limS = limSup;
	}
	bool operator()(int n)
	{
		return (n >= limI && n <= limS);
	}
private:
	int limI, limS;
};

void ex16_b()
{
	vector<int> v;
	int n, ni, ns;
	cout << "LimInf? "; cin >> ni;
	cout << "LimSup? "; cin >> ns;
	Pred r(ni, ns);
	while (true)
	{
		cout << "Number? "; cin >> n;
		if (cin.fail())
		{
			if (cin.eof())
			{
				break;
			}
			else
			{
				cout << "Invalid input" << endl;
			}
			cin.clear();
		}
		else
			v.push_back(n);
	}
	vector<int>::iterator it;
	it = remove_if(v.begin(), v.end(), r);
	for (auto pb = v.begin(); pb != it; ++pb)
	{
		cout << *pb << endl;
	}
}

namespace myfunctions
{
	void cout(const string& s) //17
	{
		string c = "";
		for (size_t i = 0; i < s.length(); i++)
		{
			if (isalpha(s[i]) || s[i] == ' ')
			{
				c += s[i];
			}
		}
		std::cout << c << endl;
	}

	bool endl(const string& s)
	{
		char x = s[s.length() - 1];
		return !(x == toupper(x));
	}
}

void ex_18()
{
	//_Class* c1 = new _Class("EDA");
//_Class* c2 = new _Class("EDE");
//_Class* c3 = new _Class("EDI");
//Feup_Student* mieic234 = new Feup_Student(234, "John Souza", "St. John Street",2, "MIEIC");
//mieic234->addNewClass(c1);
//mieic234->addNewClass(c3);
//mieic234->showRecord();
//Feup_person* mieic345 = new Feup_Student(345, "Liz Tanner", "St. Liz Street", 2, "MIEIC");
//mieic345->showRecord();
//(===========================================================================================)
//Feup_person dei987(987, "Peter Lee", "St. Peter Street");
//Feup_Student bio123(123, "John Silva", "St. John Street",3, "MIB");
//_Class* c1 = new _Class("EDA");
//_Class* c2 = new _Class("EDE");
//_Class* c3 = new _Class("EDI");
//dei987.showRecord();
//bio123.addNewClass(c1);
//bio123.showRecord();
//bio123.addNewClass(c2);
//bio123.addNewClass(c3);
//bio123.showRecord();
//(============================================================================================)

	_Class* c1 = new _Class("EDA");
	_Class* c2 = new _Class("EDU");
	std::vector<Feup_person*> p(3);
	p[0] = new Feup_Teacher(987, "Pedro Santos", "Rua do Pedro", "Assistente",
		"MIB");
	p[1] = new Feup_Student(123, "Nuno Silva", "Rua do Nuno", 3, "MIB");
	p[2] = new Feup_Student(234, "Ana Sousa", "Rua da Ana", 2, "MIEIC");
	std::cout << "BEFORE DYNAMIC_CAST:\n";
	for (unsigned int i = 0; i < p.size(); i++)
		p[i]->showRecord();
	for (unsigned int i = 0; i < p.size(); i++)
	{
		Feup_Teacher* t = dynamic_cast<Feup_Teacher*> (p[i]);
		if (t != NULL)
			t->addNewClass(c1);
		else
		{
			Feup_Student* s = dynamic_cast<Feup_Student*> (p[i]);
			if (s != NULL)
				s->addNewClass(c2);
		}
	}

	std::cout << "AFTER DYNAMIC_CAST:\n";
	for (unsigned int i = 0; i < p.size(); i++)
		p[i]->showRecord();
}

//void ex19_b()
//{
//	srand((unsigned int)time(NULL));
//	int number;
//	std::cout << "Please give the dimension that you want. "; cin >> number;
//	SpreadsheetCell** sp = (SpreadsheetCell**)malloc(number * sizeof(SpreadsheetCell*));
//	for (int i = 0; i < number; i++)
//	{
//		if (i % 2)
//		{
//			sp[i] = new SpreadsheetCellString();
//			sp[i]->set(to_string(double(rand()) / 100.0));
//		}
//		else
//		{
//			sp[i] = new SpreadsheetCellDouble();
//			sp[i]->set(to_string(double(rand()) / 100.0));
//		}
//	}
//	cout << '|';
//	for (int i = 0; i < number; i++)
//	{
//		cout << sp[i]->getString() <<'|';
//	}
//}

void ex19_c()
{
}

void ex_20()
{
	int n;
	Date_exep x(1,1,1);
	cout << "Give a year "; cin >> n;
	try
	{
		x.setYear(n);
	}
	catch (InvalidDate e)
	{
		cerr << e.what() << endl;

	}
	cout << "Give a month."; cin >> n;
	try
	{
		x.setMonth(n);
	}
	catch (InvalidDate e)
	{
		cerr << e.what() << endl;
	}
	cout << "Give a day."; cin >> n;
	try
	{
		x.setDay(n);
	}
	catch (InvalidDate e)
	{
		cerr << e.what() << endl;
	}
	x.show();
}

int main()
{
	if (3 % 2)
		cout << 1 << endl;
	return 0;
}
