#pragma once
#include "MonsterBase.h"
class MonsterOrc : public MonsterBase
{
private:
	char* _name; //¿Ã∏ß
public:
	char *getName() { return _name; }
	MonsterOrc();
	~MonsterOrc();
};

