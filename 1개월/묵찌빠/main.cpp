#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
	srand(time(NULL));
	int RandomValue = rand() % 100 + 1; // ��ǻ�Ͱ� �������� ���� ����� ������
	int ComputerChoice[2]; // ��ǻ�Ͱ� ���ϴ� ��
	int UserChioce[2]; //�÷��̾ ���ϴ°�
	int Computer; // �������� ��ǻ�Ͱ� ���°�
	int User; //�������� �÷��̾ ���°�
	cout << "���ڿ� ���̳��� ���̳��� ���ڰ��� ��~! " << endl << endl;
	cout << "�ϳ� ����~! " << endl << endl;
	cout << "1���� ������ ����, 2���� ������ ����, 3���� ������ �� �Դϴ�.(�ι� �Է� �ؾ���)" << endl;
	//��ǻ�Ͱ� ���ϴ� ��
	while (true)
	{
		for (int i = 0; i < 2; i++)
		{
			ComputerChoice[i] = rand() % 3 + 1;
		}
		//�Ѵ� �ٸ����� ���ö� ����
		if (ComputerChoice[0] != ComputerChoice[1])
		{
			break;
		}
	}

	//�Է� �κ� �ι� �Է��ؾ��Ѵ�.
	while (true)
	{
		for (int i = 0; i < 2; i++)
		{
			cin >> UserChioce[i];
		}
		//���� ���� ����
		if (UserChioce[0] == UserChioce[1])
		{
			cout << "���� ���� ������ �ʴ� �ٺ�����? �ٽ� ��~" << endl;
		}

		//�ٸ� ���� ���� ����
		else
		{
			break;
		}
	}
	
	//�÷��̾�� ��ǻ�Ͱ� ���� ���� ������
	if ((ComputerChoice[0] + ComputerChoice[1]) == (UserChioce[0] + UserChioce[1]))
	{
		if (ComputerChoice[0] > ComputerChoice[1])
		{
			Computer = ComputerChoice[0];
		}
		else
		{
			Computer = ComputerChoice[1];
		}

		//����,���� ��ǻ�Ͱ� ������
		if (ComputerChoice[0] == 1 && ComputerChoice[1] == 3)
		{
			Computer = ComputerChoice[0];
		}
		//��, ������ ��ǻ�Ͱ� ������
		else if (ComputerChoice[0] == 3 && ComputerChoice[1] == 1)
		{
			Computer = ComputerChoice[1];
		}
	}
	//���� ���� 50���� ũ�� ó�� ���� ���� ���� �������� 50���� ������ �������� ���Ѱ��� ����
	else
	{
		if (RandomValue > 50)
		{
			Computer = ComputerChoice[0];
		}
		else
		{
			Computer = ComputerChoice[1];
		}
	}

	//��ǻ�Ͱ� �� ���� Ȯ��
	cout << "��ǻ���� ";
	for (int i = 0; i < 2; i++)
	{
		if (ComputerChoice[i] == 1)
		{
			cout << "'����'";
		}
		if (ComputerChoice[i] == 2)
		{
			cout << "'����'";
		}
		if (ComputerChoice[i] == 3)
		{
			cout << "'��'";
		}
	}
	cout << "�� �½��ϴ�." << endl << endl;

	//�÷��̾ ������ Ȯ��
	cout << "����� ";
	for (int i = 0; i < 2; i++)
	{
		if (UserChioce[i] == 1)
		{
			cout << "'����'";
		}
		if (UserChioce[i] == 2)
		{
			cout << "'����'";
		}
		if (UserChioce[i] == 3)
		{
			cout << "'��'";
		}
	}
	cout << "�� �½��ϴ�." << endl << endl;

	//�������� ������ ���ϴ� �κ�
	while (true)
	{
		cout << "������ ������ �����ּ��� " << endl;
		cin >> User;

		//ó�� �� �͵� �߿� �ִ� ���
		if (User == UserChioce[0])
		{
			break;
		}
		else if (User == UserChioce[1])
		{
			break;
		}

		//ó�� �� �͵� �߿� ���� ���
		if (User != UserChioce[0])
		{
			cout << "����� �� ���� �Է����ּ���" << endl << endl;
		}

		else if(User != UserChioce[1])
		{
			cout << "����� �� ���� �Է����ּ���" << endl << endl;
		}
	}

	//������ �����
	if (User == 1)
	{
		cout << "����� ������ �½��ϴ�." << endl << endl;
		Sleep(1000);

		//��ǻ�Ͱ� ������ �����
		if (Computer == 1)
		{
			cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl << endl;
			cout << "�����ϴ�." << endl;
		}
		//��ǻ�Ͱ� ������ �����
		else if (Computer == 2)
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
	else if (User == 2)
	{
		cout << "����� ������ �½��ϴ�." << endl << endl;
		Sleep(1000);
		//��ǻ�Ͱ� ������ �����
		if (Computer == 1)
		{
			cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl << endl;
			cout << "�̰���ϴ�." << endl;
		}
		//��ǻ�Ͱ� ������ �����
		else if (Computer == 2)
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
	else if (User == 3)
	{
		cout << "����� ���� �½��ϴ�." << endl << endl;
		Sleep(1000);
		//��ǻ�Ͱ� ������ �����
		if (Computer == 1)
		{
			cout << "��ǻ�ʹ� ������ �½��ϴ�." << endl << endl;
			cout << "�����ϴ�." << endl;
		}
		//��ǻ�Ͱ� ������ �����
		else if (Computer == 2)
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
	return 0;
}