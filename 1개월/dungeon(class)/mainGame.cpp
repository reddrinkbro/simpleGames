#include "mainGame.h"



mainGame::mainGame()
{
	dragon = new MonsterDragon;
	Goblin = new MonsterGoblin;
	God = new MonsterGod;
	Orc = new MonsterOrc;
	Troll = new MonsterTroll;
	user = new player;

	
	//���� ����
	user->setLevel(1);
	user->setAtk(1000);
	user->setMaxHp(5000);
	user->setMaxMp(2000);
	user->setCurHp(user->getMaxHp());
	user->setCurMp(user->getMaxMp());
	user->setDef(500);
	
	//��� ����
	Goblin->setLevel(1);
	Goblin->setAtk(10);
	Goblin->setMaxHp(50);
	Goblin->setMaxMp(20);
	Goblin->setCurHp(Goblin->getMaxHp());
	Goblin->setCurMp(Goblin->getMaxMp());
	Goblin->setDef(5);

	//��ũ ����
	Orc->setLevel(3);
	Orc->setAtk(30);
	Orc->setMaxHp(150);
	Orc->setMaxMp(60);
	Orc->setCurHp(Orc->getMaxHp());
	Orc->setCurMp(Orc->getMaxMp());
	Orc->setDef(15);

	//Ʈ�� ����
	Troll->setLevel(5);
	Troll->setAtk(50);
	Troll->setMaxHp(250);
	Troll->setMaxMp(100);
	Troll->setCurHp(Troll->getMaxHp());
	Troll->setCurMp(Troll->getMaxMp());
	Troll->setDef(25);

	//�巡�� ����
	dragon->setLevel(10);
	dragon->setAtk(100);
	dragon->setMaxHp(500);
	dragon->setMaxMp(200);
	dragon->setCurHp(dragon->getMaxHp());
	dragon->setCurMp(dragon->getMaxMp());
	dragon->setDef(50);

	//�� ����
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

//ó�� �����ϴ� �Լ�
void mainGame::welcome()
{
	int selectMode = 0; // �������� ���Ⱥ��� ����
	
	while (true)
	{
		system("cls");
		cout << "������ ���Ű� ȯ���մϴ�." << endl;
		cout << "1)���� ���� 2)���� ����" << endl;
		cin >> selectMode;
		if (selectMode == 1)
		{
			fight();
		}
		else if (selectMode == 2)
		{
			showPlayerStat(); // ���� ����
		}
	}
}

//���� ���� ���� �Լ�
void mainGame::showPlayerStat()
{
	cout << user->getName() << "�� ����" << endl;
	cout << "��    �� : " << user->getLevel() << endl;
	cout << "�� �� �� : " << user->getAtk() << endl;
	cout << "�� �� �� : " << user->getDef() << endl;
	cout << "ü    �� : " << user->getMaxHp() << endl;
	cout << "��    �� : " << user->getMaxMp() << endl;
	Sleep(3000);
}

//���� �� �Լ�
void mainGame::fight()
{
	int selectDugeon = 0; //��� ������ ���� ����
	int selectAtk = 0; //�������� ������ ����
	int damage;
	bool yourTurn = true;
	
	
	while (true)
	{
		system("cls");
		cout << "��� ������ ���ڽ��ϱ�?" << endl;
		cout << "1) ��� ���� 2) ��ũ ���� 3) Ʈ�Ѵ��� 4) �巡�� ���� 5) ���� ���� 6)������ ����" << endl;
		cin >> selectDugeon;
		//��� ����
		if (selectDugeon == 1)
		{
			//�������� ���� ���ݷ� - ���� ����

			cout << Goblin->getName() << "��(��) ��Ÿ�����ϴ�" << endl;
			if (yourTurn == true)
			{
				cout << Goblin->getName() << "�� ��  �� : " << Goblin->getLevel() << endl;
				cout << Goblin->getName() << "�� ���ݷ� : " << Goblin->getAtk() << endl;
				cout << Goblin->getName() << "�� ���� : " << Goblin->getDef() << endl;
				cout << Goblin->getName() << "�� ü  �� : " << Goblin->getCurHp() << endl;
				cout << Goblin->getName() << "�� ��  �� : " << Goblin->getCurMp() << endl;
				cout << "1)�����ϱ� 2)��������" << endl;
				cin >> selectAtk;
			}
			if (selectAtk == 1)
			{
				cout << "���� ~!" << endl;
				Sleep(500);
				damage = (int)(user->getAtk() - Goblin->getDef());
				yourTurn = false;
				if (damage < 0) // ���� ������ �ʹ� ������
				{
					cout << "MISS!!" << endl;
				}
				else
				{
					cout << Goblin->getName() << "���� ���� " << damage << "��(��) �־���" << endl;
					Goblin->setCurHp(Goblin->getCurHp() - damage); //������ �ֱ�
				}
				if (Goblin->getCurHp() <= 0)
				{
					cout << Goblin->getName() << "��(��) �׾���!!" << endl;
					//���� ���� ��¿� ���� ���� ����
					userLevelUp();

					//���� ������ ���� ���� ���� ����
					monsterLevelUp();
					Sleep(1000);
				}
				else
				{
					cout << Goblin->getName() << "��(��) " << Goblin->getCurHp() << "��ŭ ���Ҵ�" << endl;
					damage = (int)(Goblin->getAtk() - user->getDef());
					cout << user->getName() << "��(��)" << damage << "��(��) �־���" << endl;
					user->setCurHp(user->getCurHp() - damage);
					if (user->getCurHp() <= 0)
					{
						cout << user->getName() << "��(��)" << "����߽��ϴ�." << endl;
						Sleep(1000);
					}
					else
					{
						cout << user->getName() << "��(��)" << user->getCurHp() << "��ŭ ���Ҵ�." << endl;
						yourTurn = true;
						Sleep(1000);
					}

				}
				Sleep(1500);
			}
			else if (selectAtk == 2)
			{
				cout << "����.. ����ġ�ٴ� �ѽ��ϱ�" << endl;
				Sleep(1000);
				welcome();
			}
		}
		//��ũ ����
		else if (selectDugeon == 2)
		{
			//�������� ���� ���ݷ� - ���� ����
			if (yourTurn == true)
			{
				cout << Orc->getName() << "��(��) ��Ÿ�����ϴ�" << endl;
				cout << Orc->getName() << "�� ��  �� : " << Orc->getLevel() << endl;
				cout << Orc->getName() << "�� ���ݷ� : " << Orc->getAtk() << endl;
				cout << Orc->getName() << "�� ���� : " << Orc->getDef() << endl;
				cout << Orc->getName() << "�� ü  �� : " << Orc->getCurHp() << endl;
				cout << Orc->getName() << "�� ��  �� : " << Orc->getCurMp() << endl;
				cout << "1)�����ϱ� 2)��������" << endl;
				cin >> selectAtk;
			}
			if (selectAtk == 1)
			{
				cout << "���� ~!" << endl;
				Sleep(500);
				damage = (int)(user->getAtk() - Orc->getDef());
				yourTurn = false;
				if (damage < 0)// ���� ������ �ʹ� ������
				{
					cout << "MISS!!" << endl;
				}
				else
				{
					cout << Orc->getName() << "���� ���� " << damage << "��(��) �־���" << endl;
					Orc->setCurHp(Orc->getCurHp() - damage); //������ �ֱ�
				}
				if (Orc->getCurHp() <= 0)
				{
					cout << Orc->getName() << "��(��) �׾���!!" << endl;
					//���� ���� ��¿� ���� ���� ����
					userLevelUp();

					//���� ������ ���� ���� ���� ����
					monsterLevelUp();
					Sleep(1000);
				}
				else
				{
					cout << Orc->getName() << "��(��) " << Orc->getCurHp() << "��ŭ ���Ҵ�" << endl;
					damage = (int)(Orc->getAtk() - user->getDef());
					cout << user->getName() << "��(��)" << damage << "��(��) �־���" << endl;
					user->setCurHp(user->getCurHp() - damage);
					if (user->getCurHp() <= 0)
					{
						cout << user->getName() << "��(��)" << "����߽��ϴ�." << endl;
						Sleep(1000);
					}
					else
					{
						cout << user->getName() << "��(��)" << user->getCurHp() << "��ŭ ���Ҵ�." << endl;
						yourTurn = true;
						Sleep(1000);
					}
				}
				Sleep(1500);
			}
			else if (selectAtk == 2)
			{
				cout << "����.. ����ġ�ٴ� �ѽ��ϱ�" << endl;
				Sleep(1000);
				welcome();
			}
		}

		//Ʈ�� ����
		else if (selectDugeon == 3)
		{
			//�������� ���� ���ݷ� - ���� ����
			if (yourTurn == true)
			{
				cout << Troll->getName() << "��(��) ��Ÿ�����ϴ�" << endl;
				cout << Troll->getName() << "�� ��  �� : " << Troll->getLevel() << endl;
				cout << Troll->getName() << "�� ���ݷ� : " << Troll->getAtk() << endl;
				cout << Troll->getName() << "�� ���� : " << Troll->getDef() << endl;
				cout << Troll->getName() << "�� ü  �� : " << Troll->getCurHp() << endl;
				cout << Troll->getName() << "�� ��  �� : " << Troll->getCurMp() << endl;
				cout << "1)�����ϱ� 2)��������" << endl;
				cin >> selectAtk;
			}
			if (selectAtk == 1)
			{
				cout << "���� ~!" << endl;
				Sleep(500);
				damage = (int)(user->getAtk() - Troll->getDef());
				yourTurn = false;
				if (damage < 0)// ���� ������ �ʹ� ������
				{
					cout << "MISS!!" << endl;
				}
				else
				{
					cout << Troll->getName() << "���� ���� " << damage << "��(��) �־���" << endl;
					Troll->setCurHp(Troll->getCurHp() - damage); //������ �ֱ�
				}
				if (Troll->getCurHp() <= 0)
				{
					cout << Troll->getName() << "��(��) �׾���!!" << endl;
					//���� ���� ��¿� ���� ���� ����
					userLevelUp();

					//���� ������ ���� ���� ���� ����
					monsterLevelUp();
					Sleep(1000);
				}
				else
				{
					cout << Troll->getName() << "��(��) " << Troll->getCurHp() << "��ŭ ���Ҵ�" << endl;
					damage = (int)(Troll->getAtk() - user->getDef());
					cout << user->getName() << "��(��)" << damage << "��(��) �޾Ҵ�" << endl;
					user->setCurHp(user->getCurHp() - damage);
					if (user->getCurHp() <= 0)
					{
						cout << user->getName() << "��(��)" << "����߽��ϴ�." << endl;
						Sleep(1000);
					}
					else
					{
						cout << user->getName() << "��(��)" << user->getCurHp() << "��ŭ ���Ҵ�." << endl;
						yourTurn = true;
						Sleep(1000);
					}
				}
				Sleep(1500);
			}
			else if (selectAtk == 2)
			{
				cout << "����.. ����ġ�ٴ� �ѽ��ϱ�" << endl;
				Sleep(1000);
				welcome();
			}
		}

		//�巡�� ����
		else if (selectDugeon == 4)
		{
			//�������� ���� ���ݷ� - ���� ����
			if (yourTurn == true)
			{
				cout << dragon->getName() << "��(��) ��Ÿ�����ϴ�" << endl;
				cout << dragon->getName() << "�� ��  �� : " << dragon->getLevel() << endl;
				cout << dragon->getName() << "�� ���ݷ� : " << dragon->getAtk() << endl;
				cout << dragon->getName() << "�� ���� : " << dragon->getDef() << endl;
				cout << dragon->getName() << "�� ü  �� : " << dragon->getCurHp() << endl;
				cout << dragon->getName() << "�� ��  �� : " << dragon->getCurMp() << endl;
				cout << "1)�����ϱ� 2)��������" << endl;
				cin >> selectAtk;
			}
			if (selectAtk == 1)
			{
				cout << "���� ~!" << endl;
				Sleep(500);
				damage = (int)(user->getAtk() - dragon->getDef());
				yourTurn = false;
				if (damage < 0)// ���� ������ �ʹ� ������
				{
					cout << "MISS!!" << endl;
				}
				else
				{
					cout << dragon->getName() << "���� ���� " << damage << "��(��) �־���" << endl;
					dragon->setCurHp(dragon->getCurHp() - damage); //������ �ֱ�
				}
				if (dragon->getCurHp() <= 0)
				{
					cout << dragon->getName() << "��(��) �׾���!!" << endl;
					//���� ���� ��¿� ���� ���� ����
					userLevelUp();

					//���� ������ ���� ���� ���� ����
					monsterLevelUp();
					Sleep(1000);
				}
				else
				{
					cout << dragon->getName() << "��(��) " << dragon->getCurHp() << "��ŭ ���Ҵ�" << endl;
					damage = (int)(dragon->getAtk() - user->getDef());
					cout << user->getName() << "��(��)" << damage << "��(��) �޾Ҵ�" << endl;
					user->setCurHp(user->getCurHp() - damage);
					if (user->getCurHp() <= 0)
					{
						cout << user->getName() << "��(��)" << "����߽��ϴ�." << endl;
						Sleep(1000);
					}
					else
					{
						cout << user->getName() << "��(��)" << user->getCurHp() << "��ŭ ���Ҵ�." << endl;
						yourTurn = true;
						Sleep(1000);
					}
				}
				Sleep(1500);
			}
			else if (selectAtk == 2)
			{
				cout << "����.. ����ġ�ٴ� �ѽ��ϱ�" << endl;
				Sleep(1000);
				welcome();
			}
		}

		//���� ����
		else if (selectDugeon == 5)
		{
			//�������� ���� ���ݷ� - ���� ����
			if (yourTurn == true)
			{
				cout << God->getName() << "��(��) ��Ÿ�����ϴ�" << endl;
				cout << God->getName() << "�� ��  �� : " << God->getLevel() << endl;
				cout << God->getName() << "�� ���ݷ� : " << God->getAtk() << endl;
				cout << God->getName() << "�� ���� : " << God->getDef() << endl;
				cout << God->getName() << "�� ü  �� : " << God->getCurHp() << endl;
				cout << God->getName() << "�� ��  �� : " << God->getCurMp() << endl;
				cout << "1)�����ϱ� 2)��������" << endl;
				cin >> selectAtk;
			}
			if (selectAtk == 1)
			{
				cout << "���� ~!" << endl;
				Sleep(500);
				damage = (int)(user->getAtk() - God->getDef());
				yourTurn = false;
				if (damage < 0)// ���� ������ �ʹ� ������
				{
					cout << "MISS!!" << endl;
				}
				else
				{
					cout << God->getName() << "���� ���� " << damage << "��(��) �־���" << endl;
					God->setCurHp(God->getCurHp() - damage); //������ �ֱ�
				}
				if (God->getCurHp() <= 0)
				{
					cout << God->getName() << "��(��) �׾���!!" << endl;
					//���� ���� ��¿� ���� ���� ����
					userLevelUp();

					//���� ������ ���� ���� ���� ����
					monsterLevelUp();
					Sleep(1000);
				}
				else
				{
					cout << God->getName() << "��(��) " << God->getCurHp() << "��ŭ ���Ҵ�" << endl;
					damage = (int)(God->getAtk() - user->getDef());
					cout << user->getName() << "��(��)" << damage << "��(��) �޾Ҵ�" << endl;
					user->setCurHp(user->getCurHp() - damage);
					if (user->getCurHp() <= 0)
					{
						cout << user->getName() << "��(��)" << "����߽��ϴ�." << endl;
						Sleep(1000);
					}
					else
					{
						cout << user->getName() << "��(��)" << user->getCurHp() << "��ŭ ���Ҵ�." << endl;
						yourTurn = true;
						Sleep(1000);
					}
				}
				Sleep(1500);
			}
			else if (selectAtk == 2)
			{
				cout << "����.. ����ġ�ٴ� �ѽ��ϱ�" << endl;
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