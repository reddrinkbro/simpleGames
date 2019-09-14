#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	int SelectMode; // 강화선택, 현재 강화 상태, 게임종료 선택하기 위한 변수
	int PresentLevel = 0; // 현재 강화 정도
	int Strengthen; // 강화 확률
	srand(time(NULL));

	//음.. 발생될수는 없지만 이상한 버그가 날 경우? 
	//강화 수치가 음수일 경우, 강화 수치가 41이상일 경우
	if(PresentLevel<0 || PresentLevel > 40){
		cout << "현재 버그가 났네요. 죄송합니다." << endl;
		return 0;
	}
	cout << "'극악'제련소에 오신것을 환영합니다." << endl << endl;
	cout << "최대 강화 수치는 40이야" << endl << endl;
	cout << "니가 과연 할수 있을까? ^^" << endl << endl;
	while(true) {
		//강화 확률, 확률의 바탕이 되는 수 'Strengthen'는 랜덤으로 뽑고 10에서 랜덤수를 뺀값을 'PresentStrengthen'에 저장, 강화 단계가 10단계 밑에 일때
		if (PresentLevel < 10)
		{
			Strengthen = rand() % 10;
		}
		//강화 확률, 확률의 바탕이 되는 수 'Strengthen'는 랜덤으로 뽑고 100사이에서 
		else if (PresentLevel < 20)
		{

			Strengthen = rand() % 100;

		}
		//강화 확률, 확률의 바탕이 되는 수 'Strengthen'는 랜덤으로 뽑고 30에서 랜덤수를 뺀값을 'PresentStrengthen'에 저장, 강화 단계가 30단계 밑에 일때
		else if (PresentLevel < 30)
		{
			Strengthen = rand() % 1000;

		}
		//강화 확률, 확률의 바탕이 되는 수 'Strengthen'는 랜덤으로 뽑고 40에서 랜덤수를 뺀값을 'PresentStrengthen'에 저장, 강화 단계가 40단계 밑에 일때
		else if (PresentLevel < 40)
		{
			Strengthen = rand() % 10000;
		}
		//음.. 발생될수는 없지만 이상한 버그가 날 경우? 
		//강화 수치가 음수일 경우, 강화 수치가 41이상일 경우
		if (PresentLevel > 40 || PresentLevel < 0) {
			cout << "현재 버그가 났네요. 죄송합니다." << endl;
			return 0;
		}

		cout << "현재 강화 상태는 +" << PresentLevel << "입니다." << endl << endl;
		cout << "하고 싶은 행동을 정하세요." << endl << endl;
		cout << "1.강화하기 2.나가기" << endl;
		cin >> SelectMode; // 하고 싶은 행동 입력
		cout << endl;
		if (SelectMode == 1)
		{
			//10단계 이전
			if(PresentLevel < 10)
			{
				// Strengthen값이 현재 강화 상태와 같거나 더 크면 강화 성공, 그렇지 않으면 실패 
				if (Strengthen >= PresentLevel)
				{
					cout << "강화중";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << "." << endl;;
					PresentLevel++;
					_sleep(1000);
					cout << "강화를 성공하셨습니다." << endl;
					_sleep(500);
					//강화를 성공하면 화면을 지운다.
					system("cls");
				}
				else
				{
					cout << "강화중";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << "." << endl;;
					PresentLevel = 0;
					_sleep(1000);
					cout << "강화에 실패하셨습니다 풉!" << endl;
					_sleep(1000);
					//강화를 실패하면 화면을 지운다.
					system("cls");
				}
			}
			//20단계 이전
			else if (PresentLevel < 20 && PresentLevel >= 10)
			{
				if (Strengthen <= 19-PresentLevel)
				{
					cout << "강화중";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << "." << endl;;
					PresentLevel++;
					_sleep(1000);
					cout << "강화를 성공하셨습니다." << endl;
					_sleep(500);
					//강화를 성공하면 화면을 지운다.
					system("cls");
				}
				else
				{
					cout << "강화중";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << "." << endl;;
					PresentLevel = 0;
					_sleep(1000);
					cout << "강화에 실패하셨습니다 풉!" << endl;
					_sleep(1000);
					//강화를 실패하면 화면을 지운다.
					system("cls");
				}
			}
			//30단계 이전
			else if (PresentLevel < 30 && PresentLevel >= 20)
			{
				if (Strengthen <= 29 - PresentLevel)
				{
					cout << "강화중";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << "." << endl;;
					PresentLevel++;
					_sleep(1000);
					cout << "강화를 성공하셨습니다." << endl;
					_sleep(500);
					//강화를 성공하면 화면을 지운다.
					system("cls");
				}
				else
				{
					cout << "강화중";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << "." << endl;;
					PresentLevel = 0;
					_sleep(1000);
					cout << "강화에 실패하셨습니다 풉!" << endl;
					_sleep(1000);
					//강화를 실패하면 화면을 지운다.
					system("cls");
				}
			}
			//40단계 이전
			else if (PresentLevel < 40 && PresentLevel >= 30)
			{
				if (Strengthen <= 39 - PresentLevel)
				{
					cout << "강화중";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << "." << endl;;
					PresentLevel++;
					_sleep(1000);
					cout << "강화를 성공하셨습니다." << endl;
					_sleep(500);
					//강화를 성공하면 화면을 지운다.
					system("cls");
				}
				else
				{
					cout << "강화중";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << "." << endl;;
					PresentLevel = 0;
					_sleep(1000);
					cout << "강화에 실패하셨습니다 풉!" << endl;
					_sleep(1000);
					//강화를 실패하면 화면을 지운다.
					system("cls");
				}
			}
			// 모든 강화를 성공하였을때
			else if (PresentLevel == 40)
			{
				cout << "대단하긴 한데.. 너무 사기 친듯? 그게 아니면 로또 사러 가봐^^" << endl << endl;
				cout << "모든 강화에 성공하셨습니다" << endl;
				return 0;
				
			}
		}

		//나가기
		if (SelectMode == 2)
		{
			return 0;
		}
	}
}