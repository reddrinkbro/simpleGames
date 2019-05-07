#include "pokemonBlastoise.h"



pokemonBlastoise::pokemonBlastoise()
{
	setCurHealthPoint(200);
	setMaxHealthPoint(200);
	setCurExperiencePoint(0);
	setMaxExperiencePoint(20);
	setIsCatchPokemon(false); //������ �ִ���
	setIsRevolution(true); //��ȭ ��������
	setName("�źϿ�");

	//ù��° ��ų
	skill* firstSkill = new skill;
	firstSkill->setName("������");
	firstSkill->setDamage(35);
	firstSkill->setCurSkillPoint(50);
	firstSkill->setMaxSkillPoint(50);
	firstSkill->setUsingSkillPoint(15);
	//�ι�° ��ų
	skill* secondSkill = new skill;
	secondSkill->setName("�õ���");
	secondSkill->setDamage(40);
	secondSkill->setCurSkillPoint(30);
	secondSkill->setMaxSkillPoint(30);
	secondSkill->setUsingSkillPoint(12);
	//������ ��ų
	skill* thirdSkill = new skill;
	thirdSkill->setName("���̵������");
	thirdSkill->setDamage(45);
	thirdSkill->setCurSkillPoint(40);
	thirdSkill->setMaxSkillPoint(40);
	thirdSkill->setUsingSkillPoint(20);

	_skillMap.insert(make_pair(1, firstSkill));
	_skillMap.insert(make_pair(2, secondSkill));
	_skillMap.insert(make_pair(3, thirdSkill));
}


pokemonBlastoise::~pokemonBlastoise()
{
}

void pokemonBlastoise::showImage()
{
	cout << "�����������������������������������������" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                           ���                                             ��" << endl;
	cout << "��                         ��Ƣơ�                                           ��" << endl;
	cout << "��                         ��ƢƢơ�                ���                     ��" << endl;
	cout << "��                         ��ƢƢƢơ�      �����Ƣơ�                   ��" << endl;
	cout << "��                           ��Ƣ�    ����    ��ơ��ơ�                 ��" << endl;
	cout << "��                         ��  ��              ��Ƣơ��ơ�                 ��" << endl;
	cout << "��                       ��      ���  ����  �ƢƢƢƢơ�                   ��" << endl;
	cout << "��                       ��          ��    ��  �ƢƢƢơ�  ��                 ��" << endl;
	cout << "��                     ��                  ���  �Ƣ�    ��                   ��" << endl;
	cout << "��                   ���          ��      ��Ƣ�        ��                   ��" << endl;
	cout << "��                 ��    ��      ���      ���Ƣ�        ��                 ��" << endl;
	cout << "��                 ��  ��      ��ˡ�      ���    ��      ��                 ��" << endl;
	cout << "��               ��  ��              �Ǣǡ���      �Ƣ�    ��               ��" << endl;
	cout << "��               ���  ��        �ǢǢǡ��  ��      ���    ��               ��" << endl;
	cout << "��                 ���  ��ǢǢǢǡ��    ��        ��Ƣ�  ����           ��" << endl;
	cout << "��                         �����      ��        ��  ��ơ�    ��           ��" << endl;
	cout << "��                       ��  ��          ���      ��  ��Ƣơ��             ��" << endl;
	cout << "��                       ��    ��        ������      ��ơ�               ��" << endl;
	cout << "��                         ��    ��        ����          ��                 ��" << endl;
	cout << "��                           �����        ��            ��                 ��" << endl;
	cout << "��                                   ���      ��        ��                   ��" << endl;
	cout << "��                                       ������    ���                   ��" << endl;
	cout << "��                                               �����                     ��" << endl;
	cout << "��                                                 ���                       ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "�����������������������������������������" << endl;
}