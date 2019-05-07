#include "mapBase.h"



mapBase::mapBase()
{
	pokemonPikachu* pikachu = new pokemonPikachu; // ÇÇÄ«Ãò
	pokemonVoltorb* voltorb = new pokemonVoltorb; //Âî¸®¸®°ø
	pokemonElectrode* electrode = new pokemonElectrode; //ºÕº¼
	pokemonRaichu* raichu = new pokemonRaichu; //¶óÀÌÃò
	pokemonBulbasaur* blubasaur = new pokemonBulbasaur; //ÀÌ»óÇØ¾¾
	pokemonOddish* oddish = new pokemonOddish; //¶Ñ¹÷ÃÝ
	pokemonVenusaur* venusaur = new pokemonVenusaur;
	pokemonVileplume* vileplume = new pokemonVileplume;
	pokemonPsyduck* psyduck = new pokemonPsyduck; //°í¶óÆÄ´ö
	pokemonGolduck* golduck = new pokemonGolduck; //°ñ´ö
	pokemonSquirtle* squirtle = new pokemonSquirtle; //²¿ºÏÀÌ
	pokemonBlastoise* blastoise = new pokemonBlastoise;
	pokemonDiglett* diglett = new pokemonDiglett; //µð±×´Ù
	pokemonDugtrio* dugtrio = new pokemonDugtrio; //´ÚÆ®¸®¿À
	pokemonSandshrew* sandshrew = new pokemonSandshrew; //¸ð·¡µÎÁö
	pokemonSandslash* sandslash = new pokemonSandslash; //°íÁö
	pokemonCharmander* charmander = new pokemonCharmander; //ÆÄÀÌ¸®
	pokemonCharizard* charizard = new pokemonCharizard; //¸®ÀÚ¸ù
	pokemonVulpix* vulpix = new pokemonVulpix; //½Ä½ºÅ×ÀÏ
	pokemonNinetales* ninetales = new pokemonNinetales;//³ªÀÎÅ×ÀÏ
		
	pokemonVec.push_back(pikachu);
	pokemonVec.push_back(voltorb);
	pokemonVec.push_back(electrode);
	pokemonVec.push_back(raichu);
	pokemonVec.push_back(blubasaur);
	pokemonVec.push_back(oddish);
	pokemonVec.push_back(venusaur);
	pokemonVec.push_back(vileplume);
	pokemonVec.push_back(charmander);
	pokemonVec.push_back(vulpix);
	pokemonVec.push_back(golduck);
	pokemonVec.push_back(blastoise);
	pokemonVec.push_back(diglett);
	pokemonVec.push_back(sandshrew);
	pokemonVec.push_back(dugtrio);
	pokemonVec.push_back(sandslash);
	pokemonVec.push_back(psyduck);
	pokemonVec.push_back(squirtle);
	pokemonVec.push_back(charizard);
	pokemonVec.push_back(ninetales);
}


mapBase::~mapBase()
{
}

pokemonBase* mapBase::selectPokemon(int attribute, int pokemonSelect)
{
	//Àü±â½ÃÆ¼
	if (attribute == 1)
	{
		pokemonVec[pokemonSelect]->showImage();
		cout << "\t" <<pokemonVec[pokemonSelect]->getName() << "ÀÌ(°¡) ³ªÅ¸³µ´Ù" << endl;
		return pokemonVec[pokemonSelect];
	}
	//Æ÷·¹½ºÆ®
	else if (attribute == 2)
	{
		pokemonSelect += 4;
		pokemonVec[pokemonSelect]->showImage();
		cout << "\t" << pokemonVec[pokemonSelect]->getName() << "ÀÌ(°¡) ³ªÅ¸³µ´Ù" << endl;
		return pokemonVec[pokemonSelect];
	}
	//º¼ÄÉÀÌ³ë
	else if (attribute == 3)
	{
		pokemonSelect +=+ 8;
		pokemonVec[pokemonSelect]->showImage();
		cout << "\t" << pokemonVec[pokemonSelect]->getName() << "ÀÌ(°¡) ³ªÅ¸³µ´Ù" << endl;
		return pokemonVec[pokemonSelect];
	}
	//½ºÅæ¸¶¿îÆ¾
	else if (attribute == 4)
	{
		pokemonSelect += 12;
		pokemonVec[pokemonSelect]->showImage();
		cout << "\t" << pokemonVec[pokemonSelect]->getName() << "ÀÌ(°¡) ³ªÅ¸³µ´Ù" << endl;
		return pokemonVec[pokemonSelect];
	}
	//¿öÅÍÅ·´ý
	else if (attribute == 5)
	{
		pokemonSelect += 16;
		pokemonVec[pokemonSelect]->showImage();
		cout << "\t" << pokemonVec[pokemonSelect]->getName() << "ÀÌ(°¡) ³ªÅ¸³µ´Ù" << endl;
		return pokemonVec[pokemonSelect];
	}
}

