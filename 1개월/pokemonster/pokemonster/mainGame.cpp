#include "mainGame.h"
mainGame::mainGame()
{
	for (int i = 0; i < 6; i++)
	{
		cout << endl;
	}
	user = new player;
	char* playerName = new char[0];
	cout << "\t\t�÷��̾��� �̸��� �����ּ��� : ";
	cin >> playerName; //�÷��̾� �̸� �ֱ�
	user->setName(playerName);
	cout <<"\t\t" <<user->getName() << "�� �������濡 ���Ű� ȯ���մϴ�." << endl;
} 

mainGame::~mainGame()
{
}

void mainGame::firstPokemon()
{
	int selectPokemon;
	while (true)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << endl;
		}
		cout << "\t\tó�� ���Ͻô� ���ϸ��� �������ּ���" << endl;
		cout << "\t\t1) ���̸� 2)���α� 3)�̻��ؾ�" << endl;
		cout << "\t\t�Է����ּ��� : ";
		cin >> selectPokemon; // ���ϸ� ����
		if (selectPokemon == 1)
		{
			system("cls");
			pokemonCharmander* Charmander = new pokemonCharmander; //���̸� ��ä ����
			Charmander->showImage();
			user->getPokemon(Charmander); //������ ���ϸ����� ����
			break;
		}
		else if (selectPokemon == 2)
		{
			system("cls");
			pokemonSquirtle* Squirtle = new pokemonSquirtle; //���α� ��ü ����
			Squirtle->showImage();
			user->getPokemon(Squirtle);
			break;
		}
		else if (selectPokemon == 3)
		{
			system("cls");
			pokemonBulbasaur* Bulbasaur = new pokemonBulbasaur; // �̻��ؾ� ��ü ����
			Bulbasaur->showImage();
			user->getPokemon(Bulbasaur);
			break;
		}
		else
		{
			cout << "\t\t����� ������ �ּ���." << endl;
			Sleep(500);
		}
	}
} // ó�� ���ϸ��� �����ϴ� �Լ�

void mainGame::selectMode()
{
	int select; //�� �ൿ ����
	Sleep(1000);
	user->userWin();
	system("cls");
	town->showTownImage();
	if (getPlayer()->getIsPlayerWin() == true) //6���� ��� ��ȭ ������ ���
	{
		Sleep(1000);
		cout << "\t����� ����� ���ϸ� Ʈ���̳ʰ� �Ǿ����ϴ�." << endl;
		cout << "\tGAME CLEAR" << endl;
		exit(0);
	}
	else {
		cout << "\t1)���ධ���� 2)���ϸ� ���Ͱ��� 3)�κ��丮 ���� 4)���ϸ� ����" << endl;
		cout << "\t�Է����ּ��� : ";
		cin >> select;
		//���� ������
		if (select == 1)
		{
			travleMessage(); //������ ������...
			travel(); // ������ �����ϱ� ���� �Լ�
		}
		//���ϸ� ���Ͱ���
		else if (select == 2)
		{
			goToPokemonCenter();
		}
		//�÷��̾� �κ��丮 ����
		else if (select == 3)
		{
			yourInventory();
		}
		//�÷��̾ ������ �ִ� ���ϸ� Ȯ��
		else if (select == 4)
		{
			yourPokemon();
		}
		else
		{
			cout << "\t����� �Է����ּ���." << endl;
			Sleep(500);
		}
	}
} //����, ���ϸ���, 

void mainGame::travleMessage()
{
	cout << "\t������ ������� �ߴ�..." << endl;
	Sleep(1000);
}

