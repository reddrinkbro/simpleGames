#include "shop.h"



shop::shop()
{
}


shop::~shop()
{
}

void shop::showItemPrice()
{
	cout << getName() << " ���� : " << getPrice() << "Gold   \t" ;
}
void shop::showItem()
{
	cout << getName() << endl;
}
