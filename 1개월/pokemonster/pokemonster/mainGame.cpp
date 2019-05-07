#include "mainGame.h"
mainGame::mainGame()
{
	for (int i = 0; i < 6; i++)
	{
		cout << endl;
	}
	user = new player;
	char* playerName = new char[0];
	cout << "\t\t플레이어의 이름을 정해주세요 : ";
	cin >> playerName; //플레이어 이름 넣기
	user->setName(playerName);
	cout <<"\t\t" <<user->getName() << "님 관동지방에 오신걸 환영합니다." << endl;
} 

mainGame::~mainGame()
{
}

void mainGame::firstPokemon()
{
	int selectPokemon;
	while (true)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << endl;
		}
		cout << "\t\t처음 원하시는 포켓몬을 선택해주세요" << endl;
		cout << "\t\t1) 파이리 2)꼬부기 3)이상해씨" << endl;
		cout << "\t\t입력해주세요 : ";
		cin >> selectPokemon; // 포켓몬 선택
		if (selectPokemon == 1)
		{
			system("cls");
			pokemonCharmander* Charmander = new pokemonCharmander; //파이리 객채 생성
			Charmander->showImage();
			user->getPokemon(Charmander); //유저의 포켓몬으로 넣음
			break;
		}
		else if (selectPokemon == 2)
		{
			system("cls");
			pokemonSquirtle* Squirtle = new pokemonSquirtle; //꼬부기 객체 생성
			Squirtle->showImage();
			user->getPokemon(Squirtle);
			break;
		}
		else if (selectPokemon == 3)
		{
			system("cls");
			pokemonBulbasaur* Bulbasaur = new pokemonBulbasaur; // 이상해씨 객체 생성
			Bulbasaur->showImage();
			user->getPokemon(Bulbasaur);
			break;
		}
		else
		{
			cout << "\t\t제대로 선택해 주세요." << endl;
			Sleep(500);
		}
	}
} // 처음 포켓몬을 선택하는 함수

void mainGame::selectMode()
{
	int select; //할 행동 선택
	Sleep(1000);
	user->userWin();
	system("cls");
	town->showTownImage();
	if (getPlayer()->getIsPlayerWin() == true) //6마리 모두 진화 시켰을 경우
	{
		Sleep(1000);
		cout << "\t당신은 충분한 포켓몬 트레이너가 되었습니다." << endl;
		cout << "\tGAME CLEAR" << endl;
		exit(0);
	}
	else {
		cout << "\t1)여행떠나기 2)포켓몬 센터가기 3)인벤토리 보기 4)포켓몬 정보" << endl;
		cout << "\t입력해주세요 : ";
		cin >> select;
		//여행 떠나기
		if (select == 1)
		{
			travleMessage(); //여행을 떠났다...
			travel(); // 지역을 선택하기 위한 함수
		}
		//포켓몬 센터가기
		else if (select == 2)
		{
			goToPokemonCenter();
		}
		//플레이어 인벤토리 보기
		else if (select == 3)
		{
			yourInventory();
		}
		//플레이어가 가지고 있는 포켓몬 확인
		else if (select == 4)
		{
			yourPokemon();
		}
		else
		{
			cout << "\t제대로 입력해주세요." << endl;
			Sleep(500);
		}
	}
} //여행, 포켓몬센터, 

void mainGame::travleMessage()
{
	cout << "\t여행을 떠나기로 했다..." << endl;
	Sleep(1000);
}

