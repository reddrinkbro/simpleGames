#pragma once
#include <iostream>
#include "monsterBase.h"
#include "monsterAxeGoblin.h"
#include "montserGoblin.h"
#include "monsterBigTroll.h"
#include "monsterTroll.h"

using namespace std;
class mapBase
{
private:
	char* _mapName;
public:
	char* getName() { return _mapName; }
	void setName(char* name) { _mapName = name; }

	void getMapName(); //��� �ʿ� �Դ��� Ȯ��
	
	mapBase();
	~mapBase();
};

