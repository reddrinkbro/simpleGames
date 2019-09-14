#pragma once
#include "itemBase.h"
#include "gloves.h"
#include "helmet.h"
#include "shoes.h"
#include "staff.h"
#include "armor.h"
#include "playerBase.h"

#include <iostream>
#include <vector>
#include <time.h>
#include <Windows.h>
using namespace std;
class monsterBase
{
private:
	char* _name;
	int _curHp;
	int _maxHp;
	int _atk;
	int _def;
	
public:
	itemBase* item;
	playerBase* player;
	gloves* _gloves;
	helmet* _helmet;
	shoes* _shoes;
	staff* _staff;
	armor* _armor;
	vector<itemBase*> itemVector; //아이템을 담을 벡터


	char* getName() { return _name; }
	int getCurHp() { return _curHp; }
	int getMaxHp(){return _maxHp;}
	int getAtk() { return _atk; }
	int getDef() { return _def; }

	void setName(char* name) { _name = name; }
	void setCurHp(int curHp) { _curHp = curHp; }
	void setMaxHp(int maxHp) { _maxHp = maxHp; }
	void setAtk(int atk) { _atk = atk; }
	void setDef(int def) { _def = def; }

	itemBase* monsterInItem(); // 몬스터안에 아이템을 랜덤으로 획득
	
	monsterBase();
	~monsterBase();
};