void mainGame::travel()
{
	system("cls");
	town->showTownImage();
	cout << "\t어디로 떠나시겠습니까?" << endl;
	cout << "\t1)전기시티 2)포레스트 3)볼케이노 4)스톤마운틴 5)워터킹덤 0)마을가기" << endl;
	cout << "\t입력해주세요 : ";
	int selectMap; //맵선택 하기위한 변수
	int random = rand() % 100;
	int randomPokemon; //적 포켓몬을 정하는 랜덤변수
	if (random < 45) //진화 된 포켓몬을 만날 확률 10%으로 설정
	{
		randomPokemon = 0;
	}
	else if (random < 90)
	{
		randomPokemon = 1;
	}
	else if (random < 95)
	{
		randomPokemon = 2;
	}
	else
	{
		randomPokemon = 3;
	}
	cin >> selectMap;
	//전기시티으로 갔을경우
	if (selectMap == 1)
	{
		system("cls");
		mapElectronic* Electronic = new mapElectronic; //클래스 생성
		Electronic->showImage();
		cout << "\t" <<Electronic->getName() << "으로 진입했다." << endl; //맵이름 표시
		Sleep(2000);
		system("cls");
		pokemon = Electronic->selectPokemon(selectMap, randomPokemon); // 적 포켓몬을 불러온다
		Sleep(1000);
		pokemonBattle(selectMap, Electronic, randomPokemon, pokemon); //포켓몬 배틀
	}
	//포레스트으로 갔을경우
	else if (selectMap == 2)
	{
		system("cls");
		mapForest* Forest = new mapForest;//클래스 생성
		Forest->showImage();
		cout << "\t" << Forest->getName() << "으로 진입했다." << endl;//맵이름 표시
		Sleep(2000);
		system("cls");
		pokemon = Forest->selectPokemon(selectMap, randomPokemon); // 적 포켓몬을 불러온다
		Sleep(1000);
		pokemonBattle(selectMap, Forest, randomPokemon, pokemon); //포켓몬 배틀
	}
	//볼케이노으로 갔을경우
	else if (selectMap == 3)
	{
		system("cls");
		mapVolcano* Volcano = new mapVolcano;//클래스 생성
		Volcano->showImage();
		cout << "\t" << Volcano->getName() << "으로 진입했다." << endl;//맵이름 표시
		Sleep(2000);
		system("cls");
		pokemon = Volcano->selectPokemon(selectMap, randomPokemon); // 적 포켓몬을 불러온다
		Sleep(1000);
		pokemonBattle(selectMap, Volcano, randomPokemon, pokemon); //포켓몬 배틀

	}
	//스톤마운틴으로 갔을경우
	else if (selectMap == 4)
	{
		system("cls");
		mapStone* Stone = new mapStone;//클래스 생성
		Stone->showImage();
		cout << "\t" << Stone->getName() << "으로 진입했다." << endl;//맵이름 표시
		Sleep(2000);
		system("cls");
		pokemon = Stone->selectPokemon(selectMap, randomPokemon); // 적 포켓몬을 불러온다
		Sleep(1000);
		pokemonBattle(selectMap, Stone, randomPokemon, pokemon); //포켓몬 배틀

	}
	//워터킹덤으로 갔을경우
	else if (selectMap == 5)
	{
		system("cls");
		mapLake* Lake = new mapLake;//클래스 생성
		Lake->showImage();
		cout << "\t" << Lake->getName() << "으로 진입했다." << endl;//맵이름 표시
		Sleep(2000);
		system("cls");
		pokemon = Lake->selectPokemon(selectMap, randomPokemon); // 적 포켓몬을 불러온다
		Sleep(1000);
		pokemonBattle(selectMap, Lake, randomPokemon, pokemon); //포켓몬 배틀

	}
	else if (selectMap == 0)
	{
		cout << "\t마을로 돌아갔다." << endl;
		Sleep(500);
		selectMode();
	}
	else
	{
		cout << "\t제대로 입력해 주세요." << endl;
		Sleep(500);
	}
	
}

void mainGame::goToPokemonCenter()
{
	int select;
	while (true)
	{
		system("cls");
		town->showTownImage();
		cout << "\t포켓몬 간호사 : 어서오세요 " << user->getName() << "님" << endl;
		cout << "\t포켓몬 간호사 : 무엇을 도와드릴까요?" << endl;
		cout << "\t1)포켓몬 치료 2)포켓몬 진화 3)아이템 구매 4) 나가기" << endl;
		cout << "\t입력해주세요 : ";
		cin >> select;
		//치료를 선택
		if (select == 1)
		{
			cure();
		}
		//포켓몬 진화 선택
		else if (select == 2)
		{
			pokemonRevolution();
		}
		else if (select == 3)
		{
			itemPurchase();
		}
		//나가기
		else if (select == 4)
		{
			cout << "\t포켓몬 간호사 : 나중에 또 오세요. ^^" << endl;
			selectMode();
			break;
		}
		else
		{
			cout << "\t제대로 입력해 주세요." << endl;
		}
	}
}

void mainGame::yourInventory()
{
	user->userInventory();
}

void mainGame::yourPokemon()
{
	for (int i = 0; i < user->pokemonVec.size(); i++)
	{
		cout << "\t==========================================================" << endl;
		cout << "\t포켓몬 이름 : " << user->pokemonVec[i]->getName() << endl; //포켓몬 이름 출력
		cout << "\t==========================================================" << endl;
		cout << "\t포켓몬 체력 : " << user->pokemonVec[i]->getCurHealthPoint() << " / " << user->pokemonVec[i]->getMaxHealthPoint() << endl; //포켓몬 현재 체력 / 최대 체력
		cout << "\t==========================================================" << endl;
		cout << "\t포켓몬 경험치 : " << user->pokemonVec[i]->getCurExperiencePoint() << " / " << user->pokemonVec[i]->getMaxExperiencePoint() << endl; // 포켓몬 현재 경험치 / 진화하기 위한 경험치
		cout << "\t==========================================================" << endl;
	}
	Sleep(1000);
}

