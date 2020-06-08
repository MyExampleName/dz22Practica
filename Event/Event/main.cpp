#include "event.h"
#include "Birthday.h"
#include "Custom.h"
#include "Date.h"
#include "Meeting.h"
#include "Time_.h"
#include <vector>
#include <algorithm>


int main()
{
	setlocale(0, "rus");
	vector<Event*> e;
	int menu = 0;
	Date d;
	Time_ t;
	string s1, s2;
	int i;

	do {
		system("cls");
		cout << "-------------------------------" << endl;
		cout << "\t\t����" << endl;
		cout << "1 - ������� ��� (�� ����������)" << endl;
		cout << "2 - ������� ��� ��� ��������" << endl;
		cout << "3 - ������� ��� �������" << endl;
		cout << "4 - ������� ��� ��������� �������\n" << endl;
		cout << "5 - �������� �������\n\n" << endl;
		cout << "0 - �����" << endl;
		cout << "-------------------------------" << endl;

		cin >> menu;

		switch (menu)
		{
		default:
			break;
		case 1: sort(e.begin(), e.end());
			for (int i = 0; i < e.size(); i++)
			{
				e[i]->show();
			}
			system("pause");  break;
		case 2:
			for (int i = 0; i < e.size(); i++)
			{
				if(e[i]->type() =="Birthday")
					e[i]->show();
			}
			system("pause");  break;
		case 3:
			for (int i = 0; i < e.size(); i++)
			{
				if (e[i]->type() == "Meeting")
					e[i]->show();
			}
			system("pause");  break;
		case 4:
			for (int i = 0; i < e.size(); i++)
			{
				if (e[i]->type() == "Custom")
					e[i]->show();
			}
			system("pause");  break;
		case 5: cout << "�������� �������: \n1-���� ��������\n2-�������\n3-������" << endl;
			cin >> menu;
			if (menu == 1)
			{
				cout << "������� ����: " << endl; cin >> d;
				cout << "������� ���: " << endl; cin >> s1;
				cout << "������� �����: " << endl; cin >> s2;
				cout << "������� �������: " << endl; cin >> i;

				e.push_back(new Birthday(d, i, s1, s2));
			}
			else if (menu == 2)
			{
				cout << "������� ����: " << endl; cin >> d;
				cout << "������� �����: " << endl; cin >> t;
				cout << "������� ���: " << endl; cin >> s1;
				cout << "������� �����: " << endl; cin >> s2;

				e.push_back(new Meeting(d, t, s2, s1));
			}
			else if (menu == 3)
			{
				cout << "������� ����: " << endl; cin >> d;
				cout << "������� �����: " << endl; cin >> t;
				cout << "������� �����������: " << endl; cin >> s1;

				e.push_back(new Custom(s1, d, t));
			}
			system("pause");  break;
		}


	} while (menu != 0);

	return 0;
}