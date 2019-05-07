#pragma once
#include "mapBase.h"


class mapElectronic : public mapBase
{
private:
	vector <pokemonBase*> electMonsterVec;
public:
	void showImage();
	mapElectronic();
	~mapElectronic();
};