void mainGame::pokemonBattleReady(int attribute,mapBase* map, int pokemonSelect)
{

	int select = 0;
	while (true)
	{
		system("cls");
		pokemon->showImage();
		cout << "\t1)싸운다 2)몬스터볼 사용 3)포켓몬 먹이 사용 4)도망친다" << endl;
		cout << "\t입력해주세요 : ";
		cin >> select;
		//포켓몬 배틀
		if (select == 1)
		{
			user->setIsFightState(true);
			break;
		}
		//몬스터볼 사용
		else if (select == 2)
		{
			if (pokemon->getIsCatchPokemon() == false)
			{
				cout << "\t몬스터볼로 잡을수 없는 포켓몬 입니다." << endl;
				Sleep(500);
				pokemonBattleReady(attribute, map, pokemonSelect);
			}
			else
			{
				if (pitch(attribute, map, pokemonSelect) == true)
				{
					user->setIsFightState(false);
					break;
				}// 몬스터볼 사용을 위한 함수
			}
		}
		else if (select == 3)
		{
			user->usingPokemonFood();
			Sleep(500);
		}
		//도망치기
		else if (select == 4)
		{
			cout << "\t도망 쳤다..." << endl;
			user->setIsFightState(false);
			for (int i = 0; i < user->pokemonVec.size(); i++)
			{
				user->pokemonVec[i]->mapIter = user->pokemonVec[i]->_skillMap.begin(); // 스킬에 대한 맵의 이터레이터
				for (user->pokemonVec[i]->mapIter; user->pokemonVec[i]->mapIter != user->pokemonVec[i]->_skillMap.end(); user->pokemonVec[i]->mapIter++)
				{
					user->pokemonVec[i]->mapIter->second->setCurSkillPoint(user->pokemonVec[i]->mapIter->second->getMaxSkillPoint());//포켓몬 배틀이 끝나면 스킬포인트를 초기화 시켜준다
				}
			}
			Sleep(500);
			break;
		}
		else
		{
			cout << "\t제대로 선택해 주세요." << endl;
			Sleep(500);
		}
	}
	
}

bool mainGame::pitch(int attribute, mapBase* map, int pokemonSelect)
{
	system("cls");
	pokemon->showImage();
	if (user->pokemonVec.size() >= 6)
	{
		cout << "\t더 이상 포켓몬을 잡을수 없습니다." << endl;
		Sleep(1000);
		system("cls");
		return false;
	}
	else
	{
		while (true)
		{
			char input;
			cout << "\t몬스터볼 개수 : " << user->userBall->getAmount() << endl; // 몬스터볼 개수 보여주기
			cout << "\t사용 하시겠습니까? Y/N : ";
			cin >> input;
			if (input == 'y' || input == 'Y')
			{

				if (user->userBall->getAmount() <= 0) //몬스터볼이 없을경우
				{
					cout << "\t몬스터볼이 부족합니다." << endl;
					Sleep(1000);
					return false;
					break;
				}
				else
				{
					cout << "\t몬스터 볼을 던졌다!" << endl;
					if (usingMonsterBall(attribute, map, pokemonSelect) == true) // 몬스터볼을 던졌을때 몬스터가 잡힐 확률을 정해주는 함수
					{
						return true; //잡았을경우  true 반환
						break;
					}
					else
					{
						return false; // 못잡았을 경우 false 반환
						break;
					}
				}

			}
			//몬스터볼을 사용하지 않을경우
			else if (input == 'n' || input == 'N')
			{
				return false;
				break;
			}
			else
			{
				cout << "\t제대로 입력해 주세요." << endl;
				Sleep(500);
			}
		}
	}
}

