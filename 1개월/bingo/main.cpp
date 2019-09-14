#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;


//������
//�÷��̾� ��ǻ�� ������
//�����Է�
//���� ����
//�¸� ����
struct BINGO
{
	int board[5][5]; //������
	int bingoValue = 0; //������� ������ ����
	bool is_XBingo[5] = { false }; //x���� �������� �ƴ��� �Ǵ�
	bool is_YBingo[5] = { false }; //y���� �������� �ƴ��� �Ǵ�
	bool is_Bingo[2] = { false }; //�밢������ �������� �ƴ��� �Ǵ�
};

int main()
{
	cout << "BINGO ������ ���� �ϰڽ��ϴ�." << endl;
	srand(time(NULL));
	int gameCount = 0; //�÷����ϴ� ���� ����
	BINGO player; //�÷��̾� ����ü
	BINGO computer; //��ǻ�� ����ü
	int number[25]; //������ ����
	int (*playerNumber)[5] = (int(*)[5])number; // 1���� �迭�� 2���� �迭�� ��ȯ
	int (*computerNumber)[5] = (int(*)[5])number; //1���� �迭�� 2���� �迭�� ��ȯ
	int select; //��ȣ �Է�
	bool isUserTurn = true; //������ ���� ��ǻ�������� Ȯ���ϴ� ����
	
	//��ȣ �Է�
	for (int i = 0; i < 25; i++)
	{
		number[i] = i;
	} 
	//��ȣ ����
	for (int i = 0; i < 1000; i++)
	{
		int index1 = rand() % 25;
		int index2 = rand() % 25;
		int temp = number[index1];
		number[index1] = number[index2];
		number[index2] = temp;
	}
	
	//�÷��̾� ��ȣ �Է�
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			player.board[i][j] = playerNumber[i][j]+1;
		}
	}
	//��ȣ �ٽ� ����
	for (int i = 0; i < 1000; i++)
	{
		int index1 = rand() % 25;
		int index2 = rand() % 25;
		int temp = number[index1];
		number[index1] = number[index2];
		number[index2] = temp;
	}
	//��ǻ�� ��ȣ �Է�
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			computer.board[i][j] = computerNumber[i][j]+1;
		}
	}
	//�ߺ��Ǵ� ���ڸ� ���ϱ� ���� �迭�� �ʱ�ȭ
	for (int i = 0; i < 25; i++)
	{
		number[i] = 0;
	}
	//������ �׸���
	while (true)
	{
		int randomValue = -1;
		cout << "�÷��̾� ������        ��ǻ�� ������" << endl;
		cout << "�������������������������������������������� " << endl;
		for (int i = 0; i < 5; i++)
		{
			//�÷��̾� ������
			for (int j = 0; j < 5; j++)
			{
				if (player.board[i][j] < 10 && j == 4)
				{
					cout << "�� " << player.board[i][j] << "��";
				}
				else if (player.board[i][j] < 10)
				{
					cout << "�� " << player.board[i][j];
				}
				else if (player.board[i][j] >= 10 && j == 4)
				{
					cout << "��" << player.board[i][j] << "��";
				}
				else if (player.board[i][j] >= 10)
				{
					cout << "��" << player.board[i][j];
				}

			}
			//��ǻ�� ������
			for (int j = 0; j < 5; j++)
			{
				if (computer.board[i][j] < 10 && j == 4)
				{
					cout << "�� " << computer.board[i][j] << "��\t";
				}
				else if (computer.board[i][j] < 10)
				{
					cout << "�� " << computer.board[i][j];
				}
				else if (computer.board[i][j] >= 10 && j == 4)
				{
					cout << "��" << computer.board[i][j] << "��\t";
				}
				else if (computer.board[i][j] >= 10)
				{
					cout << "��" << computer.board[i][j];
				}

			}
			if (i < 4)
			{
				cout << endl << "�������������������������������������������� ";
			}
			else
			{
				cout << endl << "�������������������������������������������� ";
			}
			cout << endl;
		}
		cout << "�÷��̾� ���� ��: " << player.bingoValue << "\t��ǻ�� ���� ��: " << computer.bingoValue << endl;
		//��ȣ �Է�
		if (isUserTurn == true)
		{
			while (true)
			{
				cout << "��ȣ�� �Է����ּ���" << endl;
				cin >> select;
				//0���� 26�̻��� �����ϸ� �ٽ� �Է�
				if (select > 25 || select < 1)
				{
					cout << "����� �� ��ȣ�� �Է����ּ���" << endl;
				}
				else
				{
					// ������ ���ڰ� 1 �̸� number[0]�� �ִ� ���� 0�̸� ���� �ѱ�� �ƴϸ� �ٽ� �̴´�
					if (number[select - 1] == 0)
					{
						number[select-1] = select;
						isUserTurn = false;
						break;
					}
					else
					{
						cout << "�̹� ������ ����� �����Դϴ�." << endl << endl;
					}
				}
			}
		}
		else
		{
			randomValue = rand() % 25 + 1;
			while (true)
			{
				//�÷��̾� ���ڶ� ���� ���ڰ� �ȳ��ö�
				if (select != randomValue)
				{
					//��ǻ�Ϳ� �ִ� ���ڶ� �������̶� �ٸ���
					if (number[randomValue-1] == 0)
					{
						number[randomValue - 1] = randomValue;
						isUserTurn = true;
						break;
					}
					else
					{
						randomValue = rand() % 25 + 1;
					}
				}
			}
			cout << "��ǻ���� �� �Դϴ�." << endl;
			cout << "��ǻ�ʹ� " << randomValue << "�� �����߽��ϴ�." << endl;
			Sleep(500);
		}

		//���� ��ȣ�� 99���� �ٲ�
		for (int i = 0; i < 5;i++)
		{
			for (int j = 0; j < 5; j++)
			{
				//������ �Է��� ���� ������
				if (player.board[i][j] == select)
				{
					player.board[i][j] = 99;
				}
				//��ǻ�Ͱ� �Է��� ���� ������
				else if (player.board[i][j] == randomValue)
				{
					player.board[i][j] = 99;
				}
				if (computer.board[i][j] == select)
				{
					computer.board[i][j] = 99;
				}
				else if (computer.board[i][j] == randomValue)
				{
					computer.board[i][j] = 99;
				}

			}
		}
		//�÷��̾� ����� Ȯ��
		int p_xCount[5] = { 0 }; //x�� ī��Ʈ���ϱ�
		int p_yCount[5] = { 0 }; //y�� ī��Ʈ���ϱ�
		int p_Count[2] = { 0 }; //�밢�� ī��Ʈ ���ϱ�
		for (int i = 0; i < 5; i++)
		{
			switch (i)
			{
				//ù��° ���� �� ����
				case 0:
				{
					for (int j = 0; j < 5; j++)
					{
						if (player.board[i][j] == 99)
						{
							p_xCount[i]++;
							//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
							if (p_xCount[i] == 5 && player.is_XBingo[i] == false)
							{
								cout << "�÷��̾� :���� !" << endl;
								player.bingoValue++;
								player.is_XBingo[i] = true;
							}
						}
					}
				}
				break;
				//�ι�° ���� �� ����
				case 1:
				{
					for (int j = 0; j < 5; j++)
					{
						if (player.board[i][j] == 99)
						{
							p_xCount[i]++;
							//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
							if (p_xCount[i] == 5 && player.is_XBingo[i] == false)
							{
								cout << "�÷��̾� :���� !" << endl;
								player.bingoValue++;
								player.is_XBingo[i] = true;
							}
						}
					}
				}
				break;
				//����° ���� �� ����
				case 2:
				{
					for (int j = 0; j < 5; j++)
					{
						if (player.board[i][j] == 99)
						{
							p_xCount[i]++;
							//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
							if (p_xCount[i] == 5 && player.is_XBingo[i] == false)
							{
								cout << "�÷��̾� :���� !" << endl;
								player.bingoValue++;
								player.is_XBingo[i] = true;
							}
						}
					}
				}
				break;
				//�׹�° ���� �� ����
				case 3:
				{
					for (int j = 0; j < 5; j++)
					{
						if (player.board[i][j] == 99)
						{
							p_xCount[i]++;
							//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
							if (p_xCount[i] == 5 && player.is_XBingo[i] == false)
							{
								cout << "�÷��̾� :���� !" << endl;
								player.bingoValue++;
								player.is_XBingo[i] = true;
							}
						}
					}
				}
				break;
				//�ټ���° ���� �� ����
				case 4:
				{
					for (int j = 0; j < 5; j++)
					{
						if (player.board[i][j] == 99)
						{
							p_xCount[i]++;
							//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
							if (p_xCount[i] == 5 && player.is_XBingo[i] == false)
							{
								cout << "�÷��̾� :���� !" << endl;
								player.bingoValue++;
								player.is_XBingo[i] = true;
							}
						}
					}
				}
				break;
			}
		}
		//Y�� ���� ���ϱ�
		for (int j = 0; j < 5; j++)
		{
			switch (j)
			{
				//ù��° ���� �� ����
				case 0:
				{
					for (int i = 0; i < 5; i++)
					{
						if (player.board[i][j] == 99)
						{
							p_yCount[j]++;
							//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
							if (p_yCount[j] == 5 && player.is_YBingo[j] == false)
							{
								cout << "�÷��̾� :���� !" << endl;
								player.bingoValue++;
								player.is_YBingo[j] = true;
							}
						}
					}
				}
				break;
				//�ι�° ���� �� ����
				case 1:
				{
					for (int i = 0; i < 5; i++)
					{
						if (player.board[i][j] == 99)
						{
							p_yCount[j]++;
							//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
							if (p_yCount[j] == 5 && player.is_YBingo[j] == false)
							{
								cout << "�÷��̾� :���� !" << endl;
								player.bingoValue++;
								player.is_YBingo[j] = true;
							}
						}
					}
				}
				break;
				//����° ���� �� ����
				case 2:
				{
					for (int i = 0; i < 5; i++)
					{
						if (player.board[i][j] == 99)
						{
							p_yCount[j]++;
							//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
							if (p_yCount[j] == 5 && player.is_YBingo[j] == false)
							{
								cout << "�÷��̾� :���� !" << endl;
								player.bingoValue++;
								player.is_YBingo[j] = true;
							}
						}
					}
				}
				break;
				//�׹�° ���� �� ����
				case 3:
				{
					for (int i = 0; i < 5; i++)
					{
						if (player.board[i][j] == 99)
						{
							p_yCount[j]++;
							//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
							if (p_yCount[j] == 5 && player.is_YBingo[j] == false)
							{
								cout << "�÷��̾� :���� !" << endl;
								player.bingoValue++;
								player.is_YBingo[j] = true;
							}
						}
					}
				}
				break;
				//�ټ���° ���� �� ����
				case 4:
				{
					for (int i = 0; i < 5; i++)
					{
						if (player.board[i][j] == 99)
						{
							p_yCount[j]++;
							//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
							if (p_yCount[j] == 5 && player.is_YBingo[j] == false)
							{
								cout << "�÷��̾� :���� !" << endl;
								player.bingoValue++;
								player.is_YBingo[j] = true;
							}
						}
					}
				}
				break;
			}
		}

		//������ �밢�� ���� Ȯ��
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i == j)
				{
					if (player.board[i][j] == 99)
					{
						p_Count[0]++;
						//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
						if (p_Count[0] == 5 && player.is_Bingo[0] == false)
						{
							cout << "�÷��̾� :���� !" << endl;
							player.bingoValue++;
							player.is_Bingo[0] = true;
						}
					}
				}
				//���밢�� ����
				if (i + j == 4)
				{
					if (player.board[i][j] == 99)
					{
						p_Count[1]++;
						if (p_Count[1] == 5 && player.is_Bingo[1] == false)
						{
							cout << "�÷��̾� :���� !" << endl;
							player.bingoValue++;
							player.is_Bingo[1] = true;
						}
					}
				}
			}
		}

		//��ǻ�� ����� Ȯ��
		int c_xCount[5] = { 0 }; //x�� ī��Ʈ���ϱ�
		int c_yCount[5] = { 0 }; //y�� ī��Ʈ���ϱ�
		int c_Count[2] = { 0 };
		for (int i = 0; i < 5; i++)
		{
			switch (i)
			{
				//ù��° ���� �� ����
			case 0:
			{
				for (int j = 0; j < 5; j++)
				{
					if (computer.board[i][j] == 99)
					{
						c_xCount[i]++;
						//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
						if (c_xCount[i] == 5 && computer.is_XBingo[i] == false)
						{
							cout << "��ǻ�� : ���� !" << endl;
							computer.bingoValue++;
							computer.is_XBingo[i] = true;
						}
					}
				}
			}
			break;
			//�ι�° ���� �� ����
			case 1:
			{
				for (int j = 0; j < 5; j++)
				{
					if (computer.board[i][j] == 99)
					{
						c_xCount[i]++;
						//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
						if (c_xCount[i] == 5 && computer.is_XBingo[i] == false)
						{
							cout << "��ǻ�� : ���� !" << endl;
							computer.bingoValue++;
							computer.is_XBingo[i] = true;
						}
					}
				}
			}
			break;
			//����° ���� �� ����
			case 2:
			{
				for (int j = 0; j < 5; j++)
				{
					if (computer.board[i][j] == 99)
					{
						c_xCount[i]++;
						//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
						if (c_xCount[i] == 5 && computer.is_XBingo[i] == false)
						{
							cout << "��ǻ�� : ���� !" << endl;
							computer.bingoValue++;
							computer.is_XBingo[i] = true;
						}
					}
				}
			}
			break;
			//�׹�° ���� �� ����
			case 3:
			{
				for (int j = 0; j < 5; j++)
				{
					if (computer.board[i][j] == 99)
					{
						c_xCount[i]++;
						//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
						if (c_xCount[i] == 5 && computer.is_XBingo[i] == false)
						{
							cout << "��ǻ�� : ���� !" << endl;
							computer.bingoValue++;
							computer.is_XBingo[i] = true;
						}
					}
				}
			}
			break;
			//�ټ���° ���� �� ����
			case 4:
			{
				for (int j = 0; j < 5; j++)
				{
					if (computer.board[i][j] == 99)
					{
						c_xCount[i]++;
						//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
						if (c_xCount[i] == 5 && computer.is_XBingo[i] == false)
						{
							cout << "��ǻ�� : ���� !" << endl;
							computer.bingoValue++;
							computer.is_XBingo[i] = true;
						}
					}
				}
			}
			break;
			}
		}
		//Y�� ���� ���ϱ�
		for (int j = 0; j < 5; j++)
		{
			switch (j)
			{
				//ù��° ���� �� ����
			case 0:
			{
				for (int i = 0; i < 5; i++)
				{
					if (computer.board[i][j] == 99)
					{
						c_yCount[j]++;
						//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
						if (c_yCount[j] == 5 && computer.is_YBingo[j] == false)
						{
							cout << "��ǻ�� : ���� !" << endl;
							computer.bingoValue++;
							computer.is_YBingo[j] = true;
						}
					}
				}
			}
			break;
			//�ι�° ���� �� ����
			case 1:
			{
				for (int i = 0; i < 5; i++)
				{
					if (computer.board[i][j] == 99)
					{
						c_yCount[j]++;
						//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
						if (c_yCount[j] == 5 && computer.is_YBingo[j] == false)
						{
							cout << "��ǻ�� : ���� !" << endl;
							computer.bingoValue++;
							computer.is_YBingo[j] = true;
						}
					}
				}
			}
			break;
			//����° ���� �� ����
			case 2:
			{
				for (int i = 0; i < 5; i++)
				{
					if (computer.board[i][j] == 99)
					{
						c_yCount[j]++;
						//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
						if (c_yCount[j] == 5 && computer.is_YBingo[j] == false)
						{
							cout << "��ǻ�� : ���� !" << endl;
							computer.bingoValue++;
							computer.is_YBingo[j] = true;
						}
					}
				}
			}
			break;
			//�׹�° ���� �� ����
			case 3:
			{
				for (int i = 0; i < 5; i++)
				{
					if (computer.board[i][j] == 99)
					{
						c_yCount[j]++;
						//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
						if (c_yCount[j] == 5 && computer.is_YBingo[j] == false)
						{
							cout << "��ǻ�� : ���� !" << endl;
							computer.bingoValue++;
							computer.is_YBingo[j] = true;
						}
					}
				}
			}
			break;
			//�ټ���° ���� �� ����
			case 4:
			{
				for (int i = 0; i < 5; i++)
				{
					if (computer.board[i][j] == 99)
					{
						c_yCount[j]++;
						//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
						if (c_yCount[j] == 5 && computer.is_YBingo[j] == false)
						{
							cout << "��ǻ�� : ���� !" << endl;
							computer.bingoValue++;
							computer.is_YBingo[j] = true;
						}
					}
				}
			}
			break;
			}
		}

		//������ �밢�� ���� Ȯ��
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i == j)
				{
					if (computer.board[i][j] == 99)
					{
						c_Count[0]++;
						//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
						if (c_Count[0] == 5 && computer.is_Bingo[0] == false)
						{
							cout << "��ǻ�� : ���� !" << endl;
							computer.bingoValue++;
							computer.is_Bingo[0] = true;
						}
					}
				}
				//���밢�� ����
				if (i + j == 4)
				{
					if (computer.board[i][j] == 99)
					{
						c_Count[1]++;
						//ī��Ʈ�� 5�̰� bool���� false�϶� ���� �ȴ�
						if (c_Count[1] == 5 && computer.is_Bingo[1] == false)
						{
							cout << "��ǻ�� : ���� !" << endl;
							computer.bingoValue++;
							computer.is_Bingo[1] = true;
						}
					}
				}
			}
		}
		//3�� ���� �Ͽ����� ���
		if (player.bingoValue == 3)
		{
			cout << "�÷��̾� ���!!" << endl;
			Sleep(1000);
			gameCount++;
		}
		else if (computer.bingoValue ==3)
		{
			cout << "��ǻ�� ���!!" << endl;
			Sleep(1000);
			gameCount++;
		}
		else if (player.bingoValue == 3 && computer.bingoValue == 3)
		{
			cout << "�����ϴ�..." << endl;
			Sleep(1000);
			gameCount++;
		}
		if (gameCount > 5)
		{
			cout << "������ ���� ����..." << endl;
			break;
		}
		Sleep(1500);
		system("cls");
	}
	return 0;
}