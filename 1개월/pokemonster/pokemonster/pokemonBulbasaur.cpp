#include "pokemonBulbasaur.h"



pokemonBulbasaur::pokemonBulbasaur()
{
	setCurHealthPoint(50);
	setMaxHealthPoint(50);
	setCurExperiencePoint(0);
	setMaxExperiencePoint(20);
	setIsCatchPokemon(true); //ÀâÀ»¼ö ÀÖ´ÂÁö
	setIsRevolution(false); //ÁøÈ­ ÇüÅÂ
	setName("ÀÌ»óÇØ¾¾");
	//Ã¹¹øÂ° ½ºÅ³
	skill* firstSkill = new skill;
	firstSkill->setName("µ¢±¼Ã¤Âï");
	firstSkill->setDamage(10);
	firstSkill->setCurSkillPoint(50);
	firstSkill->setMaxSkillPoint(50);
	firstSkill->setUsingSkillPoint(15);
	//µÎ¹øÂ° ½ºÅ³
	skill* secondSkill = new skill;
	secondSkill->setName("ÀÙ³¯°¡¸£±â");
	secondSkill->setDamage(12);
	secondSkill->setCurSkillPoint(30);
	secondSkill->setMaxSkillPoint(30);
	secondSkill->setUsingSkillPoint(12);
	//¼¼¹ø¤Š ½ºÅ³
	skill* thirdSkill = new skill;
	thirdSkill->setName("¾¾ÆøÅº");
	thirdSkill->setDamage(15);
	thirdSkill->setCurSkillPoint(40);
	thirdSkill->setMaxSkillPoint(40);
	thirdSkill->setUsingSkillPoint(20);

	_skillMap.insert(make_pair(1, firstSkill));
	_skillMap.insert(make_pair(2, secondSkill));
	_skillMap.insert(make_pair(3, thirdSkill));
}


pokemonBulbasaur::~pokemonBulbasaur()
{
}

void pokemonBulbasaur::showImage()
{
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                           ¡á¡á  ¡á¡á                       ¡á" << endl;
	cout << "¡á                                         ¡á    ¡á  ¡á¡á                     ¡á" << endl;
	cout << "¡á                                       ¡á¡á        ¡á¡á                     ¡á" << endl;
	cout << "¡á                                   ¡á¡á¡á¡à        ¡à¡á¡á                   ¡á" << endl;
	cout << "¡á                                 ¡á¡á  ¡à  ¡à¡à¡à ¡à   ¡á¡á¡á               ¡á" << endl;
	cout << "¡á                               ¡á    ¡à  ¡à¡à  ¡à ¡à       ¡á¡á             ¡á" << endl;
	cout << "¡á                     ¡á¡á    ¡á    ¡à    ¡à    ¡à   ¡à       ¡á¡á           ¡á" << endl;
	cout << "¡á                   ¡á  ¡á¡á¡á    ¡à    ¡à      ¡à     ¡à     ¡á¡á           ¡á" << endl;
	cout << "¡á                   ¡á        ¡á¡á    ¡à      ¡à       ¡à     ¡á¡á           ¡á" << endl;
	cout << "¡á                   ¡á      ¡à¡à¡á¡á¡à¡à      ¡à       ¡à     ¡á¡á           ¡á" << endl;
	cout << "¡á                   ¡á     ¡à¡à¡à    ¡á¡á     ¡à       ¡à     ¡á¡á           ¡á" << endl;
	cout << "¡á                 ¡á       ¡à¡à¡à      ¡á¡á   ¡à       ¡à   ¡á¡á             ¡á" << endl;
	cout << "¡á                 ¡á                     ¡á¡á¡á¡á       ¡à¡á¡á               ¡á" << endl;
	cout << "¡á               ¡á¡à¡á    ¡à¡à                  ¡á¡á¡á¡á¡á                   ¡á" << endl;
	cout << "¡á               ¡á      ¡à¡à     ¡á¡á¡á     ¡á¡á      ¡á¡á                   ¡á" << endl;
	cout << "¡á             ¡á               ¡á¡á¡à¡à           ¡à¡à¡á¡á                   ¡á" << endl;
	cout << "¡á             ¡á               ¡á¡á¡à             ¡à¡à¡á¡á                   ¡á" << endl;
	cout << "¡á               ¡á                        ¡á          ¡á¡á                   ¡á" << endl;
	cout << "¡á               ¡á                      ¡à¡à¡á      ¡á¡á                     ¡á" << endl;
	cout << "¡á                 ¡á¡á¡á            ¡á  ¡à¡à¡á  ¡à¡á¡á                       ¡á" << endl;
	cout << "¡á                       ¡á¡á¡á¡á¡á¡á¡á      ¡á¡á¡á¡á                         ¡á" << endl;
	cout << "¡á                                   ¡á¡à  ¡à¡á¡á                             ¡á" << endl;
	cout << "¡á                                     ¡á¡á¡á¡á                               ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl;
}