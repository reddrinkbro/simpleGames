#include "welCome.h"



welCome::welCome()
{
	for (int i = 0; i < 6; i++)
	{
		cout << endl;
	}
	cout << "\t\t 1)게임시작\t2)게임방법\t3)게임종료" << endl << endl;
	int select; // 게임 모드 선택
	cout << "\t\t입력해주세요 : ";
}


welCome::~welCome()
{
}

int welCome::explainGame()
{
	system("cls");
	int back; //뒤로가기
	cout << "게임 목표" << endl;
	cout << "플레이어는 각 지방을 여행하면서 총 6마리의 포켓몬을 키우면 됩니다." << endl << endl;
	cout << "포켓몬을 잡는 방법" << endl;
	cout << "포켓몬을 잡는 방법은 포켓몬센터에 가서 몬스터볼을 구입하여 잡으면 된다." << endl << endl;
	cout << "포켓몬 치료" << endl;
	cout << "포켓몬이 부상을 입었을 경우 포켓몬 센터에서 치료를 할수 있다." << endl << endl;
	cout << "맵" << endl;
	cout << "맵은 총 5개로 전기시티(전기포켓몬) 포레스트(풀포켓몬) 볼케이노(불포켓몬) 스톤마운틴(바위포켓몬) 워터킹덤(물포켓몬)이 있다." << endl << endl;
	cout << "아이템" << endl;
	cout << "아이템은 포켓몬을 잡기위한 몬스터볼, 포켓몬을 치료하기위한 포켓몬 먹이가 있다." << endl << endl;
	cout << "싸움 방식" << endl;
	cout << "적 포켓몬과 내 포켓몬이 서로 번갈아 가면서 싸우는 형식이다." << endl;
	cout << "포켓몬은 스킬을 사용하여 배틀을 한다." << endl;
	cout << "포켓몬은 스킬을 사용할떄마다 스킬포인트를 사용하며 스킬포인트가 부족하면 스킬을 사용할수 없습니다." << endl << endl;
	cout << "포켓몬 진화" << endl;
	cout << "포켓몬은 경험치가 20이 되면 포켓몬 센터에서 진화를 할수 있다." << endl;
	cout << "진화를 하게 되면 능력치가 오르게됩니다." << endl << endl;
	cout << "1을 누르시면 게임 시작 합니다." << endl;
	cout << "입력해주세요 : ";
	cin >> back;
	return back;
}
