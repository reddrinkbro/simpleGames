#include "pokemonBase.h"



pokemonBase::pokemonBase()
{
	srand(time(NULL));
	setIsFighting(false);
	int randomMoney = rand() % 21 + 40; //���� �������� ����
	setMoney(randomMoney);

}


pokemonBase::~pokemonBase()
{
}
