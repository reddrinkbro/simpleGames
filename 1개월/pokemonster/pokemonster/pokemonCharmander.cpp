#include "pokemonCharmander.h"



pokemonCharmander::pokemonCharmander()
{
	setCurHealthPoint(50);
	setMaxHealthPoint(50);
	setCurExperiencePoint(0);
	setMaxExperiencePoint(20);
	setIsCatchPokemon(true); //������ �ִ���
	setIsRevolution(false); //��ȭ ����
	setName("���̸�");
	//ù��° ��ų
	skill* firstSkill = new skill;
	firstSkill->setName("�Ҳɾ���");
	firstSkill->setDamage(10);
	firstSkill->setCurSkillPoint(50);
	firstSkill->setMaxSkillPoint(50);
	firstSkill->setUsingSkillPoint(15);
	//�ι�° ��ų
	skill* secondSkill = new skill;
	secondSkill->setName("ȭ�����");
	secondSkill->setDamage(12);
	secondSkill->setCurSkillPoint(30);
	secondSkill->setMaxSkillPoint(30);
	secondSkill->setUsingSkillPoint(12);
	//������ ��ų
	skill* thirdSkill = new skill;
	thirdSkill->setName("ȸ�����Ҳ�");
	thirdSkill->setDamage(15);
	thirdSkill->setCurSkillPoint(40);
	thirdSkill->setMaxSkillPoint(40);
	thirdSkill->setUsingSkillPoint(20);

	_skillMap.insert(make_pair(1, firstSkill));
	_skillMap.insert(make_pair(2, secondSkill));
	_skillMap.insert(make_pair(3, thirdSkill));
}


pokemonCharmander::~pokemonCharmander()
{
}

void pokemonCharmander::showImage()
{
	cout << "�����������������������������������������" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                      ��                    ��" << endl;
	cout << "��                          ������                ��  ��                  ��" << endl;
	cout << "��                         ��        ��               ��  ��                  ��" << endl;
	cout << "��                        ��          ��            ��      ��                ��" << endl;
	cout << "��                      ��              ��          ����  ��                ��" << endl;
	cout << "��                    ��      ���      ��          ����  ��                ��" << endl;
	cout << "��                  ��        ���        ��          ��    ��                ��" << endl;
	cout << "��                  ��        ���        ��          ��  ���                ��" << endl;
	cout << "��                    ��                    ��        ��  ��                  ��" << endl;
	cout << "��                     ���                   ��    ��    ��                  ��" << endl;
	cout << "��                        ����     ��       �����   ��                   ��" << endl;
	cout << "��                          ���� ��                    ��                   ��" << endl;
	cout << "��                          ����� ���               ��                    ��" << endl;
	cout << "��                          ������                ��                      ��" << endl;
	cout << "��                        ��  �����        �����                        ��" << endl;
	cout << "��                      ��    ����          �����                        ��" << endl;
	cout << "��                        ���      ������                                ��" << endl;
	cout << "��                                  ��      ��                                ��" << endl;
	cout << "��                                  ��      ��                                ��" << endl;
	cout << "��                                    ����                                  ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "�����������������������������������������" << endl;
}
