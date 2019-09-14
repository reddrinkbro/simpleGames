#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	int NumOne; //첫번째 번호
	int NumTwo; //두번째 번호
	int NumThree; //세번째 번호
	int NumFour; //네번째 번호
	int NumFive; //다섯번째 번호
	int NumSix; //여섯번째 번호
	int LottoCount = 0; //로또 뽑은 횟수

	srand(time(NULL));

	NumOne = rand() % 45 + 1; //첫번째 랜덤수 생성

	while (true)
	{
		NumTwo = rand() % 45 + 1;	//두번째 랜덤수 생성
		if (NumOne != NumTwo) //첫번째 랜덤수와 두번째 수와 비교 하여 다를때까지 반복을 시킨다 
		{
			break;
		}
	}

	while (true)
	{
		NumThree = rand() % 45 + 1; //세번째 랜덤수 생성
		if (NumOne != NumThree && NumTwo != NumThree) //세번째 랜덤수와 첫번째 두번째 수와 비교 하여 다를때까지 반복을 시킨다 
		{
			break;
		}
	}
	while (true)
	{
		NumFour = rand() % 45 + 1; //네번째 랜덤수 생성
		if (NumOne != NumFour && NumTwo != NumFour && NumThree!=NumFour) //네번째 랜덤수와 첫번째 두번째 세번째 수와 비교 하여 다를때까지 반복을 시킨다 
		{
			break;
		}
	}
	while (true)
	{
		NumFive = rand() % 45 + 1; //다섯번째 랜덤수 생성
		if (NumOne != NumFive && NumTwo != NumFive && NumThree != NumFive && NumFour !=NumFive) //다섯번째 랜덤수와 첫번째 두번째 세번째 네번째수와 비교 하여 다를때까지 반복을 시킨다 
		{
			break;
		}
	}
	while (true)
	{
		NumSix = rand() % 45 + 1; //여섯번째 랜덤수 생성
		if (NumOne != NumSix && NumTwo != NumSix && NumThree != NumSix && NumFour != NumSix && NumFive!= NumSix) //여섯번째 랜덤수와 첫번째 두번째 세번째 네번째 다섯번째수와 비교 하여 다를때까지 반복을 시킨다
		{
			break;
		}
	}
	cout << "첫번째 숫자는 " << NumOne << " 입니다!" << endl;
	cout << "두번째 숫자는 " << NumTwo << " 입니다!" << endl;
	cout << "세번째 숫자는 " << NumThree << " 입니다!" << endl;
	cout << "네번째 숫자는 " << NumFour << " 입니다!" << endl;
	cout << "다섯번째 숫자는 " << NumFive << " 입니다!" << endl;
	cout << "여섯번째 숫자는 " << NumSix << " 입니다!" << endl << endl;
	cout << "이번주 로또 번호는 " << NumOne << ", " << NumTwo << ", " << NumThree << ", " << NumFour << ", " << NumFive << ", " << NumSix << "입니다." << endl;
}