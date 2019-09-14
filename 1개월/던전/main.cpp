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
};

typedef struct JOB
{
	char* name; //이름
	int attack; //공격력
	int defense; //방어력
	int healthPoint; //체력
};

int main()
{
	srand(time(NULL));
	int monsterNum = 0; // 몬스터 나타난 수
	bool yourTurn = true;
	JOB state[5];
	MONSTER target[6];

	//직업 부분
	//전사 스탯
	state[0].name = "전사";
	state[0].defense = 30;
	state[0].healthPoint = 1000;

	//마법사 스탯
	state[1].name = "마법사";
	state[1].defense = 35;
	state[1].healthPoint = 500;

	//도적 스탯
	state[2].name = "도적";
	state[2].defense = 50;
	state[2].healthPoint = 500;

	//궁수 스탯
	state[3].name = "궁수";
	state[3].defense = 40;
	state[3].healthPoint = 700;

	//힐러 스탯
	state[4].name = "힐러";
	state[4].defense = 70;
	state[4].healthPoint = 700;

	//몬스터부분


	//고블린
	target[0].name = "고블린";
	target[0].defense = 10;
	target[0].healthPoint = 100;


	//골렘
	target[1].name = "골렘";
	target[1].defense = 30;
	target[1].healthPoint = 200;

	//오크
	target[2].name = "오크";
	target[2].defense = 40;
	target[2].healthPoint = 300;

	//하피
	target[3].name = "하피";
	target[3].defense = 70;
	target[3].healthPoint = 400;

	//드래곤
	target[4].name = "드래곤";
	target[4].defense = 90;
	target[4].healthPoint = 500;

	//악마
	target[5].name = "악마";
	target[5].defense = 90;
	target[5].healthPoint = 600;
	
	int selectJob = 0; //직업 선택하기 위한 변수
	bool isDie = false; //플레이어가 죽었는가
	int select = 0; //선택지에서 하기 위한 행동
	cout << "직업을 선택하세요" << endl;
	cout << "1)전사 2)마법사 3)도적 4)궁수 5)힐러" << endl;
	cout << "게임을 종료하실려면 0을 입력하세요" << endl;
	//직업 선택
	cin >> selectJob;
	if (selectJob == 0) // 0을 입력 하였을때
	{
		return 0;
	}
	else if (selectJob != 1 && selectJob != 2 && selectJob != 3 && selectJob != 4 && selectJob != 5) // 제대로된 숫자가 입력되지 않았을때
	{
		cout << "제대로 된 숫자를 입력하세요";
		Sleep(1000);
		system("cls");
	}
	
	switch (selectJob)
	{
		case 1:
		{
			cout << "전사를 선택하셨습니다." << endl;
		}
		break;
		case 2:
		{
			cout << "마법사를 선택하셨습니다." << endl;
		}
		break;
		case 3:
		{
			cout << "도적을 선택하셨습니다." << endl;
		}
		break;
		case 4:
		{
			cout << "궁수를 선택하셨습니다." << endl;
		}
		break;
		case 5:
		{
			cout << "힐러를 선택하셨습니다." << endl;
		}
		break;
	}
	Sleep(1000);
	system("cls");
	
	int choiceMonster = 0; //처음은 고블린으로 몸풀기

	//직업 선택 완료
	while (monsterNum < 6)
	{
		

		//직업 부분

		//전사
		state[0].attack = rand() % 101 + 90;
		//마법사
		state[1].attack = rand() % 81 + 60;
		//도적 
		state[2].attack = rand() % 71 + 50;
		//궁수 
		state[3].attack = rand() % 91 + 70;
		//힐러 스탯
		state[4].attack = rand() % 31 + 10;

		//몬스터부분


		//고블린
		target[0].attack = rand() % 26 + 10;
		//골렘
		target[1].attack = rand() % 31 + 10;
		//오크
		target[2].attack = rand() % 41 + 10;
		//하피
		target[3].attack = rand() % 31 + 10;
		//드래곤
		target[4].attack = rand() % 91 + 10;
		//악마
		target[5].attack = rand() % 91 + 10;

		cout << target[choiceMonster].name <<"이 나타났습니다." << endl;
		cout << "몬스터의 체력 : " << target[choiceMonster].healthPoint << endl;
		cout << "플레이어의 체력 : " << state[selectJob - 1].healthPoint << endl;
		cout << "1)공격 하기 2) 도망가기" << endl;
		cin >> select;

		//공격하기를 선택했을때
		if (select == 1)
		{
			
			//데미지가 들었갔을때
			if(state[selectJob-1].attack - target[choiceMonster].defense > 0)
			{
				//데미지는 공격력에서 상대 방어력을 뺀 값에 100을 곱하고 공격력으로 다시 나누었다.
				target[choiceMonster].healthPoint = target[choiceMonster].healthPoint - ((state[selectJob-1].attack - target[choiceMonster].defense) * 100) / state[selectJob-1].attack ;
				cout << "데미지는 " <<((state[selectJob-1].attack - target[choiceMonster].defense) * 100) / state[selectJob-1].attack << "입니다." << endl << endl;
				Sleep(400);
				yourTurn = false;
				//몬스터를 죽였을때
				if (target[choiceMonster].healthPoint <= 0)
				{
					cout << target[choiceMonster].name << "이(가) 죽었습니다." << endl;
					Sleep(700);
					target[choiceMonster].healthPoint = (choiceMonster + 1) * 100;
					monsterNum++;
					choiceMonster = rand() % 6; // 몬스터 정하기
					yourTurn = true;
					system("cls");
				}
				Sleep(1000);
				system("cls");
			}
			//데미지가 들어가지 않았을때
			else
			{
				cout << "빗나갔습니다." << endl;
				Sleep(500);
				yourTurn = false;
				system("cls");
			}
			
		}
		//도망가기를 눌렀을때
		else if (select == 2)
		{
			cout << "쯧쯧... 겁만 많고 쓸모가 없네" << endl;
			Sleep(1000);
			system("cls");
			cout << "Game Over" << endl;
			return 0;
		}
		//몬스터를 죽이지 못하였을때 몬스터 턴으로 넘어간다
		//몬스터 턴
		if (target[choiceMonster].healthPoint > 0 && yourTurn == false)
		{
			cout << "몬스터 턴 입니다." << endl;
			//몬스터가 공격에 실패할때
			if (target[choiceMonster].attack - state[selectJob - 1].defense <= 0)
			{
				cout << "몬스터가 공격 했습니다 피해 : MISS" << endl;
				yourTurn = true;
				Sleep(500);
				system("cls");
			}
			//몬스터가 공격에 성공했을때
			else
			{

				cout << "몬스터가 공격 했습니다 피해 :" << ((target[choiceMonster].attack - state[selectJob - 1].defense) * 100) / target[choiceMonster].attack << endl;
				//데미지는 공격력에서 상대 방어력을 뺀 값에 100을 곱하고 공격력으로 다시 나누었다.
				state[selectJob - 1].healthPoint = state[selectJob - 1].healthPoint - ((target[choiceMonster].attack - state[selectJob - 1].defense) * 100) / target[choiceMonster].attack;
				yourTurn = true;
				Sleep(500);
				system("cls");

				//죽었을때
				if (state[selectJob - 1].healthPoint <= 0)
				{
					cout << "당신은 죽었습니다." << endl;
					Sleep(1000);
					system("cls");
					cout << "Game Over" << endl;
					return 0;
				}
			}
		}

	}
	cout << "모든 몬스터를 사냥하셨습니다" << endl;
	return 0;
}