void mainGame::travel()
{
	system("cls");
	town->showTownImage();
	cout << "\t���� �����ðڽ��ϱ�?" << endl;
	cout << "\t1)�����Ƽ 2)������Ʈ 3)�����̳� 4)���渶��ƾ 5)����ŷ�� 0)��������" << endl;
	cout << "\t�Է����ּ��� : ";
	int selectMap; //�ʼ��� �ϱ����� ����
	int random = rand() % 100;
	int randomPokemon; //�� ���ϸ��� ���ϴ� ��������
	if (random < 45) //��ȭ �� ���ϸ��� ���� Ȯ�� 10%���� ����
	{
		randomPokemon = 0;
	}
	else if (random < 90)
	{
		randomPokemon = 1;
	}
	else if (random < 95)
	{
		randomPokemon = 2;
	}
	else
	{
		randomPokemon = 3;
	}
	cin >> selectMap;
	//�����Ƽ���� �������
	if (selectMap == 1)
	{
		system("cls");
		mapElectronic* Electronic = new mapElectronic; //Ŭ���� ����
		Electronic->showImage();
		cout << "\t" <<Electronic->getName() << "���� �����ߴ�." << endl; //���̸� ǥ��
		Sleep(2000);
		system("cls");
		pokemon = Electronic->selectPokemon(selectMap, randomPokemon); // �� ���ϸ��� �ҷ��´�
		Sleep(1000);
		pokemonBattle(selectMap, Electronic, randomPokemon, pokemon); //���ϸ� ��Ʋ
	}
	//������Ʈ���� �������
	else if (selectMap == 2)
	{
		system("cls");
		mapForest* Forest = new mapForest;//Ŭ���� ����
		Forest->showImage();
		cout << "\t" << Forest->getName() << "���� �����ߴ�." << endl;//���̸� ǥ��
		Sleep(2000);
		system("cls");
		pokemon = Forest->selectPokemon(selectMap, randomPokemon); // �� ���ϸ��� �ҷ��´�
		Sleep(1000);
		pokemonBattle(selectMap, Forest, randomPokemon, pokemon); //���ϸ� ��Ʋ
	}
	//�����̳����� �������
	else if (selectMap == 3)
	{
		system("cls");
		mapVolcano* Volcano = new mapVolcano;//Ŭ���� ����
		Volcano->showImage();
		cout << "\t" << Volcano->getName() << "���� �����ߴ�." << endl;//���̸� ǥ��
		Sleep(2000);
		system("cls");
		pokemon = Volcano->selectPokemon(selectMap, randomPokemon); // �� ���ϸ��� �ҷ��´�
		Sleep(1000);
		pokemonBattle(selectMap, Volcano, randomPokemon, pokemon); //���ϸ� ��Ʋ

	}
	//���渶��ƾ���� �������
	else if (selectMap == 4)
	{
		system("cls");
		mapStone* Stone = new mapStone;//Ŭ���� ����
		Stone->showImage();
		cout << "\t" << Stone->getName() << "���� �����ߴ�." << endl;//���̸� ǥ��
		Sleep(2000);
		system("cls");
		pokemon = Stone->selectPokemon(selectMap, randomPokemon); // �� ���ϸ��� �ҷ��´�
		Sleep(1000);
		pokemonBattle(selectMap, Stone, randomPokemon, pokemon); //���ϸ� ��Ʋ

	}
	//����ŷ������ �������
	else if (selectMap == 5)
	{
		system("cls");
		mapLake* Lake = new mapLake;//Ŭ���� ����
		Lake->showImage();
		cout << "\t" << Lake->getName() << "���� �����ߴ�." << endl;//���̸� ǥ��
		Sleep(2000);
		system("cls");
		pokemon = Lake->selectPokemon(selectMap, randomPokemon); // �� ���ϸ��� �ҷ��´�
		Sleep(1000);
		pokemonBattle(selectMap, Lake, randomPokemon, pokemon); //���ϸ� ��Ʋ

	}
	else if (selectMap == 0)
	{
		cout << "\t������ ���ư���." << endl;
		Sleep(500);
		selectMode();
	}
	else
	{
		cout << "\t����� �Է��� �ּ���." << endl;
		Sleep(500);
	}
	
}

void mainGame::goToPokemonCenter()
{
	int select;
	while (true)
	{
		system("cls");
		town->showTownImage();
		cout << "\t���ϸ� ��ȣ�� : ������� " << user->getName() << "��" << endl;
		cout << "\t���ϸ� ��ȣ�� : ������ ���͵帱���?" << endl;
		cout << "\t1)���ϸ� ġ�� 2)���ϸ� ��ȭ 3)������ ���� 4) ������" << endl;
		cout << "\t�Է����ּ��� : ";
		cin >> select;
		//ġ�Ḧ ����
		if (select == 1)
		{
			cure();
		}
		//���ϸ� ��ȭ ����
		else if (select == 2)
		{
			pokemonRevolution();
		}
		else if (select == 3)
		{
			itemPurchase();
		}
		//������
		else if (select == 4)
		{
			cout << "\t���ϸ� ��ȣ�� : ���߿� �� ������. ^^" << endl;
			selectMode();
			break;
		}
		else
		{
			cout << "\t����� �Է��� �ּ���." << endl;
		}
	}
}

void mainGame::yourInventory()
{
	user->userInventory();
}

void mainGame::yourPokemon()
{
	for (int i = 0; i < user->pokemonVec.size(); i++)
	{
		cout << "\t==========================================================" << endl;
		cout << "\t���ϸ� �̸� : " << user->pokemonVec[i]->getName() << endl; //���ϸ� �̸� ���
		cout << "\t==========================================================" << endl;
		cout << "\t���ϸ� ü�� : " << user->pokemonVec[i]->getCurHealthPoint() << " / " << user->pokemonVec[i]->getMaxHealthPoint() << endl; //���ϸ� ���� ü�� / �ִ� ü��
		cout << "\t==========================================================" << endl;
		cout << "\t���ϸ� ����ġ : " << user->pokemonVec[i]->getCurExperiencePoint() << " / " << user->pokemonVec[i]->getMaxExperiencePoint() << endl; // ���ϸ� ���� ����ġ / ��ȭ�ϱ� ���� ����ġ
		cout << "\t==========================================================" << endl;
	}
	Sleep(1000);
}

