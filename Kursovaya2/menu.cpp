#include "menu.h"
#include <iostream>
using namespace std;

void menu::startMenu()
{
	bool flag = true;
	bool fl = true;
	int in;
		while (flag)
		{
			cout << "|"; cout.width(70); cout.fill('-'); cout << "|" << endl;
			cout << "|Вариант №35"; cout.width(59); cout.fill(' '); cout << "|" << endl;
			cout << "|"; cout.width(70); cout.fill('-'); cout << "|" << endl;
			cout << "|1 - Записать студента"; cout.width(49); cout.fill(' '); cout << "|" << endl;
			cout << "|"; cout.width(70); cout.fill('-'); cout << "|" << endl;
			cout << "|2 - Вывод информации о студенте (поиск по номеру билета)"; cout.width(14); cout.fill(' '); cout << "|" << endl;
			cout << "|"; cout.width(70); cout.fill('-'); cout << "|" << endl;
			cout << "|3 - Вывод всех студентов"; cout.width(46); cout.fill(' '); cout << "|" << endl;
			cout << "|"; cout.width(70); cout.fill('-'); cout << "|" << endl;
			cout << "|4 - Изменение информации о студенте"; cout.width(35); cout.fill(' '); cout << "|" << endl;
			cout << "|"; cout.width(70); cout.fill('-'); cout << "|" << endl;
			cout << "|5 - Удаление студента"; cout.width(49); cout.fill(' '); cout << "|" << endl;
			cout << "|"; cout.width(70); cout.fill('-'); cout << "|" << endl;
			cout << "|6 - Индивидуальное задание"; cout.width(44); cout.fill(' '); cout << "|" << endl;
			cout << "|"; cout.width(70); cout.fill('-'); cout << "|" << endl;
			cout << "|7 - Завершение работы"; cout.width(49); cout.fill(' '); cout << "|" << endl;
			cout << "|"; cout.width(70); cout.fill('-'); cout << "|" << "\n\n";
			
			while (fl)
			{

				cout << "Что хотите сделать(1 - 7): ";
				cin >> in;

				if (!cin.fail())
				{
					fl = false;
				}
				else
				{
					cout << "Неверное действие. Введите ещё раз" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			fl = true;

			switch (in)
			{
			case 1:
				system("cls");
				First();
				system("cls");
				break;
			case 2:
				system("cls");
				Second();
				break;
			case 7:
				system("cls");
				cout << "Сеанс завершён успешно";
				flag = false;
				break;
			default:
				system("cls");
				cout << "Неверное число. Введите ещё раз" << "\n\n";
				break;
			}

		}
}

void menu::First()
{
	student temp;
	temp.Add();
	temp.WriteFile("Student.bin");
}

void menu::Second()
{
	char Id[10];
	cout << "Введите номер студенческого билета студента: ";
	cin >> Id;
	student temp;
	temp = student::Search(Id, "Student.bin");
	temp.Print();
	system("pause");
	system("cls");
}