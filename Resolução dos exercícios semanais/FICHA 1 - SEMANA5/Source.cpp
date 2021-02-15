#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> //atoi
#include <iomanip> //setfill
#include <algorithm> //count
#include <fstream> //files
#include <conio.h> //_getch()
#include <stdlib.h> //malloc
#include <string.h>

using namespace std;


char encryptChar(char c, int key) //5.1 a)
{
	int ci = int(c), x;
	if (ci >= 97) //minuscula
		x = 97;
	else
		x = 65;
	if (key >= 0)
		return (((ci + key) % x) % 26) + x;
	else
	{
		while ((ci - x) + key < 0)
		{
			key += 26;
		}
		return ((((ci - x) + key) % 26) + x);
	}
}


string encryptString(string s, int key) //5.1 b) c)
{
	char x;
	for (int i = 0; i < s.length(); i++)
	{
		x = s.at(i);
		if (x != ' ')
			s.at(i) = encryptChar(s[i], key);
	}
	/*
	cout << encryptString("The quick brown fox JUMPS over the lazy dog", -10) << endl;
	cout << encryptString("The quick brown fox JUMPS over the lazy dog", +10) << endl;
	*/
	return s;
}


void encryptString(int n, char s[], int key) //5.1 d)
{
	char x;
	for (int i = 0; i < n - 1; i++)
	{
		x = s[i];
		if (x != ' ')
			s[i] = encryptChar(x, key);
	}
	for (int i = 0; i < n; i++)
		cout << s[i];
	/*
	char s[44] = "The quick brown fox JUMPS over the lazy dog";
	encryptString(44, s, -10);
	*/
}


void bubbleSort(vector<string>& v, char order) //5.2 a)
{
	bool x;
	string change;
	if (order == 'a')
		x = true;
	else
		x = false;
	for (int k = 0; k < v.size(); k++)
	{
		for (int i = 0; i < (v.size() - 1); i++)
		{
			if (x)
			{
				if (v.at(i) > v.at(i + 1))
				{
					change = v.at(i);
					v.at(i) = v.at(i + 1);
					v.at(i + 1) = change;
				}
			}
			else
			{
				if (v.at(i) < v.at(i + 1))
				{
					change = v.at(i);
					v.at(i) = v.at(i + 1);
					v.at(i + 1) = change;
				}
			}
		}
	}
	/*
	vector<string> v = {"ananas","zebra", "amaralelo", "tiago", "jose", "urso", "alexandre" };
	bubbleSort(v, 'a');
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	*/
}


void BubbleSort(vector<string>& v, char c) //5.2 b)
{
	string x;
	bool k = true, ValidInput = true;
	while (k)
	{

		cout << "Please, give a name. ";
		do
		{
			ValidInput = false;
			getline(cin, x, '\n');
			v.push_back(x);
			if (cin.fail())
			{
				cin.clear();
				ValidInput = true;
				cout << "Invalid Input. ";
			}
		} while (ValidInput);
		cout << "Another one? [Y/N] " << endl;
		do
		{
			ValidInput = false;
			getline(cin, x, '\n');
			if (cin.fail())
			{
				cin.clear();
				ValidInput = true;
			}
			else if (x == "Y")
				k = true;
			else if (x == "N")
				k = false;
			else
				cout << "Invalid Input. ";
		} while (ValidInput);
	}
	if (v.size() != 0)
		bubbleSort(v, c);
	/*
	vector<string> v;
	BubbleSort(v, 'd');
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	system("pause");
	*/
}


int compare(void const* a, void const* b) //5.3
{
	return strcmp(*(const char**)a, *(const char**)b);
}


bool sequenceSearch(const string& s, int nc, char c) //5.4 a)
{
	int ii;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == c)
		{
			for (ii = i + 1; (ii - i) < nc; ii++)
			{
				if (s[ii] != c)
					break;
			}
			if ((ii - i) == nc)
				return true;
		}
	}
	return false;
	/*
	string x = "abcddeedddf";
	cout << sequenceSearch(x, 3, 'd') << endl;
	*/
}


bool SequenceSearch(const string& s, int nc, char c) //5.4 b)
{
	string x = string(nc, c);
	size_t t = s.find(x);
	cout << x << ", " << t << endl;
	if (0 <= t && t < s.length())
	{
		return true;
	}
	return false;
	/*
	string x = "abcddeeddddf";
	cout << SequenceSearch(x, 4, 'd') << endl;
	*/
}


string ToUpper(string x) //5.5
{
	for (int i = 0; i < x.length(); i++)
	{
		x[i] = toupper(x[i]);
	}
	return x;
}


