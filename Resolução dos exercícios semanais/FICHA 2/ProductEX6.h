#pragma once

class ProductEX6
{
public:
	ProductEX6();
	ProductEX6(int id, int quantity);
	int getID() const;
	int getQuantity() const;
	void setID(int id);
	void setQuantity(int quantity);
	bool isValid() const;
	void AddProduct(int quantity);
private:
	int id;
	int quantity;
};
