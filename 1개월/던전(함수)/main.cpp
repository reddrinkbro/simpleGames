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
	int experience = 50; //����ġ
	int money = 50; //���Ͱ� �ִ� ��
};

typedef struct JOB
{
	char* name; //�̸�
	int attack; //���ݷ�
	int defense; //����
	int healthPoint; //���� ü��
	int maxHealthPoint; // �ִ� ü��
	int level = 1; //����
	int money = 0; //��
	int currentExperience = 0; //���� ����ġ
	int experienceMax; //�� ����ġ
	int skill[3]; //��ų ������
	char *skillName[3]; //��ų �̸�
};


void welcome(); //ó�� �λ�
void selectJob(int select); //��������
void selectMode(JOB player, MONSTER enemy); //����, ��ȭ�� ����
MONSTER monsterState(JOB player, int boss); //���� ����
JOB playerState(int select); //�÷��̾� ����
void dungeon(JOB player, MONSTER enemy, int choiceMode); //����
int upgrade(JOB player, MONSTER enemy); //��ȭ��

int main()
{
	srand(time(NULL));
	welcome();
	return 0;
}

//ó�� �λ�
void welcome()
{
	int select;
	cout << "������� ������ ������ �ּ���" << endl;
	cout << "1) ���� 2)������ 3)���� ����" << endl;
	cin >> select; // ��������
	if (select == 3)
	{
		exit(0);
	}
	else
	{
		selectJob(select); // ���� ����
	}
}

//ó�� ������ ���� ����
void selectJob(int select)
{
	JOB player = playerState(select); //�÷��̾� �ɷ�ġ ����
	MONSTER enemy = monsterState(player,0); //���ʹɷ�ġ�� �÷��̾� �ɷ�ġ�� ���õ� �κ��� �����ϱ� ���� 
	Sleep(1000);
	selectMode(player, enemy); //��� ����
}

