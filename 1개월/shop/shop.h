#pragma once
#include <iostream>
using namespace std;

class shop
{
private:
	char* _name;
	int _price;
	
public:
	char* getName() { return _name; }
	int getPrice() { return _price; }

	void setName(char* name) { _name = name; }
	void setPrice(int price) { _price = price; }

	void showItemPrice();//������ ������ �����ش�
	void showItem();
	shop();
	~shop();
};

