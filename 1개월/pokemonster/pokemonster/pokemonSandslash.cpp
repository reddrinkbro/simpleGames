#include "pokemonSandslash.h"



pokemonSandslash::pokemonSandslash()
{
	setCurHealthPoint(200);
	setMaxHealthPoint(200);
	setCurExperiencePoint(0);
	setMaxExperiencePoint(20);
	setIsCatchPokemon(false); //������ �ִ���
	setIsRevolution(true); //��ȭ ��������
	setName("����");
	//ù��° ��ų
	skill* firstSkill = new skill;
	firstSkill->setName("�극��ũũ��");
	firstSkill->setDamage(35);
	firstSkill->setCurSkillPoint(50);
	firstSkill->setMaxSkillPoint(50);
	firstSkill->setUsingSkillPoint(15);
	//�ι�° ��ų
	skill* secondSkill = new skill;
	secondSkill->setName("�ű״�Ʃ��");
	secondSkill->setDamage(40);
	secondSkill->setCurSkillPoint(30);
	secondSkill->setMaxSkillPoint(30);
	secondSkill->setUsingSkillPoint(12);
	//������ ��ų
	skill* thirdSkill = new skill;
	thirdSkill->setName("����");
	thirdSkill->setDamage(45);
	thirdSkill->setCurSkillPoint(40);
	thirdSkill->setMaxSkillPoint(40);
	thirdSkill->setUsingSkillPoint(20);

	_skillMap.insert(make_pair(1, firstSkill));
	_skillMap.insert(make_pair(2, secondSkill));
	_skillMap.insert(make_pair(3, thirdSkill));
}


pokemonSandslash::~pokemonSandslash()
{
}

void pokemonSandslash::showImage()
{
	cout << "�����������������������������������������" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                     ��                                     ��" << endl;
	cout << "��                         ��        ��  ��      ����                       ��" << endl;
	cout << "��                       ��  ��  ��  ��  ��  ���    ��                       ��" << endl;
	cout << "��                       ��  ���  ��    ���      ��                         ��" << endl;
	cout << "��                       ��  ����  ���    ��  ������                   ��" << endl;
	cout << "��                       ��    ��    ��    ����        ��                   ��" << endl;
	cout << "��                     ��          ��      ��          ��                     ��" << endl;
	cout << "��                     ��                ��          ��  ���                 ��" << endl;
	cout << "��                   ���              ��        ���        ��               ��" << endl;
	cout << "��                   ���                  ����      ����                 ��" << endl;
	cout << "��                   ��        ���              ����    ��                 ��" << endl;
	cout << "��                   ���    ����                    ���                   ��" << endl;
	cout << "��                     ������            ��          ���                 ��" << endl;
	cout << "��                       ������ƢƢ�  ��            ��  ����           ��" << endl;
	cout << "��                                 ��Ƣơ�        ��    ��        ��         ��" << endl;
	cout << "��                               ���ơ�ƢƢ�  ��    ��      ���           ��" << endl;
	cout << "��                             ��Ƣơ�ơ����      �����               ��" << endl;
	cout << "��                               ������Ƣ�      ��                       ��" << endl;
	cout << "��                                         ����  ���                       ��" << endl;
	cout << "��                                           ���  �ơ�                       ��" << endl;
	cout << "��                                           ��ơ�ơ�                       ��" << endl;
	cout << "��                                             ����                         ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "�����������������������������������������" << endl;
}