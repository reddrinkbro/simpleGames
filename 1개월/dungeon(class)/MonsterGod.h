#pragma once
#include "MonsterBase.h"
class MonsterGod : public MonsterBase
{
private:
	char* _name; //¿Ã∏ß
public:
	char *getName() { return _name; }
	MonsterGod();
	~MonsterGod();
};

