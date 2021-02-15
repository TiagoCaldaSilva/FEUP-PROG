#pragma once
#include "Product.h"
#include <string>

using namespace std;

class Item
{
public:
	Item();
	Item(Product product, int quantity);
	string getName();
	double getPrice();
	int getQuantity();
	double getTotalPrice();
	void AddProduct(int q);
private:
	Product product;
	int quantity;
	double totalprice;
};

