#include "pokemonBase.h"



pokemonBase::pokemonBase()
{
	srand(time(NULL));
	setIsFighting(false);
	int randomMoney = rand() % 21 + 40; //µ·Àº ·£´ýÀ¸·Î ³ª¿È
	setMoney(randomMoney);

}


pokemonBase::~pokemonBase()
{
}