string normalizeName(const string& name) //5.5
{
	int ind;
	bool done;
	string result;
	vector<string> remove = { " DE ", " DO ", " DA ", " DOS ", " DAS ", " E " };
	result = ToUpper(name);
	do
	{
		done = true;
		for (int i = 0; i < remove.size(); i++) //remover pronomes
		{
			ind = result.find(remove[i]);
			if ((ind > 0) && (ind < result.length()))
			{
				result.erase(ind + 1, remove[i].length() - 1);
				done = false;
			}
			else if (ind == 0 && result[ind + remove[i].length()] == ' ')
			{
				result.erase(ind + 1, remove[i].length() - 1);
				done = false;
			}
			else if ((ind + remove[i].length()) == (result.length()) && result[ind - 1] == ' ')
			{
				result.erase(ind + 1, remove[i].length() - 1);
				done = false;
			}
		}
	} while (!done);
	ind = result.find(' ');
	while ((ind >= 0) && (ind < result.length()))
	{
		if (ind != (result.length() - 1) && ind != 0)
		{
			if (result[ind + 1] == ' ')
				result.erase(ind, 1);
			else
				ind++;
		}
		else if (ind == 0)
		{
			result.erase(0, 1);
		}
		else
		{
			if (result[ind] == ' ')
			{
				result.erase(ind, 1);
			}
		}
		ind = result.find(' ', ind);
	}
	return result;
	/*
	string name = "    Maria da Felicidade     dos Reis    e  Passos Dias de de Aguiar     ";
	name = normalizeName(name);
	cout << name << endl;
	*/
}


struct Fraction //5.6
{
	int numerator;
	int denominator;
};
bool readFraction(Fraction& fraction) //5.6
{
	char x;
	bool ValidInput = true;
	cout << "Please give a fraction. ";
	cin >> fraction.numerator;
	if (cin.fail())
	{
		ValidInput = false;
		cin.clear();
	}
	x = cin.get();
	if (x != '/')
	{
		ValidInput = false;
	}
	cin >> fraction.denominator;
	if (cin.fail())
	{
		cin.clear();
		ValidInput = false;
	}
	else if (cin.peek() != '\n')
	{
		ValidInput = false;
	}
	else if (fraction.denominator == 0)
	{
		ValidInput = false;
	}
	if (!ValidInput)
	{
		fraction.numerator = 0;
		fraction.denominator = 0;
	}
	return ValidInput;
}


int GDC_R(int x, int y) //3.5
{
	unsigned int min, max, a;
	if (x == y)
		return x;
	else if (x == 0)
		return y;
	else if (y == 0)
		return x;
	if (x < y)
	{
		min = x;
		max = y;
	}
	else
	{
		min = y;
		max = x;
	}
	while (max != min)
	{
		max -= min;
		if (max < min)
		{
			a = max;
			max = min;
			min = a;
		}
	}
	return max;
}
void reduceFraction(Fraction& fraction)
{
	int x = GDC_R(fraction.numerator, fraction.denominator);
	fraction.numerator /= x;
	fraction.denominator /= x;
	cout << fraction.numerator << '/' << fraction.denominator << endl;
}


void FractionsOPertions(Fraction fraction1, Fraction fraction2) //5.6
{
	Fraction result;
	bool x1, x2, InvalidInput;
	char x;
	string s = "+-/*";
	do
	{
		x1 = readFraction(fraction1);
		if (!x1)
			cout << "Invalid input. " << endl;
	} while (!x1);
	cout << "Now, the fraction number 2. " << endl;
	do
	{
		x2 = readFraction(fraction2);
		if (!x2)
			cout << "Invalid input. " << endl;
	} while (!x2);
	cout << "And what is the opration that you want to do? ";
	do
	{
		InvalidInput = false;
		cin >> x;
		if (cin.fail())
		{
			cin.clear();
			InvalidInput = true;
		}
		else
		{
			if (s.find(x) < s.length() || s.find(x) >= 0)
			{
				switch (int(x))
				{
				case(int('+')):
					fraction1.numerator *= fraction2.denominator;
					fraction2.numerator *= fraction1.denominator;
					result.numerator = fraction1.numerator + fraction2.numerator;
					result.denominator = fraction1.denominator * fraction2.denominator;
					break;
				case(int('-')):
					fraction1.numerator *= fraction2.denominator;
					fraction2.numerator *= fraction1.denominator;
					result.numerator = fraction1.numerator - fraction2.numerator;
					result.denominator = fraction1.denominator * fraction2.denominator;
					break;
				case(int('*')):
					result.numerator = fraction1.numerator * fraction2.numerator;
					result.denominator = fraction1.denominator * fraction2.denominator;
					break;
				case(int('/')):
					result.numerator = fraction1.numerator * fraction2.denominator;
					result.denominator = fraction1.denominator * fraction2.numerator;
					break;
				}
			}
			else
			{
				cout << "Invalid input. ";
				InvalidInput = true;
			}
		}
	} while (InvalidInput);
	reduceFraction(result);
	/*
	Fraction fraction1, fraction2;
	fraction1.numerator = 1;
	fraction1.denominator = 1;
	fraction2.numerator = 1;
	fraction2.denominator = 1;
	while (true)
	{
		FractionsOPertions(fraction1, fraction2);
	}
	*/
}


