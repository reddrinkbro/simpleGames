#pragma once
#include "MonsterBase.h"
class MonsterDragon : public MonsterBase
{
private:
	char* _name; //¿Ã∏ß
public:
	char *getName() { return _name; }
	MonsterDragon();
	~MonsterDragon();
};

