#include <iostream>
#include <time.h>
using namespace std;

int main() 
{
	int Skill_1; //��ų�� : ������(������ :10~20) ,��Ÿ�� :0
	int Skill_2; //��ų�� : �ι� ������(������ :21~31) ��Ÿ�� :1
	int Skill_3; //��ų�� : ũ��Ƽ�� ����! (������ :40~60) ��Ÿ�� : 2
	int Skill_4; // ��ų�� : ��ȭ��(������ :50~60), (�߰� ������ : 30 ,����2��) ��Ÿ�� : 3
	int Skill_5; //��ų�� : BOOM! (������ 100 ~ 110) ��Ÿ�� : 3
	int Skill_6; // ��ų�� : ������ �� ����(1�� �ɸ����: 1+2+3+...+10...+25, 2�� �ɸ���� 2+3+4+...+8+9+10...+25) ��Ÿ�� :4
	int Skill_7;//��ų�� : �ʹ� or ��� (������: ��� Ȥ�� Miss ,7����ũ�� ��� 7���� ������ Miss) ��Ÿ�� : 5
	int Skill_8;//��ų�� : BIG BOOM! (������ 200~ 220) ��Ÿ�� :4
	int Skill_9; //��ų�� : �Ǿ (������ :100~150, ���� 3��) ��Ÿ�� :4
	int Skill_10; // ��ų�� : ��Ŭ���� (������ :800~900) ��Ÿ�� 10
	int MonsterHealth; //���� ü��
	int MonsterNum = 0; //���� ���� ��
	int Select, Back; // ��������, �ڷΰ���
	int SkillSelect; //��ų ����

	int CoolDown_2 = 1; //2����ų ��Ÿ��
	int CoolDown_3 = 2; //3����ų ��Ÿ��
	int CoolDown_4 = 2; //4����ų ��Ÿ��
	int CoolDown_5 = 2; //5����ų ��Ÿ��
	int CoolDown_6 = 3; // 6����ų ��Ÿ��
	int CoolDown_7 = 5; //7����ų ��Ÿ��
	int CoolDown_8 = 4; //8����ų ��Ÿ��
	int CoolDown_9 = 4; //9����ų ��Ÿ��
	int CoolDown_10 = 10; //10����ų ��Ÿ��

	srand(time(NULL));
	while (true)
	{
		if (MonsterNum <= 10) //���� ���� ���� 10���� �����̸�
		{
			MonsterHealth = rand() % 101 + 500; // ���� ü�� 500~600
		}
		else if (MonsterNum <= 15) //���� ���� ���� 15���� �����̸�
		{
			MonsterHealth = rand() % 101 + 700; // ���� ü�� 700~800
		}
		else if (MonsterNum <= 20) //���� ���� ���� 20���� �����̸�
		{
			MonsterHealth = rand() % 101 + 900; // ���� ü�� 900~1000
		}
		else if (MonsterNum == 30) //���� ���� ���� 30�����̸�, ��������
		{
			MonsterHealth = 2000; // ���� ü�� 2000
		}
		if (MonsterNum < 30) //�Ϲݸ���
		{
			cout << "����: ������ ���Ͱ� ��Ÿ�����ϴ�! ���� ���͸� ��ġ���ֽÿɼҼ�!" << endl;
		}
		else if (MonsterNum == 30) // 30���� �϶� �������� ����
		{
			cout << "����: ū�ϳ����ϴ�!!!! �ָ��� �������Ͱ� ���� �ֽ��ϴ�. ���� ���� �������͸� ����ֽÿɼҼ�!" << endl;
		}
		cout << "1. ���� ������ ���� 2.��ų ���� Ȯ���ϱ� 3.����ġ��" << endl;
		cin >> Select; // ���͸� ������ ����, ��ų������ ����, ����ĥ�� �����ϱ�
		if (Select < 1 || Select > 3) // �߸��� ���ڸ� ������ ���
		{
			cout << "����� �� ���ڸ� ��������" << endl << endl;
		}
		_sleep(1000);
		system("cls");
	
		if (Select == 1)
		{
			cout << "���� ���� ���� ���� �� : " << MonsterNum << endl;
			cout << "���Ͱ� ��Ÿ����" << endl;
			cout << "������ ü���� " << MonsterHealth << "�̴�" << endl;
			while (true) {
				//��ų ������
				Skill_1 = rand() % 11 + 10; 
				Skill_2 = rand() % 11 + 21; 
				Skill_3 = rand() % 21 + 40; 
				Skill_4 = rand() % 11 + 50; 
				Skill_5 = rand() % 11 + 100; 
				Skill_6 = rand() % 10 + 1; 
				Skill_7 = rand() % 10 + 1;
				Skill_8 = rand() % 21 + 200;
				Skill_9 = rand() % 51 + 100;    
				Skill_10 = rand() % 101 + 800;  
				
				cout << "� ��ų�� ����Ͻðڽ��ϱ�? 1~10" << endl;
				cin >> SkillSelect; //��ų����
				cout << endl;

				//��ų ��Ÿ��
				if (SkillSelect == 2)
				{
					CoolDown_2 = CoolDown_2 - 1;
				}
				else if (SkillSelect <= 3)
				{
					CoolDown_3 = CoolDown_3 - 1;
				}
				else if (SkillSelect <= 4)
				{
					CoolDown_4 = CoolDown_4 - 1;
				}
				else if (SkillSelect <= 5)
				{
					CoolDown_5 = CoolDown_5 - 1;
				}
				else if (SkillSelect <= 6)
				{
					CoolDown_6 = CoolDown_6 - 1;
				}
				else if (SkillSelect <= 7)
				{
					CoolDown_7 = CoolDown_7 - 1;
				}
				else if (SkillSelect <= 8)
				{
					CoolDown_8 = CoolDown_8 - 1;
				}
				else if (SkillSelect <= 9)
				{
					CoolDown_9 = CoolDown_9 - 1;
				}
				else if (SkillSelect <= 10)
				{
					CoolDown_10 = CoolDown_10 - 1;
				}
				
				//1����ų
				if (SkillSelect == 1)
				{
					MonsterHealth = MonsterHealth - Skill_1;
					
					if (MonsterHealth <= 0) //���Ͱ� �׾��� ���
					{
						cout << "'������' �������� " << Skill_1 << " ������ ü���� 0�̴�" << endl;
						cout << "���͸� ��Ҵ�!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else //���Ͱ� ���� �ʾ��� ���
					{
						cout << "'������' �������� '" << Skill_1 << "' ������ ü���� " << MonsterHealth << "�̴�" << endl;
					}
				}
				//2����ų
				else if (SkillSelect == 2 && CoolDown_2 == 0)
				{
					MonsterHealth = MonsterHealth - Skill_2;
					if (MonsterHealth <= 0)//���Ͱ� �׾��� ���
					{
						cout << "'�ι� ������'�������� '" << Skill_2;
						Skill_2 = rand() % 11 + 21;
						MonsterHealth = MonsterHealth - Skill_2;
						cout <<"' '"<< Skill_2<<"' ������ ü���� 0�̴�" << endl;
						cout << "���͸� ��Ҵ�!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else//���Ͱ� ���� �ʾ��� ���
					{
						cout << "'�ι� ������'�������� '" << Skill_2;
						Skill_2 = rand() % 11 + 21;
						MonsterHealth = MonsterHealth - Skill_2;
						cout << "' '" << Skill_2 << "' ������ ü���� " << MonsterHealth << "�̴�" << endl;
					}
					
				}
				//��ų��Ÿ�� ȸ��
				else if (SkillSelect == 2 && CoolDown_2 != 0)
				{
					cout << "���� ��Ÿ�� �Դϴ�." << endl << endl;
					if (CoolDown_2 == -1)
					{
						CoolDown_2 = 1; //��ų ��Ÿ��
					}

				}
				//3����ų
				else if (SkillSelect == 3 && CoolDown_3 == 1)
				{
					MonsterHealth = MonsterHealth - Skill_3;
					if (MonsterHealth <= 0)//���Ͱ� �׾��� ���
					{
						cout << "'ũ��Ƽ�� ����!'�������� '" << Skill_3 << "' ������ ü���� 0�̴�" << endl;
						cout << "���͸� ��Ҵ�!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else//���Ͱ� ���� �ʾ��� ���
					{
						cout << "'ũ��Ƽ�� ����!'�������� '" << Skill_3 << "' ������ ü���� " << MonsterHealth << "�̴�" << endl;
					}
				}
				//��ų ��Ÿ�� ȸ��
				else if (SkillSelect == 3 && CoolDown_3 != 1)
				{
					cout << "���� ��Ÿ�� �Դϴ�." << endl << endl;
					if (CoolDown_3 == -1)
					{
						CoolDown_3 = 2;//��ų ��Ÿ��
					}

				}
				//4����ų
				else if (SkillSelect == 4 && CoolDown_4 == 1)
				{
					MonsterHealth = MonsterHealth - Skill_4;
					if (MonsterHealth <= 0)//���Ͱ� �׾��� ���
					{
						cout << "'��ȭ��'�������� '" << Skill_4 << "' ������ ü���� 0�̴�" << endl;
						cout << "���͸� ��Ҵ�!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else
					{
						cout << "'��ȭ��'�������� '" << Skill_4 << "' ������ ü���� " << MonsterHealth << "�̴�" << endl;
						if (MonsterHealth <= 30)//���Ͱ� �׾����� ��ȭ���� ù��° �߰��������� ���ϰ��
						{
							_sleep(1000);
							MonsterHealth = MonsterHealth - 30;
							cout << "'��ȭ��'�߰������� '30' ������ ü���� 0�̴�" << endl;
							cout << "���͸� ��Ҵ�!" << endl;
							MonsterNum++;
							_sleep(1000);
							system("cls");
							break;
						}
						else//���Ͱ� ��ȭ�� ù��° �߰��������� ���� �ʾ��� ���
						{
							_sleep(1000);
							MonsterHealth = MonsterHealth - 30;
							cout << "'��ȭ��'�߰������� '30' ������ ü���� " << MonsterHealth << "�̴�" << endl;
						}
						if (MonsterHealth <= 30)//���Ͱ� ��ȭ�� �ι�° �߰��������� ���� ���
						{
							_sleep(1000);
							MonsterHealth = MonsterHealth - 30;
							cout << "'��ȭ��'�߰������� '30' ������ ü���� 0�̴�" << endl;
							cout << "���͸� ��Ҵ�!" << endl;
							MonsterNum++;
							_sleep(1000);
							system("cls");
							break;
						}
						else//���Ͱ� ��ȭ�� �ι�° �߰��������� ���� �ʾ��� ���
						{
							_sleep(1000);
							MonsterHealth = MonsterHealth - 30;
							cout << "'��ȭ��'�߰������� '30' ������ ü���� " << MonsterHealth << "�̴�" << endl;
						}
					}
				}
				//��ų ��Ÿ�� ȸ��
				else if (SkillSelect == 4 && CoolDown_4 != 1)
				{
					cout << "���� ��Ÿ�� �Դϴ�." << endl << endl;
					if (CoolDown_4 == -1)
					{
						CoolDown_4 = 2;//��ų ��Ÿ��
					}

				}
				//5����ų
				else if (SkillSelect == 5 && CoolDown_5 == 1)
				{
					MonsterHealth = MonsterHealth - Skill_5;
					if (MonsterHealth <= 0)//���Ͱ� �׾��� ���
					{
						cout << "'BOOM!'�������� '" << Skill_5 << "' ������ ü���� 0�̴�" << endl;
						cout << "���͸� ��Ҵ�!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else//���Ͱ� �׾��� �ʾ��� ���
					{
						cout << "'BOOM!'�������� '" << Skill_5 << "'������ ü���� " << MonsterHealth << "�̴�" << endl;
					}	
				}
				//��ų ��Ÿ�� ȸ��
				else if (SkillSelect == 5 && CoolDown_5 != 1)
				{
					cout << "���� ��Ÿ�� �Դϴ�." << endl << endl;
					if (CoolDown_5 == -1)
					{
						CoolDown_5 = 2;//��ų ��Ÿ��
					}
					_sleep(1000);
					system("cls");
				}
				//6����ų
				else if (SkillSelect == 6 && CoolDown_6 == 2)
				{
					cout << "'������ �� ����'�������� '";
					for (int i = Skill_6; i < 26; i++)
					{
						cout << i << "'";
						MonsterHealth = MonsterHealth - i;
					}
					if (MonsterHealth <= 0)//���Ͱ� �׾��� ���
					{
						cout << "' ������ ü���� 0�̴�" << endl;
						cout << "���͸� ��Ҵ�!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else//���Ͱ� �׾��� �ʾ��� ���
					{
						cout << "������ ü���� " << MonsterHealth << "�̴�" << endl;
					}
				}
				//��ų ��Ÿ�� ȸ��
				else if (SkillSelect == 6 && CoolDown_6 != 2)
				{
					cout << "���� ��Ÿ�� �Դϴ�." << endl << endl;
					if (CoolDown_6 == -1)
					{
						CoolDown_6 = 3;//��ų ��Ÿ��
					}

				}
				//7����ų
				else if (SkillSelect == 7 && CoolDown_7 == 4)
				{
					
					if (Skill_7 > 7)//���Ͱ� �׾��� ���
					{
						printf("%d\n", Skill_7);
						cout << "���Ͱ� ����ߴ�!" << endl;
						cout << "���͸� ��Ҵ�!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else//���Ͱ� ���� �ʾ��� ���
					{
						cout << "'�ʹ� or ���'�������� ���Ϳ��� ���� �ʾҴ�. ������ ü���� " << MonsterHealth << "�̴�" << endl;
					}
				}
				//��ų ��Ÿ�� ȸ��
				else if (SkillSelect == 7 && CoolDown_7 != 4) 
				{
					cout << "���� ��Ÿ�� �Դϴ�." << endl << endl;
					if (CoolDown_7 == -1)
					{
						CoolDown_7 = 5;//��ų ��Ÿ��
					}

				}
				//8����ų
				else if (SkillSelect == 8 && CoolDown_8 == 3)
				{
					MonsterHealth = MonsterHealth - Skill_8;
					if (MonsterHealth <= 0)//���Ͱ� �׾��� ���
					{
						cout << "'BIG BOOM'�������� '" << Skill_8 << "' ������ ü���� 0�̴�" << endl;
						cout << "���͸� ��Ҵ�!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else//���Ͱ� �׾��� �ʾ��� ���
					{
						cout << "'BIG BOOM'�������� '" << Skill_8 << "'������ ü���� " << MonsterHealth << "�̴�" << endl;
					}
				}
				//��ų ��Ÿ�� ȸ��
				else if (SkillSelect == 8 && CoolDown_8 != 3)
				{
					cout << "���� ��Ÿ�� �Դϴ�." << endl << endl;
					if (CoolDown_8 == -1)
					{
						CoolDown_4 = 4;//��ų ��Ÿ��
					}
				}
				//9����ų
				else if (SkillSelect == 9 && CoolDown_9 == 3)
				{
					MonsterHealth = MonsterHealth - Skill_9;

					if (MonsterHealth <= 0)//���Ͱ� ù��° �Ǿ�� �׾��� ���
					{
						cout << "'ù��° �Ǿ'�������� '" << Skill_9 << "' ������ ü���� 0�̴�" << endl;
						cout << "���͸� ��Ҵ�!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else//���Ͱ� ù��° �Ǿ�� ���� �ʾ��� ���
					{
						cout << "'ù��° �Ǿ'�������� '" << Skill_9 << "'������ ü���� " << MonsterHealth << "�̴�" << endl;
					}
					_sleep(1000);
					Skill_9 = rand() % 51 + 100;
					MonsterHealth = MonsterHealth - Skill_9;
					if (MonsterHealth <= 0) //���Ͱ� �ι�° �Ǿ�� �׾��� ���
					{
						cout << "'�ι�° �Ǿ'�������� '" << Skill_9 << "' ������ ü���� 0�̴�" << endl;
						cout << "���͸� ��Ҵ�!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else//���Ͱ� �ι�° �Ǿ�� ���� �ʾ��� ���
					{
						cout << "'�ι�° �Ǿ'�������� '" << Skill_9 << "'������ ü���� " << MonsterHealth << "�̴�" << endl;
					}
					_sleep(1000);
					Skill_9 = rand() % 51 + 100;
					MonsterHealth = MonsterHealth - Skill_9;
					if (MonsterHealth <= 0) //���Ͱ� ����° �Ǿ�� �׾��� ���
					{
						cout << "'����° �Ǿ'�������� '" << Skill_9 << "' ������ ü���� 0�̴�" << endl;
						cout << "���͸� ��Ҵ�!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else //���Ͱ� ����° �Ǿ�� ���� �ʾ��� ���
					{
						cout << "'����° �Ǿ'�������� '" << Skill_9 << "'������ ü���� " << MonsterHealth << "�̴�" << endl;
					}
				}
				//��ų ��Ÿ�� ȸ��
				else if (SkillSelect == 9 && CoolDown_9 != 3)
				{
					cout << "���� ��Ÿ�� �Դϴ�." << endl << endl;
					if (CoolDown_9 == -1)
					{
						CoolDown_9 = 4;//��ų ��Ÿ��
					}

				}
				//10����ų
				else if (SkillSelect == 10 && CoolDown_10 == 9)
				{
					MonsterHealth = MonsterHealth - Skill_10;
					if (MonsterHealth <= 0) //���Ͱ� �׾��� ���
					{
						cout << "'��Ŭ����'�������� '" << Skill_10 << "' ������ ü���� 0�̴�" << endl;
						cout << "���͸� ��Ҵ�!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
						
					}
					else//���Ͱ� �׾��� �ʾ��� ���
					{
						cout << "'��Ŭ����'�������� '" << Skill_10 << "'������ ü���� " << MonsterHealth << "�̴�" << endl;
					}
				}
				//��ų ��Ÿ�� ȸ��
				else if (SkillSelect == 10 && CoolDown_10 != 9)
				{
					cout << "���� ��Ÿ�� �Դϴ�." << endl << endl;
					if (CoolDown_10 == -1)
					{
						CoolDown_10 = 10;//��ų ��Ÿ��
					}

				}
				//1���� 10�� �ƴ� ���ڸ� ������ ������
				else if(SkillSelect < 0 || SkillSelect > 10)
				{
					cout << "����� �� ���ڸ� �����ֽʽÿ�" << endl;
				}
				
			}
		}
		if (MonsterNum > 30) 
		{
			cout << "����:��� ���͸� ����ּż� �����մϴ� ����� �� �ô뿡 ������ ����Դϴ�." << endl << "END" << endl;
			return 0;
		}
		//��ų ���� �κ�
		else if (Select == 2)
		{

			cout << "1�� ��ų�� : ������(������ :10~20) ,��Ÿ�� :0��" << endl << endl;
			cout << "2�� ��ų�� : �ι� ������(������ :21~31) ��Ÿ�� :1��" << endl << endl;
			cout << "3�� ��ų�� : ũ��Ƽ�� ����! (������ :40~60) ��Ÿ�� : 2��" << endl << endl;
			cout << "4�� ��ų�� : ��ȭ��(������ :50~60), (�߰� ������ : 30 ,����2��) ��Ÿ�� : 2��" << endl << endl;
			cout << "5�� ��ų�� : BOOM! (������ 100 ~ 110) ��Ÿ�� : 2��" << endl << endl;
			cout << "6�� ��ų�� : ������ �� ����(������ 1�� �ɸ����: 1+2+3+...+10..+25, 2�� �ɸ���� 2+3+4+...+8+9+10..+25) ��Ÿ�� :3��" << endl << endl;
			cout << "7�� ��ų�� : �ʹ� or ��� (������: ��� Ȥ�� Miss ) ��Ÿ�� : 5��" << endl << endl;
			cout << "8�� ��ų�� : BIG BOOM! (������ 200~ 220) ��Ÿ�� :4��" << endl << endl;
			cout << "9�� ��ų�� : �Ǿ (������ :100~150, ���� 3��) ��Ÿ�� :4��" << endl << endl;
			cout << "10�� ��ų�� : ��Ŭ���� (������ :800~900) ��Ÿ�� 10��" << endl << endl;
			_sleep(500);
			cout << "�ڷ� ���Ƿ��� 1���� ���� �ּ���";
			cin >> Back;
			//�ڷ� ����
			if (Back == 1)
			{
				system("cls");
			}

		}
		//������
		else if (Select == 3)
		{
			cout << "����.. ������� �ѽ��ϱ�.. �� ��������!" << endl;
			_sleep(1000);
			return 0;
		}
	}
	return 0;
}