struct Date {
	unsigned int year, month, day;
};
void readDate(Date* d) //5.7 a)
{
	string y, m, day;
	cout << "Please give a date. [y/m/d] " << endl;
	getline(cin, y, '/');
	getline(cin, m, '/');
	getline(cin, day, '\n');
	(*d).year = atoi(y.c_str());
	(*d).month = atoi(m.c_str());
	(*d).day = atoi(day.c_str());
}


void writeDate(const Date* d) //5.7 b)
{
	cout << setfill('0');
	cout << setw(4) << (*d).year << '/' << setw(2) << (*d).month << '/' << setw(2) << (*d).day;
	/*
	Date d;
	d.year = 2001;
	d.month = 2;
	d.day = 7;
	writeDate(&d);
	*/
}


int compareDates(const Date* d1, const Date* d2)//5.7 c)
{
	if ((*d1).year > (*d2).year)
		return 1;
	else if ((*d1).year < (*d2).year)
		return -1;
	else
	{
		if ((*d1).month > (*d2).month)
			return 1;
		else if ((*d1).month < (*d2).month)
			return -1;
		else
		{
			if ((*d1).day > (*d2).day)
				return 1;
			else if ((*d1).day < (*d2).day)
				return -1;
			else
				return 0;
		}
	}
	/*
	Date d1, d2;
	d1.year = 2000;
	d1.month = 2;
	d1.day = 7;
	d2.year = 2001;
	d2.month = 2;
	d2.day = 7;
	cout << compareDates(&d1, &d2);
	*/
}


void sortDates(Date* d1, Date* d2) //5.7 d)
{
	int x = compareDates(d1, d2);
	if (x == 1)
	{
		Date x;
		x = (*d1);
		(*d1) = (*d2);
		(*d2) = x;
	}
	/*
	Date d1, d2, *d3, *d4;
	d1.year = 1999;
	d1.month = 2;
	d1.day = 7;
	d2.year = 1998;
	d2.month = 2;
	d2.day = 7;
	d3 = &d1;
	d4 = &d2;
	sortDates(d3, d4);
	*/
}


void sortedDates(Date* d1, Date* d2) //5.7 e)
{
	readDate(d1);
	readDate(d2);
	sortDates(d1, d2);
	writeDate(d1);
	cout << "-";
	writeDate(d2);
	/*
	Date Date1, Date2;
	sortedDates(&Date1, &Date2);
	*/
}


