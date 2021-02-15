#pragma once
#include <list>
#include <vector>
#include "ProductEX6.h"

using namespace std;

class Inventory
{
	friend class ProductEX6;
public:
	Inventory();
	Inventory(list<ProductEX6> lista, list<ProductEX6> total);
	void AddTotal(ProductEX6 p);
	void processOrder(ProductEX6 p);
	void productShipment(ProductEX6 p);
	void refreshOrder();
	void Showlist() const;
	void ShowTotal() const;
private:
	list<ProductEX6> lista;
	list<ProductEX6> total;
};

