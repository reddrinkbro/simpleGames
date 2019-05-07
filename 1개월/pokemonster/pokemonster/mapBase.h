#pragma once
#include "pokemonElectrode.h" //�պ�
#include "pokemonPikachu.h" //��ī��
#include "pokemonRaichu.h" //������
#include "pokemonVoltorb.h" //�����
#include "pokemonBulbasaur.h" //�̻��ؾ�
#include "pokemonOddish.h" // �ѹ���
#include "pokemonVenusaur.h"// �̻��ز�
#include "pokemonVileplume.h" // ���÷��þ�
#include "pokemonGolduck.h" //���
#include "pokemonPsyduck.h" //����Ĵ�
#include "pokemonBlastoise.h" //�źϿ�
#include "pokemonSquirtle.h" //���α�
#include "pokemonDiglett.h" //��״�
#include "pokemonDugtrio.h" //��Ʈ����
#include "pokemonSandshrew.h" //�𷡵���
#include "pokemonSandslash.h" //����
#include "pokemonCharizard.h" //���ڸ�
#include "pokemonCharmander.h" //���̸�
#include "pokemonNinetales.h" //��������
#include "pokemonVulpix.h" //�Ľ�����

#include <iostream>
#include <vector>
#include <time.h>
#include <Windows.h>

using namespace std;

class mapBase
{
private :
	char* _name;
	vector<pokemonBase*> pokemonVec; // ���ϸ� ����
public:
	char* getName() { return _name; }
	void setName(char* name) { _name = name; }
	pokemonBase* selectPokemon(int attribute, int pokemonSelect);
	void showTownImage();
	void showBlankImage();
	mapBase();
	~mapBase();
};

