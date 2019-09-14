#include <iostream>
#include<time.h>
#include <Windows.h>

using namespace std;

int main()
{
	
	srand(time(NULL));
	int lottoNum[45] = {0}; //로또 번호
	int winLotto[6] = { 0 }; // 당첨된 번호
	int playerNum[6] = { 0 };//플레이어가 입력할 번호
	int lottoCount = 0; //당첨된 번호의 수
	int loop = 0; //반복문 돌기 위한 변수
	int count = 0; // 플레이어가 배열의 번호
	int index1, index2, temp; //스왑할 변수
	

	for (int i = 0; i < 45; i++)
	{
		lottoNum[i] = i + 1; //각 숫자 입력
	}

	cout << "로또 번호를 입력하세요!!" << endl;
	//플레이어 번호 입력
	while (loop < 6)
	{
		cin >> count;
		//잘못된 숫자를 입력하였을때
		if (count > 45 || count < 1)
		{
			cout << "제대로 된 값을 입력하세요" << endl;
		}
		//제대로 입력하였을때
		else
		{
			playerNum[loop] = lottoNum[count];
			loop++;
		}

		//같은 숫자가 나왔을때
		for (int i = 0; i < 5; i++)
		{
			for (int j = i+1; j < 6; j++)
			{
				if (playerNum[i] == playerNum[j] && loop == 6)
				{
					loop = 0;
					cout << "같은 숫자가 있습니다. 다시입력해 주세요" << endl;
					Sleep(1000);
					system("cls");
					cout << "로또 번호를 입력하세요!!" << endl;
				}
			}
			
		}
			
	}
	cout << "이번 주 로또 당첨 번호는!!!" << endl;
	//로또 셔플 하기
	for (int i = 0; i < 1000; i++)
	{
		index1 = rand() % 45; //1~45까지 랜덤
		index2 = rand() % 45; //1~45까지 랜덤
		temp = lottoNum[index1]; //스왑
		lottoNum[index1] = lottoNum[index2];
		lottoNum[index2] = temp;
	}
	


	
	//당첨 로또 확인
	for (int i = 0; i < 6; i++)
	{
		winLotto[i] = lottoNum[i];
	}

	//로또번호와 플레이어 번호 비교
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0 ; j < 6; j++) 
		{
			if (playerNum[i] == winLotto[j])
			{
				lottoCount++;
			}
		}
	}
	Sleep(2000);
	cout << "당첨된 로또 번호는 ";
	for (int i = 0; i < 6; i++)
	{
		cout << winLotto[i] << " " ;
	}
	cout << "입니다." << endl << endl;
	//6개 다 맞췄을때
	if (lottoCount == 6)
	{
		cout << "1등 당첨입니다!!" << endl;
	}
	//5개 맞췄을때
	else if (lottoCount == 5)
	{
		cout << "2등 당첨입니다!!" << endl;
	}
	//4개 맞췄을때
	if (lottoCount == 4)
	{
		cout << "3등 당첨입니다!!" << endl;
	}
	//3개 이하 맞췄을때
	else
	{
		cout << "꽝입니다." << endl;
	}
	return 0;
}