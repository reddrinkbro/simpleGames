#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int main() 
{
	srand(time(NULL));
	int ComputerChoice = rand() % 3 + 1; // ��ǻ�Ͱ� ���ϴ� ��
	int UserChioce; //�÷��̾ ���ϴ°�
	cout << "'���� ���� ��' ����!" << endl;
	cout << "��ǻ�͸� �̰ܺ�����. " << endl;
	cout << "1���� ������ ����, 2���� ������ ����, 3���� ������ �� �Դϴ�." << endl;
	cin >> UserChioce;
	
	//������ �����
	if (UserChioce == 1)
	{
		cout << "����� ������ �½��ϴ�." << endl << endl;
		Sleep(1000);

		//��ǻ�Ͱ� ������ �����
		if (ComputerChoice == 1)
		{
			cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl << endl;
			cout << "�����ϴ�." << endl;
		}
		//��ǻ�Ͱ� ������ �����
		else if (ComputerChoice == 2)
		{
			cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl << endl;
			cout << "�����ϴ�." << endl;
		}
		//��ǻ�Ͱ� ���� �����
		else
		{
			cout << "��ǻ�ʹ� ���� �½��ϴ�." << endl << endl;
			cout << "�̰���ϴ�." << endl;
		}
	}

	//������ �����
	else if (UserChioce == 2)
	{
		cout << "����� ������ �½��ϴ�." << endl << endl;
		Sleep(1000);
		//��ǻ�Ͱ� ������ �����
		if (ComputerChoice == 1)
		{
			cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl << endl;
			cout << "�̰���ϴ�." << endl;
		}
		//��ǻ�Ͱ� ������ �����
		else if (ComputerChoice == 2)
		{
			cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl << endl;
			cout << "�����ϴ�." << endl;
		}
		//��ǻ�Ͱ� ���� �����
		else
		{
			cout << "��ǻ�ʹ� ���� �½��ϴ�." << endl << endl;
			cout << "�����ϴ�." << endl;
		}
	}
	//���� �����
	else if (UserChioce == 3)
	{
		cout << "����� ���� �½��ϴ�." << endl << endl;
		Sleep(1000);
		//��ǻ�Ͱ� ������ �����
		if (ComputerChoice == 1)
		{
			cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl << endl;
			cout << "�����ϴ�." << endl;
		}
		//��ǻ�Ͱ� ������ �����
		else if (ComputerChoice == 2)
		{
			cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl << endl;
			cout << "�̰���ϴ�." << endl;
		}
		//��ǻ�Ͱ� ���� �����
		else
		{
			cout << "��ǻ�ʹ� ���� �½��ϴ�." << endl << endl;
			cout << "�����ϴ�." << endl;
		}
	}
	//�߸��� ���ڸ� �Է��� ���
	else
	{
		cout << "����� �����ּ���" << endl << endl;
	}
	return 0;
}