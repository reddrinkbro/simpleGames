#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;


typedef struct MONSTER
{
	char * name; //이름
	int healthPoint; //체력
	int defense; //방어력
	int attack; //공격력
	int experience = 50; //경험치
	int money = 50; //몬스터가 주는 돈
};

typedef struct JOB
{
	char* name; //이름
	int attack; //공격력
	int defense; //방어력
	int healthPoint; //현재 체력
	int maxHealthPoint; // 최대 체력
	int level = 1; //레벨
	int money = 0; //돈
	int currentExperience = 0; //현재 경험치
	int experienceMax; //총 경험치
	int skill[3]; //스킬 데미지
	char *skillName[3]; //스킬 이름
};


void welcome(); //처음 인사
void selectJob(int select); //직업선택
void selectMode(JOB player, MONSTER enemy); //던전, 강화소 선택
MONSTER monsterState(JOB player, int boss); //몬스터 스탯
JOB playerState(int select); //플레이어 스탯
void dungeon(JOB player, MONSTER enemy, int choiceMode); //던전
int upgrade(JOB player, MONSTER enemy); //강화소

int main()
{
	srand(time(NULL));
	welcome();
	return 0;
}

//처음 인사
void welcome()
{
	int select;
	cout << "어서오세요 직업을 선택해 주세요" << endl;
	cout << "1) 전사 2)마법사 3)게임 종료" << endl;
	cin >> select; // 직업선택
	if (select == 3)
	{
		exit(0);
	}
	else
	{
		selectJob(select); // 직업 선택
	}
}

//처음 왔을때 직업 선택
void selectJob(int select)
{
	JOB player = playerState(select); //플레이어 능력치 적용
	MONSTER enemy = monsterState(player,0); //몬스터능력치중 플레이어 능력치에 관련된 부분을 적용하기 위한 
	Sleep(1000);
	selectMode(player, enemy); //모드 선택
}

