#pragma once
#include "MonsterBase.h"
class MonsterDragon : public MonsterBase
{
private:
	char* _name; //�̸�
public:
	char *getName() { return _name; }
	MonsterDragon();
	~MonsterDragon();
};

