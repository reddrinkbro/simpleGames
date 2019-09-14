#include "playerBase.h"



playerBase::playerBase()
{
	setName("플레이어");
	setMaxHp(1000);
	setCurHp(getMaxHp());
	setAtk(100);
	setDef(10);
	fire = new Fireball;
	ice = new iceAge;
	bolt = new magicBolt;
	skillListMap.insert(make_pair(1, fire)); //맵에 집어 넣는다
	skillListMap.insert(make_pair(2, ice));
	skillListMap.insert(make_pair(3, bolt));
}


playerBase::~playerBase()
{
}
