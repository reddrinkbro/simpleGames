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

	void firstPokemon(); // ���ϸ� ����
	void selectMode(); //�������� �÷��̾ �� �ൿ
	void travleMessage();
	void travel(); //���డ��
	void goToPokemonCenter(); //���ϸ� ���Ͱ���
	void yourInventory();//�κ��丮 ����
	void yourPokemon(); //���ϸ� ����
	void pokemonBattleReady(int attribute ,mapBase* map, int pokemonSelect); //���ϸ� ��Ʋ�� ������
	bool pitch(int attribute, mapBase* map, int pokemonSelect); //���ͺ� ������
	void pokemonBattle(int attribute, mapBase* map ,int pokemonSelect , pokemonBase* pokemon); //���ϸ� ��Ʋ
	void cure(); //���ϸ� ġ��
	void pokemonRevolution(); //���ϸ� ��ȭ
	bool usingMonsterBall(int attribute, mapBase* map, int pokemonSelect); //���ͺ� ����ϱ�
	void itemPurchase(); //������ ����
	void pokemonSkillCheck(int select); //���ϸ� ��Ʋ�� ���ϸ� ��ų �����ֱ�
	int showMyPokemon(); // ��Ʋ�� ���ϸ� �����ֱ�
	mainGame();
	~mainGame();
};

