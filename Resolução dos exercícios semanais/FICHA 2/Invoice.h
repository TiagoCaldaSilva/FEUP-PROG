#pragma once
#include "Client.h"
#include "Product.h"
#include "Item.h"
#include <vector>

using namespace std;

class Invoice
{
public:
	Invoice();
	Invoice(Client c);
	Invoice(Client c, vector<Item> v);
	void AddProduct(Product p, int q);
	void showInvoice();
	void AddToCart();
private:
	Client c;
	vector<Item> v;
};