void mainGame::pokemonBattle(int attribute, mapBase* map, int pokemonSelect, pokemonBase* pokemon)
{
	int selectPokemon = showMyPokemon(); // 가지고 있는 포켓몬 선택
	if (selectPokemon == 0) //마을 가기를 선택한다면
	{
		system("cls");
		map->showTownImage();
		cout << "\t마을로 갑니다." << endl;
		Sleep(500);
		selectMode(); //마을로 이동
	}
	else
	{
		while (true)
		{
			pokemonBattleReady(attribute, map, pokemonSelect); //배틀 선택지
			if (user->getIsFightState() == false)
			{
				pokemon->setCurHealthPoint(pokemon->getMaxHealthPoint()); // 적 포켓몬 체력을 다시 원상복귀
				travel(); //맵선택지로 이동
				break;
			}
			else
			{
				Sleep(500);
				pokemonSkillCheck(selectPokemon - 1); //포켓몬 스킬이름, 스킬포인트 보여주기
				int select; //스킬 선택
				int damage; //스킬의 데미지
				int randomSkillSelect = rand() % 3 + 1; //적의 스킬을 선택해주기 위한 랜덤수
				while (true)
				{
					cout << "\t\t입력해주세요 : ";
					cin >> select; //스킬입력
					if (select <= 0 || select > 3)
					{
						cout << "\t제대로 된 스킬을 선택해주세요." << endl;
						Sleep(500);
						system("cls");
						pokemon->showImage();
						pokemonSkillCheck(selectPokemon - 1); //포켓몬 스킬이름, 스킬포인트 보여주기
					}
					else
					{
						if (user->pokemonVec[selectPokemon - 1]->getSkillMap().find(select)->second->getCurSkillPoint() >= user->pokemonVec[selectPokemon - 1]->getSkillMap().find(select)->second->getUsingSkillPoint()) //스킬포인트가 충분하면 멈춘다
						{
							break;
						}
						cout << "\t스킬포인트가 부족합니다." << endl;
						Sleep(500);
						system("cls");
						pokemon->showImage();
						pokemonSkillCheck(selectPokemon - 1); //포켓몬 스킬이름, 스킬포인트 보여주기
					}
				}
				damage = user->pokemonVec[selectPokemon - 1]->getSkillMap().find(select)->second->getDamage(); // 맵을 이용하여 데미지를 넣어준다
				user->pokemonVec[selectPokemon - 1]->getSkillMap().find(select)->second->setCurSkillPoint(user->pokemonVec[selectPokemon - 1]->getSkillMap().find(select)->second->getCurSkillPoint() - user->pokemonVec[selectPokemon - 1]->getSkillMap().find(select)->second->getUsingSkillPoint()); //스킬 사용시 스킬포인트 감소
				cout << "\t" <<user->pokemonVec[selectPokemon - 1]->getName() << "은(는) " << user->pokemonVec[selectPokemon - 1]->getSkillMap().find(select)->second->getName() << "을(를)사용했다." << endl; //포켓몬이름과 스킬의 이름을 보여준다
				pokemon->setCurHealthPoint(pokemon->getCurHealthPoint() - damage); // 적 포켓몬의 체력에서 데미지만큼 뺀다
				if (pokemon->getCurHealthPoint() <= 0) //적포켓몬이 죽었을 경우
				{
					cout << "\t" << pokemon->getName() << "의 체력이 0이 되었다" << endl;
					cout << "\t" << pokemon->getName() << "이(가) 도망갔다." << endl;
					cout << "\t돈 " << pokemon->getMoney() << "를 획득" << endl;
					user->setMoney(user->getMoney() + pokemon->getMoney());
					if (user->pokemonVec[selectPokemon - 1]->getCurExperiencePoint() < 20) // 경험치가 20보다 작을경우
					{
						user->pokemonVec[selectPokemon - 1]->setCurExperiencePoint(user->pokemonVec[selectPokemon - 1]->getCurExperiencePoint() + 1); // 경험치가 증가한다
						cout << "\t경험치가 " << user->pokemonVec[selectPokemon - 1]->getCurExperiencePoint() << " / " << user->pokemonVec[selectPokemon - 1]->getMaxExperiencePoint() << "이(가) 되었다." << endl; // 현재 경험치 / 총 경험치
					}
					Sleep(1000);
					user->pokemonVec[selectPokemon - 1]->setMaxHealthPoint(user->pokemonVec[selectPokemon - 1]->getMaxHealthPoint() + (user->pokemonVec[selectPokemon - 1]->getCurExperiencePoint() * 10)); //포켓몬 경험치에 따른 체력 증가
					pokemon->setCurHealthPoint(pokemon->getMaxHealthPoint()); //적포켓몬 체력을 초기화 해준다
					user->pokemonVec[selectPokemon - 1]->mapIter = user->pokemonVec[selectPokemon - 1]->_skillMap.begin(); // 스킬에 대한 맵의 이터레이터
					for (user->pokemonVec[selectPokemon - 1]->mapIter; user->pokemonVec[selectPokemon - 1]->mapIter != user->pokemonVec[selectPokemon - 1]->_skillMap.end(); user->pokemonVec[selectPokemon - 1]->mapIter++)
					{
						user->pokemonVec[selectPokemon - 1]->mapIter->second->setDamage(user->pokemonVec[selectPokemon - 1]->mapIter->second->getDamage() + 1); //경험치에 따른 스킬데미지 상승
						user->pokemonVec[selectPokemon - 1]->mapIter->second->setCurSkillPoint(user->pokemonVec[selectPokemon - 1]->mapIter->second->getMaxSkillPoint());//포켓몬 배틀이 끝나면 스킬포인트를 초기화 시켜준다
					}
					break;
				}
				else //적포켓몬이 죽지 않았을경우
				{
					cout << "\t" << damage << "만큼 피해를 주었다" << endl;
					cout << "\t" << pokemon->getName() << "\t" << pokemon->getCurHealthPoint() << " / " << pokemon->getMaxHealthPoint() << endl; // 적 포켓몬의 현재체력 / 총 체력
					Sleep(1500);
					damage = pokemon->getSkillMap().find(randomSkillSelect)->second->getDamage(); // 데미지는 적 포켓몬의 데미지가 된다.
					cout << "\t" << pokemon->getName() << " : " << pokemon->getSkillMap().find(randomSkillSelect)->second->getName() << endl; // 적 포켓몬의 스킬이름 출력
					cout << "\t" << damage << "만큼 피해를 받았다" << endl;
					Sleep(1500);
					user->pokemonVec[selectPokemon - 1]->setCurHealthPoint(user->pokemonVec[selectPokemon - 1]->getCurHealthPoint() - damage); // 포켓몬의 체력에서 데미지만큼 빼준다
					if (user->pokemonVec[selectPokemon - 1]->getCurHealthPoint() <= 0) // 포켓몬이 죽었을 경우
					{
						cout << "\t" << user->pokemonVec[selectPokemon - 1]->getName() << "이(가) 쓰러졌다" << endl;
						user->pokemonVec[selectPokemon - 1]->setCurHealthPoint(0); //현재 체력이 0이 된다
						for (user->pokemonVec[selectPokemon - 1]->mapIter; user->pokemonVec[selectPokemon - 1]->mapIter != user->pokemonVec[selectPokemon - 1]->_skillMap.end(); user->pokemonVec[selectPokemon - 1]->mapIter++)
						{
							user->pokemonVec[selectPokemon - 1]->mapIter->second->setCurSkillPoint(user->pokemonVec[selectPokemon - 1]->mapIter->second->getMaxSkillPoint());//포켓몬 배틀이 끝나면 스킬포인트를 초기화 시켜준다
						}
						Sleep(100);
						system("cls");
						pokemon->showImage();
						pokemonBattle(attribute, map, pokemonSelect, pokemon);
					}
				}
			}
		}
	}
	travel(); //맵선택지로 이동
}

