#pragma once
#include "MonsterBase.h"
class MonsterTroll : public MonsterBase
{
private:
	char* _name; //�̸�
public:
	char *getName() { return _name; }
	MonsterTroll();
	~MonsterTroll();
};

