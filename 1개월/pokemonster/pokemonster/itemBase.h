#pragma once
#include <iostream>
using namespace std;

class itemBase
{
private:
	char* _name; //이름
	int _price; // 가격
	int _amount; //갯수
public:
	char* getName() { return _name; }
	int getPrice() { return _price; }
	int getAmount() { return _amount; }

	void setName(char* name) { _name = name; }
	void setPrice(int price) { _price = price; }
	void setAmount(int amount) { _amount = amount; }
	itemBase();
	~itemBase();
};