void mainGame::pokemonSkillCheck(int selectPokemon)
{
	cout << endl;
	cout << "\t" << pokemon->getName() << "\t" << pokemon->getCurHealthPoint() << " / " << pokemon->getMaxHealthPoint() << endl; // 적 포켓몬의 현재체력 / 총 체력
	cout << "\t===========================================================" << endl;
	cout << "\t" << user->pokemonVec[selectPokemon]->getName() << "체력\t" << user->pokemonVec[selectPokemon]->getCurHealthPoint() << " / " << user->pokemonVec[selectPokemon]->getMaxHealthPoint() << endl; //현재 체력 / 총체력
	user->pokemonVec[selectPokemon]->mapIter = user->pokemonVec[selectPokemon]->_skillMap.begin(); // 스킬에 대한 맵의 이터레이터
	cout << "\t===========================================================" << endl;
	for (user->pokemonVec[selectPokemon]->mapIter; user->pokemonVec[selectPokemon]->mapIter != user->pokemonVec[selectPokemon]->_skillMap.end(); user->pokemonVec[selectPokemon]->mapIter++)
	{
		cout << "\t" << user->pokemonVec[selectPokemon]->mapIter->first << ") " << user->pokemonVec[selectPokemon]->mapIter->second->getName() << "\t";
	} //스킬을 표시해주기 위한 for문
	cout << endl;
	user->pokemonVec[selectPokemon]->mapIter = user->pokemonVec[selectPokemon]->_skillMap.begin(); // 이터레이터를 다시쓰기 위한 초기화
	for (user->pokemonVec[selectPokemon]->mapIter; user->pokemonVec[selectPokemon]->mapIter != user->pokemonVec[selectPokemon]->_skillMap.end(); user->pokemonVec[selectPokemon]->mapIter++)
	{
		cout << "\t   " << user->pokemonVec[selectPokemon]->mapIter->second->getCurSkillPoint() << " / " << user->pokemonVec[selectPokemon]->mapIter->second->getMaxSkillPoint() << "\t";
	}//스킬포인트 표시 현재 스킬포인트 / 총 스킬포인트
}