void mainGame::pokemonBattleReady(int attribute,mapBase* map, int pokemonSelect)
{

	int select = 0;
	while (true)
	{
		system("cls");
		pokemon->showImage();
		cout << "\t1)�ο�� 2)���ͺ� ��� 3)���ϸ� ���� ��� 4)����ģ��" << endl;
		cout << "\t�Է����ּ��� : ";
		cin >> select;
		//���ϸ� ��Ʋ
		if (select == 1)
		{
			user->setIsFightState(true);
			break;
		}
		//���ͺ� ���
		else if (select == 2)
		{
			if (pokemon->getIsCatchPokemon() == false)
			{
				cout << "\t���ͺ��� ������ ���� ���ϸ� �Դϴ�." << endl;
				Sleep(500);
				pokemonBattleReady(attribute, map, pokemonSelect);
			}
			else
			{
				if (pitch(attribute, map, pokemonSelect) == true)
				{
					user->setIsFightState(false);
					break;
				}// ���ͺ� ����� ���� �Լ�
			}
		}
		else if (select == 3)
		{
			user->usingPokemonFood();
			Sleep(500);
		}
		//����ġ��
		else if (select == 4)
		{
			cout << "\t���� �ƴ�..." << endl;
			user->setIsFightState(false);
			for (int i = 0; i < user->pokemonVec.size(); i++)
			{
				user->pokemonVec[i]->mapIter = user->pokemonVec[i]->_skillMap.begin(); // ��ų�� ���� ���� ���ͷ�����
				for (user->pokemonVec[i]->mapIter; user->pokemonVec[i]->mapIter != user->pokemonVec[i]->_skillMap.end(); user->pokemonVec[i]->mapIter++)
				{
					user->pokemonVec[i]->mapIter->second->setCurSkillPoint(user->pokemonVec[i]->mapIter->second->getMaxSkillPoint());//���ϸ� ��Ʋ�� ������ ��ų����Ʈ�� �ʱ�ȭ �����ش�
				}
			}
			Sleep(500);
			break;
		}
		else
		{
			cout << "\t����� ������ �ּ���." << endl;
			Sleep(500);
		}
	}
	
}

bool mainGame::pitch(int attribute, mapBase* map, int pokemonSelect)
{
	system("cls");
	pokemon->showImage();
	if (user->pokemonVec.size() >= 6)
	{
		cout << "\t�� �̻� ���ϸ��� ������ �����ϴ�." << endl;
		Sleep(1000);
		system("cls");
		return false;
	}
	else
	{
		while (true)
		{
			char input;
			cout << "\t���ͺ� ���� : " << user->userBall->getAmount() << endl; // ���ͺ� ���� �����ֱ�
			cout << "\t��� �Ͻðڽ��ϱ�? Y/N : ";
			cin >> input;
			if (input == 'y' || input == 'Y')
			{

				if (user->userBall->getAmount() <= 0) //���ͺ��� �������
				{
					cout << "\t���ͺ��� �����մϴ�." << endl;
					Sleep(1000);
					return false;
					break;
				}
				else
				{
					cout << "\t���� ���� ������!" << endl;
					if (usingMonsterBall(attribute, map, pokemonSelect) == true) // ���ͺ��� �������� ���Ͱ� ���� Ȯ���� �����ִ� �Լ�
					{
						return true; //��������  true ��ȯ
						break;
					}
					else
					{
						return false; // ������� ��� false ��ȯ
						break;
					}
				}

			}
			//���ͺ��� ������� �������
			else if (input == 'n' || input == 'N')
			{
				return false;
				break;
			}
			else
			{
				cout << "\t����� �Է��� �ּ���." << endl;
				Sleep(500);
			}
		}
	}
}

