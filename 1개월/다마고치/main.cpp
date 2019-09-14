#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

struct DAMAGOCHI
{
	char *boring = "♡"; //즐거움 지수
	char *hungry = "★"; //포만감 지수
	char *toilet = "＠"; //청결 지수
	int boringNum = 2; //하트 갯수
	int hungryNum = 2; //별 갯수
	int toiletNum = 2; //골뱅이 갯수
	bool boringState = false;
	bool hungryState = false;
	bool toiletState = false;
	bool isTurn = false; //유저 입력차례인지 아닌지 판단
};

int main()
{
	srand(time(NULL));
	DAMAGOCHI player;
	int random = 3; // 다마고치가 할 행동을 정하기 위한 변수
	int userSelect = 0; //유저가 할 행동
	int modeSelect = 0;
	while (true)
	{
		cout << "다마고치를 키워주세요 ~_~" << endl;
		cout << "다마고치가 죽으면 게임 종료" << endl;
		cout << "1)게임 하기 2)게임 설명 보기 3)종료하기" << endl;
		cin >> modeSelect;
		if (modeSelect == 2)
		{
			cout << "이 게임은 다마고치를 키우는 게임입니다." << endl;
			cout << "다마고치는 총 3개의 상태가 있습니다." << endl;
			cout << "즐거움(♡), 포만감(★), 청결(＠) 상태가 있습니다." << endl;
			cout << "즐거움(♡), 포만감(★), 청결(＠)이 0이되면 다마고치는 죽습니다." << endl;
			cout << "즐거움(♡), 포만감(★), 청결(＠)이 5보다는 커지지 않습니다." << endl;
			cout << "플레이어는 1)놀아주기 2)밥주기 3)청소하기 4)가만히 있기 중 하나의 행동을 합니다" << endl;
			cout << "선택에 따라 다마고치의 생명이 관련되니 조심하여 게임을 플레이 하세요!" << endl;
			Sleep(5000);
			system("cls");
		}
		else if (modeSelect == 1)
		{

			Sleep(2000);
			while (true)
			{
				system("cls");
				cout << random << endl;

				//여기서 미리 감소 시켜서 화면에는 감소된 상태로 출력시킴
				//심심할 경우 
				if (random == 0 && player.isTurn == false)
				{
					player.boringNum--; //심심함 지수 -1
					player.boringState = true; //지루함 상태 존재
				}
				//배고플 경우
				else if (random == 1 && player.isTurn == false)
				{
					player.hungryNum--;//포만함 지수 -1
					player.hungryState = true;//배고픔 상태 존재
				}
				//화장실이 급한 경우
				else if (random == 2 && player.isTurn == false)
				{
					player.toiletNum--; //청결 지수 -1
					player.toiletState = true;//화장실급함 상태 존재
				}
				cout << player.hungryNum << endl;
				cout << "현재 상태 \t 즐거움 :";
				//즐거움 표시
				for (int i = 0; i < player.boringNum; i++)
				{
					cout << player.boring;
				}
				cout << endl;
				cout << "\t\t 배고픔 :";
				//배고픔 표시
				for (int i = 0; i < player.hungryNum; i++)
				{
					cout << player.hungry;
				}
				cout << endl;
				cout << "\t\t 청결 :";
				//청결 표시
				for (int i = 0; i < player.toiletNum; i++)
				{
					cout << player.toilet;
				}
				cout << endl;
				//기분이 안좋을때
				if (player.boringNum < 2 || player.hungryNum < 2 || player.toiletNum < 2)
				{
					cout << " ()  ()" << endl;
					cout << " (ㅜㅜ) " << endl;
					cout << "/l    l> " << endl;
					cout << " ()  ()\t\t";
					if (player.boringState == true) //지루함이 남아 있을때
					{
						cout << "♬";
					}
					if (player.hungryState == true) //배고픔이 남아 있을때
					{
						cout << "※";
					}
					if (player.toiletState == true) //화장실이 급한 상태일때
					{
						cout << "♨";
					}
				}
				//기분이 좋을때
				else
				{
					cout << " () ()" << endl;
					cout << " (^0^) " << endl;
					cout << "/l   l> " << endl;
					cout << " () ()\t\t";
					if (player.boringState == true)//지루함이 남아 있을때
					{
						cout << "♬";
					}
					if (player.hungryState == true)//배고픔이 남아 있을때
					{
						cout << "※";
					}
					if (player.toiletState == true)//화장실이 급한 상태일때
					{
						cout << "♨";
					}
				}
				cout << endl;
				//심심할 경우
				if (random == 0 && player.isTurn == false)
				{
					cout << "현재 다마고치가 심심합니다. 즐거움 지수 -1" << endl;
					player.isTurn = true; //유저 입력턴
				}
				//배고플 경우
				else if (random == 1 && player.isTurn == false)
				{
					cout << "현재 다마고치가 배고픕니다. 포만감 지수 -1" << endl;
					player.isTurn = true;//유저 입력턴
				}
				//화장실이 급한 경우
				else if (random == 2 && player.isTurn == false)
				{
					cout << "현재 다마고치가 화장실이 급합니다. 청결 지수 -1" << endl;
					player.isTurn = true;//유저 입력턴
				}
				//아무런 행동을 하지 않을때
				else if (random > 2 && player.isTurn == false)
				{
					if (player.boringNum < 2 || player.hungryNum < 2 || player.toiletNum < 2)
					{
						cout << "다마고치는 불편합니다." << endl;
						player.isTurn = true;//유저 입력턴
					}
					else
					{
						cout << "다마고치는 기분이 좋습니다." << endl;
						player.isTurn = true;//유저 입력턴
					}
				}
				Sleep(1000);
				// 다마고치를 제대로 관리 못했을 경우
				if (player.boringNum < 1 || player.hungryNum < 1 || player.toiletNum < 1)
				{
					cout << "다마고치가 죽어버렸습니다" << endl;
					Sleep(1000);
					system("cls");
					break;
				}

				cout << "다마고치에게 시킬 행동을 선택해주세요" << endl;
				cout << "1)놀아주기 2)밥주기 3)청소하기 4)가만히 두기" << endl;
				cin >> userSelect;
				if (userSelect == 1 && player.isTurn == true)
				{
					//즐거움 지수가 5보다 클때 5로 고정 시키기
					if (player.boringNum == 5)
					{
						cout << "이미 충분히 즐겁습니다." << endl;
					}
					else
					{
						cout << "다마고치랑 같이 놀아주었다 즐거움 지수 +1" << endl;
						player.boringNum += 1; // 즐거움 +1
					}
					player.isTurn = false; //다마고치 행동턴
					player.boringState = false; // 지루함 없애기
				}
				else if (userSelect == 2 && player.isTurn == true)
				{
					//배고픔 지수가 5보다 클때 5로 고정 시키기
					if (player.hungryNum == 5)
					{
						cout << "이미 배가 많이 부릅니다." << endl;
					}
					else
					{
						cout << "다마고치에게 밥을 주었다 포만감 지수 +1" << endl;
						player.hungryNum += 1;// 포만감 +1
					}
					player.isTurn = false; //다마고치 행동턴
					player.hungryState = false; //배고픔 없애기
				}
				else if (userSelect == 3 && player.isTurn == true)
				{
					//청결 지수가 5보다 클때 5로 고정 시키기
					if (player.toiletNum == 5)
					{
						cout << "이미 방은 깨끗합니다" << endl;
					}
					else
					{
						cout << "방을 청소하였다. 청결 지수 +1" << endl;
						player.toiletNum += 1;// 청결 +1
					}
					player.isTurn = false;//다마고치 행동턴
					player.toiletState = false;//배고픔 없애기
				}
				else if (userSelect == 4 && player.isTurn == true)
				{
					cout << "..." << endl;
					player.isTurn = false;//다마고치 행동턴
				}
				//제대로 된 선택을 하지 않을때
				else
				{
					cout << "제대로 된 행동을 선택하세요" << endl;
				}
				random = rand() % 4; //처음은 아무런 행동을 하지 않게 하기위해 마지막에 랜덤을 돌림
				Sleep(1000);
			}
		}
		else if (modeSelect == 3)
		{
			break;
		}
	}
	return 0;

}