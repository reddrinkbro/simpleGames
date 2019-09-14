#include "mainGame.h"



mainGame::mainGame()
{
	dragon = new MonsterDragon;
	Goblin = new MonsterGoblin;
	God = new MonsterGod;
	Orc = new MonsterOrc;
	Troll = new MonsterTroll;
	user = new player;

	
	//유저 설정
	user->setLevel(1);
	user->setAtk(1000);
	user->setMaxHp(5000);
	user->setMaxMp(2000);
	user->setCurHp(user->getMaxHp());
	user->setCurMp(user->getMaxMp());
	user->setDef(500);
	
	//고블린 설정
	Goblin->setLevel(1);
	Goblin->setAtk(10);
	Goblin->setMaxHp(50);
	Goblin->setMaxMp(20);
	Goblin->setCurHp(Goblin->getMaxHp());
	Goblin->setCurMp(Goblin->getMaxMp());
	Goblin->setDef(5);

	//오크 설정
	Orc->setLevel(3);
	Orc->setAtk(30);
	Orc->setMaxHp(150);
	Orc->setMaxMp(60);
	Orc->setCurHp(Orc->getMaxHp());
	Orc->setCurMp(Orc->getMaxMp());
	Orc->setDef(15);

	//트롤 설정
	Troll->setLevel(5);
	Troll->setAtk(50);
	Troll->setMaxHp(250);
	Troll->setMaxMp(100);
	Troll->setCurHp(Troll->getMaxHp());
	Troll->setCurMp(Troll->getMaxMp());
	Troll->setDef(25);

	//드래곤 설정
	dragon->setLevel(10);
	dragon->setAtk(100);
	dragon->setMaxHp(500);
	dragon->setMaxMp(200);
	dragon->setCurHp(dragon->getMaxHp());
	dragon->setCurMp(dragon->getMaxMp());
	dragon->setDef(50);

	//신 설정
	God->setLevel(100);
	God->setAtk(10000);
	God->setMaxHp(50000);
	God->setMaxMp(20000);
	God->setCurHp(God->getMaxHp());
	God->setCurMp(God->getMaxMp());
	God->setDef(5000);

	welcome();
}


mainGame::~mainGame()
{
	delete dragon;
	delete Goblin;
	delete God;
	delete Orc;
	delete Troll;
	delete user;
}

//처음 시작하는 함수
void mainGame::welcome()
{
	int selectMode = 0; // 던전갈지 스탯볼지 선택
	
	while (true)
	{
		system("cls");
		cout << "던전에 오신걸 환영합니다." << endl;
		cout << "1)던전 가기 2)스탯 보기" << endl;
		cin >> selectMode;
		if (selectMode == 1)
		{
			fight();
		}
		else if (selectMode == 2)
		{
			showPlayerStat(); // 스탯 보기
		}
	}
}

//스탯 보기 위한 함수
void mainGame::showPlayerStat()
{
	cout << user->getName() << "의 스탯" << endl;
	cout << "레    벨 : " << user->getLevel() << endl;
	cout << "공 격 력 : " << user->getAtk() << endl;
	cout << "방 어 력 : " << user->getDef() << endl;
	cout << "체    력 : " << user->getMaxHp() << endl;
	cout << "마    나 : " << user->getMaxMp() << endl;
	Sleep(3000);
}

