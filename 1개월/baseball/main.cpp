#include<iostream>
#include<time.h>
#include<windows.h>

using namespace std;


//컴퓨터 숫자 3개
//플레이어 숫자 3개
//볼, 스트라이크

int main()
{
	srand(time(NULL));
	int computerNumber[4]; //컴퓨터 숫자
	int playerNumber[4]; //플레이어 숫자
	int randomNum[9]; //랜덤숫자
	int index1, index2, temp; //스왑을 위한 변수
	for (int i = 0; i < 9; i++) 
	{
		randomNum[i] = i+1;
	}
	//숫자 섞기
	for (int i = 0; i < 100; i++)
	{
		index1 = rand() % 9; //0~9
		index2 = rand() % 9; //0~9
		temp = randomNum[index1];
		randomNum[index1] = randomNum[index2];
		randomNum[index2] = temp;
	}
	//컴퓨터 숫자 입력
	for (int i = 0; i < 3; i++)
	{
		computerNumber[i] = randomNum[i];
	}

	//숫자 보여주기 /////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < 3; i++)
	{
		cout << computerNumber[i]<<endl;
	}

	cout << "숫자 야구 시작!!" << endl;
	
	
	//스트라이크가 3일때 종료
	while (true)
	{
		int ballCount = 0; //볼카운트
		int strikeCount = 0; //스트라이크 카운트

		//플레이어 숫자 입력
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << "번째 숫자를 입력하세요" << endl;
			cin >> playerNumber[i];
		}

		for (int i = 0; i < 3; i++)
		{
			//스트라이크
			if (computerNumber[i] == playerNumber[i])
			{
				strikeCount++;
			}
			for (int j = 0; j < 3; j++)
			{
				//볼
				if (computerNumber[i] != playerNumber[i] && computerNumber[i] == playerNumber[j])
				{
					ballCount++;
				}
			}
		}
		//스트라이크 3개 되었을 때
		if (strikeCount == 3)
		{
			cout << "딩동댕!!!!" << endl;
			break;
		}
		//하나도 못맞췄을때
		else if (strikeCount == 0 && ballCount == 0)
		{
			cout << "아웃 !" << endl;
		}
		//스트라이크만 됐을때
		else if (strikeCount > 0 && ballCount ==0)
		{
			cout << "스트라이크 : " << strikeCount << endl;
		}
		//볼만 됐을때
		else if (strikeCount == 0 && ballCount > 0)
		{
			cout << "볼 : " << ballCount << endl;
		}
		//스트라이크 볼 둘다 됐을때
		else if (strikeCount > 0 && ballCount > 0)
		{
			cout << "스트라이크 : " << strikeCount << endl << "볼 : " << ballCount << endl;
		}
		Sleep(2000);
		system("cls");
	}
	return 0;
}