//��� ����
void selectMode(JOB player, MONSTER enemy)
{
	system("cls");
	int choiceMode;
	cout << "�ϰ� ���� ���� ����ּ���" << endl;
	if (player.level < 10)
	{
		cout << "1)�������� 2)��ȭ�� ���� 0)�����ϱ�" << endl;
	}
	else
	{
		cout << "1)�������� 2)��ȭ�� ���� 3) �������� ����ϱ� 0)�����ϱ�" << endl;
	}
	cin >> choiceMode;
	if (choiceMode == 1) //��������
	{
		MONSTER normal = monsterState(player, choiceMode);
		dungeon(player, normal, choiceMode);
	}
	else if (choiceMode == 2) //��ȭ�� ����
	{
		upgrade(player,enemy);
	}
	else if (choiceMode == 0) //����
	{
		exit(0);
	}
	else if (choiceMode == 3 && player.level >= 10)
	{
		MONSTER boss = monsterState(player, choiceMode);
		dungeon(player, boss, choiceMode);
	}
}
//��������
void dungeon(JOB player , MONSTER enemy, int choiceMode)
{
	int choice; //�÷��̾� ������
	int attack; //���ݽ� ������

	while (true)
	{
		system("cls");
		cout << enemy.name << "�� ��Ÿ�����ϴ�." << endl;
		cout << "������ ü�� : " << enemy.healthPoint << endl;
		cout << "�÷��̾��� ü�� : " << player.healthPoint << endl;
		cout << "1)���� �ϱ� 2) ������ ����" << endl;
		cin >> choice;
		if (choice == 1)
		{
			int attack;
			cout << "1) "<<player.skillName[0]<<" 2) "<< player.skillName[1] <<" 3) "<< player.skillName[2] << endl;
			cin >> attack;
			player.skill[attack - 1] = rand() % 100 + player.skill[attack - 1];
			int monsterDamage = player.defense - rand() % 25 + enemy.attack; // ���Ͱ� ������ ���ش� �÷��̾� ���¿��� �� ���ݷ¸�ŭ ������ ����
			if (enemy.defense < player.skill[attack - 1]) // �÷��̾� ���ݷ��� �� ������
			{
				cout << player.skillName[attack - 1] << "�������� " << player.skill[attack - 1] << "�̴�." << endl;
				enemy.healthPoint -= player.skill[attack - 1]; // ��ü�� ����
			
			}
			else//�� ������ �� ������
			{
				cout << player.skillName[attack - 1] << "�������� " << player.attack / 2 << "�̴�." << endl;
				enemy.healthPoint -= player.attack / 2; // �� ü�� ����
			}
			Sleep(1000);
			system("cls");
			if (enemy.healthPoint <= 0)
			{
				cout << "���Ͱ� ��������!!" << endl;
				player.currentExperience += enemy.experience; // ����ġ ȹ��
				player.money += enemy.money; // �÷��̾� �� ȹ��
				cout << "�� :" << enemy.money << "ȹ��" << endl;
				if (player.currentExperience >= player.experienceMax) // ���� ����ġ�� �� ����ġ�� ������
				{
					player.level += 10; // ��������
					cout << "���� ��!!!" << endl;
					cout << "������ " << player.level << "�� �Ǿ���" << endl;
					player.attack += 10; // ���ݷ� 10���
					player.currentExperience = 0; //���� ����ġ 0���� �ʱ�ȭ
					player.defense += 5; // ���� 5 ���
					player.maxHealthPoint += player.level * 50; //ü�� ���� ������ 50�� ����
					player.healthPoint = player.maxHealthPoint; //�������� �ִ�ü������ �ٲ�
					player.experienceMax = player.level * player.level * player.experienceMax; //�� ����ġ�� ���� ���� x ���� ���� x ���� �� ����->�����Ҷ����� ���ϱ޼������� ����
				}	
				Sleep(1000);
				selectMode(player, enemy);
			}
			else
			{
				cout << "���Ͱ� " << monsterDamage << "�� ������" << endl;
				player.healthPoint -= monsterDamage;
				Sleep(1000);
				if (player.healthPoint <= 0) // ü���� 0�����϶�
				{
					cout << "�÷��̾ �׾���Ƚ��ϴ�." << endl;
					Sleep(1000);
					welcome();
				}
			}
		}
		else
		{
			selectMode(player,enemy); //���� ����
		}
	}
}
//��ȭ��
int upgrade(JOB player, MONSTER enemy)
{
	int upgradeSelect;
	int PresentLevel = 0; //���� ��ȭ ��ġ
	int Strengthen; //��ȭ Ȯ��
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
	while (true)
	{
		system("cls");
		cout << "��ȭ�ҿ� ���Ű� ȯ���մϴ�." << endl;
		cout << "���� ��ȭ ��ġ�� +" << PresentLevel << "�� �Դϴ�." << endl;
		cout << "���� ������ �ִ� �ݾ��� : " << player.money << "�Դϴ�" << endl;
		cout << "1) ��ȭ �ϱ� 2) ��������" << endl;
		cin >> upgradeSelect; //��ȭ���� �������� ����
		if (upgradeSelect == 1)
		{
			if (player.money < 500 + PresentLevel * 50) // ���� �����ϸ� ��ȭ�� ����
			{
				cout << "��ȭ �ϴµ� ����� " << 500 + PresentLevel * 50 - player.money << "��ŭ �����մϴ�." << endl;
				Sleep(1000);
			}
			else
			{

				if (PresentLevel < 10)
				{
					// Strengthen���� ���� ��ȭ ���¿� ���ų� �� ũ�� ��ȭ ����, �׷��� ������ ���� 
					if (Strengthen >= PresentLevel)
					{
						player.money -= 500 + PresentLevel * 50; // �� �پ��
						cout << "��ȭ��";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << "." << endl;;
						PresentLevel++;
						Sleep(1000);
						cout << "��ȭ�� �����ϼ̽��ϴ�." << endl;
						Sleep(500);
						//��ȭ�� �����ϸ� ȭ���� �����.
						system("cls");
					}
					else
					{
						cout << "��ȭ��";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << "." << endl;;
						PresentLevel = 0;
						Sleep(1000);
						cout << "��ȭ�� �����ϼ̽��ϴ� Ǳ!" << endl;
						Sleep(1000);
						player.money -= 500 + PresentLevel * 50;// �� �پ��
						//��ȭ�� �����ϸ� ȭ���� �����.
						system("cls");
					}
				}
				//20�ܰ� ����
				else if (PresentLevel < 20 && PresentLevel >= 10)
				{
					if (Strengthen <= 19 - PresentLevel)
					{
						player.money -= 500 + PresentLevel * 50;// �� �پ��
						cout << "��ȭ��";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << "." << endl;;
						PresentLevel++;
						Sleep(1000);
						cout << "��ȭ�� �����ϼ̽��ϴ�." << endl;
						Sleep(500);
						//��ȭ�� �����ϸ� ȭ���� �����.
						system("cls");
					}
					else
					{
						cout << "��ȭ��";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << "." << endl;;
						PresentLevel = 0;
						Sleep(1000);
						cout << "��ȭ�� �����ϼ̽��ϴ� Ǳ!" << endl;
						Sleep(1000);
						player.money -= 500 + PresentLevel * 50;// �� �پ��
						//��ȭ�� �����ϸ� ȭ���� �����.
						system("cls");
					}
				}
				//30�ܰ� ����
				else if (PresentLevel < 30 && PresentLevel >= 20)
				{
					if (Strengthen <= 29 - PresentLevel)
					{
						player.money -= 500 + PresentLevel * 50;// �� �پ��
						cout << "��ȭ��";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << "." << endl;;
						PresentLevel++;
						Sleep(1000);
						cout << "��ȭ�� �����ϼ̽��ϴ�." << endl;
						Sleep(500);
						//��ȭ�� �����ϸ� ȭ���� �����.
						system("cls");
					}
					else
					{
						cout << "��ȭ��";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << "." << endl;;
						PresentLevel = 0;
						Sleep(1000);
						cout << "��ȭ�� �����ϼ̽��ϴ� Ǳ!" << endl;
						Sleep(1000);
						player.money -= 500 + PresentLevel * 50;// �� �پ��
						//��ȭ�� �����ϸ� ȭ���� �����.
						system("cls");
					}
				}
				//40�ܰ� ����
				else if (PresentLevel < 40 && PresentLevel >= 30)
				{
					if (Strengthen <= 39 - PresentLevel)
					{
						player.money -= 500 + PresentLevel * 50;// �� �پ��
						cout << "��ȭ��";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << "." << endl;;
						PresentLevel++;
						Sleep(1000);
						cout << "��ȭ�� �����ϼ̽��ϴ�." << endl;
						Sleep(500);
						//��ȭ�� �����ϸ� ȭ���� �����.
						system("cls");
					}
					else
					{
						cout << "��ȭ��";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << ".";
						Sleep(1000);
						cout << "." << endl;;
						PresentLevel = 0;
						Sleep(1000);
						cout << "��ȭ�� �����ϼ̽��ϴ� Ǳ!" << endl;
						Sleep(1000);
						player.money -= 500 + PresentLevel * 50;// �� �پ��
						//��ȭ�� �����ϸ� ȭ���� �����.
						system("cls");
					}
				}
			}
		}
		else if (upgradeSelect == 2) // ������ ���ư���
		{
			selectMode(player, enemy);
		}
	}
	return 0;
}

