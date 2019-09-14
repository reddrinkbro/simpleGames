#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

struct DAMAGOCHI
{
	char *boring = "��"; //��ſ� ����
	char *hungry = "��"; //������ ����
	char *toilet = "��"; //û�� ����
	int boringNum = 2; //��Ʈ ����
	int hungryNum = 2; //�� ����
	int toiletNum = 2; //����� ����
	bool boringState = false;
	bool hungryState = false;
	bool toiletState = false;
	bool isTurn = false; //���� �Է��������� �ƴ��� �Ǵ�
};

int main()
{
	srand(time(NULL));
	DAMAGOCHI player;
	int random = 3; // �ٸ���ġ�� �� �ൿ�� ���ϱ� ���� ����
	int userSelect = 0; //������ �� �ൿ
	int modeSelect = 0;
	while (true)
	{
		cout << "�ٸ���ġ�� Ű���ּ��� ~_~" << endl;
		cout << "�ٸ���ġ�� ������ ���� ����" << endl;
		cout << "1)���� �ϱ� 2)���� ���� ���� 3)�����ϱ�" << endl;
		cin >> modeSelect;
		if (modeSelect == 2)
		{
			cout << "�� ������ �ٸ���ġ�� Ű��� �����Դϴ�." << endl;
			cout << "�ٸ���ġ�� �� 3���� ���°� �ֽ��ϴ�." << endl;
			cout << "��ſ�(��), ������(��), û��(��) ���°� �ֽ��ϴ�." << endl;
			cout << "��ſ�(��), ������(��), û��(��)�� 0�̵Ǹ� �ٸ���ġ�� �׽��ϴ�." << endl;
			cout << "��ſ�(��), ������(��), û��(��)�� 5���ٴ� Ŀ���� �ʽ��ϴ�." << endl;
			cout << "�÷��̾�� 1)����ֱ� 2)���ֱ� 3)û���ϱ� 4)������ �ֱ� �� �ϳ��� �ൿ�� �մϴ�" << endl;
			cout << "���ÿ� ���� �ٸ���ġ�� ������ ���õǴ� �����Ͽ� ������ �÷��� �ϼ���!" << endl;
			Sleep(5000);
			system("cls");
		}
		else if (modeSelect == 1)
		{

			Sleep(2000);
			while (true)
			{
				system("cls");
				cout << random << endl;

				//���⼭ �̸� ���� ���Ѽ� ȭ�鿡�� ���ҵ� ���·� ��½�Ŵ
				//�ɽ��� ��� 
				if (random == 0 && player.isTurn == false)
				{
					player.boringNum--; //�ɽ��� ���� -1
					player.boringState = true; //������ ���� ����
				}
				//����� ���
				else if (random == 1 && player.isTurn == false)
				{
					player.hungryNum--;//������ ���� -1
					player.hungryState = true;//����� ���� ����
				}
				//ȭ����� ���� ���
				else if (random == 2 && player.isTurn == false)
				{
					player.toiletNum--; //û�� ���� -1
					player.toiletState = true;//ȭ��Ǳ��� ���� ����
				}
				cout << player.hungryNum << endl;
				cout << "���� ���� \t ��ſ� :";
				//��ſ� ǥ��
				for (int i = 0; i < player.boringNum; i++)
				{
					cout << player.boring;
				}
				cout << endl;
				cout << "\t\t ����� :";
				//����� ǥ��
				for (int i = 0; i < player.hungryNum; i++)
				{
					cout << player.hungry;
				}
				cout << endl;
				cout << "\t\t û�� :";
				//û�� ǥ��
				for (int i = 0; i < player.toiletNum; i++)
				{
					cout << player.toilet;
				}
				cout << endl;
				//����� ��������
				if (player.boringNum < 2 || player.hungryNum < 2 || player.toiletNum < 2)
				{
					cout << " ()  ()" << endl;
					cout << " (�̤�) " << endl;
					cout << "/l    l> " << endl;
					cout << " ()  ()\t\t";
					if (player.boringState == true) //�������� ���� ������
					{
						cout << "��";
					}
					if (player.hungryState == true) //������� ���� ������
					{
						cout << "��";
					}
					if (player.toiletState == true) //ȭ����� ���� �����϶�
					{
						cout << "��";
					}
				}
				//����� ������
				else
				{
					cout << " () ()" << endl;
					cout << " (^0^) " << endl;
					cout << "/l   l> " << endl;
					cout << " () ()\t\t";
					if (player.boringState == true)//�������� ���� ������
					{
						cout << "��";
					}
					if (player.hungryState == true)//������� ���� ������
					{
						cout << "��";
					}
					if (player.toiletState == true)//ȭ����� ���� �����϶�
					{
						cout << "��";
					}
				}
				cout << endl;
				//�ɽ��� ���
				if (random == 0 && player.isTurn == false)
				{
					cout << "���� �ٸ���ġ�� �ɽ��մϴ�. ��ſ� ���� -1" << endl;
					player.isTurn = true; //���� �Է���
				}
				//����� ���
				else if (random == 1 && player.isTurn == false)
				{
					cout << "���� �ٸ���ġ�� ����Ŵϴ�. ������ ���� -1" << endl;
					player.isTurn = true;//���� �Է���
				}
				//ȭ����� ���� ���
				else if (random == 2 && player.isTurn == false)
				{
					cout << "���� �ٸ���ġ�� ȭ����� ���մϴ�. û�� ���� -1" << endl;
					player.isTurn = true;//���� �Է���
				}
				//�ƹ��� �ൿ�� ���� ������
				else if (random > 2 && player.isTurn == false)
				{
					if (player.boringNum < 2 || player.hungryNum < 2 || player.toiletNum < 2)
					{
						cout << "�ٸ���ġ�� �����մϴ�." << endl;
						player.isTurn = true;//���� �Է���
					}
					else
					{
						cout << "�ٸ���ġ�� ����� �����ϴ�." << endl;
						player.isTurn = true;//���� �Է���
					}
				}
				Sleep(1000);
				// �ٸ���ġ�� ����� ���� ������ ���
				if (player.boringNum < 1 || player.hungryNum < 1 || player.toiletNum < 1)
				{
					cout << "�ٸ���ġ�� �׾���Ƚ��ϴ�" << endl;
					Sleep(1000);
					system("cls");
					break;
				}

				cout << "�ٸ���ġ���� ��ų �ൿ�� �������ּ���" << endl;
				cout << "1)����ֱ� 2)���ֱ� 3)û���ϱ� 4)������ �α�" << endl;
				cin >> userSelect;
				if (userSelect == 1 && player.isTurn == true)
				{
					//��ſ� ������ 5���� Ŭ�� 5�� ���� ��Ű��
					if (player.boringNum == 5)
					{
						cout << "�̹� ����� ��̽��ϴ�." << endl;
					}
					else
					{
						cout << "�ٸ���ġ�� ���� ����־��� ��ſ� ���� +1" << endl;
						player.boringNum += 1; // ��ſ� +1
					}
					player.isTurn = false; //�ٸ���ġ �ൿ��
					player.boringState = false; // ������ ���ֱ�
				}
				else if (userSelect == 2 && player.isTurn == true)
				{
					//����� ������ 5���� Ŭ�� 5�� ���� ��Ű��
					if (player.hungryNum == 5)
					{
						cout << "�̹� �谡 ���� �θ��ϴ�." << endl;
					}
					else
					{
						cout << "�ٸ���ġ���� ���� �־��� ������ ���� +1" << endl;
						player.hungryNum += 1;// ������ +1
					}
					player.isTurn = false; //�ٸ���ġ �ൿ��
					player.hungryState = false; //����� ���ֱ�
				}
				else if (userSelect == 3 && player.isTurn == true)
				{
					//û�� ������ 5���� Ŭ�� 5�� ���� ��Ű��
					if (player.toiletNum == 5)
					{
						cout << "�̹� ���� �����մϴ�" << endl;
					}
					else
					{
						cout << "���� û���Ͽ���. û�� ���� +1" << endl;
						player.toiletNum += 1;// û�� +1
					}
					player.isTurn = false;//�ٸ���ġ �ൿ��
					player.toiletState = false;//����� ���ֱ�
				}
				else if (userSelect == 4 && player.isTurn == true)
				{
					cout << "..." << endl;
					player.isTurn = false;//�ٸ���ġ �ൿ��
				}
				//����� �� ������ ���� ������
				else
				{
					cout << "����� �� �ൿ�� �����ϼ���" << endl;
				}
				random = rand() % 4; //ó���� �ƹ��� �ൿ�� ���� �ʰ� �ϱ����� �������� ������ ����
				Sleep(1000);
			}
		}
		else if (modeSelect == 3)
		{
			break;
		}
	}
	return 0;

}