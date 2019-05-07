#include "pokemonSandslash.h"



pokemonSandslash::pokemonSandslash()
{
	setCurHealthPoint(200);
	setMaxHealthPoint(200);
	setCurExperiencePoint(0);
	setMaxExperiencePoint(20);
	setIsCatchPokemon(false); //잡을수 있는지
	setIsRevolution(true); //진화 형태인지
	setName("고지");
	//첫번째 스킬
	skill* firstSkill = new skill;
	firstSkill->setName("브레이크크루");
	firstSkill->setDamage(35);
	firstSkill->setCurSkillPoint(50);
	firstSkill->setMaxSkillPoint(50);
	firstSkill->setUsingSkillPoint(15);
	//두번째 스킬
	skill* secondSkill = new skill;
	secondSkill->setName("매그니튜드");
	secondSkill->setDamage(40);
	secondSkill->setCurSkillPoint(30);
	secondSkill->setMaxSkillPoint(30);
	secondSkill->setUsingSkillPoint(12);
	//세번쨰 스킬
	skill* thirdSkill = new skill;
	thirdSkill->setName("지진");
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
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                     ■                                     ■" << endl;
	cout << "■                         ■        ■  ■      ■■■                       ■" << endl;
	cout << "■                       ■  ■  ■  ■  ■  ■■    ■                       ■" << endl;
	cout << "■                       ■  ■■  ■    ■■      ■                         ■" << endl;
	cout << "■                       ■  ■■■  ■■    ■  ■■■■■                   ■" << endl;
	cout << "■                       ■    ■    ■    ■■■        ■                   ■" << endl;
	cout << "■                     ■          ■      ■          ■                     ■" << endl;
	cout << "■                     ■                ■          ■  ■■                 ■" << endl;
	cout << "■                   ■□              ■        ■■        ■               ■" << endl;
	cout << "■                   ■■                  ■■■      ■■■                 ■" << endl;
	cout << "■                   ■        □■              ■■■    ■                 ■" << endl;
	cout << "■                   ■□    ■■■                    ■■                   ■" << endl;
	cout << "■                     ■□□□□            ■          ■■                 ■" << endl;
	cout << "■                       ■■■■■▒▒▒  ■            ■  ■■■           ■" << endl;
	cout << "■                                 ■▒▒■        ■    ■        ■         ■" << endl;
	cout << "■                               ■■▒■▒▒▒  ■    ■      ■■           ■" << endl;
	cout << "■                             ■▒▒■▒■■■■      ■■■■               ■" << endl;
	cout << "■                               ■■■■■▒▒      ■                       ■" << endl;
	cout << "■                                         ■■■  ■■                       ■" << endl;
	cout << "■                                           ■▒  ▒■                       ■" << endl;
	cout << "■                                           ■▒■▒■                       ■" << endl;
	cout << "■                                             ■■■                         ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■                                                                            ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
}