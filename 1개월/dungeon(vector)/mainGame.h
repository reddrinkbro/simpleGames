#pragma once
#include "mapBase.h"
#include "goblinGround.h"
#include "trollGround.h"
#include "playerBase.h"
#include "monsterBase.h"

class mainGame
{
private:
	mapBase* base;
	goblinGround* mapGoblin;
	trollGround* mapTroll;
	monsterBase* _monster;
	monsterAxeGoblin* axeGoblin;
	montserGoblin* goblin;
	monsterBigTroll* bigTroll;
	monsterTroll* troll;
	playerBase* player;
public:
	vector<mapBase*> map;
	vector<monsterBase*> monsterVector;
	vector<itemBase*> userItem;
	vector<itemBase*>::iterator invetoryIter;
	void selectWindow(); //처음 선택화면
	void selectMap();//사냥터선택
	void monsterFight(int select); //몬스터 사냥
	void showMyInventory();
	mainGame();
	~mainGame();
};

