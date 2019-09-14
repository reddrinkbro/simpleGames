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
//ó�� ȭ��
void mainGame::selectWindow()
{
	system("cls");
	int select;
	cout << "������ʹ� �������� ���±��̴�." << endl;
	cout << "1)����ǰ Ȯ�� 2)�������� ����" << endl;
	cin >> select;
	if (select == 1)
	{
		showMyInventory(); //�κ��丮 ����
	}
	else if (select == 2)
	{
		selectMap(); //���������Ϸ� ����
	}
}
//���� ����
void mainGame::selectMap()
{
	int select;
	
	system("cls");
	cout << "���� ���� ������ �����϶�" << endl;
	cout << "1)��� ���� 2)Ʈ�� ����" << endl;
	cin >> select;
	monsterFight(select);
	
}

//���Ϳ� ����
void mainGame::monsterFight(int select)
{
	
	int repeat = 0;
	int random;
	//100�� �ݺ��ؼ� ���´� ���� ���
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
		//���� �ɷ�ġ ����
		cout << monsterVector[random]->getName() << "�� ü  ���� : " << monsterVector[random]->getCurHp() << endl;
		cout << monsterVector[random]->getName() << "�� ���ݷ��� : " << monsterVector[random]->getAtk() << endl;
		cout << monsterVector[random]->getName() << "�� ������ : " << monsterVector[random]->getDef() << endl;
		cout << "1) ���̾ 2) ���̽������� 3)������Ʈ (0�� ������ �Ա��� ����.)" << endl;
		cin >> skillSelect;
		if (skillSelect == 0)
		{
			selectWindow(); //ó�� ȭ��
		}
		else if (skillSelect > 3 || skillSelect < 0) //�߸��� ���ڸ� ��������
		{
			cout << "����� �� ���ڸ� �����ּ���" << endl;
			Sleep(500);
		}
		else
		{
			int damage = player->skillListMap.find(skillSelect)->second->getDamage() - monsterVector[random]->getDef(); //�������� ��ų ���������� ������ ����
			cout << player->skillListMap.find(skillSelect)->second->getName() << endl; //��ų �̸� ���
			if (damage < 0) // ���� ������ �ʹ� ������
			{
				cout << "MISS!!" << endl;
				Sleep(1000);
			}
			else
			{
				cout << monsterVector[random]->getName() << "���� ���� " << damage << "��(��) �־���" << endl;
				monsterVector[random]->setCurHp(monsterVector[random]->getCurHp() - damage); //������ �ֱ�
				Sleep(1500);
				system("cls");
			}
			if (monsterVector[random]->getCurHp() <= 0)
			{
				cout << monsterVector[random]->getName() << "��(��) �׾���!!" << endl;
				monsterVector[random]->setCurHp(monsterVector[random]->getMaxHp()); //�׾��� ��� ü�� �ʱ�ȭ
				userItem.push_back(_monster->monsterInItem()); //������ ȹ��
				Sleep(1000);
				selectMap();
			}
			else
			{
				cout << monsterVector[random]->getName() << "��(��) " << monsterVector[random]->getCurHp() << "��ŭ ���Ҵ�" << endl;
				damage = monsterVector[random]->getAtk() - player->getDef(); //�������� ���� ���������� �÷��̾� ���� ����
				cout << player->getName() << "��(��) ������ " << damage << "��(��) �޾Ҵ�" << endl;
				player->setCurHp(player->getCurHp() - damage); //�÷��̾ �׾��� ���
				if (player->getCurHp() <= 0)
				{
					cout << player->getName() << "��(��)" << "����߽��ϴ�." << endl;
					Sleep(1000);
					player->setCurHp(player->getMaxHp()); // ü�� �ʱ�ȭ
				}
				else
				{
					cout << player->getName() << "��(��)" << player->getCurHp() << "��ŭ ���Ҵ�." << endl;
					Sleep(1000);
				}

			}

		}
	}
}

void mainGame::showMyInventory()
{
	cout << "�� �� �� ��" << endl;
	cout << "=============================" << endl;
	invetoryIter = userItem.begin(); //���ͷ����� ���
	for (invetoryIter; invetoryIter != userItem.end();invetoryIter++)
	{
		cout << (*invetoryIter)->getName() << endl;
		cout << "=============================" << endl;
	}
	Sleep(1000);
	selectWindow();
}