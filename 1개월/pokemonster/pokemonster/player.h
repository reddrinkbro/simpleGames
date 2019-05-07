#pragma once
#include "pokemonBase.h"
#include "pokemonBlastoise.h"
#include "pokemonBulbasaur.h"
#include "pokemonCharizard.h"
#include "pokemonCharmander.h"
#include "pokemonDiglett.h"
#include "pokemonDugtrio.h"
#include "pokemonElectrode.h"
#include "pokemonSandshrew.h"
#include "pokemonGolduck.h"
#include "pokemonSandslash.h"
#include "pokemonNinetales.h"
#include "pokemonOddish.h"
#include "pokemonPikachu.h"
#include "pokemonPsyduck.h"
#include "pokemonRaichu.h"
#include "pokemonSquirtle.h"
#include "pokemonVenusaur.h"
#include "pokemonVileplume.h"
#include "pokemonVoltorb.h"
#include "pokemonVulpix.h"
#include "monsterBall.h"
#include "pokemonFood.h"

#include <iostream>
#include <vector>
using namespace std;
class player
{
private:
	char* _name; //�÷��̾� �̸�
	int _money;//�÷��̾ ���� ��	
	bool _isFightState; //�ο���� �Ƚο����
	bool _playerWin; //�¸�����
public:
	monsterBall* userBall;
	pokemonFood* userFood;
	vector<itemBase*> inventory; //���� �κ��丮

	char* getName() { return _name; }
	int getMoney() { return _money; }
	bool getIsFightState() { return _isFightState; }
	bool getIsPlayerWin() { return _playerWin; }

	void setName(char* name) { _name = name; }
	void setMoney(int money) { _money = money; }
	void setIsFightState(bool isFightState) { _isFightState = isFightState; }
	void setPlayerWin(bool playerWin) { _playerWin = playerWin; }


	void yourPokemon(); //���ϸ� Ȯ���ϱ�
	void getMonsterball(int num); //���ͺ� ��� �Լ�
	void getPokemonFood(int num); //��ȭ�� ���� ��� �Լ�
	void userInventory(); //�κ��丮 Ȯ�� �Լ�
	void userWin(); //�¸��ϱ� ���� �Լ�
	void usingPokemonFood();

	vector<pokemonBase*> pokemonVec; //�÷��̾��� ���ϸ� ����
	vector<pokemonBase*>::iterator userIter;
	vector<pokemonBase*>* getPokemon(pokemonBase* pokemon); //���ϸ� ȹ��� ���ϸ� Ŭ������ ��ȯ �ϴ� �Լ�
	player();
	~player();
};

