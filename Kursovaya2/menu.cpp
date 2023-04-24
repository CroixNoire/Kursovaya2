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
			cout << "|������� �35"; cout.width(59); cout.fill(' '); cout << "|" << endl;
			cout << "|"; cout.width(70); cout.fill('-'); cout << "|" << endl;
			cout << "|1 - �������� ��������"; cout.width(49); cout.fill(' '); cout << "|" << endl;
			cout << "|"; cout.width(70); cout.fill('-'); cout << "|" << endl;
			cout << "|2 - ����� ���������� � �������� (����� �� ������ ������)"; cout.width(14); cout.fill(' '); cout << "|" << endl;
			cout << "|"; cout.width(70); cout.fill('-'); cout << "|" << endl;
			cout << "|3 - ����� ���� ���������"; cout.width(46); cout.fill(' '); cout << "|" << endl;
			cout << "|"; cout.width(70); cout.fill('-'); cout << "|" << endl;
			cout << "|4 - ��������� ���������� � ��������"; cout.width(35); cout.fill(' '); cout << "|" << endl;
			cout << "|"; cout.width(70); cout.fill('-'); cout << "|" << endl;
			cout << "|5 - �������� ��������"; cout.width(49); cout.fill(' '); cout << "|" << endl;
			cout << "|"; cout.width(70); cout.fill('-'); cout << "|" << endl;
			cout << "|6 - �������������� �������"; cout.width(44); cout.fill(' '); cout << "|" << endl;
			cout << "|"; cout.width(70); cout.fill('-'); cout << "|" << endl;
			cout << "|7 - ���������� ������"; cout.width(49); cout.fill(' '); cout << "|" << endl;
			cout << "|"; cout.width(70); cout.fill('-'); cout << "|" << "\n\n";
			
			while (fl)
			{

				cout << "��� ������ �������(1 - 7): ";
				cin >> in;

				if (!cin.fail())
				{
					fl = false;
				}
				else
				{
					cout << "�������� ��������. ������� ��� ���" << endl;
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
				cout << "����� �������� �������";
				flag = false;
				break;
			default:
				system("cls");
				cout << "�������� �����. ������� ��� ���" << "\n\n";
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
	cout << "������� ����� ������������� ������ ��������: ";
	cin >> Id;
	student temp;
	temp = student::Search(Id, "Student.bin");
	temp.Print();
	system("pause");
	system("cls");
}