#include "Inventory.h"
#include "ProductEX6.h"
#include <iostream>
#include <list>

using namespace std;

Inventory::Inventory()
{
	lista.resize(0);
	total.resize(0);
}

Inventory::Inventory(list<ProductEX6> lista, list<ProductEX6> total)
{
	this->lista = lista;
	this->total = total;
}

void Inventory::processOrder(ProductEX6 p)
{
	bool find = false;
	list<ProductEX6> x;
	p.setQuantity(1);
	list<ProductEX6>::iterator it = total.begin();
	for (it; it != total.end(); ++it)
	{
		if ((*it).getID() == p.getID())
		{
			find = true;
			if ((*it).getQuantity() != 0)
				(*it).setQuantity((*it).getQuantity() - 1);
			else
				lista.push_back(p);
		}
	}
	if (!find)
		lista.push_front(p);
}

void Inventory::productShipment(ProductEX6 p) 
{
	bool find = false, nomore = false;
	list<ProductEX6> x;
	list<ProductEX6>::reverse_iterator lst1 = lista.rbegin();
	for (lst1; lst1 != lista.rend(); ++lst1)
	{
		if ((*lst1).getID() == p.getID())
		{
			find = true;
			for (list<ProductEX6>::iterator it = total.begin(); it != total.end(); ++it)
			{
				if ((*it).getID() == p.getID() && !nomore)
					(*it).setQuantity((*it).getQuantity() - 1);
				if ((*it).getQuantity() == 0 && !nomore)
				{
					(*lst1).setQuantity(0);
					nomore = true;
					break;
				}
			}
		}
	}
	if (find)
		for (auto elem : lista)
			cout << elem.getID() << "->" << elem.getQuantity();
	refreshOrder();
}

void Inventory::AddTotal(ProductEX6 p)
{
	bool find = false;
	int index = 0;
	for (auto elem: total) {
		if (elem.getID() == p.getID())
		{
			find = true;
			elem.AddProduct(p.getQuantity());
			break;
		}
		index++;
	}
	if(!find)
	{
		total.push_back(p);
	}
	productShipment(p);
}

void Inventory::refreshOrder()
{
	list<ProductEX6> new_list;
	for (auto elem : lista)
	{
		if (elem.getQuantity() != 0)
			new_list.push_back(elem);
	}
	new_list.reverse();
	lista = new_list;
}

void Inventory::Showlist() const
{
	list<ProductEX6> x = lista;
	x.reverse();
	for (auto elem : x)
	{
		cout << elem.getID() << "-> " << elem.getQuantity() << endl;
	}
}

void Inventory::ShowTotal() const
{
	for (auto elem : total)
	{
		cout << elem.getID() << "--> " << elem.getQuantity() << endl;
	}
}