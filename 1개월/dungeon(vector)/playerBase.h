#pragma once
#include "skillBase.h"
#include "Fireball.h"
#include "iceAge.h"
#include "magicBolt.h"

#include <iostream>
#include <map>

using namespace std;
class playerBase
{
private:
	char* _name;
	int _curHp;
	int _maxHp;
	int _atk;
	int _def;
public:
	skillBase* skill;
	Fireball* fire;
	iceAge* ice;
	magicBolt* bolt;
	
	char* getName() { return _name; }
	int getCurHp() { return _curHp; }
	int getMaxHp() { return _maxHp; }
	int getAtk() { return _atk; }
	int getDef() { return _def; }

	void setName(char* name) { _name = name; }
	void setCurHp(int curHp) { _curHp = curHp; }
	void setMaxHp(int maxHp) { _maxHp = maxHp; }
	void setAtk(int atk) { _atk = atk; }
	void setDef(int def) { _def = def; }

	map<int, skillBase*> skillListMap; //스킬을 구성하고 있는 맵
	playerBase();
	~playerBase();
};

