#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

struct Card 
{
	char* name;
	int cardNumber;
	bool isAlphabet = false; //�ƽ�Ű�ڵ� ����� ����
};


int main()
{

	srand(time(NULL));
	int card[52]; //52�� ī��
	char Ace = 'A'; //�ƽ�Ű�ڵ� ����ϱ� ���� ����
	char Jack = 'J';//�ƽ�Ű�ڵ� ����ϱ� ���� ����
	char Queen = 'Q';//�ƽ�Ű�ڵ� ����ϱ� ���� ����
	char King = 'K';//�ƽ�Ű�ڵ� ����ϱ� ���� ����
	Card computerCard[3]; // ���� 2�� , �Ⱥ��̴� ī�� 1�� 0���� ���� 1���� ������
	int index1, index2, temp;//���Һ���
	int money = 100000; //ó���� ������ 10��
	int playerChoice = 0; //�������ϱ�

	//ī�� �Է�
	for (int i = 0; i < 52; i++)
	{
		card[i]= i;
	}

	//ī�� ����
	
	while (true)
	{
		for (int i = 0; i <1000; i++)
		{
			index1 = rand() % 52;
			index2 = rand() % 52;
			temp = card[index1];
			card[index1] = card[index2];
			card[index2] = temp;
		}
		//ī�� 3�� ����

		//0~12���� ���̾�
		//13~25���� Ŭ�ι�
		//26~38���� ��Ʈ
		//39~51���� �����̽�

		for (int i = 0; i < 3; i++)
		{
			computerCard[i].cardNumber = card[i];
			//0~12 ����
			if (computerCard[i].cardNumber < 13)
			{
				computerCard[i].name = "��";
				computerCard[i].cardNumber = computerCard[i].cardNumber + 1;
			}
			//13~25 ����
			else if (computerCard[i].cardNumber < 26 && computerCard[i].cardNumber >= 13)
			{
				computerCard[i].name = "��";
				computerCard[i].cardNumber = computerCard[i].cardNumber - 12;
			}
			//26~38 ����
			else if (computerCard[i].cardNumber < 39 && computerCard[i].cardNumber >= 26)
			{
				computerCard[i].name = "��";
				computerCard[i].cardNumber = computerCard[i].cardNumber - 25;
			}
			//38~51 ����
			else if (computerCard[i].cardNumber < 52 && computerCard[i].cardNumber >= 39)
			{
				computerCard[i].name = "��";
				computerCard[i].cardNumber = computerCard[i].cardNumber - 38;
			}

			//���̽�
			if (computerCard[i].cardNumber == 1)
			{
				computerCard[i].isAlphabet = true;
			}
			//��
			else if (computerCard[i].cardNumber == 11)
			{
				computerCard[i].isAlphabet = true;
			}
			//��
			else if (computerCard[i].cardNumber == 12)
			{
				computerCard[i].isAlphabet = true;
			}
			//ŷ
			else if (computerCard[i].cardNumber == 13)
			{
				computerCard[i].isAlphabet = true;
			}
		}
		//ī�� ����
		//A, J, Q, K �ϰ��
		for (int i = 0; i < 2; i++)
		{
			cout << i + 1 << "��° ī�� : " << computerCard[i].name;
			if (computerCard[i].isAlphabet == true)
			{
				if (computerCard[i].cardNumber == 1)
				{
					cout <<Ace<<"\t";
				}
				//��
				else if (computerCard[i].cardNumber == 11)
				{
					cout << Jack << "\t";
				}
				//��
				else if (computerCard[i].cardNumber == 12)
				{
					cout << Queen << "\t";
				}
				//ŷ
				else if (computerCard[i].cardNumber == 13)
				{
					cout << King << "\t";
				}
			}
			else
			{
				cout << computerCard[i].cardNumber << "\t";
			}
		}
		cout << endl;

		cout << "���� ���� �� : " << money << endl;
		cout << "���� �Ͻðڽ��ϱ� ? " << endl;
		cout << "1) 5000�� 2)10000�� 3) 30000��" << endl;
		cin >> playerChoice;
		cout << endl;

		// ù��° ���ڿ� �ι�° ������ ù��° ���ڰ� ������ 
		if (computerCard[0].cardNumber < computerCard[1].cardNumber)
		{
			if (computerCard[0].cardNumber < computerCard[2].cardNumber && computerCard[1].cardNumber > computerCard[2].cardNumber)
			{
				cout << "ī�� ����!!!" << endl;
				Sleep(1000);
				//A, J, Q, K �ϰ��
				if (computerCard[2].isAlphabet == true)
				{
					cout << "ī��� " << computerCard[2].name;
					//���̽�
					if (computerCard[2].cardNumber == 1)
					{
						cout << Ace << "�Դϴ�." << endl;
					}
					//��
					else if (computerCard[2].cardNumber == 11)
					{
						cout << Jack << "�Դϴ�." << endl;
					}
					//��
					else if (computerCard[2].cardNumber == 12)
					{
						cout << Queen << "�Դϴ�." << endl;
					}
					//ŷ
					else if (computerCard[2].cardNumber == 13)
					{
						cout << King << "�Դϴ�." << endl;
					}
				}
				//A, J, Q, K �ƴҰ��
				else 
				{
					cout << "ī��� " << computerCard[2].name << computerCard[2].cardNumber << "�Դϴ�." << endl;
				}
				//5000�� ����
				if (playerChoice == 1)
				{
					cout << "���ñ� 5000�� ȹ��" << endl;
					money = money + 5000;
				}
				//10000�� ����
				else if (playerChoice == 2)
				{
					cout << "���ñ� 10000�� ȹ��" << endl;
					money = money + 10000;
				}
				//30000�� ����
				else if (playerChoice == 3)
				{
					cout << "���ñ� 30000�� ȹ��" << endl;
					money = money + 30000;
				}
			}
			//���� ���ڰ� ������ ���
			else if (computerCard[0].cardNumber == computerCard[1].cardNumber)
			{
				cout << "��Ÿ���׿� ���� ���ڰ� ���͹��Ⱦ��" << endl;
				//5000�� ����
				if (playerChoice == 1)
				{
					cout << "���ñ� 5000�� ����" << endl;
					money = money - 5000;
				}
				//10000�� ����
				else if (playerChoice == 2)
				{
					cout << "���ñ� 10000�� ����" << endl;
					money = money - 10000;
				}
				//30000�� ����
				else if (playerChoice == 3)
				{
					cout << "���ñ� 30000�� ����" << endl;
					money = money - 30000;
				}
			}
			else
			{
				cout << "ī�� ����!!!" << endl;
				Sleep(1000);
				//A, J, Q, K �ϰ��
				if (computerCard[2].isAlphabet == true)
				{
					cout << "ī��� " << computerCard[2].name;
					//���̽�
					if (computerCard[2].cardNumber == 1)
					{
						cout << Ace << "�Դϴ�." << endl;
					}
					//��
					else if (computerCard[2].cardNumber == 11)
					{
						cout << Jack << "�Դϴ�." << endl;
					}
					//��
					else if (computerCard[2].cardNumber == 12)
					{
						cout << Queen << "�Դϴ�." << endl;
					}
					//ŷ
					else if (computerCard[2].cardNumber == 13)
					{
						cout << King << "�Դϴ�." << endl;
					}
				}
				//A, J, Q, K �ƴҰ��
				else
				{
					cout << "ī��� " << computerCard[2].name << computerCard[2].cardNumber << "�Դϴ�." << endl;
				}
				//5000�� ����
				if (playerChoice == 1)
				{
					cout << "���ñ� 5000�� ����" << endl;
					money = money - 5000;
				}
				//10000�� ����
				else if (playerChoice == 2)
				{
					cout << "���ñ� 10000�� ����" << endl;
					money = money - 10000;
				}
				//30000�� ����
				else if (playerChoice == 3)
				{
					cout << "���ñ� 30000�� ����" << endl;
					money = money - 30000;
				}
			}
		}

		// ù��° ���ڿ� �ι�° ������ �ι�° ���ڰ� ������ 
		else
		{
			//������ ���ڰ� ù��° ���ں��� ũ�ų����� �ι�° ���ں��� �۰ų� ������� computerCard[1].cardNumber ù��° ����, computerCard[0].cardNumber �ι�° ����
			if (computerCard[1].cardNumber <= computerCard[2].cardNumber && computerCard[2].cardNumber <= computerCard[0].cardNumber)
			{
				cout << "ī�� ����!!!" << endl;
				Sleep(2000);
				//A, J, Q, K �ϰ��
				if (computerCard[2].isAlphabet == true)
				{
					cout << "ī��� " << computerCard[2].name;
					//���̽�
					if (computerCard[2].cardNumber == 1)
					{
						cout << Ace << "�Դϴ�." << endl;
					}
					//��
					else if (computerCard[2].cardNumber == 11)
					{
						cout << Jack << "�Դϴ�." << endl;
					}
					//��
					else if (computerCard[2].cardNumber == 12)
					{
						cout << Queen << "�Դϴ�." << endl;
					}
					//ŷ
					else if (computerCard[2].cardNumber == 13)
					{
						cout << King << "�Դϴ�." << endl;
					}
				}
				//A, J, Q, K �ƴҰ��
				else
				{
					cout << "ī��� " << computerCard[2].name << computerCard[2].cardNumber << "�Դϴ�." << endl;
				}
				//5000�� ����
				if (playerChoice == 1)
				{
					cout << "���ñ� 5000�� ����" << endl;
					money = money - 5000;
				}
				//10000�� ����
				else if (playerChoice == 2)
				{
					cout << "���ñ� 10000�� ����" << endl;
					money = money - 10000;
				}
				//30000�� ����
				else if (playerChoice == 3)
				{
					cout << "���ñ� 30000�� ����" << endl;
					money = money - 30000;
				}
			}
			//���� ���ڰ� ��������
			else if (computerCard[0].cardNumber == computerCard[1].cardNumber)
			{
				cout << "��Ÿ���׿� ���� ���ڰ� ���͹��Ⱦ��" << endl;
				//5000�� ����
				if (playerChoice == 1)
				{
					cout << "���ñ� 5000�� ����" << endl;
					money = money - 5000;
				}
				//10000�� ����
				else if (playerChoice == 2)
				{
					cout << "���ñ� 10000�� ����" << endl;
					money = money - 10000;
				}
				//30000�� ����
				else if (playerChoice == 3)
				{
					cout << "���ñ� 30000�� ����" << endl;
					money = money - 30000;
				}
			}
			else
			{
				cout << "ī�� ����!!!" << endl;
				Sleep(2000);
				//A, J, Q, K �ϰ��
				if (computerCard[2].isAlphabet == true)
				{
					cout << "ī��� " << computerCard[2].name;
					//���̽�
					if (computerCard[2].cardNumber == 1)
					{
						cout << Ace << "�Դϴ�." << endl;
					}
					//��
					else if (computerCard[2].cardNumber == 11)
					{
						cout << Jack << "�Դϴ�." << endl;
					}
					//��
					else if (computerCard[2].cardNumber == 12)
					{
						cout << Queen << "�Դϴ�." << endl;
					}
					//ŷ
					else if (computerCard[2].cardNumber == 13)
					{
						cout << King << "�Դϴ�." << endl;
					}
				}
				//A, J, Q, K �ƴҰ��
				else
				{
					cout << "ī��� " << computerCard[2].name << computerCard[2].cardNumber << "�Դϴ�." << endl;
				}
				//5000�� ����
				if (playerChoice == 1)
				{
					cout << "���ñ� 5000�� ȹ��" << endl;
					money = money + 5000;
				}
				//10000�� ����
				else if (playerChoice == 2)
				{
					cout << "���ñ� 10000�� ȹ��" << endl;
					money = money + 10000;
				}
				//30000�� ���� 
				else if (playerChoice == 3)
				{
					cout << "���ñ� 30000�� ȹ��" << endl;
					money = money + 30000;
				}
			}
		}
		//��� ���� �Ҿ�����
		if (money <= 0)
		{
			cout << "���� ��� �Ҿ����ϴ�. " << endl;
			return 0;
		}
		//bool�� �ʱ�ȭ
		for (int i = 0;i < 3; i++) 
		{
			computerCard[i].isAlphabet = false; 
		}
		Sleep(1000);
		system("cls");
	}
}