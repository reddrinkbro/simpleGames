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
	cout << itemVector[random]->getName() << "�� �����." << endl;
	return itemVector[random]; //�������� �������� �ϳ��� ���Ͻ�Ų��
}