//모드 선택
void selectMode(JOB player, MONSTER enemy)
{
	system("cls");
	int choiceMode;
	cout << "하고 싶은 것을 골라주세요" << endl;
	if (player.level < 10)
	{
		cout << "1)던전가기 2)강화소 가기 0)종료하기" << endl;
	}
	else
	{
		cout << "1)던전가기 2)강화소 가기 3) 보스몬스터 사냥하기 0)종료하기" << endl;
	}
	cin >> choiceMode;
	if (choiceMode == 1) //던전가기
	{
		MONSTER normal = monsterState(player, choiceMode);
		dungeon(player, normal, choiceMode);
	}
	else if (choiceMode == 2) //강화소 가기
	{
		upgrade(player,enemy);
	}
	else if (choiceMode == 0) //종료
	{
		exit(0);
	}
	else if (choiceMode == 3 && player.level >= 10)
	{
		MONSTER boss = monsterState(player, choiceMode);
		dungeon(player, boss, choiceMode);
	}
}
//던전가기
void dungeon(JOB player , MONSTER enemy, int choiceMode)
{
	int choice; //플레이어 선택지
	int attack; //공격시 선택지

	while (true)
	{
		system("cls");
		cout << enemy.name << "이 나타났습니다." << endl;
		cout << "몬스터의 체력 : " << enemy.healthPoint << endl;
		cout << "플레이어의 체력 : " << player.healthPoint << endl;
		cout << "1)공격 하기 2) 마을로 가기" << endl;
		cin >> choice;
		if (choice == 1)
		{
			int attack;
			cout << "1) "<<player.skillName[0]<<" 2) "<< player.skillName[1] <<" 3) "<< player.skillName[2] << endl;
			cin >> attack;
			player.skill[attack - 1] = rand() % 100 + player.skill[attack - 1];
			int monsterDamage = player.defense - rand() % 25 + enemy.attack; // 몬스터가 입히는 피해는 플레이어 방어력에서 적 공격력만큼 뺀값이 들어옴
			if (enemy.defense < player.skill[attack - 1]) // 플레이어 공격력이 더 높을때
			{
				cout << player.skillName[attack - 1] << "데미지는 " << player.skill[attack - 1] << "이다." << endl;
				enemy.healthPoint -= player.skill[attack - 1]; // 적체력 감소
			
			}
			else//적 방어력이 더 높을때
			{
				cout << player.skillName[attack - 1] << "데미지는 " << player.attack / 2 << "이다." << endl;
				enemy.healthPoint -= player.attack / 2; // 적 체력 감소
			}
			Sleep(1000);
			system("cls");
			if (enemy.healthPoint <= 0)
			{
				cout << "몬스터가 쓰러졌다!!" << endl;
				player.currentExperience += enemy.experience; // 경험치 획득
				player.money += enemy.money; // 플레이어 돈 획득
				cout << "돈 :" << enemy.money << "획득" << endl;
				if (player.currentExperience >= player.experienceMax) // 현재 경험치가 총 경험치를 넘을때
				{
					player.level += 10; // 레벨증가
					cout << "레벨 업!!!" << endl;
					cout << "레벨이 " << player.level << "이 되었다" << endl;
					player.attack += 10; // 공격력 10상승
					player.currentExperience = 0; //현재 경험치 0으로 초기화
					player.defense += 5; // 방어력 5 상승
					player.maxHealthPoint += player.level * 50; //체력 증가 레벨당 50씩 증가
					player.healthPoint = player.maxHealthPoint; //레벨업시 최대체력으로 바뀜
					player.experienceMax = player.level * player.level * player.experienceMax; //총 경험치는 현재 레벨 x 현재 레벨 x 이전 총 레벨->렙업할때마다 기하급수적으로 오름
				}	
				Sleep(1000);
				selectMode(player, enemy);
			}
			else
			{
				cout << "몬스터가 " << monsterDamage << "를 입혔다" << endl;
				player.healthPoint -= monsterDamage;
				Sleep(1000);
				if (player.healthPoint <= 0) // 체력이 0이하일때
				{
					cout << "플레이어가 죽어버렸습니다." << endl;
					Sleep(1000);
					welcome();
				}
			}
		}
		else
		{
			selectMode(player,enemy); //마을 가기
		}
	}
}
//강화소
int upgrade(JOB player, MONSTER enemy)
{
	int upgradeSelect;
	int PresentLevel = 0; //현재 강화 수치
	int Strengthen; //강화 확률
	if (PresentLevel < 10)
	{
		Strengthen = rand() % 10;
	}
	//강화 확률, 확률의 바탕이 되는 수 'Strengthen'는 랜덤으로 뽑고 100사이에서 
	else if (PresentLevel < 20)
	{

		Strengthen = rand() % 100;

	}
	//강화 확률, 확률의 바탕이 되는 수 'Strengthen'는 랜덤으로 뽑고 30에서 랜덤수를 뺀값을 'PresentStrengthen'에 저장, 강화 단계가 30단계 밑에 일때
	else if (PresentLevel < 30)
	{
		Strengthen = rand() % 1000;

	}
	//강화 확률, 확률의 바탕이 되는 수 'Strengthen'는 랜덤으로 뽑고 40에서 랜덤수를 뺀값을 'PresentStrengthen'에 저장, 강화 단계가 40단계 밑에 일때
	else if (PresentLevel < 40)
	{
		Strengthen = rand() % 10000;
	}
	while (true)
	{
		system("cls");
		cout << "강화소에 오신걸 환영합니다." << endl;
		cout << "현재 강화 수치는 +" << PresentLevel << "강 입니다." << endl;
		cout << "현재 가지고 있는 금액은 : " << player.money << "입니다" << endl;
		cout << "1) 강화 하기 2) 마을가기" << endl;
		cin >> upgradeSelect; //강화할지 마을갈지 선택
		if (upgradeSelect == 1)
		{
			if (player.money < 500 + PresentLevel * 50) // 돈이 부족하면 강화를 못함
			{
				cout << "강화 하는데 비용이 " << 500 + PresentLevel * 50 - player.money << "만큼 부족합니다." << endl;
				Sleep(1000);
			}
			else
			{

				if (PresentLevel < 10)
				{
					// Strengthen값이 현재 강화 상태와 같거나 더 크면 강화 성공, 그렇지 않으면 실패 
					if (Strengthen >= PresentLevel)
					{
						player.money -= 500 + PresentLevel * 50; // 돈 줄어듬
						cout << "강화중";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << "." << endl;;
						PresentLevel++;
						Sleep(1000);
						cout << "강화를 성공하셨습니다." << endl;
						Sleep(500);
						//강화를 성공하면 화면을 지운다.
						system("cls");
					}
					else
					{
						cout << "강화중";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << "." << endl;;
						PresentLevel = 0;
						Sleep(1000);
						cout << "강화에 실패하셨습니다 풉!" << endl;
						Sleep(1000);
						player.money -= 500 + PresentLevel * 50;// 돈 줄어듬
						//강화를 실패하면 화면을 지운다.
						system("cls");
					}
				}
				//20단계 이전
				else if (PresentLevel < 20 && PresentLevel >= 10)
				{
					if (Strengthen <= 19 - PresentLevel)
					{
						player.money -= 500 + PresentLevel * 50;// 돈 줄어듬
						cout << "강화중";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << "." << endl;;
						PresentLevel++;
						Sleep(1000);
						cout << "강화를 성공하셨습니다." << endl;
						Sleep(500);
						//강화를 성공하면 화면을 지운다.
						system("cls");
					}
					else
					{
						cout << "강화중";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << "." << endl;;
						PresentLevel = 0;
						Sleep(1000);
						cout << "강화에 실패하셨습니다 풉!" << endl;
						Sleep(1000);
						player.money -= 500 + PresentLevel * 50;// 돈 줄어듬
						//강화를 실패하면 화면을 지운다.
						system("cls");
					}
				}
				//30단계 이전
				else if (PresentLevel < 30 && PresentLevel >= 20)
				{
					if (Strengthen <= 29 - PresentLevel)
					{
						player.money -= 500 + PresentLevel * 50;// 돈 줄어듬
						cout << "강화중";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << "." << endl;;
						PresentLevel++;
						Sleep(1000);
						cout << "강화를 성공하셨습니다." << endl;
						Sleep(500);
						//강화를 성공하면 화면을 지운다.
						system("cls");
					}
					else
					{
						cout << "강화중";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << "." << endl;;
						PresentLevel = 0;
						Sleep(1000);
						cout << "강화에 실패하셨습니다 풉!" << endl;
						Sleep(1000);
						player.money -= 500 + PresentLevel * 50;// 돈 줄어듬
						//강화를 실패하면 화면을 지운다.
						system("cls");
					}
				}
				//40단계 이전
				else if (PresentLevel < 40 && PresentLevel >= 30)
				{
					if (Strengthen <= 39 - PresentLevel)
					{
						player.money -= 500 + PresentLevel * 50;// 돈 줄어듬
						cout << "강화중";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << "." << endl;;
						PresentLevel++;
						Sleep(1000);
						cout << "강화를 성공하셨습니다." << endl;
						Sleep(500);
						//강화를 성공하면 화면을 지운다.
						system("cls");
					}
					else
					{
						cout << "강화중";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << "." << endl;;
						PresentLevel = 0;
						Sleep(1000);
						cout << "강화에 실패하셨습니다 풉!" << endl;
						Sleep(1000);
						player.money -= 500 + PresentLevel * 50;// 돈 줄어듬
						//강화를 실패하면 화면을 지운다.
						system("cls");
					}
				}
			}
		}
		else if (upgradeSelect == 2) // 마을로 돌아가기
		{
			selectMode(player, enemy);
		}
	}
	return 0;
}