void mainGame::pokemonBattle(int attribute, mapBase* map, int pokemonSelect, pokemonBase* pokemon)
{
	int selectPokemon = showMyPokemon(); // ������ �ִ� ���ϸ� ����
	if (selectPokemon == 0) //���� ���⸦ �����Ѵٸ�
	{
		system("cls");
		map->showTownImage();
		cout << "\t������ ���ϴ�." << endl;
		Sleep(500);
		selectMode(); //������ �̵�
	}
	else
	{
		while (true)
		{
			pokemonBattleReady(attribute, map, pokemonSelect); //��Ʋ ������
			if (user->getIsFightState() == false)
			{
				pokemon->setCurHealthPoint(pokemon->getMaxHealthPoint()); // �� ���ϸ� ü���� �ٽ� ���󺹱�
				travel(); //�ʼ������� �̵�
				break;
			}
			else
			{
				Sleep(500);
				pokemonSkillCheck(selectPokemon - 1); //���ϸ� ��ų�̸�, ��ų����Ʈ �����ֱ�
				int select; //��ų ����
				int damage; //��ų�� ������
				int randomSkillSelect = rand() % 3 + 1; //���� ��ų�� �������ֱ� ���� ������
				while (true)
				{
					cout << "\t\t�Է����ּ��� : ";
					cin >> select; //��ų�Է�
					if (select <= 0 || select > 3)
					{
						cout << "\t����� �� ��ų�� �������ּ���." << endl;
						Sleep(500);
						system("cls");
						pokemon->showImage();
						pokemonSkillCheck(selectPokemon - 1); //���ϸ� ��ų�̸�, ��ų����Ʈ �����ֱ�
					}
					else
					{
						if (user->pokemonVec[selectPokemon - 1]->getSkillMap().find(select)->second->getCurSkillPoint() >= user->pokemonVec[selectPokemon - 1]->getSkillMap().find(select)->second->getUsingSkillPoint()) //��ų����Ʈ�� ����ϸ� �����
						{
							break;
						}
						cout << "\t��ų����Ʈ�� �����մϴ�." << endl;
						Sleep(500);
						system("cls");
						pokemon->showImage();
						pokemonSkillCheck(selectPokemon - 1); //���ϸ� ��ų�̸�, ��ų����Ʈ �����ֱ�
					}
				}
				damage = user->pokemonVec[selectPokemon - 1]->getSkillMap().find(select)->second->getDamage(); // ���� �̿��Ͽ� �������� �־��ش�
				user->pokemonVec[selectPokemon - 1]->getSkillMap().find(select)->second->setCurSkillPoint(user->pokemonVec[selectPokemon - 1]->getSkillMap().find(select)->second->getCurSkillPoint() - user->pokemonVec[selectPokemon - 1]->getSkillMap().find(select)->second->getUsingSkillPoint()); //��ų ���� ��ų����Ʈ ����
				cout << "\t" <<user->pokemonVec[selectPokemon - 1]->getName() << "��(��) " << user->pokemonVec[selectPokemon - 1]->getSkillMap().find(select)->second->getName() << "��(��)����ߴ�." << endl; //���ϸ��̸��� ��ų�� �̸��� �����ش�
				pokemon->setCurHealthPoint(pokemon->getCurHealthPoint() - damage); // �� ���ϸ��� ü�¿��� ��������ŭ ����
				if (pokemon->getCurHealthPoint() <= 0) //�����ϸ��� �׾��� ���
				{
					cout << "\t" << pokemon->getName() << "�� ü���� 0�� �Ǿ���" << endl;
					cout << "\t" << pokemon->getName() << "��(��) ��������." << endl;
					cout << "\t�� " << pokemon->getMoney() << "�� ȹ��" << endl;
					user->setMoney(user->getMoney() + pokemon->getMoney());
					if (user->pokemonVec[selectPokemon - 1]->getCurExperiencePoint() < 20) // ����ġ�� 20���� �������
					{
						user->pokemonVec[selectPokemon - 1]->setCurExperiencePoint(user->pokemonVec[selectPokemon - 1]->getCurExperiencePoint() + 1); // ����ġ�� �����Ѵ�
						cout << "\t����ġ�� " << user->pokemonVec[selectPokemon - 1]->getCurExperiencePoint() << " / " << user->pokemonVec[selectPokemon - 1]->getMaxExperiencePoint() << "��(��) �Ǿ���." << endl; // ���� ����ġ / �� ����ġ
					}
					Sleep(1000);
					user->pokemonVec[selectPokemon - 1]->setMaxHealthPoint(user->pokemonVec[selectPokemon - 1]->getMaxHealthPoint() + (user->pokemonVec[selectPokemon - 1]->getCurExperiencePoint() * 10)); //���ϸ� ����ġ�� ���� ü�� ����
					pokemon->setCurHealthPoint(pokemon->getMaxHealthPoint()); //�����ϸ� ü���� �ʱ�ȭ ���ش�
					user->pokemonVec[selectPokemon - 1]->mapIter = user->pokemonVec[selectPokemon - 1]->_skillMap.begin(); // ��ų�� ���� ���� ���ͷ�����
					for (user->pokemonVec[selectPokemon - 1]->mapIter; user->pokemonVec[selectPokemon - 1]->mapIter != user->pokemonVec[selectPokemon - 1]->_skillMap.end(); user->pokemonVec[selectPokemon - 1]->mapIter++)
					{
						user->pokemonVec[selectPokemon - 1]->mapIter->second->setDamage(user->pokemonVec[selectPokemon - 1]->mapIter->second->getDamage() + 1); //����ġ�� ���� ��ų������ ���
						user->pokemonVec[selectPokemon - 1]->mapIter->second->setCurSkillPoint(user->pokemonVec[selectPokemon - 1]->mapIter->second->getMaxSkillPoint());//���ϸ� ��Ʋ�� ������ ��ų����Ʈ�� �ʱ�ȭ �����ش�
					}
					break;
				}
				else //�����ϸ��� ���� �ʾ������
				{
					cout << "\t" << damage << "��ŭ ���ظ� �־���" << endl;
					cout << "\t" << pokemon->getName() << "\t" << pokemon->getCurHealthPoint() << " / " << pokemon->getMaxHealthPoint() << endl; // �� ���ϸ��� ����ü�� / �� ü��
					Sleep(1500);
					damage = pokemon->getSkillMap().find(randomSkillSelect)->second->getDamage(); // �������� �� ���ϸ��� �������� �ȴ�.
					cout << "\t" << pokemon->getName() << " : " << pokemon->getSkillMap().find(randomSkillSelect)->second->getName() << endl; // �� ���ϸ��� ��ų�̸� ���
					cout << "\t" << damage << "��ŭ ���ظ� �޾Ҵ�" << endl;
					Sleep(1500);
					user->pokemonVec[selectPokemon - 1]->setCurHealthPoint(user->pokemonVec[selectPokemon - 1]->getCurHealthPoint() - damage); // ���ϸ��� ü�¿��� ��������ŭ ���ش�
					if (user->pokemonVec[selectPokemon - 1]->getCurHealthPoint() <= 0) // ���ϸ��� �׾��� ���
					{
						cout << "\t" << user->pokemonVec[selectPokemon - 1]->getName() << "��(��) ��������" << endl;
						user->pokemonVec[selectPokemon - 1]->setCurHealthPoint(0); //���� ü���� 0�� �ȴ�
						for (user->pokemonVec[selectPokemon - 1]->mapIter; user->pokemonVec[selectPokemon - 1]->mapIter != user->pokemonVec[selectPokemon - 1]->_skillMap.end(); user->pokemonVec[selectPokemon - 1]->mapIter++)
						{
							user->pokemonVec[selectPokemon - 1]->mapIter->second->setCurSkillPoint(user->pokemonVec[selectPokemon - 1]->mapIter->second->getMaxSkillPoint());//���ϸ� ��Ʋ�� ������ ��ų����Ʈ�� �ʱ�ȭ �����ش�
						}
						Sleep(100);
						system("cls");
						pokemon->showImage();
						pokemonBattle(attribute, map, pokemonSelect, pokemon);
					}
				}
			}
		}
	}
	travel(); //�ʼ������� �̵�
}

