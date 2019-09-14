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
	void welcome();//ó�� ���� ȭ��
	void showPlayerStat(); //���� ȭ��
	void fight(); // ���� ȭ��
	void userLevelUp(); //������
	void monsterLevelUp(); //���� ������
	mainGame();
	~mainGame();
};