struct EuroMillionsBet {
	vector<unsigned> mainNumbers;
	vector<unsigned> luckyStars;
};
void euromillion() //5.8
{
	EuroMillionsBet key, x;
	int nn, y, ns, r, ncounter = 0, scounter = 0;
	bool invalidinput;
	srand(time(NULL));
	cout << "How many numbers do you want to choose? ";
	do
	{
		invalidinput = false;
		cin >> nn;
		if (cin.fail())
		{
			cin.clear();
			invalidinput = true;
		}
		else if (nn <= 0)
			invalidinput = true;
		else if (cin.peek() != '\n')
			invalidinput = true;
		if (invalidinput)
			cout << "Invalid input. " << endl;
	} while (invalidinput);
	for (int i = 0; i < nn; i++)
	{
		cout << "Please give your " << i + 1 << " number ";
		do
		{
			invalidinput = false;
			cin >> y;
			if (cin.fail())
			{
				cin.clear();
				invalidinput = true;
			}
			else if (y <= 0 || y > 50)
				invalidinput = true;
			else if (cin.peek() != '\n')
				invalidinput = true;
			else if (count(x.mainNumbers.begin(), x.mainNumbers.end(), y) != 0)
				invalidinput = true;
			if (invalidinput)
				cout << "Invalid input. " << endl;
		} while (invalidinput);
		x.mainNumbers.push_back(y);
	}
	cout << "How many lucky stars do you want to choose? ";
	do
	{
		invalidinput = false;
		cin >> ns;
		if (cin.fail())
		{
			cin.clear();
			invalidinput = true;
		}
		else if (ns <= 1)
			invalidinput = true;
		else if (cin.peek() != '\n')
			invalidinput = true;
		if (invalidinput)
			cout << "Invalid input. " << endl;
	} while (invalidinput);
	for (int i = 0; i < ns; i++)
	{
		cout << "Please give your " << i + 1 << " number ";
		do
		{
			invalidinput = false;
			cin >> y;
			if (cin.fail())
			{
				cin.clear();
				invalidinput = true;
			}
			else if (y <= 0 || y > 12)
				invalidinput = true;
			else if (cin.peek() != '\n')
				invalidinput = true;
			else if (count(x.luckyStars.begin(), x.luckyStars.end(), y))
				invalidinput = true;
			if (invalidinput)
				cout << "Invalid input. " << endl;
		} while (invalidinput);
		x.luckyStars.push_back(y);
	}
	//generate random key
	for (int i = 0; i < nn; i++)
	{
		do
		{
			r = 1 + rand() % 50;
		} while (count(key.mainNumbers.begin(), key.mainNumbers.end(), r) != 0);
		cout << r << "-";
		key.mainNumbers.push_back(r);
	}
	cout << '\n';
	for (int i = 0; i < ns; i++)
	{
		do
		{
			r = 1 + rand() % 12;
		} while (count(key.luckyStars.begin(), key.luckyStars.end(), r) != 0);
		cout << r << " - ";
		key.luckyStars.push_back(r);
	}
	cout << '\n';
	//counter
	for (int i = 0; i < nn; i++)
	{
		ncounter += count(x.mainNumbers.begin(), x.mainNumbers.end(), key.mainNumbers[i]);
	}
	for (int i = 0; i < ns; i++)
	{
		scounter += count(x.luckyStars.begin(), x.luckyStars.end(), key.luckyStars[i]);
	}
	////sort vectors
	//for (int i = 0; i < nn; i++)
	//{
	//	for (int k = 0; k < nn; k++)
	//	{
	//		if (k != (nn - 1))
	//		{
	//			if (x.mainNumbers[k] > x.mainNumbers[k + 1])
	//			{
	//				r = x.mainNumbers[k];
	//				x.mainNumbers[k] = x.mainNumbers[k + 1];
	//				x.mainNumbers[k + 1] = r;
	//			}
	//			if (key.mainNumbers[k] > key.mainNumbers[k + 1])
	//			{
	//				r = key.mainNumbers[k];
	//				key.mainNumbers[k] = key.mainNumbers[k + 1];
	//				key.mainNumbers[k + 1] = r;
	//			}
	//		}
	//	}
	//}
	//for (int i = 0; i < ns; i++)
	//{
	//	for (int k = 0; k < ns; k++)
	//	{
	//		if (k != (ns - 1))
	//		{
	//			if (x.luckyStars[k] > x.luckyStars[k + 1])
	//			{
	//				r = x.luckyStars[k];
	//				x.luckyStars[k] = x.luckyStars[k + 1];
	//				x.luckyStars[k + 1] = r;
	//			}
	//			if (key.luckyStars[k] > key.luckyStars[k + 1])
	//			{
	//				r = key.luckyStars[k];
	//				key.luckyStars[k] = key.luckyStars[k + 1];
	//				key.luckyStars[k + 1] = r;
	//			}
	//		}
	//	}
	//}
	cout << "Result:" << endl << "\t- " << ncounter << " numbers." << endl << "\t- " << scounter << " lucky stars." << endl;
}


struct Adress //5.9 a)
{
	string street;
	int dnumber;
	string city;
};


struct Id //5.9 b)
{
	string name;
	int age;
	Adress adress;
};


