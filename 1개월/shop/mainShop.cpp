#include "mainShop.h"



mainShop::mainShop()
{
	armor* _armor = new armor;
	bluePotion* _bluePotion = new bluePotion;
	gloves* _gloves = new gloves;
	helmet* _helmet = new helmet;
	orangePotion* _orangePotion = new orangePotion;
	redPotion* _redPotion = new redPotion;
	sheild* _sheild = new sheild;
	shoes* _shoes = new shoes;
	sword* _sword = new sword;
	shop* _shop = new shop;
	yellowPotion* _yellowPotion = new yellowPotion;
	axe* _axe = new axe;
	spear* _spear = new spear;
	staff* _staff = new staff;
	belt* _belt = new belt;

	classShop.push_back(_redPotion); //��������
	classShop.push_back(_orangePotion); //��Ȳ����
	classShop.push_back(_bluePotion); //�Ķ� ����
	classShop.push_back(_yellowPotion); //�������
	classShop.push_back(_helmet); //����
	classShop.push_back(_armor); //����
	classShop.push_back(_gloves); //�尩
	classShop.push_back(_shoes); //�Ź�
	classShop.push_back(_belt); // ��Ʈ
	classShop.push_back(_sword); //��
	classShop.push_back(_spear); //â
	classShop.push_back(_axe); //����
	classShop.push_back(_sheild); //����
	classShop.push_back(_staff); //������
	selectionWindow();
}


mainShop::~mainShop()
{

}

void mainShop::selectionWindow()
{
	int select = 0;
	int playerMoney = 10000;
	cout << "1. �κ��丮 ���� 2. ��������" << endl;
	cin >> select;
	system("cls");
	if (select == 1)
	{
		showMyInventory();
	}
	else if (select == 2)
	{
		showShop(playerMoney);
	}
	
}
void mainShop::showMyInventory()
{
	cout << "�� �� �� ��" << endl;
	cout << "====================" << endl;
	indexIterator = playerInventory.begin();
	if (playerInventory.size() == 0)
	{
		cout << "�������� �����ϴ�." << endl;
	}
	else
	{
		for (indexIterator; indexIterator != playerInventory.end(); indexIterator++)
		{
			(*indexIterator)->showItem();
			cout << "====================" << endl;
		}
	}
	Sleep(1000);
	system("cls");
	selectionWindow();
}

void mainShop::showShop(int money)
{
	
	for (int i = 0; i < classShop.size(); i++)
	{
		cout << i + 1 << ". ";
		classShop[i]->showItemPrice();
		
		if (i % 2 == 1)
		{
			cout << endl;
			cout << "=============================================================="<< endl;
		}
	}
	cout << "����� ������ �������ּ���.(�ڷΰ���� 0�� �����ּ���)" << endl;
	cout << "���� ������ �ִ� �� : " << money << endl;
	purchaseItem(money);
	
}

