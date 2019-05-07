#include "pokemonElectrode.h"



pokemonElectrode::pokemonElectrode()
{
	setCurHealthPoint(200);
	setMaxHealthPoint(200);
	setCurExperiencePoint(0);
	setMaxExperiencePoint(20);
	setIsCatchPokemon(false); //������ �ִ���
	setIsRevolution(true); //��ȭ ���� ����
	setName("�պ�");
	//ù��° ��ų
	skill* firstSkill = new skill;
	firstSkill->setName("�Ҵк�");
	firstSkill->setDamage(30);
	firstSkill->setCurSkillPoint(50);
	firstSkill->setMaxSkillPoint(50);
	firstSkill->setUsingSkillPoint(15);
	//�ι�° ��ų
	skill* secondSkill = new skill;
	secondSkill->setName("�����ڼ���");
	secondSkill->setDamage(40);
	secondSkill->setCurSkillPoint(30);
	secondSkill->setMaxSkillPoint(30);
	secondSkill->setUsingSkillPoint(12);
	//������ ��ų
	skill* thirdSkill = new skill;
	thirdSkill->setName("������");
	thirdSkill->setDamage(45);
	thirdSkill->setCurSkillPoint(40);
	thirdSkill->setMaxSkillPoint(40);
	thirdSkill->setUsingSkillPoint(20);

	_skillMap.insert(make_pair(1, firstSkill));
	_skillMap.insert(make_pair(2, secondSkill));
	_skillMap.insert(make_pair(3, thirdSkill));
}


pokemonElectrode::~pokemonElectrode()
{
}

void pokemonElectrode::showImage()
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
	cout << "��                                 �������                               ��" << endl;
	cout << "��                             ����        ����                           ��" << endl;
	cout << "��                           ���                ���                         ��" << endl;
	cout << "��                         ���                    ���                       ��" << endl;
	cout << "��                       ��� ��            ��       ���                     ��" << endl;
	cout << "��                       ��     ��        ��           ��                     ��" << endl;
	cout << "��                       ��       ��    ��             ��                     ��" << endl;
	cout << "��                       ��    ��         ��   ������                     ��" << endl;
	cout << "��                       ��             �����       ��                     ��" << endl;
	cout << "��                       ���������            ���                     ��" << endl;
	cout << "��                         ���              ��    ���                       ��" << endl;
	cout << "��                           ���   ������   ���                         ��" << endl;
	cout << "��                             ���            ���                           ��" << endl;
	cout << "��                                 �������                               ��" << endl;
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
