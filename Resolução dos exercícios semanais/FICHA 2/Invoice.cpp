#include "Invoice.h"
#include <iostream>
#include "Client.h"
#include "Product.h"
#include "Item.h"
#include <vector>
#include <iomanip>

using namespace std;

Invoice::Invoice()
{
	Client c;
	vector<Item> v;
}

Invoice::Invoice(Client c)
{
	this->c = c;
}

Invoice::Invoice(Client c, vector<Item> v)
{
	this->c = c;
	this->v = v;
}

void Invoice::AddProduct(Product p, int q)
{
	Item x(p, q);
	v.push_back(x);
}

void Invoice::AddToCart()
{
	string text;
	double n;
	int xu;
	bool invalid, again, exist;
	do
	{
		exist = false;
		again = false;
		cout << "Please give a product. ";
		do
		{
			invalid = false;
			getline(cin, text, '\n');
			if (cin.fail())
			{
				cin.clear();
				invalid = true;
			}
			if (invalid)
				cout << "invalid input. Please try again ";
		} while (invalid);
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].getName() == text)
			{
				cout << "How many products do you want to add? ";
				exist = true;
				do
				{
					invalid = false;
					cin >> xu;
					if (cin.fail())
					{
						cin.clear();
						invalid = true;
					}
					else if (xu < 0)
					{
						invalid = true;
					}
					if (cin.peek() != '\n')
					{
						cin.ignore(10000000, '\n');
						invalid = true;
					}
					if (invalid)
						cout << "Invalid input. Please try again. ";
				} while (invalid);
				v[i].AddProduct(xu);
				
				break;
			}
		}
		if (!exist)
		{
			cout << "And what is the price? ";
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
				{
					invalid = true;
				}
				if (cin.peek() != '\n')
				{
					cin.ignore(10000000, '\n');
					invalid = true;
				}
				if (invalid)
					cout << "Invalid input. Please try again. ";
			} while (invalid);
			Product x(text, n);
			cout << "And what is the quantity? ";
			do
			{
				invalid = false;
				cin >> xu;
				if (cin.fail())
				{
					cin.clear();
					invalid = true;
				}
				else if (xu < 0)
				{
					invalid = true;
				}
				if (cin.peek() != '\n')
				{
					cin.ignore(10000000, '\n');
					invalid = true;
				}
				if (invalid)
					cout << "Invalid input. Please try again. ";
			} while (invalid);
			AddProduct(x, xu);
		}
		cout << "Do you want to add another product to your cart? [Y, N] ";
		cin.ignore();
		do
		{
			invalid = false;
			getline(cin, text, '\n');
			if (cin.fail())
			{
				cin.clear();
				invalid = true;
			}
			else if (text == "Y")
				again = true;
			else if (text != "N")
				invalid = true;
			if (invalid)
				cout << "Invalid input. Please try again. ";
		} while (invalid);
	} while (again);
}

void Invoice::showInvoice()
{
	system("cls");
	int n, y;
	double result = 0;
	string name;
	bool invalid;
	cout << c.getName() << endl;
	cout << c.getAdress() << endl;
	cout << c.getZipCode() << ", " << c.getCity() << endl;
	cout << "\nDescription" << string(10, ' ') << "Price" << string(3, ' ') << "Qty   Total" << endl;
	cout << "-------------------- ------ ----- --------" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		result += v[i].getTotalPrice();
		name = v[i].getName();
		n = name.length();
		y = n;
		if (n > 20)
		{
			cout << name.substr(0, 20);
			y = 20;
		}
		else
			cout << name;
		cout << string(21 - y, ' ') << setprecision(2) << fixed << setw(6) << v[i].getPrice();
		cout << " " << setw(5) << v[i].getQuantity() << " " << setw(8) << v[i].getTotalPrice() << endl;
		while (n > 20)
		{
			name.erase(0, 20);
			n -= 20;
			if (n > 20)
				cout << name.substr(0, 20) << endl;
			else
				cout << name.substr(0, name.length()) << endl;
		}
	}
	cout << "\nAmont due: " << result << " euro" << endl;
}