void mainGame::cure()
{
	int selectpokemon = 0; // 치료할 포켓몬 선택하기 위한 변수
	while (true)
	{
		system("cls");
		town->showTownImage();
		cout << "\t포켓몬 간호사 : 치료하실 포켓몬을 선택해주세요. (뒤로 가기는 0)" << endl;
		for (int i = 0; i < user->pokemonVec.size(); i++)
		{
			cout << "\t" << i + 1 << ". " << user->pokemonVec[i]->getName() << "\t체력 : " << user->pokemonVec[i]->getCurHealthPoint() << " / " << user->pokemonVec[i]->getMaxHealthPoint() << endl; //모든 포켓몬을 보여준다
		}
		cout << "\t입력해주세요 : ";
		cin >> selectpokemon; // 포켓몬 선택
		if (selectpokemon == 0)
		{
			break;
		}
		if (selectpokemon < 0 || selectpokemon > user->pokemonVec.size())
		{
			cout << "\t제대로 된 값을 입력해주세요" << endl;
			Sleep(500);
		}
		else
		{
			if (user->pokemonVec[selectpokemon - 1]->getCurHealthPoint() == user->pokemonVec[selectpokemon - 1]->getMaxHealthPoint()) // 체력이 풀일 경우
			{
				cout << "\t포켓몬 간호사 : 현재 선택하신 포켓몬은 체력이 충분합니다." << endl;
				Sleep(500);
			}
			else
			{
				int cureMoney = 20 + user->pokemonVec[selectpokemon - 1]->getMaxHealthPoint() - user->pokemonVec[selectpokemon - 1]->getCurHealthPoint(); //치료가격은 기본료 20에서 최대채력 - 현재체력을 더한값
				cout << "\t" << user->pokemonVec[selectpokemon - 1]->getName() << "을 선택하셨군요" << endl;
				cout << "\t포켓몬 간호사 : 치료 가격은 " << cureMoney << "입니다." << endl;
				cout << "\t현재 가지고 있는 돈 : " << user->getMoney() << endl;
				cout << "\t포켓몬 간호사 : 치료하시겠습니까? (Y/N) : ";
				char selectCure; // 치료할지 안할지 선택하기위한 변수
				cin >> selectCure; //치료하기위한 입력				
				if (selectCure == 'y' || selectCure == 'Y')
				{
					if (user->getMoney() < cureMoney)
					{
						cout << "\t돈이 부족합니다" << endl;
						Sleep(500);
					}
					else
					{
						user->setMoney(user->getMoney() - cureMoney); // 돈이 치료가격만큼 빠진다.
						user->pokemonVec[selectpokemon - 1]->setCurHealthPoint(user->pokemonVec[selectpokemon - 1]->getMaxHealthPoint()); //포켓몬 치료
						cout << "\t돈이 " << user->getMoney() << "남았습니다." << endl;
						Sleep(500);
					}
				}
				else if (selectCure == 'n' || selectCure == 'N')
				{
					break;
				}
				else
				{
					cout << "\t제대로 입력해주세요." << endl;
					Sleep(500);
				}
				
			}
		}
	}
}

