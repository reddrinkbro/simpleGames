#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	int SelectMode; // ��ȭ����, ���� ��ȭ ����, �������� �����ϱ� ���� ����
	int PresentLevel = 0; // ���� ��ȭ ����
	int Strengthen; // ��ȭ Ȯ��
	srand(time(NULL));

	//��.. �߻��ɼ��� ������ �̻��� ���װ� �� ���? 
	//��ȭ ��ġ�� ������ ���, ��ȭ ��ġ�� 41�̻��� ���
	if(PresentLevel<0 || PresentLevel > 40){
		cout << "���� ���װ� ���׿�. �˼��մϴ�." << endl;
		return 0;
	}
	cout << "'�ؾ�'���üҿ� ���Ű��� ȯ���մϴ�." << endl << endl;
	cout << "�ִ� ��ȭ ��ġ�� 40�̾�" << endl << endl;
	cout << "�ϰ� ���� �Ҽ� ������? ^^" << endl << endl;
	while(true) {
		//��ȭ Ȯ��, Ȯ���� ������ �Ǵ� �� 'Strengthen'�� �������� �̰� 10���� �������� ������ 'PresentStrengthen'�� ����, ��ȭ �ܰ谡 10�ܰ� �ؿ� �϶�
		if (PresentLevel < 10)
		{
			Strengthen = rand() % 10;
		}
		//��ȭ Ȯ��, Ȯ���� ������ �Ǵ� �� 'Strengthen'�� �������� �̰� 100���̿��� 
		else if (PresentLevel < 20)
		{

			Strengthen = rand() % 100;

		}
		//��ȭ Ȯ��, Ȯ���� ������ �Ǵ� �� 'Strengthen'�� �������� �̰� 30���� �������� ������ 'PresentStrengthen'�� ����, ��ȭ �ܰ谡 30�ܰ� �ؿ� �϶�
		else if (PresentLevel < 30)
		{
			Strengthen = rand() % 1000;

		}
		//��ȭ Ȯ��, Ȯ���� ������ �Ǵ� �� 'Strengthen'�� �������� �̰� 40���� �������� ������ 'PresentStrengthen'�� ����, ��ȭ �ܰ谡 40�ܰ� �ؿ� �϶�
		else if (PresentLevel < 40)
		{
			Strengthen = rand() % 10000;
		}
		//��.. �߻��ɼ��� ������ �̻��� ���װ� �� ���? 
		//��ȭ ��ġ�� ������ ���, ��ȭ ��ġ�� 41�̻��� ���
		if (PresentLevel > 40 || PresentLevel < 0) {
			cout << "���� ���װ� ���׿�. �˼��մϴ�." << endl;
			return 0;
		}

		cout << "���� ��ȭ ���´� +" << PresentLevel << "�Դϴ�." << endl << endl;
		cout << "�ϰ� ���� �ൿ�� ���ϼ���." << endl << endl;
		cout << "1.��ȭ�ϱ� 2.������" << endl;
		cin >> SelectMode; // �ϰ� ���� �ൿ �Է�
		cout << endl;
		if (SelectMode == 1)
		{
			//10�ܰ� ����
			if(PresentLevel < 10)
			{
				// Strengthen���� ���� ��ȭ ���¿� ���ų� �� ũ�� ��ȭ ����, �׷��� ������ ���� 
				if (Strengthen >= PresentLevel)
				{
					cout << "��ȭ��";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << "." << endl;;
					PresentLevel++;
					_sleep(1000);
					cout << "��ȭ�� �����ϼ̽��ϴ�." << endl;
					_sleep(500);
					//��ȭ�� �����ϸ� ȭ���� �����.
					system("cls");
				}
				else
				{
					cout << "��ȭ��";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << "." << endl;;
					PresentLevel = 0;
					_sleep(1000);
					cout << "��ȭ�� �����ϼ̽��ϴ� Ǳ!" << endl;
					_sleep(1000);
					//��ȭ�� �����ϸ� ȭ���� �����.
					system("cls");
				}
			}
			//20�ܰ� ����
			else if (PresentLevel < 20 && PresentLevel >= 10)
			{
				if (Strengthen <= 19-PresentLevel)
				{
					cout << "��ȭ��";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << "." << endl;;
					PresentLevel++;
					_sleep(1000);
					cout << "��ȭ�� �����ϼ̽��ϴ�." << endl;
					_sleep(500);
					//��ȭ�� �����ϸ� ȭ���� �����.
					system("cls");
				}
				else
				{
					cout << "��ȭ��";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << "." << endl;;
					PresentLevel = 0;
					_sleep(1000);
					cout << "��ȭ�� �����ϼ̽��ϴ� Ǳ!" << endl;
					_sleep(1000);
					//��ȭ�� �����ϸ� ȭ���� �����.
					system("cls");
				}
			}
			//30�ܰ� ����
			else if (PresentLevel < 30 && PresentLevel >= 20)
			{
				if (Strengthen <= 29 - PresentLevel)
				{
					cout << "��ȭ��";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << "." << endl;;
					PresentLevel++;
					_sleep(1000);
					cout << "��ȭ�� �����ϼ̽��ϴ�." << endl;
					_sleep(500);
					//��ȭ�� �����ϸ� ȭ���� �����.
					system("cls");
				}
				else
				{
					cout << "��ȭ��";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << "." << endl;;
					PresentLevel = 0;
					_sleep(1000);
					cout << "��ȭ�� �����ϼ̽��ϴ� Ǳ!" << endl;
					_sleep(1000);
					//��ȭ�� �����ϸ� ȭ���� �����.
					system("cls");
				}
			}
			//40�ܰ� ����
			else if (PresentLevel < 40 && PresentLevel >= 30)
			{
				if (Strengthen <= 39 - PresentLevel)
				{
					cout << "��ȭ��";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << "." << endl;;
					PresentLevel++;
					_sleep(1000);
					cout << "��ȭ�� �����ϼ̽��ϴ�." << endl;
					_sleep(500);
					//��ȭ�� �����ϸ� ȭ���� �����.
					system("cls");
				}
				else
				{
					cout << "��ȭ��";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << ".";
					_sleep(1000);
					cout << "." << endl;;
					PresentLevel = 0;
					_sleep(1000);
					cout << "��ȭ�� �����ϼ̽��ϴ� Ǳ!" << endl;
					_sleep(1000);
					//��ȭ�� �����ϸ� ȭ���� �����.
					system("cls");
				}
			}
			// ��� ��ȭ�� �����Ͽ�����
			else if (PresentLevel == 40)
			{
				cout << "����ϱ� �ѵ�.. �ʹ� ��� ģ��? �װ� �ƴϸ� �ζ� �緯 ����^^" << endl << endl;
				cout << "��� ��ȭ�� �����ϼ̽��ϴ�" << endl;
				return 0;
				
			}
		}

		//������
		if (SelectMode == 2)
		{
			return 0;
		}
	}
}