#include <iostream>

using namespace std;

int main()
{
	int Stone_Shord = 10;  // ���� ������  = 10
	int Bronze_Shord = 15;  // û���� ������  = 15
	int Copper_Shord = 20;  // ������ ������  = 20
	int Iron_Shord = 30;  // ö�� ������  = 30
	int Gold_Shord = 40;  // Ȳ�ݰ� ������  = 40
	int Silver_Shord = 35;  // ���� ������  = 35
	int Diamond_Shord = 50;  // ���̾Ƹ��� ������  = 50
	int Ruby_Shord = 45;  // ���� ������  = 45
	int Toy_Shord = 1;  // �峭���� ������  = 1
	int Gun_Shord = 80;  // �Ѱ� ������  = 80
	int TotalDamage = Stone_Shord + Bronze_Shord + Copper_Shord + Iron_Shord + Gold_Shord + Silver_Shord + Diamond_Shord + Ruby_Shord + Toy_Shord + Gun_Shord; //��� ���� ������ ��

	cout << "����� �� 10�ڷ縦 ȹ���ϼ̽��ϴ�." << endl << endl;
	_sleep(1000); // 1�� �� ���

	cout << "���� �������� Ȯ���Ͻðڽ��ϱ�?" << endl << endl;
	_sleep(1000);

	cout << "��" << endl << endl;
	_sleep(1500); // 1.5�ʵ� ���

				  // ���˿� ���� �޼���
	cout << " ---------------------------" << endl;
	cout << "I ù��° ���� '����'�Դϴ�. I" << endl;
	cout << "I'����'�� �������� " << Stone_Shord << "�Դϴ�.I" << endl;
	cout << " ---------------------------" << endl << endl;
	_sleep(1500);

	// û���˿� ���� �޼���
	cout << " -----------------------------" << endl;
	cout << "I �ι�° ���� 'û����'�Դϴ�. I" << endl;
	cout << "I'û����'�� �������� " << Bronze_Shord << "�Դϴ�.I" << endl;
	cout << " -----------------------------" << endl << endl;
	_sleep(1500);

	// �����˿� ���� �޼���
	cout << " -----------------------------" << endl;
	cout << "I ����° ���� '������'�Դϴ�. I" << endl;
	cout << "I'������'�� �������� " << Copper_Shord << "�Դϴ�.I" << endl;
	cout << " -----------------------------" << endl << endl;
	_sleep(1500);

	// ö�˿� ���� �޼���
	cout << " ----------------------------" << endl;
	cout << "I �׹�° ���� 'ö��'�Դϴ�.  I" << endl;
	cout << "I'ö��'�� �������� " << Iron_Shord << "�Դϴ�. I" << endl;
	cout << " ----------------------------" << endl << endl;
	_sleep(1500);

	// Ȳ�ݰ˿� ���� �޼���
	cout << " -------------------------------" << endl;
	cout << "I �ټ���° ���� 'Ȳ�ݰ�'�Դϴ�. I" << endl;
	cout << "I'Ȳ�ݰ�'�� �������� " << Gold_Shord << "�Դϴ�.  I" << endl;
	cout << " -------------------------------" << endl << endl;
	_sleep(1500);

	// ���˿� ���� �޼���
	cout << " -----------------------------" << endl;
	cout << "I ������° ���� '����'�Դϴ�. I" << endl;
	cout << "I'����'�� �������� " << Silver_Shord << "�Դϴ�.  I" << endl;
	cout << " -----------------------------" << endl << endl;
	_sleep(1500);

	// ���̾Ƹ��˿� ���� �޼���
	cout << " -------------------------------------" << endl;
	cout << "I �ϰ���° ���� '���̾Ƹ���'�Դϴ�. I" << endl;
	cout << "I'���̾Ƹ���'�� �������� " << Diamond_Shord << "�Դϴ�.  I" << endl;
	cout << " -------------------------------------" << endl << endl;
	_sleep(1500);

	// ���˿� ���� �޼���
	cout << " -------------------------------" << endl;
	cout << "I ������° ���� '����'�Դϴ�. I" << endl;
	cout << "I '����'�� �������� " << Ruby_Shord << "�Դϴ�. I" << endl;
	cout << " -------------------------------" << endl << endl;
	_sleep(1500);

	// �峭���˿� ���� �޼���
	cout << " ---------------------------------" << endl;
	cout << "I ��ȩ��° ���� '�峭����'�Դϴ�. I" << endl;
	cout << "I'�峭����'�� �������� " << Toy_Shord << "�Դϴ�.   I" << endl;
	cout << " ---------------------------------" << endl << endl;
	_sleep(1500);

	// �Ѱ˿� ���� �޼���
	cout << " ---------------------------" << endl;
	cout << "I ����° ���� '�Ѱ�'�Դϴ�. I" << endl;
	cout << "I'�Ѱ�'�� �������� " << Gun_Shord << "�Դϴ�.I" << endl;
	cout << " ---------------------------" << endl << endl;
	_sleep(1000);

	// ��� ���� ������ �ջ�
	cout << "��� ���� �������� " << TotalDamage << "�Դϴ�." << endl;
	cout << "---------------------------" << endl;
	cout << "�׷��� ����� '����'�Դϴ�." << endl << endl;

	return 0;
}