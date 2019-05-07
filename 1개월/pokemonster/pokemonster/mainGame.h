#pragma once
#include "player.h"
#include "mapElectronic.h"
#include "mapForest.h"
#include "mapLake.h"
#include "mapStone.h"
#include "mapVolcano.h"

#include <Windows.h>
class mainGame
{
private:
	player* user;
	pokemonBase* pokemon;
	mapBase* town;
public:
	player* getPlayer() { return user; }

	void firstPokemon(); // 포켓몬 선택
	void selectMode(); //마을에서 플레이어가 할 행동
	void travleMessage();
	void travel(); //여행가기
	void goToPokemonCenter(); //포켓몬 센터가기
	void yourInventory();//인벤토리 보기
	void yourPokemon(); //포켓몬 보기
	void pokemonBattleReady(int attribute ,mapBase* map, int pokemonSelect); //포켓몬 배틀전 선택지
	bool pitch(int attribute, mapBase* map, int pokemonSelect); //몬스터볼 던지기
	void pokemonBattle(int attribute, mapBase* map ,int pokemonSelect , pokemonBase* pokemon); //포켓몬 배틀
	void cure(); //포켓몬 치료
	void pokemonRevolution(); //포켓몬 진화
	bool usingMonsterBall(int attribute, mapBase* map, int pokemonSelect); //몬스터볼 사용하기
	void itemPurchase(); //아이템 구매
	void pokemonSkillCheck(int select); //포켓몬 배틀시 포켓몬 스킬 보여주기
	int showMyPokemon(); // 배틀시 포켓몬 보여주기
	mainGame();
	~mainGame();
};