//전투 중 함수
void mainGame::fight()
{
	int selectDugeon = 0; //어느 던전을 갈지 선택
	int selectAtk = 0; //공격할지 안할지 선택
	int damage;
	bool yourTurn = true;
	
	
	while (true)
	{
		system("cls");
		cout << "어느 던전을 가겠습니까?" << endl;
		cout << "1) 고블린 던전 2) 오크 던전 3) 트롤던전 4) 드래곤 던전 5) 신의 던전 6)마을로 가기" << endl;
		cin >> selectDugeon;
		//고블린 던전
		if (selectDugeon == 1)
		{
			//데미지는 유저 공격력 - 몬스터 방어력

			cout << Goblin->getName() << "이(가) 나타났습니다" << endl;
			if (yourTurn == true)
			{
				cout << Goblin->getName() << "의 레  벨 : " << Goblin->getLevel() << endl;
				cout << Goblin->getName() << "의 공격력 : " << Goblin->getAtk() << endl;
				cout << Goblin->getName() << "의 방어력 : " << Goblin->getDef() << endl;
				cout << Goblin->getName() << "의 체  력 : " << Goblin->getCurHp() << endl;
				cout << Goblin->getName() << "의 마  나 : " << Goblin->getCurMp() << endl;
				cout << "1)공격하기 2)도망가기" << endl;
				cin >> selectAtk;
			}
			if (selectAtk == 1)
			{
				cout << "공격 ~!" << endl;
				Sleep(500);
				damage = (int)(user->getAtk() - Goblin->getDef());
				yourTurn = false;
				if (damage < 0) // 몬스터 방어력이 너무 높을때
				{
					cout << "MISS!!" << endl;
				}
				else
				{
					cout << Goblin->getName() << "에게 피해 " << damage << "을(를) 주었다" << endl;
					Goblin->setCurHp(Goblin->getCurHp() - damage); //데미지 주기
				}
				if (Goblin->getCurHp() <= 0)
				{
					cout << Goblin->getName() << "은(는) 죽었다!!" << endl;
					//유저 레벨 상승에 따른 스탯 증가
					userLevelUp();

					//유저 레벨에 따른 몬스터 스탯 증가
					monsterLevelUp();
					Sleep(1000);
				}
				else
				{
					cout << Goblin->getName() << "은(는) " << Goblin->getCurHp() << "만큼 남았다" << endl;
					damage = (int)(Goblin->getAtk() - user->getDef());
					cout << user->getName() << "은(는)" << damage << "을(를) 주었다" << endl;
					user->setCurHp(user->getCurHp() - damage);
					if (user->getCurHp() <= 0)
					{
						cout << user->getName() << "은(는)" << "사망했습니다." << endl;
						Sleep(1000);
					}
					else
					{
						cout << user->getName() << "은(는)" << user->getCurHp() << "만큼 남았다." << endl;
						yourTurn = true;
						Sleep(1000);
					}

				}
				Sleep(1500);
			}
			else if (selectAtk == 2)
			{
				cout << "쯧쯧.. 도망치다니 한심하군" << endl;
				Sleep(1000);
				welcome();
			}
		}
		//오크 던전
		else if (selectDugeon == 2)
		{
			//데미지는 유저 공격력 - 몬스터 방어력
			if (yourTurn == true)
			{
				cout << Orc->getName() << "이(가) 나타났습니다" << endl;
				cout << Orc->getName() << "의 레  벨 : " << Orc->getLevel() << endl;
				cout << Orc->getName() << "의 공격력 : " << Orc->getAtk() << endl;
				cout << Orc->getName() << "의 방어력 : " << Orc->getDef() << endl;
				cout << Orc->getName() << "의 체  력 : " << Orc->getCurHp() << endl;
				cout << Orc->getName() << "의 마  나 : " << Orc->getCurMp() << endl;
				cout << "1)공격하기 2)도망가기" << endl;
				cin >> selectAtk;
			}
			if (selectAtk == 1)
			{
				cout << "공격 ~!" << endl;
				Sleep(500);
				damage = (int)(user->getAtk() - Orc->getDef());
				yourTurn = false;
				if (damage < 0)// 몬스터 방어력이 너무 높을때
				{
					cout << "MISS!!" << endl;
				}
				else
				{
					cout << Orc->getName() << "에게 피해 " << damage << "을(를) 주었다" << endl;
					Orc->setCurHp(Orc->getCurHp() - damage); //데미지 주기
				}
				if (Orc->getCurHp() <= 0)
				{
					cout << Orc->getName() << "은(는) 죽었다!!" << endl;
					//유저 레벨 상승에 따른 스탯 증가
					userLevelUp();

					//유저 레벨에 따른 몬스터 스탯 증가
					monsterLevelUp();
					Sleep(1000);
				}
				else
				{
					cout << Orc->getName() << "은(는) " << Orc->getCurHp() << "만큼 남았다" << endl;
					damage = (int)(Orc->getAtk() - user->getDef());
					cout << user->getName() << "은(는)" << damage << "을(를) 주었다" << endl;
					user->setCurHp(user->getCurHp() - damage);
					if (user->getCurHp() <= 0)
					{
						cout << user->getName() << "은(는)" << "사망했습니다." << endl;
						Sleep(1000);
					}
					else
					{
						cout << user->getName() << "은(는)" << user->getCurHp() << "만큼 남았다." << endl;
						yourTurn = true;
						Sleep(1000);
					}
				}
				Sleep(1500);
			}
			else if (selectAtk == 2)
			{
				cout << "쯧쯧.. 도망치다니 한심하군" << endl;
				Sleep(1000);
				welcome();
			}
		}

		//트롤 던전
		else if (selectDugeon == 3)
		{
			//데미지는 유저 공격력 - 몬스터 방어력
			if (yourTurn == true)
			{
				cout << Troll->getName() << "이(가) 나타났습니다" << endl;
				cout << Troll->getName() << "의 레  벨 : " << Troll->getLevel() << endl;
				cout << Troll->getName() << "의 공격력 : " << Troll->getAtk() << endl;
				cout << Troll->getName() << "의 방어력 : " << Troll->getDef() << endl;
				cout << Troll->getName() << "의 체  력 : " << Troll->getCurHp() << endl;
				cout << Troll->getName() << "의 마  나 : " << Troll->getCurMp() << endl;
				cout << "1)공격하기 2)도망가기" << endl;
				cin >> selectAtk;
			}
			if (selectAtk == 1)
			{
				cout << "공격 ~!" << endl;
				Sleep(500);
				damage = (int)(user->getAtk() - Troll->getDef());
				yourTurn = false;
				if (damage < 0)// 몬스터 방어력이 너무 높을때
				{
					cout << "MISS!!" << endl;
				}
				else
				{
					cout << Troll->getName() << "에게 피해 " << damage << "을(를) 주었다" << endl;
					Troll->setCurHp(Troll->getCurHp() - damage); //데미지 주기
				}
				if (Troll->getCurHp() <= 0)
				{
					cout << Troll->getName() << "은(는) 죽었다!!" << endl;
					//유저 레벨 상승에 따른 스탯 증가
					userLevelUp();

					//유저 레벨에 따른 몬스터 스탯 증가
					monsterLevelUp();
					Sleep(1000);
				}
				else
				{
					cout << Troll->getName() << "은(는) " << Troll->getCurHp() << "만큼 남았다" << endl;
					damage = (int)(Troll->getAtk() - user->getDef());
					cout << user->getName() << "은(는)" << damage << "을(를) 받았다" << endl;
					user->setCurHp(user->getCurHp() - damage);
					if (user->getCurHp() <= 0)
					{
						cout << user->getName() << "은(는)" << "사망했습니다." << endl;
						Sleep(1000);
					}
					else
					{
						cout << user->getName() << "은(는)" << user->getCurHp() << "만큼 남았다." << endl;
						yourTurn = true;
						Sleep(1000);
					}
				}
				Sleep(1500);
			}
			else if (selectAtk == 2)
			{
				cout << "쯧쯧.. 도망치다니 한심하군" << endl;
				Sleep(1000);
				welcome();
			}
		}

		//드래곤 던전
		else if (selectDugeon == 4)
		{
			//데미지는 유저 공격력 - 몬스터 방어력
			if (yourTurn == true)
			{
				cout << dragon->getName() << "이(가) 나타났습니다" << endl;
				cout << dragon->getName() << "의 레  벨 : " << dragon->getLevel() << endl;
				cout << dragon->getName() << "의 공격력 : " << dragon->getAtk() << endl;
				cout << dragon->getName() << "의 방어력 : " << dragon->getDef() << endl;
				cout << dragon->getName() << "의 체  력 : " << dragon->getCurHp() << endl;
				cout << dragon->getName() << "의 마  나 : " << dragon->getCurMp() << endl;
				cout << "1)공격하기 2)도망가기" << endl;
				cin >> selectAtk;
			}
			if (selectAtk == 1)
			{
				cout << "공격 ~!" << endl;
				Sleep(500);
				damage = (int)(user->getAtk() - dragon->getDef());
				yourTurn = false;
				if (damage < 0)// 몬스터 방어력이 너무 높을때
				{
					cout << "MISS!!" << endl;
				}
				else
				{
					cout << dragon->getName() << "에게 피해 " << damage << "을(를) 주었다" << endl;
					dragon->setCurHp(dragon->getCurHp() - damage); //데미지 주기
				}
				if (dragon->getCurHp() <= 0)
				{
					cout << dragon->getName() << "은(는) 죽었다!!" << endl;
					//유저 레벨 상승에 따른 스탯 증가
					userLevelUp();

					//유저 레벨에 따른 몬스터 스탯 증가
					monsterLevelUp();
					Sleep(1000);
				}
				else
				{
					cout << dragon->getName() << "은(는) " << dragon->getCurHp() << "만큼 남았다" << endl;
					damage = (int)(dragon->getAtk() - user->getDef());
					cout << user->getName() << "은(는)" << damage << "을(를) 받았다" << endl;
					user->setCurHp(user->getCurHp() - damage);
					if (user->getCurHp() <= 0)
					{
						cout << user->getName() << "은(는)" << "사망했습니다." << endl;
						Sleep(1000);
					}
					else
					{
						cout << user->getName() << "은(는)" << user->getCurHp() << "만큼 남았다." << endl;
						yourTurn = true;
						Sleep(1000);
					}
				}
				Sleep(1500);
			}
			else if (selectAtk == 2)
			{
				cout << "쯧쯧.. 도망치다니 한심하군" << endl;
				Sleep(1000);
				welcome();
			}
		}

		//신의 던전
		else if (selectDugeon == 5)
		{
			//데미지는 유저 공격력 - 몬스터 방어력
			if (yourTurn == true)
			{
				cout << God->getName() << "이(가) 나타났습니다" << endl;
				cout << God->getName() << "의 레  벨 : " << God->getLevel() << endl;
				cout << God->getName() << "의 공격력 : " << God->getAtk() << endl;
				cout << God->getName() << "의 방어력 : " << God->getDef() << endl;
				cout << God->getName() << "의 체  력 : " << God->getCurHp() << endl;
				cout << God->getName() << "의 마  나 : " << God->getCurMp() << endl;
				cout << "1)공격하기 2)도망가기" << endl;
				cin >> selectAtk;
			}
			if (selectAtk == 1)
			{
				cout << "공격 ~!" << endl;
				Sleep(500);
				damage = (int)(user->getAtk() - God->getDef());
				yourTurn = false;
				if (damage < 0)// 몬스터 방어력이 너무 높을때
				{
					cout << "MISS!!" << endl;
				}
				else
				{
					cout << God->getName() << "에게 피해 " << damage << "을(를) 주었다" << endl;
					God->setCurHp(God->getCurHp() - damage); //데미지 주기
				}
				if (God->getCurHp() <= 0)
				{
					cout << God->getName() << "은(는) 죽었다!!" << endl;
					//유저 레벨 상승에 따른 스탯 증가
					userLevelUp();

					//유저 레벨에 따른 몬스터 스탯 증가
					monsterLevelUp();
					Sleep(1000);
				}
				else
				{
					cout << God->getName() << "은(는) " << God->getCurHp() << "만큼 남았다" << endl;
					damage = (int)(God->getAtk() - user->getDef());
					cout << user->getName() << "은(는)" << damage << "을(를) 받았다" << endl;
					user->setCurHp(user->getCurHp() - damage);
					if (user->getCurHp() <= 0)
					{
						cout << user->getName() << "은(는)" << "사망했습니다." << endl;
						Sleep(1000);
					}
					else
					{
						cout << user->getName() << "은(는)" << user->getCurHp() << "만큼 남았다." << endl;
						yourTurn = true;
						Sleep(1000);
					}
				}
				Sleep(1500);
			}
			else if (selectAtk == 2)
			{
				cout << "쯧쯧.. 도망치다니 한심하군" << endl;
				Sleep(1000);
				welcome();
			}
		}
		else if (selectDugeon == 6)
		{
			welcome();
		}
	}
}

