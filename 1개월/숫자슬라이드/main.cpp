#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
	srand(time(NULL));
	int number[25]; //����
	int sucess[25]; //������ �� �迭
	int userSelect = 0; //������ ������ ��ȣ
	int userMove = 0; // ������ �����̴� ����
	int numberCount = 0; //���ڸ� ���� ����
	bool isMove = false;
	
	//���� �Է�
	for (int i = 0; i < 25; i++)
	{
		number[i] = i;
	}
	//������ �� �迭 �Է�
	for (int i = 0; i < 25; i++)
	{
		// 1,2,3,4,5...24 ���� �Է�
		sucess[i] = i+1;
		//���������� 0 �Է�
		if (i == 24)
		{
			sucess[24] = 0;
		}
	}
	//���� ����
	for (int i = 0; i < 1000; i++)
	{
		int index1 = rand() % 25;
		int index2 = rand() % 25;
		int temp = number[index1];
		number[index1] = number[index2];
		number[index2] = temp;
	}
	
	//������ ��ȣ�� �����Ѵ�
	while (true)
	{
		if (isMove == false)
		{
			cout << "�� �� �� �� �� �� �� �� ! " << endl << endl;
			cout << "����������������������" << endl;
			//������ �׸���
			for (int i = 0; i < 25; i++)
			{
				if (i % 5 == 0)
				{
					cout << "��";
				}
				if (number[i] < 10)
				{
					cout << number[i] << " ��";
				}
				else
				{
					cout << number[i] << "��";
				}
				if (i % 5 == 4)
				{
					cout << endl;
					if (i == 24)
					{
						cout << "����������������������" << endl;
					}
					else
					{
						cout << "����������������������" << endl;
					}
					
				}
			}
			while (true)
			{
				cout << "������ ��ȣ�� ���ϼ���" << endl;
				cin >> userSelect;
				if (userSelect > 24)
				{
					cout << "����� �� ���ڸ� �Է��ϼ���" << endl;
				}
				else
				{
					break;
				}
			}
			isMove = true;
		}
		// ��ȣ�� ���������� ��ȣ�� �����̰� �Ѵ�.
		else
		{
			while (true)
			{
				//ī��Ʈ�� �ݺ��Ҷ����� �ʱ�ȭ
				numberCount = 0;
				cout << "�� �� �� �� �� �� �� �� ! " << endl << endl;
				cout << "����������������������" << endl;
				//������ �׸���
				for (int i = 0; i < 25; i++)
				{
					if (i % 5 == 0)
					{
						cout << "��";
					}
					if (number[i] < 10)
					{
						cout << number[i] << " ��";
					}
					else
					{
						cout << number[i] << "��";
					}
					if (i % 5 == 4)
					{
						cout << endl;
						if (i == 24)
						{
							cout << "����������������������" << endl;
						}
						else
						{
							cout << "����������������������" << endl;
						}

					}
				}
				for (int i = 0; i < 25; i++)
				{
					//���ڰ� ���ڸ��� ����������
					if (number[i] == userSelect && number[i] == sucess[i])
					{
						cout << "���� " << userSelect << " ����! " << endl;
						Sleep(1000);
						
						isMove = false;
					}
					if (number[i] == sucess[i])
					{
						//�ݺ����� ���鼭 �ѹ��� Ȯ���Ͽ� �ڸ��� �´� ���ڰ� ������ ī��Ʈ�� 1����
						numberCount++;
						//ī��Ʈ�� 25 ��, ��� ��ȣ�� �´� �ڸ��� ������ ���� ����
						if (numberCount == 25)
						{
							cout << "��� ���ڸ� ������ϴ�" << endl;
							return 0;
						}
					}
				}
				//�ٽ� ���� �Է�
				if (isMove == false)
				{
					break;
				}

				cout << "���� ������ ��ȣ�� " << userSelect << "�Դϴ�" << endl;
				cout << "�̵��� ����(4) , ������(6), ����(8), �Ʒ���(5)" << endl;
				cin >> userMove;
				//���� �̵�
				if (userMove == 4)
				{
					for (int i = 0; i < 25; i++)
					{
						//������ ��ȣ�� ���� ��ȣ ã��
						if (userSelect == number[i])
						{
							//���� ������ �������� �̵����� ���ϰ� �ϱ�
							if (i % 5 != 0)
							{
								int temp = number[i];
								number[i] = number[i - 1];
								number[i - 1] = temp;
								break; //�ѹ��� �ٲ�� �ϱ�
							}
						}
					}
				}
				//������ �̵�
				else if (userMove == 6)
				{
					for (int i = 0; i < 25; i++)
					{
						//������ ��ȣ�� ���� ��ȣ ã��
						if (userSelect == number[i])
						{
							//���� �������� ���������� �̵����� ���ϰ� �ϱ�
							if (i % 5 != 4)
							{
								int temp = number[i];
								number[i] = number[i + 1];
								number[i + 1] = temp;
								break; //�ѹ��� �ٲ�� �ϱ�
							}
						}
					}
				}
				//���� �̵�
				else if (userMove == 8)
				{
					for (int i = 0; i < 25; i++)
					{
						//������ ��ȣ�� ���� ��ȣ ã��
						if (userSelect == number[i])
						{
							//���� ������ �������� �̵����� ���ϰ� �ϱ�
							if (i > 4)
							{
								int temp = number[i];
								number[i] = number[i - 5];
								number[i - 5] = temp;
								break; //�ѹ��� �ٲ�� �ϱ�
							}
						}
					}
				}
				//�Ʒ� �̵�
				else if (userMove == 5)
				{
					for (int i = 0; i < 25; i++)
					{
						//������ ��ȣ�� ���� ��ȣ ã��
						if (userSelect == number[i])
						{
							//���� �Ʒ����� �Ʒ������� �̵����� ���ϰ� �ϱ�
							if (i < 20)
							{
								int temp = number[i];
								number[i] = number[i + 5];
								number[i + 5] = temp;
								break; //�ѹ��� �ٲ�� �ϱ�
							}
						}
					}
				}
				system("cls");
			}
		}
		system("cls");
	}
	return 0;
}