void samestreet() //5.9 c)
{
	bool invalidinput;
	int n;
	string city;
	Id z;
	vector<Id> v;
	vector<int> final;
	cout << "How many persons do you want do identify? ";
	do
	{
		invalidinput = false;
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			invalidinput = true;
		}
		else if (n < 0)
			invalidinput = true;
		else if (cin.peek() != '\n')
		{
			invalidinput = true;
			cin.ignore(100000, '\n');
		}
		if (invalidinput)
			cout << "Invallid input. ";
	} while (invalidinput);
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "Person " << i + 1 << ":" << endl;
		cout << "-Please give a name. ";
		do
		{
			invalidinput = false;
			getline(cin, z.name, '\n');
			z.name = normalizeName(z.name);
			if (cin.fail())
			{
				cin.clear();
				invalidinput = true;
			}
			if (invalidinput)
				cout << "Invalid input. ";
		} while (invalidinput); //name
		cout << "And what is the age? ";
		do
		{
			invalidinput = false;
			cin >> z.age;
			if (cin.fail())
			{
				cin.clear();
				invalidinput = true;
			}
			else if (z.age < 0)
				invalidinput = true;
			else if (cin.peek() != '\n')
			{
				invalidinput = true;
				cin.ignore(100000, '\n');
			}
			if (invalidinput)
				cout << "Invallid input. ";
		} while (invalidinput); //age
		cin.ignore();
		cout << "About the adress..." << endl;
		cout << "What is the street? ";
		do
		{
			invalidinput = false;
			getline(cin, z.adress.street, '\n');
			z.adress.street = normalizeName(z.adress.street);
			if (cin.fail())
			{
				cin.clear();
				invalidinput = true;
			}
			if (invalidinput)
				cout << "Invalid input. ";
		} while (invalidinput); //street
		cout << "And the door number? ";
		do
		{
			invalidinput = false;
			cin >> z.adress.dnumber;
			if (cin.fail())
			{
				cin.clear();
				invalidinput = true;
			}
			else if (z.adress.dnumber < 0)
				invalidinput = true;
			else if (cin.peek() != '\n')
			{
				invalidinput = true;
				cin.ignore(100000, '\n');
			}
			if (invalidinput)
				cout << "Invallid input. ";
		} while (invalidinput); //door number
		cin.ignore();
		cout << "And the city? ";
		do
		{
			invalidinput = false;
			getline(cin, z.adress.city, '\n');
			z.adress.city = normalizeName(z.adress.city);
			if (cin.fail())
			{
				cin.clear();
				invalidinput = true;
			}
			if (invalidinput)
				cout << "Invalid input. ";
		} while (invalidinput); //city
		v.push_back(z);
	}
	system("cls");
	cout << "What is the city that you want to look? ";
	getline(cin, city, '\n');
	city = normalizeName(city);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].adress.city == city)
			final.push_back(i);
	}
	while (final.size() != 0)
	{
		cout << v[final[0]].adress.street << ": " << endl;
		cout << '-' << v[final[0]].name << endl;
		for (int i = 1; i < final.size(); i++)
		{
			if (v[final[i]].adress.street == v[final[0]].adress.street)
			{
				cout << '-' << v[final[i]].name << endl;
				n = final[final.size() - 1];
				final[final.size() - 1] = final[i];
				final[i] = n;
				i--;
				final.resize(final.size() - 1);
			}
		}
		if (final.size() != 1)
		{
			n = final[final.size() - 1];
			final[final.size() - 1] = final[0];
			final[0] = n;
			final.resize(final.size() - 1);
		}
		else
			final.resize(final.size() - 1);
	}
}


struct Point
{
	double x;
	double y;
};
struct Polygon
{
	vector<Point> v;
};
double Area(Polygon v) //5.10 a)
{
	double count = 0;
	for (int i = 0; i < v.v.size(); i++)
	{
		cout << "x = " << v.v[i].x << ", y = " << v.v[i].y << endl;
		if (i == v.v.size() - 1)
		{
			count += (v.v[i].x * v.v[0].y - v.v[i].y * v.v[0].x);
		}
		else
			count += (v.v[i].x * v.v[i + 1].y - v.v[i].y * v.v[i + 1].x);
	}
	if (count < 0)
		count *= (-1);
	return (count / 2);
	/*
	Polygon P;
	Point c;
	c.x = 1;
	c.y = 1;
	P.v.push_back(c);
	c.x = 1;
	c.y = 3;
	P.v.push_back(c);
	c.x = 3;
	c.y = 1;
	P.v.push_back(c);
	c.x = 3;
	c.y = 3;
	P.v.push_back(c);
	cout << Area(P) << endl;
	*/
}


typedef struct
{
	double x;
	double y;
}Pointt;
typedef struct
{
	vector<Pointt> v;
}Polygonn;
double Area(Polygonn v) //5.10 b)
{
	double count = 0;
	for (int i = 0; i < v.v.size(); i++)
	{
		cout << "x = " << v.v[i].x << ", y = " << v.v[i].y << endl;
		if (i == v.v.size() - 1)
		{
			count += (v.v[i].x * v.v[0].y - v.v[i].y * v.v[0].x);
		}
		else
			count += (v.v[i].x * v.v[i + 1].y - v.v[i].y * v.v[i + 1].x);
	}
	if (count < 0)
		count *= (-1);
	return (count / 2);
	/*
	Polygon P;
	Point c;
	c.x = 1;
	c.y = 1;
	P.v.push_back(c);
	c.x = 1;
	c.y = 3;
	P.v.push_back(c);
	c.x = 3;
	c.y = 1;
	P.v.push_back(c);
	c.x = 3;
	c.y = 3;
	P.v.push_back(c);
	cout << Area(P) << endl;
	*/
}


