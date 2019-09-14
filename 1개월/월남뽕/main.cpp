#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

struct Card 
{
	char* name;
	int cardNumber;
	bool isAlphabet = false; //아스키코드 사용을 위함
};


int main()
{

	srand(time(NULL));
	int card[52]; //52장 카드
	char Ace = 'A'; //아스키코드 사용하기 위한 변수
	char Jack = 'J';//아스키코드 사용하기 위한 변수
	char Queen = 'Q';//아스키코드 사용하기 위한 변수
	char King = 'K';//아스키코드 사용하기 위한 변수
	Card computerCard[3]; // 보기 2개 , 안보이는 카드 1개 0번이 왼쪽 1번이 오른쪽
	int index1, index2, temp;//스왑변수
	int money = 100000; //처음에 가진돈 10만
	int playerChoice = 0; //배팅정하기

	//카드 입력
	for (int i = 0; i < 52; i++)
	{
		card[i]= i;
	}

	//카드 셔플
	
	while (true)
	{
		for (int i = 0; i <1000; i++)
		{
			index1 = rand() % 52;
			index2 = rand() % 52;
			temp = card[index1];
			card[index1] = card[index2];
			card[index2] = temp;
		}
		//카드 3장 선택

		//0~12까지 다이아
		//13~25까지 클로버
		//26~38까지 하트
		//39~51까지 스페이스

		for (int i = 0; i < 3; i++)
		{
			computerCard[i].cardNumber = card[i];
			//0~12 숫자
			if (computerCard[i].cardNumber < 13)
			{
				computerCard[i].name = "◆";
				computerCard[i].cardNumber = computerCard[i].cardNumber + 1;
			}
			//13~25 숫자
			else if (computerCard[i].cardNumber < 26 && computerCard[i].cardNumber >= 13)
			{
				computerCard[i].name = "♣";
				computerCard[i].cardNumber = computerCard[i].cardNumber - 12;
			}
			//26~38 숫자
			else if (computerCard[i].cardNumber < 39 && computerCard[i].cardNumber >= 26)
			{
				computerCard[i].name = "♥";
				computerCard[i].cardNumber = computerCard[i].cardNumber - 25;
			}
			//38~51 숫자
			else if (computerCard[i].cardNumber < 52 && computerCard[i].cardNumber >= 39)
			{
				computerCard[i].name = "♠";
				computerCard[i].cardNumber = computerCard[i].cardNumber - 38;
			}

			//에이스
			if (computerCard[i].cardNumber == 1)
			{
				computerCard[i].isAlphabet = true;
			}
			//잭
			else if (computerCard[i].cardNumber == 11)
			{
				computerCard[i].isAlphabet = true;
			}
			//퀸
			else if (computerCard[i].cardNumber == 12)
			{
				computerCard[i].isAlphabet = true;
			}
			//킹
			else if (computerCard[i].cardNumber == 13)
			{
				computerCard[i].isAlphabet = true;
			}
		}
		//카드 공개
		//A, J, Q, K 일경우
		for (int i = 0; i < 2; i++)
		{
			cout << i + 1 << "번째 카드 : " << computerCard[i].name;
			if (computerCard[i].isAlphabet == true)
			{
				if (computerCard[i].cardNumber == 1)
				{
					cout <<Ace<<"\t";
				}
				//잭
				else if (computerCard[i].cardNumber == 11)
				{
					cout << Jack << "\t";
				}
				//퀸
				else if (computerCard[i].cardNumber == 12)
				{
					cout << Queen << "\t";
				}
				//킹
				else if (computerCard[i].cardNumber == 13)
				{
					cout << King << "\t";
				}
			}
			else
			{
				cout << computerCard[i].cardNumber << "\t";
			}
		}
		cout << endl;

		cout << "현재 가진 돈 : " << money << endl;
		cout << "배팅 하시겠습니까 ? " << endl;
		cout << "1) 5000원 2)10000원 3) 30000원" << endl;
		cin >> playerChoice;
		cout << endl;

		// 첫번째 숫자와 두번째 숫자중 첫번째 숫자가 작을때 
		if (computerCard[0].cardNumber < computerCard[1].cardNumber)
		{
			if (computerCard[0].cardNumber < computerCard[2].cardNumber && computerCard[1].cardNumber > computerCard[2].cardNumber)
			{
				cout << "카드 공개!!!" << endl;
				Sleep(1000);
				//A, J, Q, K 일경우
				if (computerCard[2].isAlphabet == true)
				{
					cout << "카드는 " << computerCard[2].name;
					//에이스
					if (computerCard[2].cardNumber == 1)
					{
						cout << Ace << "입니다." << endl;
					}
					//잭
					else if (computerCard[2].cardNumber == 11)
					{
						cout << Jack << "입니다." << endl;
					}
					//퀸
					else if (computerCard[2].cardNumber == 12)
					{
						cout << Queen << "입니다." << endl;
					}
					//킹
					else if (computerCard[2].cardNumber == 13)
					{
						cout << King << "입니다." << endl;
					}
				}
				//A, J, Q, K 아닐경우
				else 
				{
					cout << "카드는 " << computerCard[2].name << computerCard[2].cardNumber << "입니다." << endl;
				}
				//5000원 배팅
				if (playerChoice == 1)
				{
					cout << "배팅금 5000원 획득" << endl;
					money = money + 5000;
				}
				//10000원 배팅
				else if (playerChoice == 2)
				{
					cout << "배팅금 10000원 획득" << endl;
					money = money + 10000;
				}
				//30000원 배팅
				else if (playerChoice == 3)
				{
					cout << "배팅금 30000원 획득" << endl;
					money = money + 30000;
				}
			}
			//같은 숫자가 나왔을 경우
			else if (computerCard[0].cardNumber == computerCard[1].cardNumber)
			{
				cout << "안타깝네요 같은 숫자가 나와버렸어요" << endl;
				//5000원 배팅
				if (playerChoice == 1)
				{
					cout << "배팅금 5000원 차감" << endl;
					money = money - 5000;
				}
				//10000원 배팅
				else if (playerChoice == 2)
				{
					cout << "배팅금 10000원 차감" << endl;
					money = money - 10000;
				}
				//30000원 배팅
				else if (playerChoice == 3)
				{
					cout << "배팅금 30000원 차감" << endl;
					money = money - 30000;
				}
			}
			else
			{
				cout << "카드 공개!!!" << endl;
				Sleep(1000);
				//A, J, Q, K 일경우
				if (computerCard[2].isAlphabet == true)
				{
					cout << "카드는 " << computerCard[2].name;
					//에이스
					if (computerCard[2].cardNumber == 1)
					{
						cout << Ace << "입니다." << endl;
					}
					//잭
					else if (computerCard[2].cardNumber == 11)
					{
						cout << Jack << "입니다." << endl;
					}
					//퀸
					else if (computerCard[2].cardNumber == 12)
					{
						cout << Queen << "입니다." << endl;
					}
					//킹
					else if (computerCard[2].cardNumber == 13)
					{
						cout << King << "입니다." << endl;
					}
				}
				//A, J, Q, K 아닐경우
				else
				{
					cout << "카드는 " << computerCard[2].name << computerCard[2].cardNumber << "입니다." << endl;
				}
				//5000원 배팅
				if (playerChoice == 1)
				{
					cout << "배팅금 5000원 차감" << endl;
					money = money - 5000;
				}
				//10000원 배팅
				else if (playerChoice == 2)
				{
					cout << "배팅금 10000원 차감" << endl;
					money = money - 10000;
				}
				//30000원 배팅
				else if (playerChoice == 3)
				{
					cout << "배팅금 30000원 차감" << endl;
					money = money - 30000;
				}
			}
		}

		// 첫번째 숫자와 두번째 숫자중 두번째 숫자가 작을때 
		else
		{
			//숨겨진 숫자가 첫번째 숫자보다 크거나같고 두번째 숫자보다 작거나 같을경우 computerCard[1].cardNumber 첫번째 숫자, computerCard[0].cardNumber 두번째 숫자
			if (computerCard[1].cardNumber <= computerCard[2].cardNumber && computerCard[2].cardNumber <= computerCard[0].cardNumber)
			{
				cout << "카드 공개!!!" << endl;
				Sleep(2000);
				//A, J, Q, K 일경우
				if (computerCard[2].isAlphabet == true)
				{
					cout << "카드는 " << computerCard[2].name;
					//에이스
					if (computerCard[2].cardNumber == 1)
					{
						cout << Ace << "입니다." << endl;
					}
					//잭
					else if (computerCard[2].cardNumber == 11)
					{
						cout << Jack << "입니다." << endl;
					}
					//퀸
					else if (computerCard[2].cardNumber == 12)
					{
						cout << Queen << "입니다." << endl;
					}
					//킹
					else if (computerCard[2].cardNumber == 13)
					{
						cout << King << "입니다." << endl;
					}
				}
				//A, J, Q, K 아닐경우
				else
				{
					cout << "카드는 " << computerCard[2].name << computerCard[2].cardNumber << "입니다." << endl;
				}
				//5000원 배팅
				if (playerChoice == 1)
				{
					cout << "배팅금 5000원 차감" << endl;
					money = money - 5000;
				}
				//10000원 배팅
				else if (playerChoice == 2)
				{
					cout << "배팅금 10000원 차감" << endl;
					money = money - 10000;
				}
				//30000원 배팅
				else if (playerChoice == 3)
				{
					cout << "배팅금 30000원 차감" << endl;
					money = money - 30000;
				}
			}
			//같은 숫자가 나왔을때
			else if (computerCard[0].cardNumber == computerCard[1].cardNumber)
			{
				cout << "안타깝네요 같은 숫자가 나와버렸어요" << endl;
				//5000원 배팅
				if (playerChoice == 1)
				{
					cout << "배팅금 5000원 차감" << endl;
					money = money - 5000;
				}
				//10000원 배팅
				else if (playerChoice == 2)
				{
					cout << "배팅금 10000원 차감" << endl;
					money = money - 10000;
				}
				//30000원 배팅
				else if (playerChoice == 3)
				{
					cout << "배팅금 30000원 차감" << endl;
					money = money - 30000;
				}
			}
			else
			{
				cout << "카드 공개!!!" << endl;
				Sleep(2000);
				//A, J, Q, K 일경우
				if (computerCard[2].isAlphabet == true)
				{
					cout << "카드는 " << computerCard[2].name;
					//에이스
					if (computerCard[2].cardNumber == 1)
					{
						cout << Ace << "입니다." << endl;
					}
					//잭
					else if (computerCard[2].cardNumber == 11)
					{
						cout << Jack << "입니다." << endl;
					}
					//퀸
					else if (computerCard[2].cardNumber == 12)
					{
						cout << Queen << "입니다." << endl;
					}
					//킹
					else if (computerCard[2].cardNumber == 13)
					{
						cout << King << "입니다." << endl;
					}
				}
				//A, J, Q, K 아닐경우
				else
				{
					cout << "카드는 " << computerCard[2].name << computerCard[2].cardNumber << "입니다." << endl;
				}
				//5000원 배팅
				if (playerChoice == 1)
				{
					cout << "배팅금 5000원 획득" << endl;
					money = money + 5000;
				}
				//10000원 배팅
				else if (playerChoice == 2)
				{
					cout << "배팅금 10000원 획득" << endl;
					money = money + 10000;
				}
				//30000원 배팅 
				else if (playerChoice == 3)
				{
					cout << "배팅금 30000원 획득" << endl;
					money = money + 30000;
				}
			}
		}
		//모든 돈을 잃었을때
		if (money <= 0)
		{
			cout << "돈을 모두 잃었습니다. " << endl;
			return 0;
		}
		//bool값 초기화
		for (int i = 0;i < 3; i++) 
		{
			computerCard[i].isAlphabet = false; 
		}
		Sleep(1000);
		system("cls");
	}
}