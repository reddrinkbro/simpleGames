#pragma once

#include "MonsterBase.h"
#include "MonsterDragon.h"
#include "MonsterGoblin.h"
#include "MonsterGod.h"
#include "MonsterOrc.h"
#include "MonsterTroll.h"
#include "player.h"

#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

class mainGame
{
private:
	MonsterDragon* dragon;
	MonsterGoblin* Goblin;
	MonsterGod* God;
	MonsterOrc* Orc;
	MonsterTroll* Troll;
	player* user;
public:	
	void welcome();//처음 시작 화면
	void showPlayerStat(); //스탯 화면
	void fight(); // 전투 화면
	void userLevelUp(); //레벨업
	void monsterLevelUp(); //몬스터 레벨업
	mainGame();
	~mainGame();
};