void SortFileNames() //5.11 a)
{
	vector<string> v;
	string next;
	ifstream str_in;
	str_in.open("names.txt");
	if (!str_in.is_open())
	{
		cerr << "Input file opening failed" << endl;
		exit(1);
	}
	while (getline(str_in, next, '\n'))
	{
		v.push_back(next);
	}
	str_in.close();
	for (int i = 0; i < v.size(); i++)
	{
		for (int k = 0; k < v.size() - 1; k++)
		{
			if (v[k] > v[k + 1])
			{
				next = v[k];
				v[k] = v[k + 1];
				v[k + 1] = next;
			}
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}


void SortFilesNames() //5.11 b)
{
	ifstream str_in;
	ofstream str_out;
	string next;
	vector<string> v;
	str_in.open("names.txt");
	if (!str_in.is_open())
	{
		cerr << "Invalid file opening input" << endl;
		exit(1);
	}
	while (getline(str_in, next, '\n'))
	{
		v.push_back(next);
	}
	str_in.close();
	for (int i = 0; i < v.size(); i++)
	{
		for (int k = 0; k < v.size() - 1; k++)
		{
			if (v[k] > v[k + 1])
			{
				next = v[k];
				v[k] = v[k + 1];
				v[k + 1] = next;
			}
		}
	}
	str_out.open("names_sorted.txt");
	for (int i = 0; i < v.size(); i++)
	{
		str_out << v[i] << endl;
	}
	str_out.close();
}


void compress(string file1, string file2)
{
	ifstream str_in;
	ofstream str_out;
	int counter;
	string text;
	str_in.open(file1);
	str_out.open(file2);
	if (!str_in.is_open())
	{
		cerr << "Invalid file opening input. " << endl;
		exit(1);
	}
	getline(str_in, text, '\n');
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] != 'b' && text[i] != 'w')
			str_out << text[i];
		else if (text[i] == 'b')
		{
			if (text[i - 1] == 'b')
				counter++;
			else if (text[i - 1] == 'w')
			{
				str_out << counter << 'w';
				counter = 1;
			}
			else
			{
				counter = 1;
			}
		}
		else if (text[i] == 'w')
		{
			if (text[i - 1] == 'w')
				counter++;
			else if (text[i - 1] == 'b')
			{
				str_out << counter << 'b';
				counter = 1;
			}
			else
			{
				counter = 1;
			}
		}
		if (i == (text.length() - 1))
		{
			str_out << counter << text[i];
		}
	}
	str_in.close();
	str_out.close();
}


void uncompress(string file1, string file2)
{
	ifstream str_in;
	ofstream str_out;
	string text, n;
	int ind, k = 0;
	str_in.open(file1);
	str_out.open(file2);
	if (!str_in.is_open())
	{
		cerr << "Inavlid file opening input. ";
		exit(1);
	}
	getline(str_in, text, '\n');
	if (text.find('b') < text.find('w'))
	{
		ind = text.find('b');
	}
	else
	{
		ind = text.find('w');
	}
	while (text[ind - k] != ' ')
	{
		k++;
	}
	str_out << text.substr(0, (ind - k + 1));
	for (int i = (ind - k + 1); i < text.length(); i++)
	{
		if (int(text[i]) >= 48 && int(text[i]) <= 57)
		{
			n += text[i];
		}
		else
		{
			str_out << string(atoi(n.c_str()), text[i]);
			n.erase(0, n.length());
		}
	}
	str_in.close();
	str_out.close();
}


int mainn(int argc, char* arg[]) //5.12 a), 5.12 b)
{
	uncompress(arg[1], arg[2]);
	return 0;
}


