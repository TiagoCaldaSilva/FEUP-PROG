#include "ProductEX6.h"
#include <time.h>
#include <iostream>
#include "Inventory.h"

ProductEX6::ProductEX6()
{
	int n;
	id = pow(10, 9);
	srand(time(NULL));
	id += rand() % id;
	quantity = 0;
}

ProductEX6::ProductEX6(int id, int quantity)
{
	this->id = id; this->quantity = quantity;
}

int ProductEX6::getID() const
{
	return id;
}

int ProductEX6::getQuantity() const
{
	return quantity;
}

void ProductEX6::setID(int id)
{
	this->id = id;
}

void ProductEX6::setQuantity(int quantity)
{
	this->quantity = quantity;
}

bool ProductEX6::isValid() const
{
	if ((id / int(pow(10, 8))) == 1)
		return true;
	return false;

}

void ProductEX6::AddProduct(int quantity)
{
	this->quantity += quantity;
}