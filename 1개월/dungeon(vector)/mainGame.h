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
	void selectWindow(); //ó�� ����ȭ��
	void selectMap();//����ͼ���
	void monsterFight(int select); //���� ���
	void showMyInventory();
	mainGame();
	~mainGame();
};

