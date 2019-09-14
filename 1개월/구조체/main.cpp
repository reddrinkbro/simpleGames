#include <iostream>
#include <windows.h>
using namespace std;

typedef struct Job
{
	char* name; //이름
	int attack; //공격력
	int defense; //방어력
	int healthPoint; //체력
	int manaPoint; //마나
	int speed; //이속
	int attackSpeed; //공속
	int lucky; //운
	int intellect; //지력
	int masicResist; //마법저항
	int critical; //크리티컬
	int power; //힘
	int dex; //민첩
	int ability; //솜씨
	int Gwang; //광조?
	int level; //레벨
	int experiencePoint; //경험치
	int casting; //캐스팅속도
	int attackArea; //공격범위
};


int main()
{
	Job state[5];
	//전사 스탯
	state[0].name = "전사";
	state[0].attack = 100;
	state[0].defense = 100;
	state[0].healthPoint = 1000;
	state[0].manaPoint = 500;
	state[0].speed = 20;
	state[0].attackSpeed = 30;
	state[0].lucky = 10;
	state[0].intellect = 5;
	state[0].masicResist = 50;
	state[0].critical = 30;
	state[0].power = 100;
	state[0].dex = 30;
	state[0].ability = 20;
	state[0].Gwang = 1;
	state[0].level = 1;
	state[0].experiencePoint = 0;
	state[0].casting = 4;
	state[0].attackArea = 3;
	//마법사 스탯
	state[1].name = "마법사";
	state[1].attack = 80;
	state[1].defense = 40;
	state[1].healthPoint = 500;
	state[1].manaPoint = 1000;
	state[1].speed = 20;
	state[1].attackSpeed = 20;
	state[1].lucky = 20;
	state[1].intellect = 50;
	state[1].masicResist = 80;
	state[1].critical = 20;
	state[1].power = 80;
	state[1].dex = 40;
	state[1].ability = 70;
	state[1].Gwang = 2;
	state[1].level = 1;
	state[1].experiencePoint = 0;
	state[1].casting = 7;
	state[1].attackArea = 10;
	//도적 스탯
	state[2].name = "도적";
	state[2].attack = 70;
	state[2].defense = 30;
	state[2].healthPoint = 900;
	state[2].manaPoint = 600;
	state[2].speed = 100;
	state[2].attackSpeed = 100;
	state[2].lucky = 80;
	state[2].intellect = 35;
	state[2].masicResist = 50;
	state[2].critical = 100;
	state[2].power = 70;
	state[2].dex = 110;
	state[2].ability = 90;
	state[2].Gwang = 3;
	state[2].level = 1;
	state[2].experiencePoint = 0;
	state[2].casting = 10;
	state[2].attackArea = 6;
	//궁수 스탯
	state[3].name = "궁수";
	state[3].attack = 90;
	state[3].defense = 40;
	state[3].healthPoint = 700;
	state[3].manaPoint = 700;
	state[3].speed = 40;
	state[3].attackSpeed = 50;
	state[3].lucky = 40;
	state[3].intellect = 40;
	state[3].masicResist = 60;
	state[3].critical = 90;
	state[3].power = 90;
	state[3].dex = 100;
	state[3].ability = 60;
	state[3].Gwang = 4;
	state[3].level = 1;
	state[3].experiencePoint = 0;
	state[3].casting = 9;
	state[3].attackArea = 8;
	//힐러 스탯
	state[4].name = "힐러";
	state[4].attack = 20;
	state[4].defense = 100;
	state[4].healthPoint = 700;
	state[4].manaPoint = 1000;
	state[4].speed = 30;
	state[4].attackSpeed = 20;
	state[4].lucky = 20;
	state[4].intellect = 90;
	state[4].masicResist = 100;
	state[4].critical = 10;
	state[4].power = 30;
	state[4].dex = 30;
	state[4].ability = 70;
	state[4].Gwang = 5;
	state[4].level = 1;
	state[4].experiencePoint = 0;
	state[4].casting = 7;
	state[4].attackArea = 3;
	while (true)
	{

		cout << "직업을 선택하세요." << endl << endl;
		cout << "1)전사 2)마법사 3)도적 4)궁수 5)힐러" << endl<< endl;
		cout << "그만 보시려면 0을 눌러주세요" << endl;

		int selectJob = 0; //직업 스탯 보기위한 변수
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
		for (int i = 0; i < 5; i++)
		{
			// 스탯 출력
			if (selectJob == i+1)
			{

				cout << "이름:" << state[i].name << endl;
				cout << "공격력:" << state[i].attack << endl;
				cout << "방어력:" << state[i].defense << endl;
				cout << "체력:" << state[i].healthPoint << endl;
				cout << "마나:" << state[i].manaPoint << endl;
				cout << "이동속도:" << state[i].speed << endl;
				cout << "공격속도:" << state[i].attackSpeed << endl;
				cout << "운:" << state[i].lucky << endl;
				cout << "지력:" << state[i].intellect << endl;
				cout << "마법저항:" << state[i].masicResist << endl;
				cout << "크리티컬:" << state[i].critical << endl;
				cout << "힘:" << state[i].power << endl;
				cout << "민첩:" << state[i].dex << endl;
				cout << "솜씨:" << state[i].ability << endl;
				cout << "광조:" << state[i].Gwang << endl;
				cout << "레벨:" << state[i].level << endl;
				cout << "경험치:" << state[i].experiencePoint << endl;
				cout << "캐스팅속도:" << state[i].casting << endl;
				cout << "공격범위:" << state[i].attackArea << endl << endl;
			}
			
		}

	}
}