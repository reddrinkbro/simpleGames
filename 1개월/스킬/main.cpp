#include <iostream>
#include <time.h>
using namespace std;

int main() 
{
	int Skill_1; //스킬명 : 때리기(데미지 :10~20) ,쿨타임 :0
	int Skill_2; //스킬명 : 두번 때리기(데미지 :21~31) 쿨타임 :1
	int Skill_3; //스킬명 : 크리티컬 폭발! (데미지 :40~60) 쿨타임 : 2
	int Skill_4; // 스킬명 : 독화살(데미지 :50~60), (추가 데미지 : 30 ,지속2초) 쿨타임 : 3
	int Skill_5; //스킬명 : BOOM! (데미지 100 ~ 110) 쿨타임 : 3
	int Skill_6; // 스킬명 : 무지개 총 공격(1이 걸릴경우: 1+2+3+...+10...+25, 2가 걸릴경우 2+3+4+...+8+9+10...+25) 쿨타임 :4
	int Skill_7;//스킬명 : 쪽박 or 대박 (데미지: 즉사 혹은 Miss ,7보다크면 즉사 7보다 작으면 Miss) 쿨타임 : 5
	int Skill_8;//스킬명 : BIG BOOM! (데미지 200~ 220) 쿨타임 :4
	int Skill_9; //스킬명 : 피어샷 (데미지 :100~150, 지속 3초) 쿨타임 :4
	int Skill_10; // 스킬명 : 뉴클리어 (데미지 :800~900) 쿨타임 10
	int MonsterHealth; //몬스터 체력
	int MonsterNum = 0; //잡은 몬스터 수
	int Select, Back; // 지문선택, 뒤로가기
	int SkillSelect; //스킬 선택

	int CoolDown_2 = 1; //2번스킬 쿨타임
	int CoolDown_3 = 2; //3번스킬 쿨타임
	int CoolDown_4 = 2; //4번스킬 쿨타임
	int CoolDown_5 = 2; //5번스킬 쿨타임
	int CoolDown_6 = 3; // 6번스킬 쿨타임
	int CoolDown_7 = 5; //7번스킬 쿨타임
	int CoolDown_8 = 4; //8번스킬 쿨타임
	int CoolDown_9 = 4; //9번스킬 쿨타임
	int CoolDown_10 = 10; //10번스킬 쿨타임

	srand(time(NULL));
	while (true)
	{
		if (MonsterNum <= 10) //잡은 몬스터 수가 10마리 이하이면
		{
			MonsterHealth = rand() % 101 + 500; // 몬스터 체력 500~600
		}
		else if (MonsterNum <= 15) //잡은 몬스터 수가 15마리 이하이면
		{
			MonsterHealth = rand() % 101 + 700; // 몬스터 체력 700~800
		}
		else if (MonsterNum <= 20) //잡은 몬스터 수가 20마리 이하이면
		{
			MonsterHealth = rand() % 101 + 900; // 몬스터 체력 900~1000
		}
		else if (MonsterNum == 30) //잡은 몬스터 수가 30마리이면, 보스몬스터
		{
			MonsterHealth = 2000; // 몬스터 체력 2000
		}
		if (MonsterNum < 30) //일반몬스터
		{
			cout << "촌장: 마을에 몬스터가 나타났습니다! 용사님 몬스터를 해치워주시옵소서!" << endl;
		}
		else if (MonsterNum == 30) // 30마리 일때 보스몬스터 등장
		{
			cout << "촌장: 큰일났습니다!!!! 멀리서 보스몬스터가 오고 있습니다. 용사님 제발 보스몬스터를 잡아주시옵소서!" << endl;
		}
		cout << "1. 몬스터 잡으러 가기 2.스킬 설명 확인하기 3.도망치기" << endl;
		cin >> Select; // 몬스터를 잡으러 갈지, 스킬설명을 볼지, 도망칠지 선택하기
		if (Select < 1 || Select > 3) // 잘못된 숫자를 눌렀을 경우
		{
			cout << "제대로 된 숫자를 누르세요" << endl << endl;
		}
		_sleep(1000);
		system("cls");
	
		if (Select == 1)
		{
			cout << "현재 까지 잡은 몬스터 수 : " << MonsterNum << endl;
			cout << "몬스터가 나타났다" << endl;
			cout << "몬스터의 체력은 " << MonsterHealth << "이다" << endl;
			while (true) {
				//스킬 데미지
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
				
				cout << "어떤 스킬을 사용하시겠습니까? 1~10" << endl;
				cin >> SkillSelect; //스킬선택
				cout << endl;

				//스킬 쿨타임
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
				
				//1번스킬
				if (SkillSelect == 1)
				{
					MonsterHealth = MonsterHealth - Skill_1;
					
					if (MonsterHealth <= 0) //몬스터가 죽었을 경우
					{
						cout << "'때리기' 데미지는 " << Skill_1 << " 몬스터의 체력은 0이다" << endl;
						cout << "몬스터를 잡았다!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else //몬스터가 죽지 않았을 경우
					{
						cout << "'때리기' 데미지는 '" << Skill_1 << "' 몬스터의 체력은 " << MonsterHealth << "이다" << endl;
					}
				}
				//2번스킬
				else if (SkillSelect == 2 && CoolDown_2 == 0)
				{
					MonsterHealth = MonsterHealth - Skill_2;
					if (MonsterHealth <= 0)//몬스터가 죽었을 경우
					{
						cout << "'두번 때리기'데미지는 '" << Skill_2;
						Skill_2 = rand() % 11 + 21;
						MonsterHealth = MonsterHealth - Skill_2;
						cout <<"' '"<< Skill_2<<"' 몬스터의 체력은 0이다" << endl;
						cout << "몬스터를 잡았다!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else//몬스터가 죽지 않았을 경우
					{
						cout << "'두번 때리기'데미지는 '" << Skill_2;
						Skill_2 = rand() % 11 + 21;
						MonsterHealth = MonsterHealth - Skill_2;
						cout << "' '" << Skill_2 << "' 몬스터의 체력은 " << MonsterHealth << "이다" << endl;
					}
					
				}
				//스킬쿨타임 회복
				else if (SkillSelect == 2 && CoolDown_2 != 0)
				{
					cout << "아직 쿨타임 입니다." << endl << endl;
					if (CoolDown_2 == -1)
					{
						CoolDown_2 = 1; //스킬 쿨타임
					}

				}
				//3번스킬
				else if (SkillSelect == 3 && CoolDown_3 == 1)
				{
					MonsterHealth = MonsterHealth - Skill_3;
					if (MonsterHealth <= 0)//몬스터가 죽었을 경우
					{
						cout << "'크리티컬 폭발!'데미지는 '" << Skill_3 << "' 몬스터의 체력은 0이다" << endl;
						cout << "몬스터를 잡았다!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else//몬스터가 죽지 않았을 경우
					{
						cout << "'크리티컬 폭발!'데미지는 '" << Skill_3 << "' 몬스터의 체력은 " << MonsterHealth << "이다" << endl;
					}
				}
				//스킬 쿨타임 회복
				else if (SkillSelect == 3 && CoolDown_3 != 1)
				{
					cout << "아직 쿨타임 입니다." << endl << endl;
					if (CoolDown_3 == -1)
					{
						CoolDown_3 = 2;//스킬 쿨타임
					}

				}
				//4번스킬
				else if (SkillSelect == 4 && CoolDown_4 == 1)
				{
					MonsterHealth = MonsterHealth - Skill_4;
					if (MonsterHealth <= 0)//몬스터가 죽었을 경우
					{
						cout << "'독화살'데미지는 '" << Skill_4 << "' 몬스터의 체력은 0이다" << endl;
						cout << "몬스터를 잡았다!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else
					{
						cout << "'독화살'데미지는 '" << Skill_4 << "' 몬스터의 체력은 " << MonsterHealth << "이다" << endl;
						if (MonsterHealth <= 30)//몬스터가 죽었을때 독화살의 첫번째 추가데미지로 죽일경우
						{
							_sleep(1000);
							MonsterHealth = MonsterHealth - 30;
							cout << "'독화살'추가데미지 '30' 몬스터의 체력은 0이다" << endl;
							cout << "몬스터를 잡았다!" << endl;
							MonsterNum++;
							_sleep(1000);
							system("cls");
							break;
						}
						else//몬스터가 독화살 첫번째 추가데미지에 죽지 않았을 경우
						{
							_sleep(1000);
							MonsterHealth = MonsterHealth - 30;
							cout << "'독화살'추가데미지 '30' 몬스터의 체력은 " << MonsterHealth << "이다" << endl;
						}
						if (MonsterHealth <= 30)//몬스터가 독화살 두번째 추가데미지에 죽을 경우
						{
							_sleep(1000);
							MonsterHealth = MonsterHealth - 30;
							cout << "'독화살'추가데미지 '30' 몬스터의 체력은 0이다" << endl;
							cout << "몬스터를 잡았다!" << endl;
							MonsterNum++;
							_sleep(1000);
							system("cls");
							break;
						}
						else//몬스터가 독화살 두번째 추가데미지에 죽지 않았을 경우
						{
							_sleep(1000);
							MonsterHealth = MonsterHealth - 30;
							cout << "'독화살'추가데미지 '30' 몬스터의 체력은 " << MonsterHealth << "이다" << endl;
						}
					}
				}
				//스킬 쿨타임 회복
				else if (SkillSelect == 4 && CoolDown_4 != 1)
				{
					cout << "아직 쿨타임 입니다." << endl << endl;
					if (CoolDown_4 == -1)
					{
						CoolDown_4 = 2;//스킬 쿨타임
					}

				}
				//5번스킬
				else if (SkillSelect == 5 && CoolDown_5 == 1)
				{
					MonsterHealth = MonsterHealth - Skill_5;
					if (MonsterHealth <= 0)//몬스터가 죽었을 경우
					{
						cout << "'BOOM!'데미지는 '" << Skill_5 << "' 몬스터의 체력은 0이다" << endl;
						cout << "몬스터를 잡았다!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else//몬스터가 죽었지 않았을 경우
					{
						cout << "'BOOM!'데미지는 '" << Skill_5 << "'몬스터의 체력은 " << MonsterHealth << "이다" << endl;
					}	
				}
				//스킬 쿨타임 회복
				else if (SkillSelect == 5 && CoolDown_5 != 1)
				{
					cout << "아직 쿨타임 입니다." << endl << endl;
					if (CoolDown_5 == -1)
					{
						CoolDown_5 = 2;//스킬 쿨타임
					}
					_sleep(1000);
					system("cls");
				}
				//6번스킬
				else if (SkillSelect == 6 && CoolDown_6 == 2)
				{
					cout << "'무지개 총 공격'데미지는 '";
					for (int i = Skill_6; i < 26; i++)
					{
						cout << i << "'";
						MonsterHealth = MonsterHealth - i;
					}
					if (MonsterHealth <= 0)//몬스터가 죽었을 경우
					{
						cout << "' 몬스터의 체력은 0이다" << endl;
						cout << "몬스터를 잡았다!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else//몬스터가 죽었지 않았을 경우
					{
						cout << "몬스터의 체력은 " << MonsterHealth << "이다" << endl;
					}
				}
				//스킬 쿨타임 회복
				else if (SkillSelect == 6 && CoolDown_6 != 2)
				{
					cout << "아직 쿨타임 입니다." << endl << endl;
					if (CoolDown_6 == -1)
					{
						CoolDown_6 = 3;//스킬 쿨타임
					}

				}
				//7번스킬
				else if (SkillSelect == 7 && CoolDown_7 == 4)
				{
					
					if (Skill_7 > 7)//몬스터가 죽었을 경우
					{
						printf("%d\n", Skill_7);
						cout << "몬스터가 즉사했다!" << endl;
						cout << "몬스터를 잡았다!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else//몬스터가 죽지 않았을 경우
					{
						cout << "'쪽박 or 대박'데미지는 몬스터에게 들어가지 않았다. 몬스터의 체력은 " << MonsterHealth << "이다" << endl;
					}
				}
				//스킬 쿨타임 회복
				else if (SkillSelect == 7 && CoolDown_7 != 4) 
				{
					cout << "아직 쿨타임 입니다." << endl << endl;
					if (CoolDown_7 == -1)
					{
						CoolDown_7 = 5;//스킬 쿨타임
					}

				}
				//8번스킬
				else if (SkillSelect == 8 && CoolDown_8 == 3)
				{
					MonsterHealth = MonsterHealth - Skill_8;
					if (MonsterHealth <= 0)//몬스터가 죽었을 경우
					{
						cout << "'BIG BOOM'데미지는 '" << Skill_8 << "' 몬스터의 체력은 0이다" << endl;
						cout << "몬스터를 잡았다!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else//몬스터가 죽었지 않았을 경우
					{
						cout << "'BIG BOOM'데미지는 '" << Skill_8 << "'몬스터의 체력은 " << MonsterHealth << "이다" << endl;
					}
				}
				//스킬 쿨타임 회복
				else if (SkillSelect == 8 && CoolDown_8 != 3)
				{
					cout << "아직 쿨타임 입니다." << endl << endl;
					if (CoolDown_8 == -1)
					{
						CoolDown_4 = 4;//스킬 쿨타임
					}
				}
				//9번스킬
				else if (SkillSelect == 9 && CoolDown_9 == 3)
				{
					MonsterHealth = MonsterHealth - Skill_9;

					if (MonsterHealth <= 0)//몬스터가 첫번째 피어샷에 죽었을 경우
					{
						cout << "'첫번째 피어샷'데미지는 '" << Skill_9 << "' 몬스터의 체력은 0이다" << endl;
						cout << "몬스터를 잡았다!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else//몬스터가 첫번째 피어샷에 죽지 않았을 경우
					{
						cout << "'첫번째 피어샷'데미지는 '" << Skill_9 << "'몬스터의 체력은 " << MonsterHealth << "이다" << endl;
					}
					_sleep(1000);
					Skill_9 = rand() % 51 + 100;
					MonsterHealth = MonsterHealth - Skill_9;
					if (MonsterHealth <= 0) //몬스터가 두번째 피어샷에 죽었을 경우
					{
						cout << "'두번째 피어샷'데미지는 '" << Skill_9 << "' 몬스터의 체력은 0이다" << endl;
						cout << "몬스터를 잡았다!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else//몬스터가 두번째 피어샷에 죽지 않았을 경우
					{
						cout << "'두번째 피어샷'데미지는 '" << Skill_9 << "'몬스터의 체력은 " << MonsterHealth << "이다" << endl;
					}
					_sleep(1000);
					Skill_9 = rand() % 51 + 100;
					MonsterHealth = MonsterHealth - Skill_9;
					if (MonsterHealth <= 0) //몬스터가 세번째 피어샷에 죽었을 경우
					{
						cout << "'세번째 피어샷'데미지는 '" << Skill_9 << "' 몬스터의 체력은 0이다" << endl;
						cout << "몬스터를 잡았다!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
					}
					else //몬스터가 세번째 피어샷에 죽지 않았을 경우
					{
						cout << "'세번째 피어샷'데미지는 '" << Skill_9 << "'몬스터의 체력은 " << MonsterHealth << "이다" << endl;
					}
				}
				//스킬 쿨타임 회복
				else if (SkillSelect == 9 && CoolDown_9 != 3)
				{
					cout << "아직 쿨타임 입니다." << endl << endl;
					if (CoolDown_9 == -1)
					{
						CoolDown_9 = 4;//스킬 쿨타임
					}

				}
				//10번스킬
				else if (SkillSelect == 10 && CoolDown_10 == 9)
				{
					MonsterHealth = MonsterHealth - Skill_10;
					if (MonsterHealth <= 0) //몬스터가 죽었을 경우
					{
						cout << "'뉴클리어'데미지는 '" << Skill_10 << "' 몬스터의 체력은 0이다" << endl;
						cout << "몬스터를 잡았다!" << endl;
						MonsterNum++;
						_sleep(1000);
						system("cls");
						break;
						
					}
					else//몬스터가 죽었지 않았을 경우
					{
						cout << "'뉴클리어'데미지는 '" << Skill_10 << "'몬스터의 체력은 " << MonsterHealth << "이다" << endl;
					}
				}
				//스킬 쿨타임 회복
				else if (SkillSelect == 10 && CoolDown_10 != 9)
				{
					cout << "아직 쿨타임 입니다." << endl << endl;
					if (CoolDown_10 == -1)
					{
						CoolDown_10 = 10;//스킬 쿨타임
					}

				}
				//1에서 10이 아닌 숫자를 누르면 동작함
				else if(SkillSelect < 0 || SkillSelect > 10)
				{
					cout << "제대로 된 숫자를 눌러주십시오" << endl;
				}
				
			}
		}
		if (MonsterNum > 30) 
		{
			cout << "촌장:모든 몬스터를 잡아주셔서 감사합니다 당신은 이 시대에 진정한 용사입니다." << endl << "END" << endl;
			return 0;
		}
		//스킬 설명 부분
		else if (Select == 2)
		{

			cout << "1번 스킬명 : 때리기(데미지 :10~20) ,쿨타임 :0번" << endl << endl;
			cout << "2번 스킬명 : 두번 때리기(데미지 :21~31) 쿨타임 :1번" << endl << endl;
			cout << "3번 스킬명 : 크리티컬 폭발! (데미지 :40~60) 쿨타임 : 2번" << endl << endl;
			cout << "4번 스킬명 : 독화살(데미지 :50~60), (추가 데미지 : 30 ,지속2초) 쿨타임 : 2번" << endl << endl;
			cout << "5번 스킬명 : BOOM! (데미지 100 ~ 110) 쿨타임 : 2번" << endl << endl;
			cout << "6번 스킬명 : 무지개 총 공격(데미지 1이 걸릴경우: 1+2+3+...+10..+25, 2가 걸릴경우 2+3+4+...+8+9+10..+25) 쿨타임 :3번" << endl << endl;
			cout << "7번 스킬명 : 쪽박 or 대박 (데미지: 즉사 혹은 Miss ) 쿨타임 : 5번" << endl << endl;
			cout << "8번 스킬명 : BIG BOOM! (데미지 200~ 220) 쿨타임 :4번" << endl << endl;
			cout << "9번 스킬명 : 피어샷 (데미지 :100~150, 지속 3초) 쿨타임 :4번" << endl << endl;
			cout << "10번 스킬명 : 뉴클리어 (데미지 :800~900) 쿨타임 10번" << endl << endl;
			_sleep(500);
			cout << "뒤로 가실려면 1번을 눌러 주세요";
			cin >> Back;
			//뒤로 가기
			if (Back == 1)
			{
				system("cls");
			}

		}
		//나가기
		else if (Select == 3)
		{
			cout << "쯧쯧.. 용사주제 한심하군.. 썩 물러가라!" << endl;
			_sleep(1000);
			return 0;
		}
	}
	return 0;
}