void mainGame::pokemonRevolution()
{
	int select;
	while (true)
	{
		system("cls");
		town->showTownImage();
		cout << "\t포켓몬 간호사 : 진화를 시킬 포켓몬을 선택해주세요. (뒤로가기는 0)" << endl;
		for (int i = 0; i < user->pokemonVec.size(); i++)
		{
			if (user->pokemonVec[i]->getCurExperiencePoint() == 20)//현재 경험치가 20인 모든 포켓몬을 보여준다
			{
				cout << "\t" << i + 1 << ". " << user->pokemonVec[i]->getName() << endl;
			}
		}
		cout << "\t입력해주세요 : ";
		cin >> select;
		if (select == 0)
		{
			break;
		}
		if (select <0 || select >user->pokemonVec.size())
		{
			cout << "\t제대로 된 값을 입력해주세요." << endl;
			Sleep(500);
		}
		else
		{
			if (user->pokemonVec[select - 1]->getCurExperiencePoint() == 20) // 진화를 선택할 경우
			{
				cout << "\t"<< user->getName() << " : 어?!!" << user->pokemonVec[select - 1]->getName() << "의 상태가!!" << endl;
				Sleep(1000);
				cout << "\t" << user->pokemonVec[select - 1]->getName() << "이(가) ";
			}
			
			if (user->pokemonVec[select - 1]->getName() == "파이리" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonCharizard* Charizard = new pokemonCharizard;
				user->pokemonVec[select - 1]->setName(Charizard->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Charizard->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for(int i = 1 ; i <4 ; i++)
				{ 
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Charizard->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Charizard->getSkillMap().find(i)->second->getDamage());
				}
				delete Charizard;
			}
			else if (user->pokemonVec[select - 1]->getName() == "이상해씨" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonVenusaur* Venusaur = new pokemonVenusaur;
				user->pokemonVec[select - 1]->setName(Venusaur->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Venusaur->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Venusaur->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Venusaur->getSkillMap().find(i)->second->getDamage());
				}
				delete Venusaur;
			}
			else if (user->pokemonVec[select - 1]->getName() == "꼬부기" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonBlastoise* Blastoise = new pokemonBlastoise;
				user->pokemonVec[select - 1]->setName(Blastoise->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Blastoise->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Blastoise->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Blastoise->getSkillMap().find(i)->second->getDamage());
				}
				delete Blastoise;
			}
			else if (user->pokemonVec[select - 1]->getName() == "피카츄" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonRaichu* Raichu = new pokemonRaichu;
				user->pokemonVec[select - 1]->setName(Raichu->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Raichu->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Raichu->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Raichu->getSkillMap().find(i)->second->getDamage());
				}
				delete Raichu;
			}
			else if (user->pokemonVec[select - 1]->getName() == "찌리리공" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonElectrode* Electrode = new pokemonElectrode;
				user->pokemonVec[select - 1]->setName(Electrode->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Electrode->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Electrode->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Electrode->getSkillMap().find(i)->second->getDamage());
				}
				delete Electrode;
			}
			else if (user->pokemonVec[select - 1]->getName() == "식스테일" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonNinetales* Ninetales = new pokemonNinetales;
				user->pokemonVec[select - 1]->setName(Ninetales->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Ninetales->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Ninetales->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Ninetales->getSkillMap().find(i)->second->getDamage());
				}
				delete Ninetales;
			}
			else if (user->pokemonVec[select - 1]->getName() == "뚜벅쵸" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonVileplume* Vileplume = new pokemonVileplume;
				user->pokemonVec[select - 1]->setName(Vileplume->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Vileplume->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Vileplume->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Vileplume->getSkillMap().find(i)->second->getDamage());
				}
				delete Vileplume;
			}
			else if (user->pokemonVec[select - 1]->getName() == "고라파덕" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonGolduck* Golduck = new pokemonGolduck;
				user->pokemonVec[select - 1]->setName(Golduck->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Golduck->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Golduck->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Golduck->getSkillMap().find(i)->second->getDamage());
				}
				delete Golduck;
			}
			else if (user->pokemonVec[select - 1]->getName() == "디그다" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonDugtrio* Dugtrio = new pokemonDugtrio;
				user->pokemonVec[select - 1]->setName(Dugtrio->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Dugtrio->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Dugtrio->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Dugtrio->getSkillMap().find(i)->second->getDamage());
				}
				delete Dugtrio;
			}
			else if (user->pokemonVec[select - 1]->getName() == "모래두지" && user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				pokemonSandslash* Sandslash = new pokemonSandslash;
				user->pokemonVec[select - 1]->setName(Sandslash->getName());
				user->pokemonVec[select - 1]->setMaxHealthPoint(Sandslash->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setCurHealthPoint(user->pokemonVec[select - 1]->getMaxHealthPoint());
				user->pokemonVec[select - 1]->setIsRevolution(true);
				for (int i = 1; i <4; i++)
				{
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setName(Sandslash->getSkillMap().find(i)->second->getName());
					user->pokemonVec[select - 1]->getSkillMap().find(i)->second->setDamage(Sandslash->getSkillMap().find(i)->second->getDamage());
				}
				delete Sandslash;
			}
			
			if (user->pokemonVec[select - 1]->getCurExperiencePoint() == 20)
			{
				cout << user->pokemonVec[select - 1]->getName() << "으로 진화 하였다!" << endl;
			}
			Sleep(1000);
			break;
		}
	}
}

bool mainGame::usingMonsterBall(int attribute, mapBase* map, int pokemonSelect)
{
	int sucessPercent = rand() % 10;
	float compare = (pokemon->getCurHealthPoint() / pokemon->getMaxHealthPoint()) * 100; //일정체력이하인지 확인
	if (compare <= 10.0 && pokemon->getIsCatchPokemon() == true) // 10퍼센트 이하일 경우, 적 포켓몬이 잡을수 있는 경우
	{
		if (sucessPercent < 2) //0 1 이 나오면 잡게 된다
		{
			user->getPokemon(pokemon);
			user->userBall->setAmount(user->userBall->getAmount() - 1); //몬스터볼을 사용하면 감소한다.
			Sleep(500);
			pokemon->setIsCatchPokemon(false); //한번 몬스터볼 잡는 걸 시도 하면 두번은 못하도록 설정
			return true;
		}
		else //잡지 못하였을 경우
		{
			cout << "\t" << pokemon->getName() << "을 잡지 못했습니다" << endl;
			user->userBall->setAmount(user->userBall->getAmount() - 1); //몬스터볼을 사용하면 감소한다.
			Sleep(500);
			pokemon->setIsCatchPokemon(false); //한번 몬스터볼 잡는 걸 시도 하면 두번은 못하도록 설정
			return false;
		}
	}
	else if (compare > 10.0 && pokemon->getIsCatchPokemon() == true) //잡을수 있는데 체력이 높을경우
	{
		cout << "\t체력이 높아서 몬스터볼을 사용 할 수 없습니다." << endl;
		Sleep(500);
		return false;
	}
}

