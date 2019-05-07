#include "pokemonCharmander.h"



pokemonCharmander::pokemonCharmander()
{
	setCurHealthPoint(50);
	setMaxHealthPoint(50);
	setCurExperiencePoint(0);
	setMaxExperiencePoint(20);
	setIsCatchPokemon(true); //잡을수 있는지
	setIsRevolution(false); //진화 형태
	setName("파이리");
	//첫번째 스킬
	skill* firstSkill = new skill;
	firstSkill->setName("불꽃엄니");
	firstSkill->setDamage(10);
	firstSkill->setCurSkillPoint(50);
	firstSkill->setMaxSkillPoint(50);
	firstSkill->setUsingSkillPoint(15);
	//두번째 스킬
	skill* secondSkill = new skill;
	secondSkill->setName("화염방사");
	secondSkill->setDamage(12);
	secondSkill->setCurSkillPoint(30);
	secondSkill->setMaxSkillPoint(30);
	secondSkill->setUsingSkillPoint(12);
	//세번쨰 스킬
	skill* thirdSkill = new skill;
	thirdSkill->setName("회오리불꽃");
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
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                      ■                    ■" << endl;
	cout << "■                          ■■■■■                ■  ■                  ■" << endl;
	cout << "■                         ■        ■               ■  ■                  ■" << endl;
	cout << "■                        ■          ■            ■      ■                ■" << endl;
	cout << "■                      ■              ■          ■□□  ■                ■" << endl;
	cout << "■                    ■      □■      ■          ■□□  ■                ■" << endl;
	cout << "■                  ■        ■■        ■          ■    ■                ■" << endl;
	cout << "■                  ■        ■■        ■          ■  ■■                ■" << endl;
	cout << "■                    ■                    ■        ■  ■                  ■" << endl;
	cout << "■                     ■■                   ■    ■    ■                  ■" << endl;
	cout << "■                        ■■■     ■       ■■■■   ■                   ■" << endl;
	cout << "■                          ■□□ ■                    ■                   ■" << endl;
	cout << "■                          ■□□□ ■■               ■                    ■" << endl;
	cout << "■                          ■□□□□                ■                      ■" << endl;
	cout << "■                        ■  ■□□□        ■■■■                        ■" << endl;
	cout << "■                      ■    ■■■          ■■■■                        ■" << endl;
	cout << "■                        ■■      ■■■■■                                ■" << endl;
	cout << "■                                  ■      ■                                ■" << endl;
	cout << "■                                  ■      ■                                ■" << endl;
	cout << "■                                    ■■■                                  ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
}