//�÷��̾��� ������ ���� ���� ���� ,����ġ �� ���� �ʿ�

MONSTER monsterState(JOB player, int boss)
{
	MONSTER target[2];
	
	if (boss == 1)
	{
		target[0].name = "���"; // ���� �̸�
		target[0].attack = rand() % 20 + player.level; //���ݷ��� �÷��̾� ������ ���� ����
		target[0].defense = 70 + player.level; // �� ������ �÷��̾� ������ ���� ����
		target[0].healthPoint = 100 + (player.level * 50); // �� ü���� �÷��̾� ������ ���� 50�� ����
		target[0].money = rand() % 50 + (player.level * 50); //���Ͱ� �� ��, ���� ���� �� 50 �� ����
		target[0].experience = player.level * 50; // ���Ͱ� �� ����ġ, ����ġ�� �÷��̾� ������ 50�� ����
		return target[0];
	}
	//�������͸� ���ý�
	else
	{
		target[1].name = "�巡��"; // ���� �̸�
		target[1].attack = rand() % 100 + player.level; //���� �⺻ ���ݷ�
		target[1].defense = 150 + player.level; // ���� �⺻ ����
		target[1].healthPoint = 1000 + player.level*50; // ���� �⺻ ü��
		target[1].money = rand() % 1000 + (player.level * 500); //���Ͱ� �� ��
		target[1].experience = player.level * 500; // ���Ͱ� �� ����ġ
		return target[1];
	}
}

//�÷��̾� ����
JOB playerState(int select)
{
	JOB player[2];
	if (select == 1)
	{
		player[select - 1].name = "����"; //�̸�
		player[select - 1].level = 1; //����
		player[select - 1].attack = 30; //���ݷ�
		player[select - 1].defense = 150 ; //����
		player[select - 1].maxHealthPoint = 1000; //�ִ� ü��
		player[select - 1].healthPoint = player[select - 1].maxHealthPoint; //���� ü��
		player[select - 1].money = 0; //��
		player[select - 1].experienceMax = 50;//�� ����ġ
		player[select - 1].skill[0] = rand() % 25 + player[select - 1].attack;//��ų1  ������
		player[select - 1].skill[1] = rand() % 25 + player[select - 1].attack * 2;//��ų2  ������
		player[select - 1].skill[2] = rand() % 25 + player[select - 1].attack * 3;//��ų3  ������
		player[select - 1].skillName[0] = "�Ŀ���Ʈ����ũ";//��ų1 �̸�
		player[select - 1].skillName[1] = "ũ��Ƽ�� ����";//��ų2 �̸�
		player[select - 1].skillName[2] = "�����";//��ų3 �̸�
		cout << player[select - 1].name << "�� �����ϼ̱���" << endl;
		return player[select - 1];
	}
	else
	{
		player[select - 1].name = "������"; //�̸�
		player[select - 1].level = 1; //����
		player[select - 1].attack = 100; //���ݷ�
		player[select - 1].defense = 50; //����
		player[select - 1].maxHealthPoint = 300;//�ִ� ü��
		player[select - 1].healthPoint = player[select - 1].maxHealthPoint; //���� ü��
		player[select - 1].money = 0; //��
		player[select - 1].experienceMax = 50;//�� ����ġ
		player[select - 1].skill[0] = player[select - 1].attack; //��ų1  ������
		player[select - 1].skill[1] = player[select - 1].attack * 2; //��ų2 ������
		player[select - 1].skill[2] = player[select - 1].attack * 3;//��ų3 ������
		player[select - 1].skillName[0] = "���̾"; //��ų1 �̸�
		player[select - 1].skillName[1] = "���̽� ������";//��ų2 �̸�
		player[select - 1].skillName[2] = "����Ʈ�׺�";//��ų3 �̸�
		cout << player[select - 1].name << "�� �����ϼ̱���" << endl;
		return player[select - 1];
	}

}