void mainGame::userLevelUp()
{
	user->setLevel(user->getLevel() + 1);
	user->setAtk(user->getAtk() + 500);
	user->setDef(user->getDef() + 500);
	user->setMaxHp(user->getMaxHp() + 5000);
	user->setCurHp(user->getMaxHp());
	user->setMaxMp(user->getMaxMp() + 2000);
	user->setCurMp(user->getMaxMp());
}

void mainGame::monsterLevelUp()
{
	if (user->getLevel() > Goblin->getLevel())
	{
		Goblin->setCurHp(Goblin->getMaxHp() + (user->getLevel() - 1) * 5);
		Goblin->setAtk(Goblin->getAtk() + (user->getLevel() - 1));
		Goblin->setCurMp(Goblin->getMaxMp() + (user->getLevel() - 1));
		Goblin->setDef(Goblin->getDef() + (user->getLevel() - 1));
		Goblin->setLevel(Goblin->getLevel() + (user->getLevel() - 1));
	}
	if (user->getLevel() > Orc->getLevel())
	{
		Orc->setCurHp(Orc->getMaxHp() + (user->getLevel() - 1) * 15);
		Orc->setAtk(Orc->getAtk() + (user->getLevel() - 1) * 3);
		Orc->setCurMp(Orc->getMaxMp() + (user->getLevel() - 1) * 3);
		Orc->setDef(Orc->getDef() + (user->getLevel() - 1) * 3);
		Orc->setLevel(Orc->getLevel() + (user->getLevel() - 1));
	}
	if (user->getLevel() > Troll->getLevel())
	{
		Troll->setCurHp(Troll->getMaxHp() + (user->getLevel() - 1) * 25);
		Troll->setAtk(Troll->getAtk() + (user->getLevel() - 1) * 5);
		Troll->setCurMp(Troll->getMaxMp() + (user->getLevel() - 1) * 5);
		Troll->setDef(Troll->getDef() + (user->getLevel() - 1) * 5);
		Troll->setLevel(Troll->getLevel() + (user->getLevel() - 1));
	}
	if (user->getLevel() > dragon->getLevel())
	{
		dragon->setCurHp(dragon->getMaxHp() + (user->getLevel() - 1) * 10);
		dragon->setAtk(dragon->getAtk() + (user->getLevel() - 1) * 10);
		dragon->setCurMp(dragon->getMaxMp() + (user->getLevel() - 1) * 10);
		dragon->setDef(dragon->getDef() + (user->getLevel() - 1) * 10);
		dragon->setLevel(dragon->getLevel() + (user->getLevel() - 1));
	}
	if (user->getLevel() > God->getLevel())
	{
		God->setCurHp(God->getMaxHp() + (user->getLevel() - 1) * 100);
		God->setAtk(God->getAtk() + (user->getLevel() - 1) * 100);
		God->setCurMp(God->getMaxMp() + (user->getLevel() - 1) * 100);
		God->setDef(God->getDef() + (user->getLevel() - 1) * 100);
		God->setLevel(God->getLevel() + (user->getLevel() - 1));
	}
}