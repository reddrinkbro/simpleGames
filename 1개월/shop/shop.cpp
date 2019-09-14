#include "shop.h"



shop::shop()
{
}


shop::~shop()
{
}

void shop::showItemPrice()
{
	cout << getName() << " АЁАн : " << getPrice() << "Gold   \t" ;
}
void shop::showItem()
{
	cout << getName() << endl;
}
