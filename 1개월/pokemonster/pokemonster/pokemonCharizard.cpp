#include "pokemonCharizard.h"



pokemonCharizard::pokemonCharizard()
{
	setCurHealthPoint(200);
	setMaxHealthPoint(200);
	setCurExperiencePoint(0);
	setMaxExperiencePoint(20);
	setIsCatchPokemon(false); //������ �ִ���
	setIsRevolution(true); //��ȭ ���� ����
	setName("���ڸ�");
	//ù��° ��ų
	skill* firstSkill = new skill;
	firstSkill->setName("��ǳ");
	firstSkill->setDamage(35);
	firstSkill->setCurSkillPoint(50);
	firstSkill->setMaxSkillPoint(50);
	firstSkill->setUsingSkillPoint(15);
	//�ι�° ��ų
	skill* secondSkill = new skill;
	secondSkill->setName("�Ҳɼ���");
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


pokemonCharizard::~pokemonCharizard()
{
}

void pokemonCharizard::showImage()
{
	cout << "�����������������������������������������" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                      ������            ��" << endl;
	cout << "��                                                  ���ǢǢǢǢǡ�          ��" << endl;
	cout << "��                      ���          ����      ��ǢǢǢǢƢƢǢǡ�        ��" << endl;
	cout << "��                    ��  ��        ��      �������ǢǢǢƢ�  ��        ��" << endl;
	cout << "��                    ��  ��      ���        ��      ���Ǣǡ�      ��      ��" << endl;
	cout << "��                  ��  ��      ��  ���      ��  �Ƣ�    ���  ��    ��      ��" << endl;
	cout << "��                  ��  ��    ��    ��  ��      ��ƢƢƢ�    ���      ��    ��" << endl;
	cout << "��                ��  �����    ��      ��  ����ƢƢƢƢ�    ��  ��      ��" << endl;
	cout << "��                ��      ��    ����    ���    ���ƢƢƢƢƢ�  ��        ��" << endl;
	cout << "��              ��                    ���        ��ơ�ƢƢƢƢƢ�  ��      ��" << endl;
	cout << "��              ��                                  �ƢƢƢƢơ����        ��" << endl;
	cout << "��              ��        ��    ���                  ��  ���      ��        ��" << endl;
	cout << "��            ��        ���    ��  ��        ��  ��  ��      ��  ��          ��" << endl;
	cout << "��          ��        ����  ��      ��    ����    ��      ��  ��          ��" << endl;
	cout << "��        ��              ���      ��  ���        ��          ���          ��" << endl;
	cout << "��          ���      ���          ��    ���    ��            ��            ��" << endl;
	cout << "��              ����                ��    ����  ��          ��            ��" << endl;
	cout << "��                                  �����      ��          ��              ��" << endl;
	cout << "��                                  �������  ��          ��              ��" << endl;
	cout << "��                                              ����      ��                ��" << endl;
	cout << "��                                                ���  ��  ��                ��" << endl;
	cout << "��                                                  �����                  ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "�����������������������������������������" << endl;
}