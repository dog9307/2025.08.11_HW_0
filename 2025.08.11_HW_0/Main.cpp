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
		cout << "HP�� MP�� �Է����ּ���: ";
		cin >> stat[HP] >> stat[MP];

		if (!(stat[HP] < 50 || stat[MP] < 50))
			break;

		cout << "HP�� HP�� ���� �ʹ� �۽��ϴ�. �ٽ� �Է��� �ּ���." << endl;
	} while (stat[HP] < 50 || stat[MP] < 50);

	do
	{
		cout << "���ݷ°� �濩���� �Է����ּ���: ";
		cin >> stat[ATK] >> stat[DEF];


		if (!(stat[ATK] <= 0 || stat[DEF] <= 0))
			break;

		cout << "���ݷ��̳� ������ ���� �ʹ� �۽��ϴ�. �ٽ� �Է��� �ּ���." << endl;
	} while (stat[ATK] <= 0 || stat[DEF] <= 0);

	cout << "* ������ ���޵Ǿ����ϴ�. (HP, MP ���� �� 5��)" << endl;
	setPotion(5, &hpPotionCount, &mpPotionCount);

	cout << "=============================================" << endl;
	cout << "< ���� ���� �ý��� >" << endl;

	while (1)
	{
		cout << "1. HP ȸ��" << endl
			 << "2. MP ȸ��" << endl
			 << "3. HP ��ȭ" << endl
			 << "4. MP ��ȭ" << endl
			 << "5. ���� ��ų ���" << endl
			 << "6. �ʻ��" << endl
			 << "7. ������" << endl;

		cout << "��ȣ�� �������ּ���: ";
		cin >> menu;

		switch (menu)
		{
			case MENU_HP_POTION:

				if (hpPotionCount >= 1)
				{
					stat[HP] += 20;
					--hpPotionCount;
					cout << "* HP�� 20 ȸ���Ǿ����ϴ�. ǥ���� 1�� �����˴ϴ�." << endl;
					cout << "���� HP: " << stat[HP] << endl;
					cout << "���� ���� ��: " << hpPotionCount << endl;
				}
				else
					cout << "������ �����մϴ�." << endl;

				break;

			case MENU_MP_POTION:

				if (mpPotionCount >= 1)
				{
					stat[MP] += 20;
					--mpPotionCount;
					cout << "* MP�� 20 ȸ���Ǿ����ϴ�. ǥ���� 1�� �����˴ϴ�." << endl;
					cout << "���� MP: " << stat[MP] << endl;
					cout << "���� ���� ��: " << mpPotionCount << endl;
				}
				else
					cout << "������ �����մϴ�." << endl;

				break;

			case MENU_HP_UP:

				stat[HP] *= 2;
				cout << "* HP�� 2��� �����Ǿ����ϴ�." << endl;
				cout << "���� HP: " << stat[HP] << endl;

				break;

			case MENU_MP_UP:

				stat[MP] *= 2;
				cout << "* MP�� 2��� �����Ǿ����ϴ�." << endl;
				cout << "���� MP: " << stat[MP] << endl;

				break;

			case MENU_ATTACK:

				if (stat[MP] >= 50)
				{
					stat[MP] -= 50;
					cout << "* ��ų�� ����Ͽ� MP�� 50 �Ҹ�Ǿ����ϴ�.." << endl;
					cout << "���� MP: " << stat[MP] << endl;
				}
				else
					cout << "��ų ����� �Ұ��մϴ�." << endl;

				break;

			case MENU_ULT:

				if (stat[MP] > 0)
				{
					stat[MP] /= 2;
					cout << "* ��ų�� ����Ͽ� MP�� 50% �Ҹ�Ǿ����ϴ�.." << endl;
					cout << "���� MP: " << stat[MP] << endl;
				}
				else
					cout << "�ʻ�� ����� �Ұ��մϴ�." << endl;

				break;

			case MENU_EXIT:

				cout << "���α׷��� �����մϴ�." << endl;
				exit(100);

				break;

			default:

				cout << "�߸��� �޴��� �����ϼ̽��ϴ�." << endl;

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
