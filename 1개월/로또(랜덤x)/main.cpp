#include <iostream>
#include<time.h>
#include <Windows.h>

using namespace std;

int main()
{
	
	srand(time(NULL));
	int lottoNum[45] = {0}; //�ζ� ��ȣ
	int winLotto[6] = { 0 }; // ��÷�� ��ȣ
	int playerNum[6] = { 0 };//�÷��̾ �Է��� ��ȣ
	int lottoCount = 0; //��÷�� ��ȣ�� ��
	int loop = 0; //�ݺ��� ���� ���� ����
	int count = 0; // �÷��̾ �迭�� ��ȣ
	int index1, index2, temp; //������ ����
	

	for (int i = 0; i < 45; i++)
	{
		lottoNum[i] = i + 1; //�� ���� �Է�
	}

	cout << "�ζ� ��ȣ�� �Է��ϼ���!!" << endl;
	//�÷��̾� ��ȣ �Է�
	while (loop < 6)
	{
		cin >> count;
		//�߸��� ���ڸ� �Է��Ͽ�����
		if (count > 45 || count < 1)
		{
			cout << "����� �� ���� �Է��ϼ���" << endl;
		}
		//����� �Է��Ͽ�����
		else
		{
			playerNum[loop] = lottoNum[count];
			loop++;
		}

		//���� ���ڰ� ��������
		for (int i = 0; i < 5; i++)
		{
			for (int j = i+1; j < 6; j++)
			{
				if (playerNum[i] == playerNum[j] && loop == 6)
				{
					loop = 0;
					cout << "���� ���ڰ� �ֽ��ϴ�. �ٽ��Է��� �ּ���" << endl;
					Sleep(1000);
					system("cls");
					cout << "�ζ� ��ȣ�� �Է��ϼ���!!" << endl;
				}
			}
			
		}
			
	}
	cout << "�̹� �� �ζ� ��÷ ��ȣ��!!!" << endl;
	//�ζ� ���� �ϱ�
	for (int i = 0; i < 1000; i++)
	{
		index1 = rand() % 45; //1~45���� ����
		index2 = rand() % 45; //1~45���� ����
		temp = lottoNum[index1]; //����
		lottoNum[index1] = lottoNum[index2];
		lottoNum[index2] = temp;
	}
	


	
	//��÷ �ζ� Ȯ��
	for (int i = 0; i < 6; i++)
	{
		winLotto[i] = lottoNum[i];
	}

	//�ζǹ�ȣ�� �÷��̾� ��ȣ ��
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0 ; j < 6; j++) 
		{
			if (playerNum[i] == winLotto[j])
			{
				lottoCount++;
			}
		}
	}
	Sleep(2000);
	cout << "��÷�� �ζ� ��ȣ�� ";
	for (int i = 0; i < 6; i++)
	{
		cout << winLotto[i] << " " ;
	}
	cout << "�Դϴ�." << endl << endl;
	//6�� �� ��������
	if (lottoCount == 6)
	{
		cout << "1�� ��÷�Դϴ�!!" << endl;
	}
	//5�� ��������
	else if (lottoCount == 5)
	{
		cout << "2�� ��÷�Դϴ�!!" << endl;
	}
	//4�� ��������
	if (lottoCount == 4)
	{
		cout << "3�� ��÷�Դϴ�!!" << endl;
	}
	//3�� ���� ��������
	else
	{
		cout << "���Դϴ�." << endl;
	}
	return 0;
}