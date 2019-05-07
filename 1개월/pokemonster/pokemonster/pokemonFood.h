#pragma once
#include "itemBase.h"
class pokemonFood : public itemBase
{
private:
	int _healing; //È¸º¹·®
public:
	int getHealing() { return _healing; }
	pokemonFood();
	~pokemonFood();
};