void mainGame::pokemonSkillCheck(int selectPokemon)
{
	cout << endl;
	cout << "\t" << pokemon->getName() << "\t" << pokemon->getCurHealthPoint() << " / " << pokemon->getMaxHealthPoint() << endl; // �� ���ϸ��� ����ü�� / �� ü��
	cout << "\t===========================================================" << endl;
	cout << "\t" << user->pokemonVec[selectPokemon]->getName() << "ü��\t" << user->pokemonVec[selectPokemon]->getCurHealthPoint() << " / " << user->pokemonVec[selectPokemon]->getMaxHealthPoint() << endl; //���� ü�� / ��ü��
	user->pokemonVec[selectPokemon]->mapIter = user->pokemonVec[selectPokemon]->_skillMap.begin(); // ��ų�� ���� ���� ���ͷ�����
	cout << "\t===========================================================" << endl;
	for (user->pokemonVec[selectPokemon]->mapIter; user->pokemonVec[selectPokemon]->mapIter != user->pokemonVec[selectPokemon]->_skillMap.end(); user->pokemonVec[selectPokemon]->mapIter++)
	{
		cout << "\t" << user->pokemonVec[selectPokemon]->mapIter->first << ") " << user->pokemonVec[selectPokemon]->mapIter->second->getName() << "\t";
	} //��ų�� ǥ�����ֱ� ���� for��
	cout << endl;
	user->pokemonVec[selectPokemon]->mapIter = user->pokemonVec[selectPokemon]->_skillMap.begin(); // ���ͷ����͸� �ٽþ��� ���� �ʱ�ȭ
	for (user->pokemonVec[selectPokemon]->mapIter; user->pokemonVec[selectPokemon]->mapIter != user->pokemonVec[selectPokemon]->_skillMap.end(); user->pokemonVec[selectPokemon]->mapIter++)
	{
		cout << "\t   " << user->pokemonVec[selectPokemon]->mapIter->second->getCurSkillPoint() << " / " << user->pokemonVec[selectPokemon]->mapIter->second->getMaxSkillPoint() << "\t";
	}//��ų����Ʈ ǥ�� ���� ��ų����Ʈ / �� ��ų����Ʈ
}

