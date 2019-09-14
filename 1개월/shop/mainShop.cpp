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

	classShop.push_back(_redPotion); //레드포션
	classShop.push_back(_orangePotion); //주황포션
	classShop.push_back(_bluePotion); //파란 포션
	classShop.push_back(_yellowPotion); //노랑포션
	classShop.push_back(_helmet); //투구
	classShop.push_back(_armor); //갑옷
	classShop.push_back(_gloves); //장갑
	classShop.push_back(_shoes); //신발
	classShop.push_back(_belt); // 벨트
	classShop.push_back(_sword); //검
	classShop.push_back(_spear); //창
	classShop.push_back(_axe); //도끼
	classShop.push_back(_sheild); //방패
	classShop.push_back(_staff); //지팡이
	selectionWindow();
}


mainShop::~mainShop()
{

}

void mainShop::selectionWindow()
{
	int select = 0;
	int playerMoney = 10000;
	cout << "1. 인벤토리 보기 2. 상점가기" << endl;
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
	cout << "인 벤 토 리" << endl;
	cout << "====================" << endl;
	indexIterator = playerInventory.begin();
	if (playerInventory.size() == 0)
	{
		cout << "아이템이 없습니다." << endl;
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
	cout << "사려는 물건을 선택해주세요.(뒤로가기는 0을 눌러주세요)" << endl;
	cout << "현재 가지고 있는 돈 : " << money << endl;
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
			cout << "돈이 부족합니다" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userRedPotion->getName() << "을 구매했습니다" << endl;
			playerInventory.push_back(_userRedPotion);
			money -= 100;
		}
	}
	else if (selectItem == 2)
	{
		
		orangePotion* _userOrangePotion = new orangePotion;
		if (money < _userOrangePotion->getPrice())
		{
			cout << "돈이 부족합니다" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userOrangePotion->getName() << "을 구매했습니다" << endl;
			playerInventory.push_back(_userOrangePotion);
			money -= 300;
		}
	}
	else if (selectItem == 3)
	{
		bluePotion* _userBluePotion = new bluePotion;
		if (money < _userBluePotion->getPrice())
		{
			cout << "돈이 부족합니다" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userBluePotion->getName() << "을 구매했습니다" << endl;
			playerInventory.push_back(_userBluePotion);
			money -= 200;
		}
	}
	else if (selectItem == 4)
	{
		yellowPotion* _userYellowPotion = new yellowPotion;
		if (money < _userYellowPotion->getPrice())
		{
			cout << "돈이 부족합니다" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userYellowPotion->getName() << "을 구매했습니다" << endl;
			playerInventory.push_back(_userYellowPotion);
			money -= 500;
		}
	}
	else if (selectItem == 5)
	{
		helmet* _userHelmet = new helmet;
		if (money < _userHelmet->getPrice())
		{
			cout << "돈이 부족합니다" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			money -= 1100;
			cout << _userHelmet->getName() << "을 구매했습니다" << endl;
			playerInventory.push_back(_userHelmet);
		}
	}
	else if (selectItem == 6)
	{
		armor* _userArmor = new armor;
		if (money < _userArmor->getPrice())
		{
			cout << "돈이 부족합니다" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userArmor->getName() << "을 구매했습니다" << endl;
			playerInventory.push_back(_userArmor);
			money -= 1000;
		}
	}
	else if (selectItem == 7)
	{
		gloves* _userGloves = new gloves;
		if (money < _userGloves->getPrice())
		{
			cout << "돈이 부족합니다" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userGloves->getName() << "을 구매했습니다" << endl;
			playerInventory.push_back(_userGloves);
			money -= 800;
		}
	}
	else if (selectItem == 8)
	{
		shoes* _userShoes = new shoes;
		if (money < _userShoes->getPrice())
		{
			cout << "돈이 부족합니다" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userShoes->getName() << "을 구매했습니다" << endl;
			playerInventory.push_back(_userShoes);
			money -= 600;
		}
	}
	else if (selectItem == 9)
	{
		belt* _userBelt = new belt;
		if (money < _userBelt->getPrice())
		{
			cout << "돈이 부족합니다" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userBelt->getName() << "을 구매했습니다" << endl;
			playerInventory.push_back(_userBelt);
			money -= 900;
		}
	}
	else if (selectItem == 10)
	{
		sword* _userSword = new sword;
		if (money < _userSword->getPrice())
		{
			cout << "돈이 부족합니다" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userSword->getName() << "을 구매했습니다" << endl;
			playerInventory.push_back(_userSword);
			money -= 1000;
		}
	}
	else if (selectItem == 11)
	{
		spear* _userSpear = new spear;
		if (money < _userSpear->getPrice())
		{
			cout << "돈이 부족합니다" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userSpear->getName() << "을 구매했습니다" << endl;
			playerInventory.push_back(_userSpear);
			money -= 1300;
		}
	}
	else if (selectItem == 12)
	{
		axe* _userAxe = new axe;
		if (money < _userAxe->getPrice())
		{
			cout << "돈이 부족합니다" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userAxe->getName() << "을 구매했습니다" << endl;
			playerInventory.push_back(_userAxe);
			money -= 1400;
		}
	}
	else if (selectItem == 13)
	{
		sheild* _userSheild = new sheild;
		if (money < _userSheild->getPrice())
		{
			cout << "돈이 부족합니다" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userSheild->getName() << "을 구매했습니다" << endl;
			playerInventory.push_back(_userSheild);
			money -= 1200;
		}
	}
	else if (selectItem == 14)
	{
		staff* _userStaff = new staff;
		if (money < _userStaff->getPrice())
		{
			cout << "돈이 부족합니다" << endl;
			Sleep(1000);
			system("cls");
			selectionWindow();
		}
		else
		{
			cout << _userStaff->getName() << "을 구매했습니다" << endl;
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