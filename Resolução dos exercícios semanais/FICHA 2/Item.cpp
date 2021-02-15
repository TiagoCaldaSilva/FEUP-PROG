#include "Item.h"
#include "Product.h"
#include <string>

using namespace std;

Item::Item()
{
	Product product;
	quantity = 0;
	totalprice = 0;
}

Item::Item(Product product, int quantity)
{
	this->product = product;
	this->quantity = quantity;
	this->totalprice = quantity * product.getPrice();
}

string Item::getName()
{
	return product.getname();
}

double Item::getPrice()
{
	return product.getPrice();
}

int Item::getQuantity()
{
	return quantity;
}

double Item::getTotalPrice()
{
	return totalprice;
}

void Item::AddProduct(int q)
{
	quantity += q;
	totalprice += q * product.getPrice();
}