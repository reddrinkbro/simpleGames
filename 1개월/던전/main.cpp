#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

typedef struct MONSTER
{
	char * name; //�̸�
	int healthPoint; //ü��
	int defense; //����
	int attack; //���ݷ�
};

typedef struct JOB
{
	char* name; //�̸�
	int attack; //���ݷ�
	int defense; //����
	int healthPoint; //ü��
};

int main()
{
	srand(time(NULL));
	int monsterNum = 0; // ���� ��Ÿ�� ��
	bool yourTurn = true;
	JOB state[5];
	MONSTER target[6];

	//���� �κ�
	//���� ����
	state[0].name = "����";
	state[0].defense = 30;
	state[0].healthPoint = 1000;

	//������ ����
	state[1].name = "������";
	state[1].defense = 35;
	state[1].healthPoint = 500;

	//���� ����
	state[2].name = "����";
	state[2].defense = 50;
	state[2].healthPoint = 500;

	//�ü� ����
	state[3].name = "�ü�";
	state[3].defense = 40;
	state[3].healthPoint = 700;

	//���� ����
	state[4].name = "����";
	state[4].defense = 70;
	state[4].healthPoint = 700;

	//���ͺκ�


	//���
	target[0].name = "���";
	target[0].defense = 10;
	target[0].healthPoint = 100;


	//��
	target[1].name = "��";
	target[1].defense = 30;
	target[1].healthPoint = 200;

	//��ũ
	target[2].name = "��ũ";
	target[2].defense = 40;
	target[2].healthPoint = 300;

	//����
	target[3].name = "����";
	target[3].defense = 70;
	target[3].healthPoint = 400;

	//�巡��
	target[4].name = "�巡��";
	target[4].defense = 90;
	target[4].healthPoint = 500;

	//�Ǹ�
	target[5].name = "�Ǹ�";
	target[5].defense = 90;
	target[5].healthPoint = 600;
	
	int selectJob = 0; //���� �����ϱ� ���� ����
	bool isDie = false; //�÷��̾ �׾��°�
	int select = 0; //���������� �ϱ� ���� �ൿ
	cout << "������ �����ϼ���" << endl;
	cout << "1)���� 2)������ 3)���� 4)�ü� 5)����" << endl;
	cout << "������ �����ϽǷ��� 0�� �Է��ϼ���" << endl;
	//���� ����
	cin >> selectJob;
	if (selectJob == 0) // 0�� �Է� �Ͽ�����
	{
		return 0;
	}
	else if (selectJob != 1 && selectJob != 2 && selectJob != 3 && selectJob != 4 && selectJob != 5) // ����ε� ���ڰ� �Էµ��� �ʾ�����
	{
		cout << "����� �� ���ڸ� �Է��ϼ���";
		Sleep(1000);
		system("cls");
	}
	
	switch (selectJob)
	{
		case 1:
		{
			cout << "���縦 �����ϼ̽��ϴ�." << endl;
		}
		break;
		case 2:
		{
			cout << "�����縦 �����ϼ̽��ϴ�." << endl;
		}
		break;
		case 3:
		{
			cout << "������ �����ϼ̽��ϴ�." << endl;
		}
		break;
		case 4:
		{
			cout << "�ü��� �����ϼ̽��ϴ�." << endl;
		}
		break;
		case 5:
		{
			cout << "������ �����ϼ̽��ϴ�." << endl;
		}
		break;
	}
	Sleep(1000);
	system("cls");
	
	int choiceMonster = 0; //ó���� ������� ��Ǯ��

	//���� ���� �Ϸ�
	while (monsterNum < 6)
	{
		

		//���� �κ�

		//����
		state[0].attack = rand() % 101 + 90;
		//������
		state[1].attack = rand() % 81 + 60;
		//���� 
		state[2].attack = rand() % 71 + 50;
		//�ü� 
		state[3].attack = rand() % 91 + 70;
		//���� ����
		state[4].attack = rand() % 31 + 10;

		//���ͺκ�


		//���
		target[0].attack = rand() % 26 + 10;
		//��
		target[1].attack = rand() % 31 + 10;
		//��ũ
		target[2].attack = rand() % 41 + 10;
		//����
		target[3].attack = rand() % 31 + 10;
		//�巡��
		target[4].attack = rand() % 91 + 10;
		//�Ǹ�
		target[5].attack = rand() % 91 + 10;

		cout << target[choiceMonster].name <<"�� ��Ÿ�����ϴ�." << endl;
		cout << "������ ü�� : " << target[choiceMonster].healthPoint << endl;
		cout << "�÷��̾��� ü�� : " << state[selectJob - 1].healthPoint << endl;
		cout << "1)���� �ϱ� 2) ��������" << endl;
		cin >> select;

		//�����ϱ⸦ ����������
		if (select == 1)
		{
			
			//�������� ���������
			if(state[selectJob-1].attack - target[choiceMonster].defense > 0)
			{
				//�������� ���ݷ¿��� ��� ������ �� ���� 100�� ���ϰ� ���ݷ����� �ٽ� ��������.
				target[choiceMonster].healthPoint = target[choiceMonster].healthPoint - ((state[selectJob-1].attack - target[choiceMonster].defense) * 100) / state[selectJob-1].attack ;
				cout << "�������� " <<((state[selectJob-1].attack - target[choiceMonster].defense) * 100) / state[selectJob-1].attack << "�Դϴ�." << endl << endl;
				Sleep(400);
				yourTurn = false;
				//���͸� �׿�����
				if (target[choiceMonster].healthPoint <= 0)
				{
					cout << target[choiceMonster].name << "��(��) �׾����ϴ�." << endl;
					Sleep(700);
					target[choiceMonster].healthPoint = (choiceMonster + 1) * 100;
					monsterNum++;
					choiceMonster = rand() % 6; // ���� ���ϱ�
					yourTurn = true;
					system("cls");
				}
				Sleep(1000);
				system("cls");
			}
			//�������� ���� �ʾ�����
			else
			{
				cout << "���������ϴ�." << endl;
				Sleep(500);
				yourTurn = false;
				system("cls");
			}
			
		}
		//�������⸦ ��������
		else if (select == 2)
		{
			cout << "����... �̸� ���� ���� ����" << endl;
			Sleep(1000);
			system("cls");
			cout << "Game Over" << endl;
			return 0;
		}
		//���͸� ������ ���Ͽ����� ���� ������ �Ѿ��
		//���� ��
		if (target[choiceMonster].healthPoint > 0 && yourTurn == false)
		{
			cout << "���� �� �Դϴ�." << endl;
			//���Ͱ� ���ݿ� �����Ҷ�
			if (target[choiceMonster].attack - state[selectJob - 1].defense <= 0)
			{
				cout << "���Ͱ� ���� �߽��ϴ� ���� : MISS" << endl;
				yourTurn = true;
				Sleep(500);
				system("cls");
			}
			//���Ͱ� ���ݿ� ����������
			else
			{

				cout << "���Ͱ� ���� �߽��ϴ� ���� :" << ((target[choiceMonster].attack - state[selectJob - 1].defense) * 100) / target[choiceMonster].attack << endl;
				//�������� ���ݷ¿��� ��� ������ �� ���� 100�� ���ϰ� ���ݷ����� �ٽ� ��������.
				state[selectJob - 1].healthPoint = state[selectJob - 1].healthPoint - ((target[choiceMonster].attack - state[selectJob - 1].defense) * 100) / target[choiceMonster].attack;
				yourTurn = true;
				Sleep(500);
				system("cls");

				//�׾�����
				if (state[selectJob - 1].healthPoint <= 0)
				{
					cout << "����� �׾����ϴ�." << endl;
					Sleep(1000);
					system("cls");
					cout << "Game Over" << endl;
					return 0;
				}
			}
		}

	}
	cout << "��� ���͸� ����ϼ̽��ϴ�" << endl;
	return 0;
}