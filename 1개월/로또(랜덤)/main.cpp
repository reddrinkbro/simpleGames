#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	int NumOne; //ù��° ��ȣ
	int NumTwo; //�ι�° ��ȣ
	int NumThree; //����° ��ȣ
	int NumFour; //�׹�° ��ȣ
	int NumFive; //�ټ���° ��ȣ
	int NumSix; //������° ��ȣ
	int LottoCount = 0; //�ζ� ���� Ƚ��

	srand(time(NULL));

	NumOne = rand() % 45 + 1; //ù��° ������ ����

	while (true)
	{
		NumTwo = rand() % 45 + 1;	//�ι�° ������ ����
		if (NumOne != NumTwo) //ù��° �������� �ι�° ���� �� �Ͽ� �ٸ������� �ݺ��� ��Ų�� 
		{
			break;
		}
	}

	while (true)
	{
		NumThree = rand() % 45 + 1; //����° ������ ����
		if (NumOne != NumThree && NumTwo != NumThree) //����° �������� ù��° �ι�° ���� �� �Ͽ� �ٸ������� �ݺ��� ��Ų�� 
		{
			break;
		}
	}
	while (true)
	{
		NumFour = rand() % 45 + 1; //�׹�° ������ ����
		if (NumOne != NumFour && NumTwo != NumFour && NumThree!=NumFour) //�׹�° �������� ù��° �ι�° ����° ���� �� �Ͽ� �ٸ������� �ݺ��� ��Ų�� 
		{
			break;
		}
	}
	while (true)
	{
		NumFive = rand() % 45 + 1; //�ټ���° ������ ����
		if (NumOne != NumFive && NumTwo != NumFive && NumThree != NumFive && NumFour !=NumFive) //�ټ���° �������� ù��° �ι�° ����° �׹�°���� �� �Ͽ� �ٸ������� �ݺ��� ��Ų�� 
		{
			break;
		}
	}
	while (true)
	{
		NumSix = rand() % 45 + 1; //������° ������ ����
		if (NumOne != NumSix && NumTwo != NumSix && NumThree != NumSix && NumFour != NumSix && NumFive!= NumSix) //������° �������� ù��° �ι�° ����° �׹�° �ټ���°���� �� �Ͽ� �ٸ������� �ݺ��� ��Ų��
		{
			break;
		}
	}
	cout << "ù��° ���ڴ� " << NumOne << " �Դϴ�!" << endl;
	cout << "�ι�° ���ڴ� " << NumTwo << " �Դϴ�!" << endl;
	cout << "����° ���ڴ� " << NumThree << " �Դϴ�!" << endl;
	cout << "�׹�° ���ڴ� " << NumFour << " �Դϴ�!" << endl;
	cout << "�ټ���° ���ڴ� " << NumFive << " �Դϴ�!" << endl;
	cout << "������° ���ڴ� " << NumSix << " �Դϴ�!" << endl << endl;
	cout << "�̹��� �ζ� ��ȣ�� " << NumOne << ", " << NumTwo << ", " << NumThree << ", " << NumFour << ", " << NumFive << ", " << NumSix << "�Դϴ�." << endl;
}