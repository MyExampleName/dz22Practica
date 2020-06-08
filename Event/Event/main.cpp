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
		cout << "\t\tМЕНЮ" << endl;
		cout << "1 - Вывести все (от ближайшего)" << endl;
		cout << "2 - Вывести все дни Рождения" << endl;
		cout << "3 - Вывести все встречи" << endl;
		cout << "4 - Вывести все остальные события\n" << endl;
		cout << "5 - Добавить событие\n\n" << endl;
		cout << "0 - выйти" << endl;
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
		case 5: cout << "Выберите событие: \n1-День Рождение\n2-Встреча\n3-Другое" << endl;
			cin >> menu;
			if (menu == 1)
			{
				cout << "Введите дату: " << endl; cin >> d;
				cout << "Введите имя: " << endl; cin >> s1;
				cout << "Введите место: " << endl; cin >> s2;
				cout << "Введите возраст: " << endl; cin >> i;

				e.push_back(new Birthday(d, i, s1, s2));
			}
			else if (menu == 2)
			{
				cout << "Введите дату: " << endl; cin >> d;
				cout << "Введите время: " << endl; cin >> t;
				cout << "Введите имя: " << endl; cin >> s1;
				cout << "Введите место: " << endl; cin >> s2;

				e.push_back(new Meeting(d, t, s2, s1));
			}
			else if (menu == 3)
			{
				cout << "Введите дату: " << endl; cin >> d;
				cout << "Введите время: " << endl; cin >> t;
				cout << "Введите комментарий: " << endl; cin >> s1;

				e.push_back(new Custom(s1, d, t));
			}
			system("pause");  break;
		}


	} while (menu != 0);

	return 0;
}