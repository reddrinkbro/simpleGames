#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
	srand(time(NULL));
	int RandomValue = rand() % 100 + 1; // 컴퓨터가 마지막에 낼때 사용할 랜덤수
	int ComputerChoice[2]; // 컴퓨터가 정하는 것
	int UserChioce[2]; //플레이어가 정하는것
	int Computer; // 마지막에 컴퓨터가 내는것
	int User; //마지막에 플레이어가 내는것
	cout << "감자에 싹이나서 잎이나서 감자감자 보~! " << endl << endl;
	cout << "하나 빼끼~! " << endl << endl;
	cout << "1번을 누르면 가위, 2번을 누르면 바위, 3번을 누르면 보 입니다.(두번 입력 해야함)" << endl;
	//컴퓨터가 정하는 것
	while (true)
	{
		for (int i = 0; i < 2; i++)
		{
			ComputerChoice[i] = rand() % 3 + 1;
		}
		//둘다 다른값을 나올때 멈춤
		if (ComputerChoice[0] != ComputerChoice[1])
		{
			break;
		}
	}

	//입력 부분 두번 입력해야한다.
	while (true)
	{
		for (int i = 0; i < 2; i++)
		{
			cin >> UserChioce[i];
		}
		//같은 값을 낼때
		if (UserChioce[0] == UserChioce[1])
		{
			cout << "같은 것을 내나니 너는 바보구나? 다시 내~" << endl;
		}

		//다른 값을 낼때 멈춤
		else
		{
			break;
		}
	}
	
	//플레이어와 컴퓨터가 같은 것을 냈을때
	if ((ComputerChoice[0] + ComputerChoice[1]) == (UserChioce[0] + UserChioce[1]))
	{
		if (ComputerChoice[0] > ComputerChoice[1])
		{
			Computer = ComputerChoice[0];
		}
		else
		{
			Computer = ComputerChoice[1];
		}

		//가위,보를 컴퓨터가 냈을때
		if (ComputerChoice[0] == 1 && ComputerChoice[1] == 3)
		{
			Computer = ComputerChoice[0];
		}
		//보, 가위를 컴퓨터가 냈을때
		else if (ComputerChoice[0] == 3 && ComputerChoice[1] == 1)
		{
			Computer = ComputerChoice[1];
		}
	}
	//랜덤 값이 50보다 크면 처음 정한 것을 내고 랜덤값이 50보다 작으면 마지막에 정한것을 낸다
	else
	{
		if (RandomValue > 50)
		{
			Computer = ComputerChoice[0];
		}
		else
		{
			Computer = ComputerChoice[1];
		}
	}

	//컴퓨터가 낸 것을 확인
	cout << "컴퓨터은 ";
	for (int i = 0; i < 2; i++)
	{
		if (ComputerChoice[i] == 1)
		{
			cout << "'가위'";
		}
		if (ComputerChoice[i] == 2)
		{
			cout << "'바위'";
		}
		if (ComputerChoice[i] == 3)
		{
			cout << "'보'";
		}
	}
	cout << "를 냈습니다." << endl << endl;

	//플레이어가 낸것을 확인
	cout << "당신은 ";
	for (int i = 0; i < 2; i++)
	{
		if (UserChioce[i] == 1)
		{
			cout << "'가위'";
		}
		if (UserChioce[i] == 2)
		{
			cout << "'바위'";
		}
		if (UserChioce[i] == 3)
		{
			cout << "'보'";
		}
	}
	cout << "를 냈습니다." << endl << endl;

	//마지막에 낼것을 정하는 부분
	while (true)
	{
		cout << "다음에 낼것을 정해주세요 " << endl;
		cin >> User;

		//처음 낸 것들 중에 있는 경우
		if (User == UserChioce[0])
		{
			break;
		}
		else if (User == UserChioce[1])
		{
			break;
		}

		//처음 낸 것들 중에 없을 경우
		if (User != UserChioce[0])
		{
			cout << "제대로 된 값을 입력해주세요" << endl << endl;
		}

		else if(User != UserChioce[1])
		{
			cout << "제대로 된 값을 입력해주세요" << endl << endl;
		}
	}

	//가위를 낸경우
	if (User == 1)
	{
		cout << "당신은 가위를 냈습니다." << endl << endl;
		Sleep(1000);

		//컴퓨터가 가위를 낼경우
		if (Computer == 1)
		{
			cout << "컴퓨터는 가위를 냈습니다." << endl << endl;
			cout << "비겼습니다." << endl;
		}
		//컴퓨터가 바위를 낼경우
		else if (Computer == 2)
		{
			cout << "컴퓨터는 바위를 냈습니다." << endl << endl;
			cout << "졌습니다." << endl;
		}
		//컴퓨터가 보를 낼경우
		else
		{
			cout << "컴퓨터는 보를 냈습니다." << endl << endl;
			cout << "이겼습니다." << endl;
		}
	}

	//바위를 낼경우
	else if (User == 2)
	{
		cout << "당신은 바위를 냈습니다." << endl << endl;
		Sleep(1000);
		//컴퓨터가 가위를 낼경우
		if (Computer == 1)
		{
			cout << "컴퓨터는 가위를 냈습니다." << endl << endl;
			cout << "이겼습니다." << endl;
		}
		//컴퓨터가 바위를 낼경우
		else if (Computer == 2)
		{
			cout << "컴퓨터는 바위를 냈습니다." << endl << endl;
			cout << "비겼습니다." << endl;
		}
		//컴퓨터가 보를 낼경우
		else
		{
			cout << "컴퓨터는 보를 냈습니다." << endl << endl;
			cout << "졌습니다." << endl;
		}
	}
	//보를 낼경우
	else if (User == 3)
	{
		cout << "당신은 보를 냈습니다." << endl << endl;
		Sleep(1000);
		//컴퓨터가 가위를 낼경우
		if (Computer == 1)
		{
			cout << "컴퓨터는 가위를 냈습니다." << endl << endl;
			cout << "졌습니다." << endl;
		}
		//컴퓨터가 바위를 낼경우
		else if (Computer == 2)
		{
			cout << "컴퓨터는 바위를 냈습니다." << endl << endl;
			cout << "이겼습니다." << endl;
		}
		//컴퓨터가 보를 낼경우
		else
		{
			cout << "컴퓨터는 보를 냈습니다." << endl << endl;
			cout << "비겼습니다." << endl;
		}
	}
	return 0;
}