#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
	int RandomValue; //��ǻ�Ͱ� �����ϴ°�
	int ChoiceValue; // ���� �����ϴ� ����

	srand(time(NULL));
	RandomValue = rand() % 99 + 1; // 1���� 100���� ����
	while (true)
	{
		cout << "���ڸ� �Է��ϼ���"<< endl;
		cin >> ChoiceValue;
		cout << endl;

		// ��ǻ�Ͱ� ���� ���ں��� �÷��̾ ���ڰ� Ŭ���
		if (RandomValue > ChoiceValue)
		{
			cout << "�Է� �Ͻ� ���ں��� �� ū ���� �Դϴ�." << endl <<endl;
			Sleep(1000);
		}
		// ��ǻ�Ͱ� ���� ���ں��� �÷��̾ ���ڰ� ���� ���
		else if (RandomValue < ChoiceValue)
		{
			cout << "�Է� �Ͻ� ���ں��� �� ���� ���� �Դϴ�." << endl << endl;
			Sleep(1000);
		}
		//// ��ǻ�Ͱ� ���� ���ں��� �÷��̾ ���ڰ� ���� ���
		else
		{
			cout << "�����Դϴ�." << endl;
			Sleep(1000);
			break;
		}
	}
}