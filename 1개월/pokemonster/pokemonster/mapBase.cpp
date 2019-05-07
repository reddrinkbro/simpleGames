#include "mapBase.h"



mapBase::mapBase()
{
	pokemonPikachu* pikachu = new pokemonPikachu; // ��ī��
	pokemonVoltorb* voltorb = new pokemonVoltorb; //�����
	pokemonElectrode* electrode = new pokemonElectrode; //�պ�
	pokemonRaichu* raichu = new pokemonRaichu; //������
	pokemonBulbasaur* blubasaur = new pokemonBulbasaur; //�̻��ؾ�
	pokemonOddish* oddish = new pokemonOddish; //�ѹ���
	pokemonVenusaur* venusaur = new pokemonVenusaur;
	pokemonVileplume* vileplume = new pokemonVileplume;
	pokemonPsyduck* psyduck = new pokemonPsyduck; //����Ĵ�
	pokemonGolduck* golduck = new pokemonGolduck; //���
	pokemonSquirtle* squirtle = new pokemonSquirtle; //������
	pokemonBlastoise* blastoise = new pokemonBlastoise;
	pokemonDiglett* diglett = new pokemonDiglett; //��״�
	pokemonDugtrio* dugtrio = new pokemonDugtrio; //��Ʈ����
	pokemonSandshrew* sandshrew = new pokemonSandshrew; //�𷡵���
	pokemonSandslash* sandslash = new pokemonSandslash; //����
	pokemonCharmander* charmander = new pokemonCharmander; //���̸�
	pokemonCharizard* charizard = new pokemonCharizard; //���ڸ�
	pokemonVulpix* vulpix = new pokemonVulpix; //�Ľ�����
	pokemonNinetales* ninetales = new pokemonNinetales;//��������
		
	pokemonVec.push_back(pikachu);
	pokemonVec.push_back(voltorb);
	pokemonVec.push_back(electrode);
	pokemonVec.push_back(raichu);
	pokemonVec.push_back(blubasaur);
	pokemonVec.push_back(oddish);
	pokemonVec.push_back(venusaur);
	pokemonVec.push_back(vileplume);
	pokemonVec.push_back(charmander);
	pokemonVec.push_back(vulpix);
	pokemonVec.push_back(golduck);
	pokemonVec.push_back(blastoise);
	pokemonVec.push_back(diglett);
	pokemonVec.push_back(sandshrew);
	pokemonVec.push_back(dugtrio);
	pokemonVec.push_back(sandslash);
	pokemonVec.push_back(psyduck);
	pokemonVec.push_back(squirtle);
	pokemonVec.push_back(charizard);
	pokemonVec.push_back(ninetales);
}


mapBase::~mapBase()
{
}

pokemonBase* mapBase::selectPokemon(int attribute, int pokemonSelect)
{
	//�����Ƽ
	if (attribute == 1)
	{
		pokemonVec[pokemonSelect]->showImage();
		cout << "\t" <<pokemonVec[pokemonSelect]->getName() << "��(��) ��Ÿ����" << endl;
		return pokemonVec[pokemonSelect];
	}
	//������Ʈ
	else if (attribute == 2)
	{
		pokemonSelect += 4;
		pokemonVec[pokemonSelect]->showImage();
		cout << "\t" << pokemonVec[pokemonSelect]->getName() << "��(��) ��Ÿ����" << endl;
		return pokemonVec[pokemonSelect];
	}
	//�����̳�
	else if (attribute == 3)
	{
		pokemonSelect +=+ 8;
		pokemonVec[pokemonSelect]->showImage();
		cout << "\t" << pokemonVec[pokemonSelect]->getName() << "��(��) ��Ÿ����" << endl;
		return pokemonVec[pokemonSelect];
	}
	//���渶��ƾ
	else if (attribute == 4)
	{
		pokemonSelect += 12;
		pokemonVec[pokemonSelect]->showImage();
		cout << "\t" << pokemonVec[pokemonSelect]->getName() << "��(��) ��Ÿ����" << endl;
		return pokemonVec[pokemonSelect];
	}
	//����ŷ��
	else if (attribute == 5)
	{
		pokemonSelect += 16;
		pokemonVec[pokemonSelect]->showImage();
		cout << "\t" << pokemonVec[pokemonSelect]->getName() << "��(��) ��Ÿ����" << endl;
		return pokemonVec[pokemonSelect];
	}
}

void mapBase::showTownImage()
{
	cout << "�����������������������������������������" << endl;
	cout << "��                          ��                                                ��" << endl;
	cout << "��          ��             ���                                               ��" << endl;
	cout << "��         ���           ����                       ��                     ��" << endl;
	cout << "��        ����        ������                    ���                    ��" << endl;
	cout << "��      ������       �����                    ����                   ��" << endl;
	cout << "��       �����        ��  ���                  ������                 ��" << endl;
	cout << "��       ��  ���        �ᤱ���                   �����                  ��" << endl;
	cout << "��    �� �ᤱ���        ��ߡ��                   ��  ���                  ��" << endl;
	cout << "��   ����ߡ��                                   �ᤱ���                  ��" << endl;
	cout << "��  ����          ������                      ��ߡ��                  ��" << endl;
	cout << "�������       ��   ��   ��                                               ��" << endl;
	cout << "�� �����        �������                                               ��" << endl;
	cout << "�� ��  ���   ����  ����  ����              ��ߡ���ߡ�              ��" << endl;
	cout << "�� �ᤱ���   ��    ��ߣߣߡ�    ��              ��   ���� ��              ��" << endl;
	cout << "�� ��ߡ��   ��        ��        ��              ��   �ᦫ�� ��              ��" << endl;
	cout << "��            ��    ���������    ��              ��   ���� ��              ��" << endl;
	cout << "��            ��      ����      ��            ����������            ��" << endl;
	cout << "��            ��                  ��            ��              ��            ��" << endl;
	cout << "��            ������������            ��    ������  ��            ��" << endl;
	cout << "��       �����������������       ��    �ᤱ���  ��            ��" << endl;
	cout << "��         ��   ��  ��   ��   ��  �� ��         �����ߡ����            ��" << endl;
	cout << "��         ��                        ��                                       ��" << endl;
	cout << "��         ��       ������       ��                                       ��" << endl;
	cout << "��         ��       ��  ��  ��       ��                                       ��" << endl;
	cout << "��         ��       ��  ��  ��       ��                                       ��" << endl;
	cout << "��         ��       ��  ��  ��       ��                                       ��" << endl;
	cout << "��         ��       ������       ��                                       ��" << endl;
	cout << "��         ��                        ��                                       ��" << endl;
	cout << "��       �����������������                                     ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "�����������������������������������������" << endl;
}

void mapBase::showBlankImage()
{
	cout << "�����������������������������������������" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "�����������������������������������������" << endl;
}