//플레이어의 레벨에 따른 몬스터 출현 ,경험치 돈 수정 필요

MONSTER monsterState(JOB player, int boss)
{
	MONSTER target[2];
	
	if (boss == 1)
	{
		target[0].name = "고블린"; // 몬스터 이름
		target[0].attack = rand() % 20 + player.level; //공격력은 플레이어 레벨에 따라 증가
		target[0].defense = 70 + player.level; // 적 방어력은 플레이어 레벨에 따라 증가
		target[0].healthPoint = 100 + (player.level * 50); // 적 체력은 플레이어 레벨에 따라 50씩 증가
		target[0].money = rand() % 50 + (player.level * 50); //몬스터가 줄 돈, 돈은 레벨 당 50 씩 증가
		target[0].experience = player.level * 50; // 몬스터가 줄 경험치, 경험치는 플레이어 레벨당 50씩 증가
		return target[0];
	}
	//보스몬스터를 선택시
	else
	{
		target[1].name = "드래곤"; // 몬스터 이름
		target[1].attack = rand() % 100 + player.level; //몬스터 기본 공격력
		target[1].defense = 150 + player.level; // 몬스터 기본 방어력
		target[1].healthPoint = 1000 + player.level*50; // 몬스터 기본 체력
		target[1].money = rand() % 1000 + (player.level * 500); //몬스터가 줄 돈
		target[1].experience = player.level * 500; // 몬스터가 줄 경험치
		return target[1];
	}
}

