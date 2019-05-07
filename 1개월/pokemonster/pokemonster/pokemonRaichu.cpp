#include "pokemonRaichu.h"



pokemonRaichu::pokemonRaichu()
{
	setCurHealthPoint(200);
	setMaxHealthPoint(200);
	setCurExperiencePoint(0);
	setMaxExperiencePoint(20);
	setIsCatchPokemon(false); //������ �ִ���
	setIsRevolution(true); //��ȭ ���� ����
	setName("������");
	//ù��° ��ų
	skill* firstSkill = new skill;
	firstSkill->setName("������ġ");
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
	thirdSkill->setName("100����Ʈ");
	thirdSkill->setDamage(45);
	thirdSkill->setCurSkillPoint(40);
	thirdSkill->setMaxSkillPoint(40);
	thirdSkill->setUsingSkillPoint(20);

	_skillMap.insert(make_pair(1, firstSkill));
	_skillMap.insert(make_pair(2, secondSkill));
	_skillMap.insert(make_pair(3, thirdSkill));
}


pokemonRaichu::~pokemonRaichu()
{
}

void pokemonRaichu::showImage()
{
	cout << "�����������������������������������������" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                            ����                                          ��" << endl;
	cout << "��                          ��ǡ�            �����                        ��" << endl;
	cout << "��                        ��Ǣǡ�        ���Ǣǡ�          ��              ��" << endl;
	cout << "��                        ��ǡ�        ��Ǣ̢̢�            ��              ��" << endl;
	cout << "��                        ��ǡ�����Ǣ̢̢̢̡�        ��̡�            ��" << endl;
	cout << "��                      ��          ��ǢǢ̢̡���        ��̡�            ��" << endl;
	cout << "��                    ��              �ǢǢ̡�    ��        ��̡��          ��" << endl;
	cout << "��                  ���                  ���              ��̢̡�          ��" << endl;
	cout << "��                  ���                    ��              ��̢̡�          ��" << endl;
	cout << "��                  ��        ���            ��      ����̢̢̡�          ��" << endl;
	cout << "��                    ��      ���̢�        ��    ��  �̢̢̡��            ��" << endl;
	cout << "��                      ��        �̢�          ��  ����̢̡�              ��" << endl;
	cout << "��                    ��                        ��  ��    ��̡�              ��" << endl;
	cout << "��                      �����            ��  ��  ����  ��                ��" << endl;
	cout << "��                          �����  ��    ��  ��      ���                  ��" << endl;
	cout << "��                          �������  ��    ����    ��                  ��" << endl;
	cout << "��                        ��  �������      ��  �����                  ��" << endl;
	cout << "��                        ��������      ��                              ��" << endl;
	cout << "��                                  ����  ���                              ��" << endl;
	cout << "��                                    ��      ��                              ��" << endl;
	cout << "��                                      ����                                ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "�����������������������������������������" << endl;
}