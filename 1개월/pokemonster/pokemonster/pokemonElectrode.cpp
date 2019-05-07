#include "pokemonElectrode.h"



pokemonElectrode::pokemonElectrode()
{
	setCurHealthPoint(200);
	setMaxHealthPoint(200);
	setCurExperiencePoint(0);
	setMaxExperiencePoint(20);
	setIsCatchPokemon(false); //잡을수 있는지
	setIsRevolution(true); //진화 형태 인지
	setName("붐볼");
	//첫번째 스킬
	skill* firstSkill = new skill;
	firstSkill->setName("소닉붐");
	firstSkill->setDamage(30);
	firstSkill->setCurSkillPoint(50);
	firstSkill->setMaxSkillPoint(50);
	firstSkill->setUsingSkillPoint(15);
	//두번째 스킬
	skill* secondSkill = new skill;
	secondSkill->setName("전기자석파");
	secondSkill->setDamage(40);
	secondSkill->setCurSkillPoint(30);
	secondSkill->setMaxSkillPoint(30);
	secondSkill->setUsingSkillPoint(12);
	//세번쨰 스킬
	skill* thirdSkill = new skill;
	thirdSkill->setName("대폭팔");
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
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                 ■■■■■■                               ■" << endl;
	cout << "■                             ■■■        ■■■                           ■" << endl;
	cout << "■                           ■■                ■■                         ■" << endl;
	cout << "■                         ■■                    ■■                       ■" << endl;
	cout << "■                       ■■ ■            ■       ■■                     ■" << endl;
	cout << "■                       ■     ■        ■           ■                     ■" << endl;
	cout << "■                       ■       ■    ■             ■                     ■" << endl;
	cout << "■                       ■    ■         ■   ■■■■■                     ■" << endl;
	cout << "■                       ■             ■■■■       ■                     ■" << endl;
	cout << "■                       ■■■■■■■■            ■■                     ■" << endl;
	cout << "■                         ■■              ■    ■■                       ■" << endl;
	cout << "■                           ■■   ■■■■■   ■■                         ■" << endl;
	cout << "■                             ■■            ■■                           ■" << endl;
	cout << "■                                 ■■■■■■                               ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
}
