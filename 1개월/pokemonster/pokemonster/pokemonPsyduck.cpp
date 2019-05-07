#include "pokemonPsyduck.h"



pokemonPsyduck::pokemonPsyduck()
{
	setCurHealthPoint(50);
	setMaxHealthPoint(50);
	setCurExperiencePoint(0);
	setMaxExperiencePoint(20);
	setIsCatchPokemon(true); //잡을수 있는지
	setIsRevolution(false); //진화형태인지
	setName("고라파덕");
	//첫번째 스킬
	skill* firstSkill = new skill;
	firstSkill->setName("물대포");
	firstSkill->setDamage(10);
	firstSkill->setCurSkillPoint(50);
	firstSkill->setMaxSkillPoint(50);
	firstSkill->setUsingSkillPoint(15);
	//두번째 스킬
	skill* secondSkill = new skill;
	secondSkill->setName("할퀴기");
	secondSkill->setDamage(12);
	secondSkill->setCurSkillPoint(30);
	secondSkill->setMaxSkillPoint(30);
	secondSkill->setUsingSkillPoint(12);
	//세번쨰 스킬
	skill* thirdSkill = new skill;
	thirdSkill->setName("눈보라");
	thirdSkill->setDamage(15);
	thirdSkill->setCurSkillPoint(40);
	thirdSkill->setMaxSkillPoint(40);
	thirdSkill->setUsingSkillPoint(20);

	_skillMap.insert(make_pair(1, firstSkill));
	_skillMap.insert(make_pair(2, secondSkill));
	_skillMap.insert(make_pair(3, thirdSkill));
}


pokemonPsyduck::~pokemonPsyduck()
{
}

void pokemonPsyduck::showImage()
{
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                    ■    ■                                ■" << endl;
	cout << "■                                    ■  ■■  ■■                          ■" << endl;
	cout << "■                            ■■■    ■■  ■■                            ■" << endl;
	cout << "■                          ■      ■■■■■                                ■" << endl;
	cout << "■                        ■    ■■        ■■                              ■" << endl;
	cout << "■                      ■    ■                ■                            ■" << endl;
	cout << "■                      ■    □                  ■                          ■" << endl;
	cout << "■                      ■  □■        □□    ■  ■                        ■" << endl;
	cout << "■                        ■  □■■  □■□□■      ■                      ■" << endl;
	cout << "■                        ■  ■    ■■□□  ■      ■                      ■" << endl;
	cout << "■                        ■■    ▦    ■              ■                    ■" << endl;
	cout << "■                      ■                ■  ■        ■                    ■" << endl;
	cout << "■                      ■            ■■■■        ■                      ■" << endl;
	cout << "■                        ■        ■              ■                        ■" << endl;
	cout << "■                          ■■■■                ■■■■                  ■" << endl;
	cout << "■                        ■■                      ■    ■                  ■" << endl;
	cout << "■                      ■    ■                  ■    ■                    ■" << endl;
	cout << "■                        ■    ■■          ■■■■■                      ■" << endl;
	cout << "■                          ■■    ■■■■■    ■                          ■" << endl;
	cout << "■                              ■■  ■        ■                            ■" << endl;
	cout << "■                                      ■■■■                              ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
}