void mainGame::cure()
{
	int selectpokemon = 0; // ġ���� ���ϸ� �����ϱ� ���� ����
	while (true)
	{
		system("cls");
		town->showTownImage();
		cout << "\t���ϸ� ��ȣ�� : ġ���Ͻ� ���ϸ��� �������ּ���. (�ڷ� ����� 0)" << endl;
		for (int i = 0; i < user->pokemonVec.size(); i++)
		{
			cout << "\t" << i + 1 << ". " << user->pokemonVec[i]->getName() << "\tü�� : " << user->pokemonVec[i]->getCurHealthPoint() << " / " << user->pokemonVec[i]->getMaxHealthPoint() << endl; //��� ���ϸ��� �����ش�
		}
		cout << "\t�Է����ּ��� : ";
		cin >> selectpokemon; // ���ϸ� ����
		if (selectpokemon == 0)
		{
			break;
		}
		if (selectpokemon < 0 || selectpokemon > user->pokemonVec.size())
		{
			cout << "\t����� �� ���� �Է����ּ���" << endl;
			Sleep(500);
		}
		else
		{
			if (user->pokemonVec[selectpokemon - 1]->getCurHealthPoint() == user->pokemonVec[selectpokemon - 1]->getMaxHealthPoint()) // ü���� Ǯ�� ���
			{
				cout << "\t���ϸ� ��ȣ�� : ���� �����Ͻ� ���ϸ��� ü���� ����մϴ�." << endl;
				Sleep(500);
			}
			else
			{
				int cureMoney = 20 + user->pokemonVec[selectpokemon - 1]->getMaxHealthPoint() - user->pokemonVec[selectpokemon - 1]->getCurHealthPoint(); //ġ�ᰡ���� �⺻�� 20���� �ִ�ä�� - ����ü���� ���Ѱ�
				cout << "\t" << user->pokemonVec[selectpokemon - 1]->getName() << "�� �����ϼ̱���" << endl;
				cout << "\t���ϸ� ��ȣ�� : ġ�� ������ " << cureMoney << "�Դϴ�." << endl;
				cout << "\t���� ������ �ִ� �� : " << user->getMoney() << endl;
				cout << "\t���ϸ� ��ȣ�� : ġ���Ͻðڽ��ϱ�? (Y/N) : ";
				char selectCure; // ġ������ ������ �����ϱ����� ����
				cin >> selectCure; //ġ���ϱ����� �Է�				
				if (selectCure == 'y' || selectCure == 'Y')
				{
					if (user->getMoney() < cureMoney)
					{
						cout << "\t���� �����մϴ�" << endl;
						Sleep(500);
					}
					else
					{
						user->setMoney(user->getMoney() - cureMoney); // ���� ġ�ᰡ�ݸ�ŭ ������.
						user->pokemonVec[selectpokemon - 1]->setCurHealthPoint(user->pokemonVec[selectpokemon - 1]->getMaxHealthPoint()); //���ϸ� ġ��
						cout << "\t���� " << user->getMoney() << "���ҽ��ϴ�." << endl;
						Sleep(500);
					}
				}
				else if (selectCure == 'n' || selectCure == 'N')
				{
					break;
				}
				else
				{
					cout << "\t����� �Է����ּ���." << endl;
					Sleep(500);
				}
				
			}
		}
	}
}