void mainGame::itemPurchase()
{
	system("cls");
	town->showTownImage();
	int selectItem = 0; //아이템 선택
	int itemNum = 0; //구매할 아이템 개수
	monsterBall* ball = new monsterBall; //몬스터볼 객체 생성
	pokemonFood* food = new pokemonFood; //진화의 돌 객체 생성
	cout << "\t포켓몬 간호사 : 어떤 아이템을 구입하시겠습니까?" << endl;
	cout << "\t1. " << ball->getName() << " : " << ball->getPrice() << endl; //몬스터볼 이름과 가격표시
	cout << "\t2. " << food->getName() << " : " << food->getPrice() << endl; //진화의 돌 이름과 가격 표시
	cout << "\t현재 가지고 있는 돈 : " << user->getMoney() << endl;
	cout << "\t입력해주세요 : ";
	cin >> selectItem;
	if (selectItem == 1)
	{
		if (user->getMoney() < ball->getPrice()) // 돈이 부족하다면
		{
			cout << "\t돈이 부족합니다." << endl;
			Sleep(1000);
		}
		else
		{
			while (true)
			{
				cout << "\t몇개를 구매하시겠습니까? : ";
				cin >> itemNum;
				if (itemNum < 1) //입력 잘못했을때
				{
					cout << "\t제대로 된 숫자를 입력하세요." << endl;
					Sleep(500);
				}
				else
				{
					if (user->getMoney() < (ball->getPrice()*itemNum)) //돈이 부족하다면
					{
						cout << "\t돈이 부족합니다." << endl;
						Sleep(500);
					}
					else
					{
						cout <<"\t" << ball->getName() << "을 " << itemNum << "개 구입했습니다" << endl;
						user->setMoney(user->getMoney() - (ball->getPrice() * itemNum)); //유저 돈을 줄인다.
						user->getMonsterball(itemNum);
						Sleep(1000);
						break;
					}
				}
			}
		}
	}
	else if (selectItem == 2)
	{
		if (user->getMoney() < food->getPrice()) // 돈이 부족하다면
		{
			cout << "\t돈이 부족합니다." << endl;
			Sleep(1000);
		}
		else
		{
			while (true)
			{
				cout << "\t몇개를 구매하시겠습니까? : ";
				cin >> itemNum;
				if (itemNum < 1) //입력 잘못했을때
				{
					cout << "\t제대로 된 숫자를 입력하세요." << endl;
					Sleep(500);
				}
				else
				{
					if (user->getMoney() < (food->getPrice()*itemNum)) //돈이 부족하다면
					{
						cout << "\t돈이 부족합니다." << endl;
						Sleep(500);
					}
					else
					{
						cout << "\t" << food->getName() << "을 " << itemNum << "개 구입했습니다" << endl;
						user->setMoney(user->getMoney() - (food->getPrice() * itemNum)); //유저 돈을 줄인다.
						user->getPokemonFood(itemNum);
						Sleep(1000);
						break;
					}
				}
			}
		}
	}
}

int mainGame::showMyPokemon()
{
	int select; //포켓몬 선택
	while (true)
	{
		cout << "\t현재 가지고 있는 포켓몬" << endl;
		for (int i = 0; i < user->pokemonVec.size(); i++) //유저가 가지고 있는 포켓몬을 모두 보여준다
		{
			cout << "\t" << i + 1 << ". " << user->pokemonVec[i]->getName() << "\t체력 : "; //체력을 보여준다
			cout << "\t" << user->pokemonVec[i]->getCurHealthPoint() << " / " << user->pokemonVec[i]->getMaxHealthPoint() << endl; // 현재체력 / 총 체력
		}
		cout << "\t원하시는 포켓몬을 선택하세요 (마을로 가기는 0을 눌러주세요.)" << endl;
		cout << "\t입력해주세요 : ";
		cin >> select; // 포켓몬을 선택
		if (select <0 || select >user->pokemonVec.size()) //입력 잘못했을때
		{
			cout << "\t제대로 된 값을 입력해주세요" << endl;
			Sleep(500);
		}
		else
		{
			if (select == 0)
			{
				break;
			}
			if (user->pokemonVec.size() < select) //잘못된 값을 입력할때
			{
				cout << "\t제대로 선택해주세요" << endl;
				Sleep(500);
			}
			else
			{
				if (user->pokemonVec[select - 1]->getCurHealthPoint() == 0) // 체력이 0일경우 선택을 하지 못하게 한다
				{
					cout << "\t체력이 " << user->pokemonVec[select - 1]->getCurHealthPoint() << "이기 때문에 선택할수 없습니다." << endl;
					cout << "\t포켓몬 센터에서 치료해주세요." << endl;
					Sleep(1000);
					system("cls");
					pokemon->showImage();
				}
				else
				{
					cout << "\t" << user->getName() << " : " << "가라 ! " << user->pokemonVec[select - 1]->getName() << endl;
					user->pokemonVec[select - 1]->setIsFighting(true);
					Sleep(1000);
					break;
				}
			}
		}
	}
	return select;
}


// 포켓몬 센터갔다가 인벤토리 가면 벡터 오류가 있었는데 사라졌다 이유를 알수 없다;;