void mainShop::purchaseItem(int money)
{
	int selectItem = 0;
	cin >> selectItem;
	
	if (selectItem == 1)
	{
		
		
		redPotion* _userRedPotion = new redPotion;
		if (money < _userRedPotion->getPrice())
		{
			cout << "���� �����մϴ�" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userRedPotion->getName() << "�� �����߽��ϴ�" << endl;
			playerInventory.push_back(_userRedPotion);
			money -= 100;
		}
	}
	else if (selectItem == 2)
	{
		
		orangePotion* _userOrangePotion = new orangePotion;
		if (money < _userOrangePotion->getPrice())
		{
			cout << "���� �����մϴ�" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userOrangePotion->getName() << "�� �����߽��ϴ�" << endl;
			playerInventory.push_back(_userOrangePotion);
			money -= 300;
		}
	}
	else if (selectItem == 3)
	{
		bluePotion* _userBluePotion = new bluePotion;
		if (money < _userBluePotion->getPrice())
		{
			cout << "���� �����մϴ�" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userBluePotion->getName() << "�� �����߽��ϴ�" << endl;
			playerInventory.push_back(_userBluePotion);
			money -= 200;
		}
	}
	else if (selectItem == 4)
	{
		yellowPotion* _userYellowPotion = new yellowPotion;
		if (money < _userYellowPotion->getPrice())
		{
			cout << "���� �����մϴ�" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userYellowPotion->getName() << "�� �����߽��ϴ�" << endl;
			playerInventory.push_back(_userYellowPotion);
			money -= 500;
		}
	}
	else if (selectItem == 5)
	{
		helmet* _userHelmet = new helmet;
		if (money < _userHelmet->getPrice())
		{
			cout << "���� �����մϴ�" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			money -= 1100;
			cout << _userHelmet->getName() << "�� �����߽��ϴ�" << endl;
			playerInventory.push_back(_userHelmet);
		}
	}
	else if (selectItem == 6)
	{
		armor* _userArmor = new armor;
		if (money < _userArmor->getPrice())
		{
			cout << "���� �����մϴ�" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userArmor->getName() << "�� �����߽��ϴ�" << endl;
			playerInventory.push_back(_userArmor);
			money -= 1000;
		}
	}
	else if (selectItem == 7)
	{
		gloves* _userGloves = new gloves;
		if (money < _userGloves->getPrice())
		{
			cout << "���� �����մϴ�" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userGloves->getName() << "�� �����߽��ϴ�" << endl;
			playerInventory.push_back(_userGloves);
			money -= 800;
		}
	}
	else if (selectItem == 8)
	{
		shoes* _userShoes = new shoes;
		if (money < _userShoes->getPrice())
		{
			cout << "���� �����մϴ�" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userShoes->getName() << "�� �����߽��ϴ�" << endl;
			playerInventory.push_back(_userShoes);
			money -= 600;
		}
	}
	else if (selectItem == 9)
	{
		belt* _userBelt = new belt;
		if (money < _userBelt->getPrice())
		{
			cout << "���� �����մϴ�" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userBelt->getName() << "�� �����߽��ϴ�" << endl;
			playerInventory.push_back(_userBelt);
			money -= 900;
		}
	}
	else if (selectItem == 10)
	{
		sword* _userSword = new sword;
		if (money < _userSword->getPrice())
		{
			cout << "���� �����մϴ�" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userSword->getName() << "�� �����߽��ϴ�" << endl;
			playerInventory.push_back(_userSword);
			money -= 1000;
		}
	}
	else if (selectItem == 11)
	{
		spear* _userSpear = new spear;
		if (money < _userSpear->getPrice())
		{
			cout << "���� �����մϴ�" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userSpear->getName() << "�� �����߽��ϴ�" << endl;
			playerInventory.push_back(_userSpear);
			money -= 1300;
		}
	}
	else if (selectItem == 12)
	{
		axe* _userAxe = new axe;
		if (money < _userAxe->getPrice())
		{
			cout << "���� �����մϴ�" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userAxe->getName() << "�� �����߽��ϴ�" << endl;
			playerInventory.push_back(_userAxe);
			money -= 1400;
		}
	}
	else if (selectItem == 13)
	{
		sheild* _userSheild = new sheild;
		if (money < _userSheild->getPrice())
		{
			cout << "���� �����մϴ�" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userSheild->getName() << "�� �����߽��ϴ�" << endl;
			playerInventory.push_back(_userSheild);
			money -= 1200;
		}
	}
	else if (selectItem == 14)
	{
		staff* _userStaff = new staff;
		if (money < _userStaff->getPrice())
		{
			cout << "���� �����մϴ�" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userStaff->getName() << "�� �����߽��ϴ�" << endl;
			playerInventory.push_back(_userStaff);
			money -= 1500;
		}
	}
	else if (selectItem == 0)
	{
		system("cls");
		selectionWindow();
	}
	Sleep(1000);
	system("cls");
	showShop(money);
}