#include<iostream>
#include<time.h>
#include<windows.h>

using namespace std;


//��ǻ�� ���� 3��
//�÷��̾� ���� 3��
//��, ��Ʈ����ũ

int main()
{
	srand(time(NULL));
	int computerNumber[4]; //��ǻ�� ����
	int playerNumber[4]; //�÷��̾� ����
	int randomNum[9]; //��������
	int index1, index2, temp; //������ ���� ����
	for (int i = 0; i < 9; i++) 
	{
		randomNum[i] = i+1;
	}
	//���� ����
	for (int i = 0; i < 100; i++)
	{
		index1 = rand() % 9; //0~9
		index2 = rand() % 9; //0~9
		temp = randomNum[index1];
		randomNum[index1] = randomNum[index2];
		randomNum[index2] = temp;
	}
	//��ǻ�� ���� �Է�
	for (int i = 0; i < 3; i++)
	{
		computerNumber[i] = randomNum[i];
	}

	//���� �����ֱ� /////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < 3; i++)
	{
		cout << computerNumber[i]<<endl;
	}

	cout << "���� �߱� ����!!" << endl;
	
	
	//��Ʈ����ũ�� 3�϶� ����
	while (true)
	{
		int ballCount = 0; //��ī��Ʈ
		int strikeCount = 0; //��Ʈ����ũ ī��Ʈ

		//�÷��̾� ���� �Է�
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << "��° ���ڸ� �Է��ϼ���" << endl;
			cin >> playerNumber[i];
		}

		for (int i = 0; i < 3; i++)
		{
			//��Ʈ����ũ
			if (computerNumber[i] == playerNumber[i])
			{
				strikeCount++;
			}
			for (int j = 0; j < 3; j++)
			{
				//��
				if (computerNumber[i] != playerNumber[i] && computerNumber[i] == playerNumber[j])
				{
					ballCount++;
				}
			}
		}
		//��Ʈ����ũ 3�� �Ǿ��� ��
		if (strikeCount == 3)
		{
			cout << "������!!!!" << endl;
			break;
		}
		//�ϳ��� ����������
		else if (strikeCount == 0 && ballCount == 0)
		{
			cout << "�ƿ� !" << endl;
		}
		//��Ʈ����ũ�� ������
		else if (strikeCount > 0 && ballCount ==0)
		{
			cout << "��Ʈ����ũ : " << strikeCount << endl;
		}
		//���� ������
		else if (strikeCount == 0 && ballCount > 0)
		{
			cout << "�� : " << ballCount << endl;
		}
		//��Ʈ����ũ �� �Ѵ� ������
		else if (strikeCount > 0 && ballCount > 0)
		{
			cout << "��Ʈ����ũ : " << strikeCount << endl << "�� : " << ballCount << endl;
		}
		Sleep(2000);
		system("cls");
	}
	return 0;
}