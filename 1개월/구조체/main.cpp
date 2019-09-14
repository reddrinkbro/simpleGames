#include <iostream>
#include <windows.h>
using namespace std;

typedef struct Job
{
	char* name; //�̸�
	int attack; //���ݷ�
	int defense; //����
	int healthPoint; //ü��
	int manaPoint; //����
	int speed; //�̼�
	int attackSpeed; //����
	int lucky; //��
	int intellect; //����
	int masicResist; //��������
	int critical; //ũ��Ƽ��
	int power; //��
	int dex; //��ø
	int ability; //�ؾ�
	int Gwang; //����?
	int level; //����
	int experiencePoint; //����ġ
	int casting; //ĳ���üӵ�
	int attackArea; //���ݹ���
};


int main()
{
	Job state[5];
	//���� ����
	state[0].name = "����";
	state[0].attack = 100;
	state[0].defense = 100;
	state[0].healthPoint = 1000;
	state[0].manaPoint = 500;
	state[0].speed = 20;
	state[0].attackSpeed = 30;
	state[0].lucky = 10;
	state[0].intellect = 5;
	state[0].masicResist = 50;
	state[0].critical = 30;
	state[0].power = 100;
	state[0].dex = 30;
	state[0].ability = 20;
	state[0].Gwang = 1;
	state[0].level = 1;
	state[0].experiencePoint = 0;
	state[0].casting = 4;
	state[0].attackArea = 3;
	//������ ����
	state[1].name = "������";
	state[1].attack = 80;
	state[1].defense = 40;
	state[1].healthPoint = 500;
	state[1].manaPoint = 1000;
	state[1].speed = 20;
	state[1].attackSpeed = 20;
	state[1].lucky = 20;
	state[1].intellect = 50;
	state[1].masicResist = 80;
	state[1].critical = 20;
	state[1].power = 80;
	state[1].dex = 40;
	state[1].ability = 70;
	state[1].Gwang = 2;
	state[1].level = 1;
	state[1].experiencePoint = 0;
	state[1].casting = 7;
	state[1].attackArea = 10;
	//���� ����
	state[2].name = "����";
	state[2].attack = 70;
	state[2].defense = 30;
	state[2].healthPoint = 900;
	state[2].manaPoint = 600;
	state[2].speed = 100;
	state[2].attackSpeed = 100;
	state[2].lucky = 80;
	state[2].intellect = 35;
	state[2].masicResist = 50;
	state[2].critical = 100;
	state[2].power = 70;
	state[2].dex = 110;
	state[2].ability = 90;
	state[2].Gwang = 3;
	state[2].level = 1;
	state[2].experiencePoint = 0;
	state[2].casting = 10;
	state[2].attackArea = 6;
	//�ü� ����
	state[3].name = "�ü�";
	state[3].attack = 90;
	state[3].defense = 40;
	state[3].healthPoint = 700;
	state[3].manaPoint = 700;
	state[3].speed = 40;
	state[3].attackSpeed = 50;
	state[3].lucky = 40;
	state[3].intellect = 40;
	state[3].masicResist = 60;
	state[3].critical = 90;
	state[3].power = 90;
	state[3].dex = 100;
	state[3].ability = 60;
	state[3].Gwang = 4;
	state[3].level = 1;
	state[3].experiencePoint = 0;
	state[3].casting = 9;
	state[3].attackArea = 8;
	//���� ����
	state[4].name = "����";
	state[4].attack = 20;
	state[4].defense = 100;
	state[4].healthPoint = 700;
	state[4].manaPoint = 1000;
	state[4].speed = 30;
	state[4].attackSpeed = 20;
	state[4].lucky = 20;
	state[4].intellect = 90;
	state[4].masicResist = 100;
	state[4].critical = 10;
	state[4].power = 30;
	state[4].dex = 30;
	state[4].ability = 70;
	state[4].Gwang = 5;
	state[4].level = 1;
	state[4].experiencePoint = 0;
	state[4].casting = 7;
	state[4].attackArea = 3;
	while (true)
	{

		cout << "������ �����ϼ���." << endl << endl;
		cout << "1)���� 2)������ 3)���� 4)�ü� 5)����" << endl<< endl;
		cout << "�׸� ���÷��� 0�� �����ּ���" << endl;

		int selectJob = 0; //���� ���� �������� ����
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
		for (int i = 0; i < 5; i++)
		{
			// ���� ���
			if (selectJob == i+1)
			{

				cout << "�̸�:" << state[i].name << endl;
				cout << "���ݷ�:" << state[i].attack << endl;
				cout << "����:" << state[i].defense << endl;
				cout << "ü��:" << state[i].healthPoint << endl;
				cout << "����:" << state[i].manaPoint << endl;
				cout << "�̵��ӵ�:" << state[i].speed << endl;
				cout << "���ݼӵ�:" << state[i].attackSpeed << endl;
				cout << "��:" << state[i].lucky << endl;
				cout << "����:" << state[i].intellect << endl;
				cout << "��������:" << state[i].masicResist << endl;
				cout << "ũ��Ƽ��:" << state[i].critical << endl;
				cout << "��:" << state[i].power << endl;
				cout << "��ø:" << state[i].dex << endl;
				cout << "�ؾ�:" << state[i].ability << endl;
				cout << "����:" << state[i].Gwang << endl;
				cout << "����:" << state[i].level << endl;
				cout << "����ġ:" << state[i].experiencePoint << endl;
				cout << "ĳ���üӵ�:" << state[i].casting << endl;
				cout << "���ݹ���:" << state[i].attackArea << endl << endl;
			}
			
		}

	}
}