void Euro(string file1, string file2) //5.13
{
	string text, number;
	bool invalid, end;
	int n, k, counter;
	vector<vector<int>> key, bet;
	ifstream str_in;
	ofstream str_out;
	str_in.open(file1);
	if (!str_in.is_open())
	{
		cerr << "Invalid file opening input. ";
		exit(1);
	}
	str_out.open(file2);
	str_out << "KEY = ";
	for (int i = 0; i < 2; i++)
	{
		key.push_back({});
		end = false;
		k = 1;
		do
		{
			if (i == 1)
			{
				cout << "Please give the " << k << " lucky star. ";
			}
			else
			{
				cout << "Please give the " << k << " main number. ";
			}
			do
			{
				invalid = false;
				cin >> n;
				if (cin.fail())
				{
					cin.clear();
					end = true;
				}
				else if (i == 0 && (n > 50 || n <= 0))
					invalid = true;
				else if (i == 1 && (n <= 0 || n > 12))
					invalid = true;
				else if (key[i].size() != 0)
				{
					if (1 == count(key[i].begin(), key[i].end(), n))
						invalid = true;
				}
				//if (cin.peek() != '\n' && !end)
				//{
				//	cin.ignore(1000000, '\n');
				//	invalid = true;
				//}
				if (invalid)
					cout << "Invalid input. Please try again. ";
			} while (invalid);
			if (i == 1 && k == 1)
				str_out << " -  " << n;
			else
				str_out << " " << n;
			if (!end)
				key[i].push_back(n);
			k++;
		} while (!end);
	}
	str_out << '\n';
	while (getline(str_in, text, '\n'))
	{
		k = 0;
		bet.push_back({});
		bet.push_back({});
		if (int(text[0]) >= 48 && int(text[0]) <= 57 || text[0] == ' ') //linha da aposta
		{
			for (int i = 0; i < text.length(); i++)
			{
				if (text[i] == ' ')
				{
					if (number.length() != 0)
					{
						str_out << number << ' ';
						bet[k].push_back(atoi(number.c_str()));
						number.erase(0, number.length());
					}
				}
				else if (text[i] == '-')
				{
					str_out << '-';
					k = 1;
				}
				else
				{
					number += text[i];
				}
			}
			if (number.length() != 0)
			{
				str_out << number;
				bet[k].push_back(atoi(number.c_str()));
				number.erase(0, number.length());
			}
			str_out << " =>  " << bet[0].size() << "- " << bet[1].size() << " |  ";
			for (int k = 0; k != 2; k++)
			{
				counter = 0;
				for (int i = 0; i < bet[k].size(); i++)
				{
					counter += count(key[k].begin(), key[k].end(), bet[k][i]);
				}
				if (k == 0)
					str_out << counter << "- ";
				else
					str_out << counter << endl;;
			}
		}
		else //linha do nome
		{
			str_out << text << endl;
		}
		bet.resize(0);
	}
	str_in.close();
	str_out.close();
}

