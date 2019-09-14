#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int main() 
{
	srand(time(NULL));
	int ComputerChoice = rand() % 3 + 1; // 컴퓨터가 정하는 것
	int UserChioce; //플레이어가 정하는것
	cout << "'가위 바위 보' 게임!" << endl;
	cout << "컴퓨터를 이겨보세요. " << endl;
	cout << "1번을 누르면 가위, 2번을 누르면 바위, 3번을 누르면 보 입니다." << endl;
	cin >> UserChioce;
	
	//가위를 낼경우
	if (UserChioce == 1)
	{
		cout << "당신은 가위를 냈습니다." << endl << endl;
		Sleep(1000);

		//컴퓨터가 가위를 낼경우
		if (ComputerChoice == 1)
		{
			cout << "컴퓨터는 가위를 냈습니다." << endl << endl;
			cout << "비겼습니다." << endl;
		}
		//컴퓨터가 바위를 낼경우
		else if (ComputerChoice == 2)
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
	else if (UserChioce == 2)
	{
		cout << "당신은 바위를 냈습니다." << endl << endl;
		Sleep(1000);
		//컴퓨터가 가위를 낼경우
		if (ComputerChoice == 1)
		{
			cout << "컴퓨터는 가위를 냈습니다." << endl << endl;
			cout << "이겼습니다." << endl;
		}
		//컴퓨터가 바위를 낼경우
		else if (ComputerChoice == 2)
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
	else if (UserChioce == 3)
	{
		cout << "당신은 보를 냈습니다." << endl << endl;
		Sleep(1000);
		//컴퓨터가 가위를 낼경우
		if (ComputerChoice == 1)
		{
			cout << "컴퓨터는 가위를 냈습니다." << endl << endl;
			cout << "졌습니다." << endl;
		}
		//컴퓨터가 바위를 낼경우
		else if (ComputerChoice == 2)
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
	//잘못된 숫자를 입력할 경우
	else
	{
		cout << "제대로 눌러주세요" << endl << endl;
	}
	return 0;
}