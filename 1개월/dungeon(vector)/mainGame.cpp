#include "mainGame.h"



mainGame::mainGame()
{
	base = new mapBase;
	mapGoblin = new goblinGround;
	mapTroll = new trollGround;
	axeGoblin = new monsterAxeGoblin;
	goblin = new montserGoblin;
	bigTroll = new monsterBigTroll;
	troll = new monsterTroll;
	player = new playerBase;
	_monster = new monsterBase;

	monsterVector.push_back(goblin);
	monsterVector.push_back(axeGoblin);
	monsterVector.push_back(troll);
	monsterVector.push_back(bigTroll);
	selectWindow();
}


mainGame::~mainGame()
{
}
//처음 화면
void mainGame::selectWindow()
{
	system("cls");
	int select;
	cout << "여기부터는 던전으로 가는길이다." << endl;
	cout << "1)소지품 확인 2)던전으로 가기" << endl;
	cin >> select;
	if (select == 1)
	{
		showMyInventory(); //인벤토리 보기
	}
	else if (select == 2)
	{
		selectMap(); //던전선택하러 가기
	}
}
//던전 선택
void mainGame::selectMap()
{
	int select;
	
	system("cls");
	cout << "가고 싶은 던전을 선택하라" << endl;
	cout << "1)고블린 던전 2)트롤 던전" << endl;
	cin >> select;
	monsterFight(select);
	
}

//몬스터와 전투
void mainGame::monsterFight(int select)
{
	
	int repeat = 0;
	int random;
	//100번 반복해서 나온는 값을 사용
	while (repeat < 100)
	{
		if (select == 1)
		{
			random = rand() % 2;
		}
		else
		{
			random = rand() % 2 + 2;
		}
		repeat++;
	}
	int skillSelect;
	int i;
	while (true)
	{
		system("cls");
		//몬스터 능력치 띄우기
		cout << monsterVector[random]->getName() << "의 체  력은 : " << monsterVector[random]->getCurHp() << endl;
		cout << monsterVector[random]->getName() << "의 공격력은 : " << monsterVector[random]->getAtk() << endl;
		cout << monsterVector[random]->getName() << "의 방어력은 : " << monsterVector[random]->getDef() << endl;
		cout << "1) 파이어볼 2) 아이스에이지 3)매직볼트 (0을 누르면 입구로 간다.)" << endl;
		cin >> skillSelect;
		if (skillSelect == 0)
		{
			selectWindow(); //처음 화면
		}
		else if (skillSelect > 3 || skillSelect < 0) //잘못된 숫자를 눌렀을때
		{
			cout << "제대로 된 숫자를 눌러주세요" << endl;
			Sleep(500);
		}
		else
		{
			int damage = player->skillListMap.find(skillSelect)->second->getDamage() - monsterVector[random]->getDef(); //데미지는 스킬 데미지에서 방어력을 뺀값
			cout << player->skillListMap.find(skillSelect)->second->getName() << endl; //스킬 이름 출력
			if (damage < 0) // 몬스터 방어력이 너무 높을때
			{
				cout << "MISS!!" << endl;
				Sleep(1000);
			}
			else
			{
				cout << monsterVector[random]->getName() << "에게 피해 " << damage << "을(를) 주었다" << endl;
				monsterVector[random]->setCurHp(monsterVector[random]->getCurHp() - damage); //데미지 주기
				Sleep(1500);
				system("cls");
			}
			if (monsterVector[random]->getCurHp() <= 0)
			{
				cout << monsterVector[random]->getName() << "은(는) 죽었다!!" << endl;
				monsterVector[random]->setCurHp(monsterVector[random]->getMaxHp()); //죽었을 경우 체력 초기화
				userItem.push_back(_monster->monsterInItem()); //아이템 획득
				Sleep(1000);
				selectMap();
			}
			else
			{
				cout << monsterVector[random]->getName() << "은(는) " << monsterVector[random]->getCurHp() << "만큼 남았다" << endl;
				damage = monsterVector[random]->getAtk() - player->getDef(); //데미지는 몬스터 데미지에서 플레이어 방어력 뺀값
				cout << player->getName() << "은(는) 데미지 " << damage << "을(를) 받았다" << endl;
				player->setCurHp(player->getCurHp() - damage); //플레이어가 죽었을 경우
				if (player->getCurHp() <= 0)
				{
					cout << player->getName() << "은(는)" << "사망했습니다." << endl;
					Sleep(1000);
					player->setCurHp(player->getMaxHp()); // 체력 초기화
				}
				else
				{
					cout << player->getName() << "은(는)" << player->getCurHp() << "만큼 남았다." << endl;
					Sleep(1000);
				}

			}

		}
	}
}

void mainGame::showMyInventory()
{
	cout << "인 벤 토 리" << endl;
	cout << "=============================" << endl;
	invetoryIter = userItem.begin(); //이터레이터 사용
	for (invetoryIter; invetoryIter != userItem.end();invetoryIter++)
	{
		cout << (*invetoryIter)->getName() << endl;
		cout << "=============================" << endl;
	}
	Sleep(1000);
	selectWindow();
}