void ToUper(string& text) //5.14
{
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = toupper(text[i]);
	}
}
struct ID
{
	string name;
	int n;
};
int number_of_digits(int n)
{
	int counter = 1;
	while (n > 10)
	{
		n /= 10;
		counter++;
	}
	return counter;
}
bool Again()
{
	bool invalid;
	string name;
	do
	{
		invalid = false;
		getline(cin, name, '\n');
		ToUper(name);
		if (name == "Y")
		{
			return true;
		}
		else if (name == "N")
		{
			return false;
		}
		else if (cin.fail())
		{
			cin.clear();
			invalid = true;
		}
		else
			invalid = true;
		if (invalid)
			cout << "Invalid input. Please try again. ";
	} while (invalid);
}
void phone(string file1)//5.15
{
	int k = 0, n, line;
	ID id;
	string text, name, number, copy, copy2;
	bool valid, end, find, invalid, nop, again, names;
	vector<ID> contacts; //nomes da forma name - num
	ifstream str_in;
	ofstream str_out;
	str_in.open(file1);
	if (!str_in.is_open())
	{
		cerr << "Invalid file opening input";
		exit(1);
	}
	while (getline(str_in, text, '\n'))
	{
		k = 0;
		name.resize(0);
		number.resize(0);
		contacts.push_back(id);
		if (text.length() != 0)
		{
			while (text[k] != '-')
			{
				name += text[k];
				k++;
			}
			k += 2; //ignorar o - e o espaço
			contacts[contacts.size() - 1].name = name;
			for (int i = k; i < text.size(); i++)
			{
				number += text[i];
			}
			contacts[contacts.size() - 1].n = atoi(number.c_str());
		}
		else
		{
			contacts[contacts.size() - 1].name = "\n";
		}
	}
	str_in.close();
	do
	{
		end = false;
		cout << "\t\tMenu" << endl;
		cout << "\tAdd a number" << endl;
		cout << "\tRemove a number" << endl;
		cout << "\tSearch for a number" << endl;
		cout << "\n\nWhat do you want to do? [Add, Remove, Search, CTRL-Z (to end)] ";
		do
		{
			valid = true;
			getline(cin, text, '\n');
			ToUper(text);
			if (cin.fail())
			{
				cin.clear();
				end = true;
			}
			else if (text == "ADD")
			{
				system("cls");
				do
				{
					again = true;
					for (int i = 0; i < contacts.size(); i++)
					{
						if (contacts[i].name == "\n")
						{
							line = i;
							break;
						}
					}
					cout << "Please give a name.";
					do
					{
						invalid = true;
						getline(cin, name, '\n');
						if (cin.fail())
						{
							cin.clear();
							cout << "Invalid input. Please try again. ";
						}
						else
						{
							name = name + " ";
							if (line == contacts.size())
							{
								contacts.push_back(id);
								line++;
							}
							contacts[line].name = name;
							invalid = false;
						}
					} while (invalid);
					cout << "And now give the number. ";
					do
					{
						invalid = true;
						cin >> n;
						if (number_of_digits(n) != 9)
						{
							invalid = false;
						}
						else if (cin.fail())
						{
							cin.clear();
							invalid = false;
						}
						else
						{
							contacts[line].n = n;
						}
						if (!invalid)
							cout << "Invalid input. ";
					} while (!invalid);
					cout << "Do you want to add another number? [Y/N] ";
					cin.ignore();
					again = !Again();
				} while (!again);
				system("cls");
			}
			else if (text == "REMOVE")
			{
				system("cls");
				do
				{
					names = false;
					for (int i = 0; i < contacts.size(); i++)
					{
						if (contacts[i].name != "\n")
							names = true;
					}
					if (!names)
					{
						cout << "You don't have names to remove. Press any key to back to main menu... ";
						_getch();
					}
					else
					{
						cout << "Please give a name. ";
						do
						{
							invalid = false;
							getline(cin, text, '\n');
							if (cin.fail())
							{
								cin.clear();
								invalid = true;
							}
							else
							{
								valid = false;
								for (int i = 0; i < contacts.size(); i++)
								{
									copy = text + " ";
									ToUper(copy);
									copy2 = contacts[i].name;
									ToUper(copy2);
									if (copy == copy2)
									{
										cout << contacts[i].name << "- " << contacts[i].n << endl;
										cout << "Is this the contact that you want to remove? [Y/N] ";
										valid = Again();
										if (valid)
										{
											contacts[i].name = "\n";
											break;
										}
									}
								}
								if (valid)
									cout << "Contact removed. " << endl;
								else
									cout << "Ups. Contact not found. " << endl;
							}
						} while (invalid);
						cout << "Do you want to remove another contact? [Y/N] ";
						end = Again();
					}
				} while (end);
				system("cls");
			}
			else if (text == "SEARCH")
			{
				system("cls");
				do
				{
					cout << "Please give a name. ";
					getline(cin, text, '\n');
					find = false;
					text = text + " ";
					copy2 = text;
					ToUper(copy2);
					for (int i = 0; i < contacts.size(); i++)
					{
						copy = contacts[i].name;
						ToUper(copy);
						if (copy == copy2)
						{
							cout << contacts[i].name << "- " << contacts[i].n;
							cout << "\nIs this the contact that you are searching? [Y/N] ";
							find = Again();
							if (find)
								break;
						}
					}
					if (!find)
						cout << "UPS. Contact not found. ";
					cout << "Do you want to search again? [Y/N] ";
					nop = Again();
				} while (nop);
				system("cls");
			}
			else
			{
				cout << "Invalid input. Please try again. ";
				valid = false;
			}
		} while (!valid);
	} while (!end);
	str_out.open(file1);
	for (int i = 0; i < (contacts.size() - 1); i++)
	{
		if (contacts[i].name != "\n")
			str_out << contacts[i].name << "- " << contacts[i].n << "\n";
		else
			str_out << contacts[i].name;
	}
	str_out << contacts[contacts.size() - 1].name << contacts[contacts.size() - 1].n;
	str_out.close();
}

int main()
{
	/*int n;
	string text;
	cout << "Please give a number of name that you want to give. "; cin >> n; cin.ignore();
	char **name;
	name = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		cout << "Please give the " << i + 1 << " name. ";
		getline(cin, text, '\n');
		name[i] = (char*)malloc(100);
		name[i] = (char*)text.c_str();
	}
	cout << name[0] << ", " << name[1] << ", " << name[2] << endl;

	qsort(name, n, sizeof(char*), *compare);



	char** names;
	int n_names = 1;
	string text;
	names = new char* [n_names];
	text = "tiago";
	for (int i = 0; i < n_names; i++)
	{
		names[i] = new char[100];
		names[i] = (char*)text.c_str();
	}
	cout << names[0] << endl;*/
	return 0;
}

