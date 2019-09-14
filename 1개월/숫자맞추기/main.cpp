#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
	int RandomValue; //컴퓨터가 지정하는값
	int ChoiceValue; // 내가 선택하는 숫자

	srand(time(NULL));
	RandomValue = rand() % 99 + 1; // 1부터 100까지 숫자
	while (true)
	{
		cout << "숫자를 입력하세요"<< endl;
		cin >> ChoiceValue;
		cout << endl;

		// 컴퓨터가 정한 숫자보다 플레이어가 숫자가 클경우
		if (RandomValue > ChoiceValue)
		{
			cout << "입력 하신 숫자보다 더 큰 숫자 입니다." << endl <<endl;
			Sleep(1000);
		}
		// 컴퓨터가 정한 숫자보다 플레이어가 숫자가 작을 경우
		else if (RandomValue < ChoiceValue)
		{
			cout << "입력 하신 숫자보다 더 작은 숫자 입니다." << endl << endl;
			Sleep(1000);
		}
		//// 컴퓨터가 정한 숫자보다 플레이어가 숫자가 같을 경우
		else
		{
			cout << "정답입니다." << endl;
			Sleep(1000);
			break;
		}
	}
}