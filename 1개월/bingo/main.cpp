#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;


//사이즈
//플레이어 컴퓨터 빙고판
//숫자입력
//빙고 조건
//승리 조건
struct BINGO
{
	int board[5][5]; //빙고판
	int bingoValue = 0; //현재까지 빙고의 갯수
	bool is_XBingo[5] = { false }; //x축이 빙고인지 아닌지 판단
	bool is_YBingo[5] = { false }; //y축이 빙고인지 아닌지 판단
	bool is_Bingo[2] = { false }; //대각선축이 빙고인지 아닌지 판단
};

int main()
{
	cout << "BINGO 게임을 시작 하겠습니다." << endl;
	srand(time(NULL));
	int gameCount = 0; //플레이하는 게임 숫자
	BINGO player; //플레이어 구조체
	BINGO computer; //컴퓨터 구조체
	int number[25]; //빙고판 숫자
	int (*playerNumber)[5] = (int(*)[5])number; // 1차원 배열을 2차원 배열로 변환
	int (*computerNumber)[5] = (int(*)[5])number; //1차원 배열을 2차원 배열로 변환
	int select; //번호 입력
	bool isUserTurn = true; //유저턴 인진 컴퓨터턴인지 확인하는 변수
	
	//번호 입력
	for (int i = 0; i < 25; i++)
	{
		number[i] = i;
	} 
	//번호 섞기
	for (int i = 0; i < 1000; i++)
	{
		int index1 = rand() % 25;
		int index2 = rand() % 25;
		int temp = number[index1];
		number[index1] = number[index2];
		number[index2] = temp;
	}
	
	//플레이어 번호 입력
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			player.board[i][j] = playerNumber[i][j]+1;
		}
	}
	//번호 다시 섞기
	for (int i = 0; i < 1000; i++)
	{
		int index1 = rand() % 25;
		int index2 = rand() % 25;
		int temp = number[index1];
		number[index1] = number[index2];
		number[index2] = temp;
	}
	//컴퓨터 번호 입력
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			computer.board[i][j] = computerNumber[i][j]+1;
		}
	}
	//중복되는 숫자를 구하기 위한 배열로 초기화
	for (int i = 0; i < 25; i++)
	{
		number[i] = 0;
	}
	//빙고판 그리기
	while (true)
	{
		int randomValue = -1;
		cout << "플레이어 빙고판        컴퓨터 빙고판" << endl;
		cout << "┌─────────┐┌─────────┐ " << endl;
		for (int i = 0; i < 5; i++)
		{
			//플레이어 빙고판
			for (int j = 0; j < 5; j++)
			{
				if (player.board[i][j] < 10 && j == 4)
				{
					cout << "│ " << player.board[i][j] << "│";
				}
				else if (player.board[i][j] < 10)
				{
					cout << "│ " << player.board[i][j];
				}
				else if (player.board[i][j] >= 10 && j == 4)
				{
					cout << "│" << player.board[i][j] << "│";
				}
				else if (player.board[i][j] >= 10)
				{
					cout << "│" << player.board[i][j];
				}

			}
			//컴퓨터 빙고판
			for (int j = 0; j < 5; j++)
			{
				if (computer.board[i][j] < 10 && j == 4)
				{
					cout << "│ " << computer.board[i][j] << "│\t";
				}
				else if (computer.board[i][j] < 10)
				{
					cout << "│ " << computer.board[i][j];
				}
				else if (computer.board[i][j] >= 10 && j == 4)
				{
					cout << "│" << computer.board[i][j] << "│\t";
				}
				else if (computer.board[i][j] >= 10)
				{
					cout << "│" << computer.board[i][j];
				}

			}
			if (i < 4)
			{
				cout << endl << "├─────────┤├─────────┤ ";
			}
			else
			{
				cout << endl << "└─────────┘└─────────┘ ";
			}
			cout << endl;
		}
		cout << "플레이어 빙고 수: " << player.bingoValue << "\t컴퓨터 빙고 수: " << computer.bingoValue << endl;
		//번호 입력
		if (isUserTurn == true)
		{
			while (true)
			{
				cout << "번호를 입력해주세요" << endl;
				cin >> select;
				//0이하 26이상을 선택하면 다시 입력
				if (select > 25 || select < 1)
				{
					cout << "제대로 된 번호를 입력해주세요" << endl;
				}
				else
				{
					// 선택한 숫자가 1 이면 number[0]에 있는 값이 0이면 턴을 넘기고 아니면 다시 뽑는다
					if (number[select - 1] == 0)
					{
						number[select-1] = select;
						isUserTurn = false;
						break;
					}
					else
					{
						cout << "이미 이전에 사용한 숫자입니다." << endl << endl;
					}
				}
			}
		}
		else
		{
			randomValue = rand() % 25 + 1;
			while (true)
			{
				//플레이어 숫자랑 같은 숫자가 안나올때
				if (select != randomValue)
				{
					//컴퓨터에 있는 숫자랑 랜덤값이랑 다를때
					if (number[randomValue-1] == 0)
					{
						number[randomValue - 1] = randomValue;
						isUserTurn = true;
						break;
					}
					else
					{
						randomValue = rand() % 25 + 1;
					}
				}
			}
			cout << "컴퓨터의 턴 입니다." << endl;
			cout << "컴퓨터는 " << randomValue << "를 선택했습니다." << endl;
			Sleep(500);
		}

		//맞춘 번호를 99으로 바꿈
		for (int i = 0; i < 5;i++)
		{
			for (int j = 0; j < 5; j++)
			{
				//유저가 입력한 값이 맞을때
				if (player.board[i][j] == select)
				{
					player.board[i][j] = 99;
				}
				//컴퓨터가 입력한 값이 맞을때
				else if (player.board[i][j] == randomValue)
				{
					player.board[i][j] = 99;
				}
				if (computer.board[i][j] == select)
				{
					computer.board[i][j] = 99;
				}
				else if (computer.board[i][j] == randomValue)
				{
					computer.board[i][j] = 99;
				}

			}
		}
		//플레이어 빙고수 확인
		int p_xCount[5] = { 0 }; //x축 카운트구하기
		int p_yCount[5] = { 0 }; //y축 카운트구하기
		int p_Count[2] = { 0 }; //대각선 카운트 구하기
		for (int i = 0; i < 5; i++)
		{
			switch (i)
			{
				//첫번째 가로 줄 빙고
				case 0:
				{
					for (int j = 0; j < 5; j++)
					{
						if (player.board[i][j] == 99)
						{
							p_xCount[i]++;
							//카운트가 5이고 bool값이 false일때 빙고가 된다
							if (p_xCount[i] == 5 && player.is_XBingo[i] == false)
							{
								cout << "플레이어 :빙고 !" << endl;
								player.bingoValue++;
								player.is_XBingo[i] = true;
							}
						}
					}
				}
				break;
				//두번째 가로 줄 빙고
				case 1:
				{
					for (int j = 0; j < 5; j++)
					{
						if (player.board[i][j] == 99)
						{
							p_xCount[i]++;
							//카운트가 5이고 bool값이 false일때 빙고가 된다
							if (p_xCount[i] == 5 && player.is_XBingo[i] == false)
							{
								cout << "플레이어 :빙고 !" << endl;
								player.bingoValue++;
								player.is_XBingo[i] = true;
							}
						}
					}
				}
				break;
				//세번째 가로 줄 빙고
				case 2:
				{
					for (int j = 0; j < 5; j++)
					{
						if (player.board[i][j] == 99)
						{
							p_xCount[i]++;
							//카운트가 5이고 bool값이 false일때 빙고가 된다
							if (p_xCount[i] == 5 && player.is_XBingo[i] == false)
							{
								cout << "플레이어 :빙고 !" << endl;
								player.bingoValue++;
								player.is_XBingo[i] = true;
							}
						}
					}
				}
				break;
				//네번째 가로 줄 빙고
				case 3:
				{
					for (int j = 0; j < 5; j++)
					{
						if (player.board[i][j] == 99)
						{
							p_xCount[i]++;
							//카운트가 5이고 bool값이 false일때 빙고가 된다
							if (p_xCount[i] == 5 && player.is_XBingo[i] == false)
							{
								cout << "플레이어 :빙고 !" << endl;
								player.bingoValue++;
								player.is_XBingo[i] = true;
							}
						}
					}
				}
				break;
				//다섯번째 가로 줄 빙고
				case 4:
				{
					for (int j = 0; j < 5; j++)
					{
						if (player.board[i][j] == 99)
						{
							p_xCount[i]++;
							//카운트가 5이고 bool값이 false일때 빙고가 된다
							if (p_xCount[i] == 5 && player.is_XBingo[i] == false)
							{
								cout << "플레이어 :빙고 !" << endl;
								player.bingoValue++;
								player.is_XBingo[i] = true;
							}
						}
					}
				}
				break;
			}
		}
		//Y축 빙고 구하기
		for (int j = 0; j < 5; j++)
		{
			switch (j)
			{
				//첫번째 세로 줄 빙고
				case 0:
				{
					for (int i = 0; i < 5; i++)
					{
						if (player.board[i][j] == 99)
						{
							p_yCount[j]++;
							//카운트가 5이고 bool값이 false일때 빙고가 된다
							if (p_yCount[j] == 5 && player.is_YBingo[j] == false)
							{
								cout << "플레이어 :빙고 !" << endl;
								player.bingoValue++;
								player.is_YBingo[j] = true;
							}
						}
					}
				}
				break;
				//두번째 세로 줄 빙고
				case 1:
				{
					for (int i = 0; i < 5; i++)
					{
						if (player.board[i][j] == 99)
						{
							p_yCount[j]++;
							//카운트가 5이고 bool값이 false일때 빙고가 된다
							if (p_yCount[j] == 5 && player.is_YBingo[j] == false)
							{
								cout << "플레이어 :빙고 !" << endl;
								player.bingoValue++;
								player.is_YBingo[j] = true;
							}
						}
					}
				}
				break;
				//세번째 세로 줄 빙고
				case 2:
				{
					for (int i = 0; i < 5; i++)
					{
						if (player.board[i][j] == 99)
						{
							p_yCount[j]++;
							//카운트가 5이고 bool값이 false일때 빙고가 된다
							if (p_yCount[j] == 5 && player.is_YBingo[j] == false)
							{
								cout << "플레이어 :빙고 !" << endl;
								player.bingoValue++;
								player.is_YBingo[j] = true;
							}
						}
					}
				}
				break;
				//네번째 세로 줄 빙고
				case 3:
				{
					for (int i = 0; i < 5; i++)
					{
						if (player.board[i][j] == 99)
						{
							p_yCount[j]++;
							//카운트가 5이고 bool값이 false일때 빙고가 된다
							if (p_yCount[j] == 5 && player.is_YBingo[j] == false)
							{
								cout << "플레이어 :빙고 !" << endl;
								player.bingoValue++;
								player.is_YBingo[j] = true;
							}
						}
					}
				}
				break;
				//다섯번째 세로 줄 빙고
				case 4:
				{
					for (int i = 0; i < 5; i++)
					{
						if (player.board[i][j] == 99)
						{
							p_yCount[j]++;
							//카운트가 5이고 bool값이 false일때 빙고가 된다
							if (p_yCount[j] == 5 && player.is_YBingo[j] == false)
							{
								cout << "플레이어 :빙고 !" << endl;
								player.bingoValue++;
								player.is_YBingo[j] = true;
							}
						}
					}
				}
				break;
			}
		}

		//밑으로 대각선 빙고 확인
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i == j)
				{
					if (player.board[i][j] == 99)
					{
						p_Count[0]++;
						//카운트가 5이고 bool값이 false일때 빙고가 된다
						if (p_Count[0] == 5 && player.is_Bingo[0] == false)
						{
							cout << "플레이어 :빙고 !" << endl;
							player.bingoValue++;
							player.is_Bingo[0] = true;
						}
					}
				}
				//역대각선 빙고
				if (i + j == 4)
				{
					if (player.board[i][j] == 99)
					{
						p_Count[1]++;
						if (p_Count[1] == 5 && player.is_Bingo[1] == false)
						{
							cout << "플레이어 :빙고 !" << endl;
							player.bingoValue++;
							player.is_Bingo[1] = true;
						}
					}
				}
			}
		}

		//컴퓨터 빙고수 확인
		int c_xCount[5] = { 0 }; //x축 카운트구하기
		int c_yCount[5] = { 0 }; //y축 카운트구하기
		int c_Count[2] = { 0 };
		for (int i = 0; i < 5; i++)
		{
			switch (i)
			{
				//첫번째 가로 줄 빙고
			case 0:
			{
				for (int j = 0; j < 5; j++)
				{
					if (computer.board[i][j] == 99)
					{
						c_xCount[i]++;
						//카운트가 5이고 bool값이 false일때 빙고가 된다
						if (c_xCount[i] == 5 && computer.is_XBingo[i] == false)
						{
							cout << "컴퓨터 : 빙고 !" << endl;
							computer.bingoValue++;
							computer.is_XBingo[i] = true;
						}
					}
				}
			}
			break;
			//두번째 가로 줄 빙고
			case 1:
			{
				for (int j = 0; j < 5; j++)
				{
					if (computer.board[i][j] == 99)
					{
						c_xCount[i]++;
						//카운트가 5이고 bool값이 false일때 빙고가 된다
						if (c_xCount[i] == 5 && computer.is_XBingo[i] == false)
						{
							cout << "컴퓨터 : 빙고 !" << endl;
							computer.bingoValue++;
							computer.is_XBingo[i] = true;
						}
					}
				}
			}
			break;
			//세번째 가로 줄 빙고
			case 2:
			{
				for (int j = 0; j < 5; j++)
				{
					if (computer.board[i][j] == 99)
					{
						c_xCount[i]++;
						//카운트가 5이고 bool값이 false일때 빙고가 된다
						if (c_xCount[i] == 5 && computer.is_XBingo[i] == false)
						{
							cout << "컴퓨터 : 빙고 !" << endl;
							computer.bingoValue++;
							computer.is_XBingo[i] = true;
						}
					}
				}
			}
			break;
			//네번째 가로 줄 빙고
			case 3:
			{
				for (int j = 0; j < 5; j++)
				{
					if (computer.board[i][j] == 99)
					{
						c_xCount[i]++;
						//카운트가 5이고 bool값이 false일때 빙고가 된다
						if (c_xCount[i] == 5 && computer.is_XBingo[i] == false)
						{
							cout << "컴퓨터 : 빙고 !" << endl;
							computer.bingoValue++;
							computer.is_XBingo[i] = true;
						}
					}
				}
			}
			break;
			//다섯번째 가로 줄 빙고
			case 4:
			{
				for (int j = 0; j < 5; j++)
				{
					if (computer.board[i][j] == 99)
					{
						c_xCount[i]++;
						//카운트가 5이고 bool값이 false일때 빙고가 된다
						if (c_xCount[i] == 5 && computer.is_XBingo[i] == false)
						{
							cout << "컴퓨터 : 빙고 !" << endl;
							computer.bingoValue++;
							computer.is_XBingo[i] = true;
						}
					}
				}
			}
			break;
			}
		}
		//Y축 빙고 구하기
		for (int j = 0; j < 5; j++)
		{
			switch (j)
			{
				//첫번째 세로 줄 빙고
			case 0:
			{
				for (int i = 0; i < 5; i++)
				{
					if (computer.board[i][j] == 99)
					{
						c_yCount[j]++;
						//카운트가 5이고 bool값이 false일때 빙고가 된다
						if (c_yCount[j] == 5 && computer.is_YBingo[j] == false)
						{
							cout << "컴퓨터 : 빙고 !" << endl;
							computer.bingoValue++;
							computer.is_YBingo[j] = true;
						}
					}
				}
			}
			break;
			//두번째 세로 줄 빙고
			case 1:
			{
				for (int i = 0; i < 5; i++)
				{
					if (computer.board[i][j] == 99)
					{
						c_yCount[j]++;
						//카운트가 5이고 bool값이 false일때 빙고가 된다
						if (c_yCount[j] == 5 && computer.is_YBingo[j] == false)
						{
							cout << "컴퓨터 : 빙고 !" << endl;
							computer.bingoValue++;
							computer.is_YBingo[j] = true;
						}
					}
				}
			}
			break;
			//세번째 세로 줄 빙고
			case 2:
			{
				for (int i = 0; i < 5; i++)
				{
					if (computer.board[i][j] == 99)
					{
						c_yCount[j]++;
						//카운트가 5이고 bool값이 false일때 빙고가 된다
						if (c_yCount[j] == 5 && computer.is_YBingo[j] == false)
						{
							cout << "컴퓨터 : 빙고 !" << endl;
							computer.bingoValue++;
							computer.is_YBingo[j] = true;
						}
					}
				}
			}
			break;
			//네번째 세로 줄 빙고
			case 3:
			{
				for (int i = 0; i < 5; i++)
				{
					if (computer.board[i][j] == 99)
					{
						c_yCount[j]++;
						//카운트가 5이고 bool값이 false일때 빙고가 된다
						if (c_yCount[j] == 5 && computer.is_YBingo[j] == false)
						{
							cout << "컴퓨터 : 빙고 !" << endl;
							computer.bingoValue++;
							computer.is_YBingo[j] = true;
						}
					}
				}
			}
			break;
			//다섯번째 세로 줄 빙고
			case 4:
			{
				for (int i = 0; i < 5; i++)
				{
					if (computer.board[i][j] == 99)
					{
						c_yCount[j]++;
						//카운트가 5이고 bool값이 false일때 빙고가 된다
						if (c_yCount[j] == 5 && computer.is_YBingo[j] == false)
						{
							cout << "컴퓨터 : 빙고 !" << endl;
							computer.bingoValue++;
							computer.is_YBingo[j] = true;
						}
					}
				}
			}
			break;
			}
		}

		//밑으로 대각선 빙고 확인
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i == j)
				{
					if (computer.board[i][j] == 99)
					{
						c_Count[0]++;
						//카운트가 5이고 bool값이 false일때 빙고가 된다
						if (c_Count[0] == 5 && computer.is_Bingo[0] == false)
						{
							cout << "컴퓨터 : 빙고 !" << endl;
							computer.bingoValue++;
							computer.is_Bingo[0] = true;
						}
					}
				}
				//역대각선 빙고
				if (i + j == 4)
				{
					if (computer.board[i][j] == 99)
					{
						c_Count[1]++;
						//카운트가 5이고 bool값이 false일때 빙고가 된다
						if (c_Count[1] == 5 && computer.is_Bingo[1] == false)
						{
							cout << "컴퓨터 : 빙고 !" << endl;
							computer.bingoValue++;
							computer.is_Bingo[1] = true;
						}
					}
				}
			}
		}
		//3개 빙고 하였을때 우승
		if (player.bingoValue == 3)
		{
			cout << "플레이어 우승!!" << endl;
			Sleep(1000);
			gameCount++;
		}
		else if (computer.bingoValue ==3)
		{
			cout << "컴퓨터 우승!!" << endl;
			Sleep(1000);
			gameCount++;
		}
		else if (player.bingoValue == 3 && computer.bingoValue == 3)
		{
			cout << "비겼습니다..." << endl;
			Sleep(1000);
			gameCount++;
		}
		if (gameCount > 5)
		{
			cout << "오늘은 여기 까지..." << endl;
			break;
		}
		Sleep(1500);
		system("cls");
	}
	return 0;
}