void mainGame::pokemonRevolution()
{
	int select;
	while (true)
	{
		system("cls");
		town->showTownImage();
		cout << "\t���ϸ� ��ȣ�� : ��ȭ�� ��ų ���ϸ��� �������ּ���. (�ڷΰ���� 0)" << endl;
		for (int i = 0; i < user->pokemonVec.size(); i++)
		{
			if (user->pokemonVec[i]->getCurExperiencePoint() == 20)//���� ����ġ�� 20�� ��� ���ϸ��� �����ش�
			{
				cout << "\t" << i + 1 << ". " << user->pokemonVec[i]->getName() << endl;
			}
		}
		cout << "\t�Է����ּ��� : ";
		cin >> select;
		if (select == 0)
		{
			break;
		}
		if (select <0 || select >user->pokemonVec.size())
		{
			cout << "\t����� �� ���� �Է����ּ���." << endl;
			Sleep(500);
		}
		else
		{
			if (user->pokemonVec[select - 1]->getCurExperiencePoint() == 20) // ��ȭ�� ������ ���
			{
				cout << "\t"<< user->getName() << " : ��?!!" << user->pokemonVec[select - 1]->getName() << "�� ���°�!!" << endl;
				Sleep(1000);
				cout << "\t" << user->pokemonVec[select - 1]->getName() << "��(��) ";
			}
			
			if (user->pokemonVec[select - 1]->getName() == "���̸�" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonCharizard* Charizard = new pokemonCharizard;
				user->pokemonVec[select - 1]->setName(Charizard->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Charizard->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for(int i = 1 ; i <4 ; i++)
				{ 
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Charizard->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Charizard->getSkillMap().find(i)->second->getDamage());
				}
				delete Charizard;
			}
			else if (user->pokemonVec[select - 1]->getName() == "�̻��ؾ�" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonVenusaur* Venusaur = new pokemonVenusaur;
				user->pokemonVec[select - 1]->setName(Venusaur->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Venusaur->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Venusaur->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Venusaur->getSkillMap().find(i)->second->getDamage());
				}
				delete Venusaur;
			}
			else if (user->pokemonVec[select - 1]->getName() == "���α�" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonBlastoise* Blastoise = new pokemonBlastoise;
				user->pokemonVec[select - 1]->setName(Blastoise->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Blastoise->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Blastoise->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Blastoise->getSkillMap().find(i)->second->getDamage());
				}
				delete Blastoise;
			}
			else if (user->pokemonVec[select - 1]->getName() == "��ī��" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonRaichu* Raichu = new pokemonRaichu;
				user->pokemonVec[select - 1]->setName(Raichu->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Raichu->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Raichu->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Raichu->getSkillMap().find(i)->second->getDamage());
				}
				delete Raichu;
			}
			else if (user->pokemonVec[select - 1]->getName() == "�����" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonElectrode* Electrode = new pokemonElectrode;
				user->pokemonVec[select - 1]->setName(Electrode->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Electrode->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Electrode->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Electrode->getSkillMap().find(i)->second->getDamage());
				}
				delete Electrode;
			}
			else if (user->pokemonVec[select - 1]->getName() == "�Ľ�����" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonNinetales* Ninetales = new pokemonNinetales;
				user->pokemonVec[select - 1]->setName(Ninetales->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Ninetales->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Ninetales->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Ninetales->getSkillMap().find(i)->second->getDamage());
				}
				delete Ninetales;
			}
			else if (user->pokemonVec[select - 1]->getName() == "�ѹ���" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonVileplume* Vileplume = new pokemonVileplume;
				user->pokemonVec[select - 1]->setName(Vileplume->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Vileplume->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Vileplume->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Vileplume->getSkillMap().find(i)->second->getDamage());
				}
				delete Vileplume;
			}
			else if (user->pokemonVec[select - 1]->getName() == "����Ĵ�" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonGolduck* Golduck = new pokemonGolduck;
				user->pokemonVec[select - 1]->setName(Golduck->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Golduck->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Golduck->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Golduck->getSkillMap().find(i)->second->getDamage());
				}
				delete Golduck;
			}
			else if (user->pokemonVec[select - 1]->getName() == "��״�" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonDugtrio* Dugtrio = new pokemonDugtrio;
				user->pokemonVec[select - 1]->setName(Dugtrio->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Dugtrio->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Dugtrio->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Dugtrio->getSkillMap().find(i)->second->getDamage());
				}
				delete Dugtrio;
			}
			else if (user->pokemonVec[select - 1]->getName() == "�𷡵���" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonSandslash* Sandslash = new pokemonSandslash;
				user->pokemonVec[select - 1]->setName(Sandslash->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Sandslash->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Sandslash->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Sandslash->getSkillMap().find(i)->second->getDamage());
				}
				delete Sandslash;
			}
			
			if (user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				cout << user->pokemonVec[select - 1]->getName() << "���� ��ȭ �Ͽ���!" << endl;
			}
			Sleep(1000);
			break;
		}
	}
}

bool mainGame::usingMonsterBall(int attribute, mapBase* map, int pokemonSelect)
{
	int sucessPercent = rand() % 10;
	float compare = (pokemon->getCurHealthPoint() / pokemon->getMaxHealthPoint()) * 100; //����ü���������� Ȯ��
	if (compare <= 10.0 && pokemon->getIsCatchPokemon() == true) // 10�ۼ�Ʈ ������ ���, �� ���ϸ��� ������ �ִ� ���
	{
		if (sucessPercent < 2) //0 1 �� ������ ��� �ȴ�
		{
			user->getPokemon(pokemon);
			user->userBall->setAmount(user->userBall->getAmount() - 1); //���ͺ��� ����ϸ� �����Ѵ�.
			Sleep(500);
			pokemon->setIsCatchPokemon(false); //�ѹ� ���ͺ� ��� �� �õ� �ϸ� �ι��� ���ϵ��� ����
			return true;
		}
		else //���� ���Ͽ��� ���
		{
			cout << "\t" << pokemon->getName() << "�� ���� ���߽��ϴ�" << endl;
			user->userBall->setAmount(user->userBall->getAmount() - 1); //���ͺ��� ����ϸ� �����Ѵ�.
			Sleep(500);
			pokemon->setIsCatchPokemon(false); //�ѹ� ���ͺ� ��� �� �õ� �ϸ� �ι��� ���ϵ��� ����
			return false;
		}
	}
	else if (compare > 10.0 && pokemon->getIsCatchPokemon() == true) //������ �ִµ� ü���� �������
	{
		cout << "\tü���� ���Ƽ� ���ͺ��� ��� �� �� �����ϴ�." << endl;
		Sleep(500);
		return false;
	}
}