//플레이어 설정
JOB playerState(int select)
{
	JOB player[2];
	if (select == 1)
	{
		player[select - 1].name = "전사"; //이름
		player[select - 1].level = 1; //레벨
		player[select - 1].attack = 30; //공격력
		player[select - 1].defense = 150 ; //방어력
		player[select - 1].maxHealthPoint = 1000; //최대 체력
		player[select - 1].healthPoint = player[select - 1].maxHealthPoint; //현재 체력
		player[select - 1].money = 0; //돈
		player[select - 1].experienceMax = 50;//총 경험치
		player[select - 1].skill[0] = rand() % 25 + player[select - 1].attack;//스킬1  데미지
		player[select - 1].skill[1] = rand() % 25 + player[select - 1].attack * 2;//스킬2  데미지
		player[select - 1].skill[2] = rand() % 25 + player[select - 1].attack * 3;//스킬3  데미지
		player[select - 1].skillName[0] = "파워스트라이크";//스킬1 이름
		player[select - 1].skillName[1] = "크리티컬 어택";//스킬2 이름
		player[select - 1].skillName[2] = "백어택";//스킬3 이름
		cout << player[select - 1].name << "을 선택하셨군요" << endl;
		return player[select - 1];
	}
	else
	{
		player[select - 1].name = "마법사"; //이름
		player[select - 1].level = 1; //레벨
		player[select - 1].attack = 100; //공격력
		player[select - 1].defense = 50; //방어력
		player[select - 1].maxHealthPoint = 300;//최대 체력
		player[select - 1].healthPoint = player[select - 1].maxHealthPoint; //현재 체력
		player[select - 1].money = 0; //돈
		player[select - 1].experienceMax = 50;//총 경험치
		player[select - 1].skill[0] = player[select - 1].attack; //스킬1  데미지
		player[select - 1].skill[1] = player[select - 1].attack * 2; //스킬2 데미지
		player[select - 1].skill[2] = player[select - 1].attack * 3;//스킬3 데미지
		player[select - 1].skillName[0] = "파이어볼"; //스킬1 이름
		player[select - 1].skillName[1] = "아이스 에이지";//스킬2 이름
		player[select - 1].skillName[2] = "라이트닝빔";//스킬3 이름
		cout << player[select - 1].name << "을 선택하셨군요" << endl;
		return player[select - 1];
	}

}