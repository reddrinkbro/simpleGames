#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
	srand(time(NULL));
	int number[25]; //숫자
	int sucess[25]; //정답이 될 배열
	int userSelect = 0; //유저가 선택한 번호
	int userMove = 0; // 유저가 움직이는 방향
	int numberCount = 0; //숫자를 맞춘 갯수
	bool isMove = false;
	
	//숫자 입력
	for (int i = 0; i < 25; i++)
	{
		number[i] = i;
	}
	//정답이 될 배열 입력
	for (int i = 0; i < 25; i++)
	{
		// 1,2,3,4,5...24 까지 입력
		sucess[i] = i+1;
		//마지막에는 0 입력
		if (i == 24)
		{
			sucess[24] = 0;
		}
	}
	//숫자 섞기
	for (int i = 0; i < 1000; i++)
	{
		int index1 = rand() % 25;
		int index2 = rand() % 25;
		int temp = number[index1];
		number[index1] = number[index2];
		number[index2] = temp;
	}
	
	//움직일 번호를 선택한다
	while (true)
	{
		if (isMove == false)
		{
			cout << "숫 자 슬 라 이 드 게 임 ! " << endl << endl;
			cout << "┌─┬─┬─┬─┬─┐" << endl;
			//보드판 그리기
			for (int i = 0; i < 25; i++)
			{
				if (i % 5 == 0)
				{
					cout << "│";
				}
				if (number[i] < 10)
				{
					cout << number[i] << " │";
				}
				else
				{
					cout << number[i] << "│";
				}
				if (i % 5 == 4)
				{
					cout << endl;
					if (i == 24)
					{
						cout << "└─┴─┴─┴─┴─┘" << endl;
					}
					else
					{
						cout << "├─┼─┼─┼─┼─┤" << endl;
					}
					
				}
			}
			while (true)
			{
				cout << "움직일 번호를 정하세요" << endl;
				cin >> userSelect;
				if (userSelect > 24)
				{
					cout << "제대로 된 숫자를 입력하세요" << endl;
				}
				else
				{
					break;
				}
			}
			isMove = true;
		}
		// 번호를 선택했으면 번호를 움직이게 한다.
		else
		{
			while (true)
			{
				//카운트는 반복할때마다 초기화
				numberCount = 0;
				cout << "숫 자 슬 라 이 드 게 임 ! " << endl << endl;
				cout << "┌─┬─┬─┬─┬─┐" << endl;
				//보드판 그리기
				for (int i = 0; i < 25; i++)
				{
					if (i % 5 == 0)
					{
						cout << "│";
					}
					if (number[i] < 10)
					{
						cout << number[i] << " │";
					}
					else
					{
						cout << number[i] << "│";
					}
					if (i % 5 == 4)
					{
						cout << endl;
						if (i == 24)
						{
							cout << "└─┴─┴─┴─┴─┘" << endl;
						}
						else
						{
							cout << "├─┼─┼─┼─┼─┤" << endl;
						}

					}
				}
				for (int i = 0; i < 25; i++)
				{
					//숫자가 제자리에 맞춰졌을때
					if (number[i] == userSelect && number[i] == sucess[i])
					{
						cout << "숫자 " << userSelect << " 정답! " << endl;
						Sleep(1000);
						
						isMove = false;
					}
					if (number[i] == sucess[i])
					{
						//반복문을 돌면서 한번식 확인하여 자리에 맞는 숫자가 있으면 카운트를 1증가
						numberCount++;
						//카운트가 25 즉, 모든 번호가 맞는 자리에 있으면 게임 종료
						if (numberCount == 25)
						{
							cout << "모든 숫자를 맞췄습니다" << endl;
							return 0;
						}
					}
				}
				//다시 숫자 입력
				if (isMove == false)
				{
					break;
				}

				cout << "현재 선택한 번호는 " << userSelect << "입니다" << endl;
				cout << "이동은 왼쪽(4) , 오른쪽(6), 위쪽(8), 아래쪽(5)" << endl;
				cin >> userMove;
				//왼쪽 이동
				if (userMove == 4)
				{
					for (int i = 0; i < 25; i++)
					{
						//선택한 번호랑 같은 번호 찾기
						if (userSelect == number[i])
						{
							//제일 왼쪽은 왼쪽으로 이동하지 못하게 하기
							if (i % 5 != 0)
							{
								int temp = number[i];
								number[i] = number[i - 1];
								number[i - 1] = temp;
								break; //한번만 바뀌게 하기
							}
						}
					}
				}
				//오른쪽 이동
				else if (userMove == 6)
				{
					for (int i = 0; i < 25; i++)
					{
						//선택한 번호랑 같은 번호 찾기
						if (userSelect == number[i])
						{
							//제일 오른쪽은 오른쪽으로 이동하지 못하게 하기
							if (i % 5 != 4)
							{
								int temp = number[i];
								number[i] = number[i + 1];
								number[i + 1] = temp;
								break; //한번만 바뀌게 하기
							}
						}
					}
				}
				//위쪽 이동
				else if (userMove == 8)
				{
					for (int i = 0; i < 25; i++)
					{
						//선택한 번호랑 같은 번호 찾기
						if (userSelect == number[i])
						{
							//제일 위쪽은 위쪽으로 이동하지 못하게 하기
							if (i > 4)
							{
								int temp = number[i];
								number[i] = number[i - 5];
								number[i - 5] = temp;
								break; //한번만 바뀌게 하기
							}
						}
					}
				}
				//아래 이동
				else if (userMove == 5)
				{
					for (int i = 0; i < 25; i++)
					{
						//선택한 번호랑 같은 번호 찾기
						if (userSelect == number[i])
						{
							//제일 아래쪽은 아래쪽으로 이동하지 못하게 하기
							if (i < 20)
							{
								int temp = number[i];
								number[i] = number[i + 5];
								number[i + 5] = temp;
								break; //한번만 바뀌게 하기
							}
						}
					}
				}
				system("cls");
			}
		}
		system("cls");
	}
	return 0;
}