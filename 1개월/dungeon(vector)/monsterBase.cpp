#include "monsterBase.h"



monsterBase::monsterBase()
{
	_gloves = new gloves;
	_helmet = new helmet;
	_shoes = new shoes;
	_staff = new staff;
	_armor = new armor;
	itemVector.push_back(_gloves);
	itemVector.push_back(_helmet);
	itemVector.push_back(_shoes);
	itemVector.push_back(_staff);
	itemVector.push_back(_armor);
}


monsterBase::~monsterBase()
{
}

itemBase* monsterBase::monsterInItem()
{
	int random = rand() % 5;
	cout << itemVector[random]->getName() << "을 얻었다." << endl;
	return itemVector[random]; //랜덤으로 아이템중 하나는 리턴시킨다
}