void mainGame::itemPurchase()
{
	system("cls");
	town->showTownImage();
	int selectItem = 0; //������ ����
	int itemNum = 0; //������ ������ ����
	monsterBall* ball = new monsterBall; //���ͺ� ��ü ����
	pokemonFood* food = new pokemonFood; //��ȭ�� �� ��ü ����
	cout << "\t���ϸ� ��ȣ�� : � �������� �����Ͻðڽ��ϱ�?" << endl;
	cout << "\t1. " << ball->getName() << " : " << ball->getPrice() << endl; //���ͺ� �̸��� ����ǥ��
	cout << "\t2. " << food->getName() << " : " << food->getPrice() << endl; //��ȭ�� �� �̸��� ���� ǥ��
	cout << "\t���� ������ �ִ� �� : " << user->getMoney() << endl;
	cout << "\t�Է����ּ��� : ";
	cin >> selectItem;
	if (selectItem == 1)
	{
		if (user->getMoney() < ball->getPrice()) // ���� �����ϴٸ�
		{
			cout << "\t���� �����մϴ�." << endl;
			Sleep(1000);
		}
		else
		{
			while (true)
			{
				cout << "\t��� �����Ͻðڽ��ϱ�? : ";
				cin >> itemNum;
				if (itemNum < 1) //�Է� �߸�������
				{
					cout << "\t����� �� ���ڸ� �Է��ϼ���." << endl;
					Sleep(500);
				}
				else
				{
					if (user->getMoney() < (ball->getPrice()*itemNum)) //���� �����ϴٸ�
					{
						cout << "\t���� �����մϴ�." << endl;
						Sleep(500);
					}
					else
					{
						cout <<"\t" << ball->getName() << "�� " << itemNum << "�� �����߽��ϴ�" << endl;
						user->setMoney(user->getMoney() - (ball->getPrice() * itemNum)); //���� ���� ���δ�.
						user->getMonsterball(itemNum);
						Sleep(1000);
						break;
					}
				}
			}
		}
	}
	else if (selectItem == 2)
	{
		if (user->getMoney() < food->getPrice()) // ���� �����ϴٸ�
		{
			cout << "\t���� �����մϴ�." << endl;
			Sleep(1000);
		}
		else
		{
			while (true)
			{
				cout << "\t��� �����Ͻðڽ��ϱ�? : ";
				cin >> itemNum;
				if (itemNum < 1) //�Է� �߸�������
				{
					cout << "\t����� �� ���ڸ� �Է��ϼ���." << endl;
					Sleep(500);
				}
				else
				{
					if (user->getMoney() < (food->getPrice()*itemNum)) //���� �����ϴٸ�
					{
						cout << "\t���� �����մϴ�." << endl;
						Sleep(500);
					}
					else
					{
						cout << "\t" << food->getName() << "�� " << itemNum << "�� �����߽��ϴ�" << endl;
						user->setMoney(user->getMoney() - (food->getPrice() * itemNum)); //���� ���� ���δ�.
						user->getPokemonFood(itemNum);
						Sleep(1000);
						break;
					}
				}
			}
		}
	}
}

int mainGame::showMyPokemon()
{
	int select; //���ϸ� ����
	while (true)
	{
		cout << "\t���� ������ �ִ� ���ϸ�" << endl;
		for (int i = 0; i < user->pokemonVec.size(); i++) //������ ������ �ִ� ���ϸ��� ��� �����ش�
		{
			cout << "\t" << i + 1 << ". " << user->pokemonVec[i]->getName() << "\tü�� : "; //ü���� �����ش�
			cout << "\t" << user->pokemonVec[i]->getCurHealthPoint() << " / " << user->pokemonVec[i]->getMaxHealthPoint() << endl; // ����ü�� / �� ü��
		}
		cout << "\t���Ͻô� ���ϸ��� �����ϼ��� (������ ����� 0�� �����ּ���.)" << endl;
		cout << "\t�Է����ּ��� : ";
		cin >> select; // ���ϸ��� ����
		if (select <0 || select >user->pokemonVec.size()) //�Է� �߸�������
		{
			cout << "\t����� �� ���� �Է����ּ���" << endl;
			Sleep(500);
		}
		else
		{
			if (select == 0)
			{
				break;
			}
			if (user->pokemonVec.size() < select) //�߸��� ���� �Է��Ҷ�
			{
				cout << "\t����� �������ּ���" << endl;
				Sleep(500);
			}
			else
			{
				if (user->pokemonVec[select - 1]->getCurHealthPoint() == 0) // ü���� 0�ϰ�� ������ ���� ���ϰ� �Ѵ�
				{
					cout << "\tü���� " << user->pokemonVec[select - 1]->getCurHealthPoint() << "�̱� ������ �����Ҽ� �����ϴ�." << endl;
					cout << "\t���ϸ� ���Ϳ��� ġ�����ּ���." << endl;
					Sleep(1000);
					system("cls");
					pokemon->showImage();
				}
				else
				{
					cout << "\t" << user->getName() << " : " << "���� ! " << user->pokemonVec[select - 1]->getName() << endl;
					user->pokemonVec[select - 1]->setIsFighting(true);
					Sleep(1000);
					break;
				}
			}
		}
	}
	return select;
}


// ���ϸ� ���Ͱ��ٰ� �κ��丮 ���� ���� ������ �־��µ� ������� ������ �˼� ����;;