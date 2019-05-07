#include "pokemonSquirtle.h"



pokemonSquirtle::pokemonSquirtle()
{
	setCurHealthPoint(50);
	setMaxHealthPoint(50);
	setCurExperiencePoint(0);
	setMaxExperiencePoint(20);
	setIsCatchPokemon(true); //잡을수 있는지
	setIsRevolution(false); //진화 형태
	setName("꼬부기");
	//첫번째 스킬
	skill* firstSkill = new skill;
	firstSkill->setName("몸통박치기");
	firstSkill->setDamage(10);
	firstSkill->setCurSkillPoint(50);
	firstSkill->setMaxSkillPoint(50);
	firstSkill->setUsingSkillPoint(15);
	//두번째 스킬
	skill* secondSkill = new skill;
	secondSkill->setName("물대포");
	secondSkill->setDamage(12);
	secondSkill->setCurSkillPoint(30);
	secondSkill->setMaxSkillPoint(30);
	secondSkill->setUsingSkillPoint(12);
	//세번쨰 스킬
	skill* thirdSkill = new skill;
	thirdSkill->setName("거품광선");
	thirdSkill->setDamage(15);
	thirdSkill->setCurSkillPoint(40);
	thirdSkill->setMaxSkillPoint(40);
	thirdSkill->setUsingSkillPoint(20);

	_skillMap.insert(make_pair(1, firstSkill));
	_skillMap.insert(make_pair(2, secondSkill));
	_skillMap.insert(make_pair(3, thirdSkill));
}


pokemonSquirtle::~pokemonSquirtle()
{
}

void pokemonSquirtle::showImage()
{
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                         ■■■■                  ■■■                   ■" << endl;
	cout << "■                       ■        ■■            ■      ■                 ■" << endl;
	cout << "■                     ■              ■■      ■          ■               ■" << endl;
	cout << "■                     ■              ■  ■■  ■      ■  ■               ■" << endl;
	cout << "■                   ■□              □      ■      ■    ■               ■" << endl;
	cout << "■                   ■        □■      □      ■    ■  ■                 ■" << endl;
	cout << "■                   ■        ■□      □      ■  ■■■                   ■" << endl;
	cout << "■                     ■      ■□      ■□      ■■                       ■" << endl;
	cout << "■                       ■■        ■■    □    ■                         ■" << endl;
	cout << "■                        ■  ■■■■        □    ■                        ■" << endl;
	cout << "■                         ■■    ■      ■□    ■                         ■" << endl;
	cout << "■                             ■    ■■■■□    ■                         ■" << endl;
	cout << "■                           ■  ■          ■□■                           ■" << endl;
	cout << "■                             ■■■■      ■□■                           ■" << endl;
	cout << "■                                   ■■■  ■■                             ■" << endl;
	cout << "■                                     ■      ■                             ■" << endl;
	cout << "■                                      ■■■■                              ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
}