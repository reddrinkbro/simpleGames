#pragma once
#include "MonsterBase.h"
class MonsterGoblin : public MonsterBase
{
private:
	char* _name; //¿Ã∏ß
public:
	char *getName() { return _name; }
	MonsterGoblin();
	~MonsterGoblin();
};

