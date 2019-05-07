#include "mainGame.h"
#include <Windows.h>
#include "welCome.h"

void pokemonImage();

int main()
{
	system(" mode  con cols=80 lines=55");
	system("title 포켓몬스터");
	system("color ff");
	srand(time(NULL));
	pokemonImage();
	welCome* come = new welCome;
	int select;
	cin >> select;
	while (true)
	{
		if (select == 1)
		{
			delete come;
			system("cls");
			pokemonImage();
			mainGame* main = new mainGame;
			Sleep(1000);
			system("cls");
			pokemonImage();
			main->firstPokemon(); // 처음 보켓몬 선택
			Sleep(500);
			while (true)
			{
				main->selectMode(); //여행가기, 포켓몬센터가기, 인벤토리 보기
			}
			delete main;
			break;
		}
		else if (select == 2)
		{
			if (come->explainGame() == 1)
			{
				select = 1;
			}
		}
		else if (select == 3)
		{
			for (int i = 0; i < 6; i++)
			{
				cout << endl;
			}
			cout << "\t\t 게임을 종료합니다." << endl;
			break;
			return 0;
		}
	}
}
void pokemonImage()
{
	for (int i = 0; i < 6; i++)
	{
		cout << endl;
	}
	cout << "\t■■■   ■■   ■    ■  ■■■  ■      ■   ■■   ■      ■" << endl;
	cout << "\t■  ■ ■    ■ ■  ■    ■      ■■  ■■ ■    ■ ■■    ■" << endl;
	cout << "\t■■   ■    ■ ■■      ■■■  ■  ■  ■ ■    ■ ■  ■  ■" << endl;
	cout << "\t■     ■    ■ ■  ■    ■      ■      ■ ■    ■ ■    ■■" << endl;
	cout << "\t■       ■■   ■    ■  ■■■  ■      ■   ■■   ■      ■" << endl;
}