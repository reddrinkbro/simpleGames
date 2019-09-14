#include "playerBase.h"



playerBase::playerBase()
{
	setName("�÷��̾�");
	setMaxHp(1000);
	setCurHp(getMaxHp());
	setAtk(100);
	setDef(10);
	fire = new Fireball;
	ice = new iceAge;
	bolt = new magicBolt;
	skillListMap.insert(make_pair(1, fire)); //�ʿ� ���� �ִ´�
	skillListMap.insert(make_pair(2, ice));
	skillListMap.insert(make_pair(3, bolt));
}


playerBase::~playerBase()
{
}
