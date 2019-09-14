#include <iostream>

using namespace std;

int main()
{
	int Stone_Shord = 10;  // 돌검 데미지  = 10
	int Bronze_Shord = 15;  // 청동검 데미지  = 15
	int Copper_Shord = 20;  // 구리검 데미지  = 20
	int Iron_Shord = 30;  // 철검 데미지  = 30
	int Gold_Shord = 40;  // 황금검 데미지  = 40
	int Silver_Shord = 35;  // 은검 데미지  = 35
	int Diamond_Shord = 50;  // 다이아몬드검 데미지  = 50
	int Ruby_Shord = 45;  // 루비검 데미지  = 45
	int Toy_Shord = 1;  // 장난감검 데미지  = 1
	int Gun_Shord = 80;  // 총검 데미지  = 80
	int TotalDamage = Stone_Shord + Bronze_Shord + Copper_Shord + Iron_Shord + Gold_Shord + Silver_Shord + Diamond_Shord + Ruby_Shord + Toy_Shord + Gun_Shord; //모든 총의 데미지 합

	cout << "당신은 검 10자루를 획득하셨습니다." << endl << endl;
	_sleep(1000); // 1초 뒤 출력

	cout << "검의 데미지를 확인하시겠습니까?" << endl << endl;
	_sleep(1000);

	cout << "예" << endl << endl;
	_sleep(1500); // 1.5초뒤 출력

				  // 돌검에 대한 메세지
	cout << " ---------------------------" << endl;
	cout << "I 첫번째 검은 '돌검'입니다. I" << endl;
	cout << "I'돌검'의 데미지는 " << Stone_Shord << "입니다.I" << endl;
	cout << " ---------------------------" << endl << endl;
	_sleep(1500);

	// 청동검에 대한 메세지
	cout << " -----------------------------" << endl;
	cout << "I 두번째 검은 '청동검'입니다. I" << endl;
	cout << "I'청동검'의 데미지는 " << Bronze_Shord << "입니다.I" << endl;
	cout << " -----------------------------" << endl << endl;
	_sleep(1500);

	// 구리검에 대한 메세지
	cout << " -----------------------------" << endl;
	cout << "I 세번째 검은 '구리검'입니다. I" << endl;
	cout << "I'구리검'의 데미지는 " << Copper_Shord << "입니다.I" << endl;
	cout << " -----------------------------" << endl << endl;
	_sleep(1500);

	// 철검에 대한 메세지
	cout << " ----------------------------" << endl;
	cout << "I 네번째 검은 '철검'입니다.  I" << endl;
	cout << "I'철검'의 데미지는 " << Iron_Shord << "입니다. I" << endl;
	cout << " ----------------------------" << endl << endl;
	_sleep(1500);

	// 황금검에 대한 메세지
	cout << " -------------------------------" << endl;
	cout << "I 다섯번째 검은 '황금검'입니다. I" << endl;
	cout << "I'황금검'의 데미지는 " << Gold_Shord << "입니다.  I" << endl;
	cout << " -------------------------------" << endl << endl;
	_sleep(1500);

	// 은검에 대한 메세지
	cout << " -----------------------------" << endl;
	cout << "I 여섯번째 검은 '은검'입니다. I" << endl;
	cout << "I'은검'의 데미지는 " << Silver_Shord << "입니다.  I" << endl;
	cout << " -----------------------------" << endl << endl;
	_sleep(1500);

	// 다이아몬드검에 대한 메세지
	cout << " -------------------------------------" << endl;
	cout << "I 일곱번째 검은 '다이아몬드검'입니다. I" << endl;
	cout << "I'다이아몬드검'의 데미지는 " << Diamond_Shord << "입니다.  I" << endl;
	cout << " -------------------------------------" << endl << endl;
	_sleep(1500);

	// 루비검에 대한 메세지
	cout << " -------------------------------" << endl;
	cout << "I 여덟번째 검은 '루비검'입니다. I" << endl;
	cout << "I '루비검'의 데미지는 " << Ruby_Shord << "입니다. I" << endl;
	cout << " -------------------------------" << endl << endl;
	_sleep(1500);

	// 장난감검에 대한 메세지
	cout << " ---------------------------------" << endl;
	cout << "I 아홉번째 검은 '장난감검'입니다. I" << endl;
	cout << "I'장난감검'의 데미지는 " << Toy_Shord << "입니다.   I" << endl;
	cout << " ---------------------------------" << endl << endl;
	_sleep(1500);

	// 총검에 대한 메세지
	cout << " ---------------------------" << endl;
	cout << "I 열번째 검은 '총검'입니다. I" << endl;
	cout << "I'총검'의 데미지는 " << Gun_Shord << "입니다.I" << endl;
	cout << " ---------------------------" << endl << endl;
	_sleep(1000);

	// 모든 검의 데미지 합산
	cout << "모든 검의 데미지는 " << TotalDamage << "입니다." << endl;
	cout << "---------------------------" << endl;
	cout << "그래도 당신은 '거지'입니다." << endl << endl;

	return 0;
}