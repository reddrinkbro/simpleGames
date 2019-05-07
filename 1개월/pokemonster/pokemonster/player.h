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
	char* _name; //플레이어 이름
	int _money;//플레이어가 가진 돈	
	bool _isFightState; //싸우는지 안싸우는지
	bool _playerWin; //승리조건
public:
	monsterBall* userBall;
	pokemonFood* userFood;
	vector<itemBase*> inventory; //유저 인벤토리

	char* getName() { return _name; }
	int getMoney() { return _money; }
	bool getIsFightState() { return _isFightState; }
	bool getIsPlayerWin() { return _playerWin; }

	void setName(char* name) { _name = name; }
	void setMoney(int money) { _money = money; }
	void setIsFightState(bool isFightState) { _isFightState = isFightState; }
	void setPlayerWin(bool playerWin) { _playerWin = playerWin; }


	void yourPokemon(); //포켓몬 확인하기
	void getMonsterball(int num); //몬스터볼 얻는 함수
	void getPokemonFood(int num); //진화의 돌을 얻는 함수
	void userInventory(); //인벤토리 확인 함수
	void userWin(); //승리하기 위한 함수
	void usingPokemonFood();

	vector<pokemonBase*> pokemonVec; //플레이어의 포켓몬 벡터
	vector<pokemonBase*>::iterator userIter;
	vector<pokemonBase*>* getPokemon(pokemonBase* pokemon); //포켓몬 획득시 포켓몬 클래스를 반환 하는 함수
	player();
	~player();
};

