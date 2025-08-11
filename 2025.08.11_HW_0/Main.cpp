#include <iostream>
#include <Windows.h>
using namespace std;

#define HP		0
#define MP		1
#define ATK		2
#define DEF		3
#define STATS	4

#define MENU_HP_POTION	1
#define MENU_MP_POTION	2
#define MENU_HP_UP		3
#define MENU_MP_UP		4
#define MENU_ATTACK		5
#define MENU_ULT		6
#define MENU_EXIT		7



void setPotion(int count, int* p_HPPotion, int* p_MPPotion);

int main()
{
	int stat[STATS];
	int hpPotionCount = 5, mpPotionCount = 5;
	int menu = 0;
	ZeroMemory(stat, sizeof(int) * STATS);

	do
	{
		cout << "HP와 MP를 입력해주세요: ";
		cin >> stat[HP] >> stat[MP];

		if (!(stat[HP] < 50 || stat[MP] < 50))
			break;

		cout << "HP나 HP의 값이 너무 작습니다. 다시 입력해 주세요." << endl;
	} while (stat[HP] < 50 || stat[MP] < 50);

	do
	{
		cout << "공격력과 방여력을 입력해주세요: ";
		cin >> stat[ATK] >> stat[DEF];


		if (!(stat[ATK] <= 0 || stat[DEF] <= 0))
			break;

		cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해 주세요." << endl;
	} while (stat[ATK] <= 0 || stat[DEF] <= 0);

	cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
	setPotion(5, &hpPotionCount, &mpPotionCount);

	cout << "=============================================" << endl;
	cout << "< 스탯 관리 시스템 >" << endl;

	while (1)
	{
		cout << "1. HP 회복" << endl
			 << "2. MP 회복" << endl
			 << "3. HP 강화" << endl
			 << "4. MP 강화" << endl
			 << "5. 공격 스킬 사용" << endl
			 << "6. 필살기" << endl
			 << "7. 나가기" << endl;

		cout << "번호를 선택해주세요: ";
		cin >> menu;

		switch (menu)
		{
			case MENU_HP_POTION:

				if (hpPotionCount >= 1)
				{
					stat[HP] += 20;
					--hpPotionCount;
					cout << "* HP가 20 회복되었습니다. 표션이 1개 차감됩니다." << endl;
					cout << "현재 HP: " << stat[HP] << endl;
					cout << "남은 포션 수: " << hpPotionCount << endl;
				}
				else
					cout << "포션이 부족합니다." << endl;

				break;

			case MENU_MP_POTION:

				if (mpPotionCount >= 1)
				{
					stat[MP] += 20;
					--mpPotionCount;
					cout << "* MP가 20 회복되었습니다. 표션이 1개 차감됩니다." << endl;
					cout << "현재 MP: " << stat[MP] << endl;
					cout << "남은 포션 수: " << mpPotionCount << endl;
				}
				else
					cout << "포션이 부족합니다." << endl;

				break;

			case MENU_HP_UP:

				stat[HP] *= 2;
				cout << "* HP가 2배로 증가되었습니다." << endl;
				cout << "현재 HP: " << stat[HP] << endl;

				break;

			case MENU_MP_UP:

				stat[MP] *= 2;
				cout << "* MP가 2배로 증가되었습니다." << endl;
				cout << "현재 MP: " << stat[MP] << endl;

				break;

			case MENU_ATTACK:

				if (stat[MP] >= 50)
				{
					stat[MP] -= 50;
					cout << "* 스킬을 사용하여 MP가 50 소모되었습니다.." << endl;
					cout << "현재 MP: " << stat[MP] << endl;
				}
				else
					cout << "스킬 사용이 불가합니다." << endl;

				break;

			case MENU_ULT:

				if (stat[MP] > 0)
				{
					stat[MP] /= 2;
					cout << "* 스킬을 사용하여 MP가 50% 소모되었습니다.." << endl;
					cout << "현재 MP: " << stat[MP] << endl;
				}
				else
					cout << "필살기 사용이 불가합니다." << endl;

				break;

			case MENU_EXIT:

				cout << "프로그램을 종료합니다." << endl;
				exit(100);

				break;

			default:

				cout << "잘못된 메뉴를 선택하셨습니다." << endl;

				break;
		}
	}

	return 0;
}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	(*p_HPPotion) = count;
	(*p_MPPotion) = count;
}
