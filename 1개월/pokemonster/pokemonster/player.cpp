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
	cout << "\t" <<pokemon->getName() << "을 얻었다!!" << endl;
	pokemonVec.push_back(pokemon); //포켓몬을 얻었을떄 벡터에 집어 넣는다
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
	userBall->setAmount(userBall->getAmount() + num); //포켓몬볼 얻기
}

void player::getPokemonFood(int num)
{
	userFood->setAmount(userFood->getAmount() + num);  //포켓몬 먹이얻기
}

void player::userInventory()
{
	cout << "\t============================" << endl;
	cout << "\t인 벤 토 리" << endl;
	cout << "\t============================" << endl;
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i]->getAmount() != 0)
		{
			cout << "\t" <<inventory[i]->getName() << "\t" << inventory[i]->getAmount() << "개" << endl;
			cout << "\t============================" << endl;
		}
	}
	cout <<"\t현재 가지고 있는 골드 : "<< getMoney() << endl;
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
	if (condition == 6)//포켓몬 6마리 모았고 모두 진화했을경우 게임 끝
	{
		setPlayerWin(true);
	}
}

void player::usingPokemonFood()
{
	char select;
	cout << "\t포켓몬 먹이를 사용하시겠습니까?(Y/N)" << endl;
	cout << "\t현재 가지고 있는 포켓몬 먹이 : " << userFood->getAmount() << "개" << endl;
	cout << "\t입력하세요 : ";
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
					cout << "\t포켓몬 먹이를 사용했습니다." << endl;
					pokemonVec[i]->setCurHealthPoint(pokemonVec[i]->getCurHealthPoint() + userFood->getHealing()); //포켓몬 체력을 올려준다
					cout << "\t" <<userFood->getHealing() << "만큼 회복했습니다." << endl;
				}
			}
		}
		else
		{
			cout << "\t포켓몬 먹이가 없습니다." << endl;
		}
	}	
}