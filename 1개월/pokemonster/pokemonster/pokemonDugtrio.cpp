#include "pokemonDugtrio.h"



pokemonDugtrio::pokemonDugtrio()
{
	setCurHealthPoint(200);
	setMaxHealthPoint(200);
	setCurExperiencePoint(0);
	setMaxExperiencePoint(20);
	setIsCatchPokemon(false); //������ �ִ���
	setIsRevolution(true); //��ȭ ��������
	setName("��Ʈ����");
	//ù��° ��ų
	skill* firstSkill = new skill;
	firstSkill->setName("����Ѹ���");
	firstSkill->setDamage(35);
	firstSkill->setCurSkillPoint(50);
	firstSkill->setMaxSkillPoint(50);
	firstSkill->setUsingSkillPoint(15);
	//�ι�° ��ų
	skill* secondSkill = new skill;
	secondSkill->setName("������");
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


pokemonDugtrio::~pokemonDugtrio()
{
}

void pokemonDugtrio::showImage()
{
	cout << "�����������������������������������������" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                   ����                                   ��" << endl;
	cout << "��                                 ��      ��                                 ��" << endl;
	cout << "��                               ��          ��                               ��" << endl;
	cout << "��                               ���  ��    ��                               ��" << endl;
	cout << "��                               ���  ��    ��                               ��" << endl;
	cout << "��                               ��ˢ�      �����                         ��" << endl;
	cout << "��                               ��          ��      ��                       ��" << endl;
	cout << "��                             ����      ��          ��                     ��" << endl;
	cout << "��                           ��      ��    ���  ��    ��                     ��" << endl;
	cout << "��                         ��          ��  ���  ��    ��                     ��" << endl;
	cout << "��                       ����  ��    ����ˢ�      ��                     ��" << endl;
	cout << "��                       ����  ��    ��  ��          ��                     ��" << endl;
	cout << "��                     ����ˢ�      ��  ��    ��    ���                   ��" << endl;
	cout << "��                     ��  ��        ���  ����  �����                   ��" << endl;
	cout << "��                     ��  ������          ��  ��  ���                   ��" << endl;
	cout << "��                       ��          ���  ��    ��  ���                     ��" << endl;
	cout << "��                         ���          ��      ����                       ��" << endl;
	cout << "��                             ����������                             ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "�����������������������������������������" << endl;
}