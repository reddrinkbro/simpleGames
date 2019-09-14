#pragma once
#include "armor.h"
#include "axe.h"
#include "bluePotion.h"
#include "gloves.h"
#include "helmet.h"
#include "orangePotion.h"
#include "redPotion.h"
#include "sheild.h"
#include "shoes.h"
#include "shop.h"
#include "sword.h"
#include "spear.h"
#include "yellowPotion.h"
#include "belt.h"
#include "staff.h"

#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

class mainShop
{
private:
	armor* _armor; 
	bluePotion* _bluePotion; 
	gloves* _gloves;
	helmet* _helmet;
	orangePotion* _orangePotion;
	redPotion* _redPotion;
	sheild* _sheild;
	shoes* _shoes;
	sword* _sword;
	shop* _shop;
	yellowPotion* _yellowPotion;
	axe* _axe;
	spear* _spear;
	staff* _staff;
	belt* _belt;

	vector<shop*> classShop;
	vector<shop*>::iterator indexIterator;
	vector<shop*> playerInventory;

	
public:
	void selectionWindow();//ó�� ����ȭ��
	void showMyInventory(); //�κ��丮 ����
	void showShop(int money); //��������
	void purchaseItem(int money); //������ ����
	mainShop();
	~mainShop();
};