void mapBase::showTownImage()
{
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl;
	cout << "¡á                          ¡á                                                ¡á" << endl;
	cout << "¡á          ¡á             ¡á¡á                                               ¡á" << endl;
	cout << "¡á         ¡á¡á           ¡á¡á¡á                       ¡á                     ¡á" << endl;
	cout << "¡á        ¡á¡á¡á        ¡á¡á¡á¡á¡á                    ¡á¡á                    ¡á" << endl;
	cout << "¡á      ¡á¡á¡á¡á¡á       ¡á¡á¡á¡á                    ¡á¡á¡á                   ¡á" << endl;
	cout << "¡á       ¡á¡á¡á¡á        ¡á  ¡á¡á                  ¡á¡á¡á¡á¡á                 ¡á" << endl;
	cout << "¡á       ¡á  ¡á¡á        ¡á¤±¡á¡á                   ¡á¡á¡á¡á                  ¡á" << endl;
	cout << "¡á    ¡á ¡á¤±¡á¡á        ¡á£ß¡á¡á                   ¡á  ¡á¡á                  ¡á" << endl;
	cout << "¡á   ¡á¡á¡á£ß¡á¡á                                   ¡á¤±¡á¡á                  ¡á" << endl;
	cout << "¡á  ¡á¡á¡á          ¡á¡á¡á¡á¡á                      ¡á£ß¡á¡á                  ¡á" << endl;
	cout << "¡á¡á¡á¡á¡á¡á       ¡á   ¡á   ¡á                                               ¡á" << endl;
	cout << "¡á ¡á¡á¡á¡á        ¡á¡á¡á¡á¡á¡á                                               ¡á" << endl;
	cout << "¡á ¡á  ¡á¡á   ¡á¡á¡á  ¡á¡á¡á  ¡á¡á¡á              ¡á£ß¡á¡á¡á£ß¡á              ¡á" << endl;
	cout << "¡á ¡á¤±¡á¡á   ¡á    ¡á£ß£ß£ß¡á    ¡á              ¡á   ¡á¡á¡á ¡á              ¡á" << endl;
	cout << "¡á ¡á£ß¡á¡á   ¡á        ¡Û        ¡á              ¡á   ¡á¦«¡á ¡á              ¡á" << endl;
	cout << "¡á            ¡á    ¡á£þ£þ£þ¡á    ¡á              ¡á   ¡á¡á¡á ¡á              ¡á" << endl;
	cout << "¡á            ¡á      ¡á¡á¡á      ¡á            ¡á¡á¡á¡á¡á¡á¡á¡á¡á            ¡á" << endl;
	cout << "¡á            ¡á                  ¡á            ¡á              ¡á            ¡á" << endl;
	cout << "¡á            ¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á            ¡á    ¡á£þ¡á¡á  ¡á            ¡á" << endl;
	cout << "¡á       ¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á       ¡á    ¡á¤±¡á¡á  ¡á            ¡á" << endl;
	cout << "¡á         ¡á   Æ÷  ÄÏ   ¸ó   ¼¾  ÅÍ ¡á         ¡á¡á¡á¡á£ß¡á¡á¡á¡á            ¡á" << endl;
	cout << "¡á         ¡á                        ¡á                                       ¡á" << endl;
	cout << "¡á         ¡á       ¡á¡á¡á¡á¡á       ¡á                                       ¡á" << endl;
	cout << "¡á         ¡á       ¡á  ¡á  ¡á       ¡á                                       ¡á" << endl;
	cout << "¡á         ¡á       ¡á  ¡á  ¡á       ¡á                                       ¡á" << endl;
	cout << "¡á         ¡á       ¡á  ¡á  ¡á       ¡á                                       ¡á" << endl;
	cout << "¡á         ¡á       ¡á¡á¡á¡á¡á       ¡á                                       ¡á" << endl;
	cout << "¡á         ¡á                        ¡á                                       ¡á" << endl;
	cout << "¡á       ¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á                                     ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl;
}

void mapBase::showBlankImage()
{
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á                                                                            ¡á" << endl;
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl;
}