#pragma once
#include "pokemonElectrode.h" //붐볼
#include "pokemonPikachu.h" //피카츄
#include "pokemonRaichu.h" //라이츄
#include "pokemonVoltorb.h" //찌리리공
#include "pokemonBulbasaur.h" //이상해씨
#include "pokemonOddish.h" // 뚜벅쵸
#include "pokemonVenusaur.h"// 이상해꽃
#include "pokemonVileplume.h" // 라플레시아
#include "pokemonGolduck.h" //골덕
#include "pokemonPsyduck.h" //고라파덕
#include "pokemonBlastoise.h" //거북왕
#include "pokemonSquirtle.h" //꼬부기
#include "pokemonDiglett.h" //디그다
#include "pokemonDugtrio.h" //닥트리오
#include "pokemonSandshrew.h" //모래두지
#include "pokemonSandslash.h" //고지
#include "pokemonCharizard.h" //리자몽
#include "pokemonCharmander.h" //파이리
#include "pokemonNinetales.h" //나인테일
#include "pokemonVulpix.h" //식스테일

#include <iostream>
#include <vector>
#include <time.h>
#include <Windows.h>

using namespace std;

class mapBase
{
private :
	char* _name;
	vector<pokemonBase*> pokemonVec; // 포켓몬 벡터
public:
	char* getName() { return _name; }
	void setName(char* name) { _name = name; }
	pokemonBase* selectPokemon(int attribute, int pokemonSelect);
	void showTownImage();
	void showBlankImage();
	mapBase();
	~mapBase();
};

