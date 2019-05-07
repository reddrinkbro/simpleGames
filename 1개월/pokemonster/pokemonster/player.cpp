#include "player.h"



player::player()
{	
	setMoney(0);
	setIsFightState(false);
	setPlayerWin(false);
	userBall = new monsterBall;
	userFood = new pokemonFood;
	inventory.push_back(userBall);
	inventory.push_back(userFood);
}


player::~player()
{
}


vector<pokemonBase*>* player::getPokemon(pokemonBase* pokemon) 
{
	cout << "\t" <<pokemon->getName() << "�� �����!!" << endl;
	pokemonVec.push_back(pokemon); //���ϸ��� ������� ���Ϳ� ���� �ִ´�
	return &pokemonVec;
}

void player::yourPokemon()
{
	for (int i = 0; i < pokemonVec.size(); i++)
	{
		cout << pokemonVec[i]->getName() << endl;
		cout << "================================" << endl;
	}
}

void player::getMonsterball(int num)
{
	userBall->setAmount(userBall->getAmount() + num); //���ϸ� ���
}

void player::getPokemonFood(int num)
{
	userFood->setAmount(userFood->getAmount() + num);  //���ϸ� ���̾��
}

void player::userInventory()
{
	cout << "\t============================" << endl;
	cout << "\t�� �� �� ��" << endl;
	cout << "\t============================" << endl;
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i]->getAmount() != 0)
		{
			cout << "\t" <<inventory[i]->getName() << "\t" << inventory[i]->getAmount() << "��" << endl;
			cout << "\t============================" << endl;
		}
	}
	cout <<"\t���� ������ �ִ� ��� : "<< getMoney() << endl;
}
void player::userWin()
{
	int condition = 0;
	for (int i = 0; i < pokemonVec.size(); i++)
	{
		if (pokemonVec[i]->getIsRevolution() == true)
		{
			condition++; 
		}
	}
	if (condition == 6)//���ϸ� 6���� ��Ұ� ��� ��ȭ������� ���� ��
	{
		setPlayerWin(true);
	}
}

void player::usingPokemonFood()
{
	char select;
	cout << "\t���ϸ� ���̸� ����Ͻðڽ��ϱ�?(Y/N)" << endl;
	cout << "\t���� ������ �ִ� ���ϸ� ���� : " << userFood->getAmount() << "��" << endl;
	cout << "\t�Է��ϼ��� : ";
	cin >> select;
	if (select == 'y' || select == 'Y')
	{
		if (userFood->getAmount() > 0)
		{
			for (int i = 0; i < pokemonVec.size(); i++)
			{
				if (pokemonVec[i]->getIsFighting() == true)
				{
					userFood->setAmount(userFood->getAmount() - 1);
					cout << "\t���ϸ� ���̸� ����߽��ϴ�." << endl;
					pokemonVec[i]->setCurHealthPoint(pokemonVec[i]->getCurHealthPoint() + userFood->getHealing()); //���ϸ� ü���� �÷��ش�
					cout << "\t" <<userFood->getHealing() << "��ŭ ȸ���߽��ϴ�." << endl;
				}
			}
		}
		else
		{
			cout << "\t���ϸ� ���̰� �����ϴ�." << endl;
		}
	}	
}