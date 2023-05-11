#include "menu.h"
#include <iostream>
#include <fstream>
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
			case 3:
				system("cls");
				Third();
				break;
			case 4:
				system("cls");
				Fourth();
				break;
			case 5:
				system("cls");
				Fifth();
				break;
			case 6:
				system("cls");
				Sixth();
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
	temp.ReadFile(Id);
	system("pause");
	system("cls");
}

void menu::Third()
{
	student temp;
	temp.PrintAll();
	system("pause");
	system("cls");
}

void menu::Fourth()
{
	char Id[10];
	cout << "������� ����� ������������� ������ ��������: ";
	cin >> Id;
	student temp;
	temp.ChangeFile(Id);
	system("cls");
}

void menu::Fifth()
{
	char Id[10];
	cout << "������� ����� ������������� ������ ��������: ";
	cin >> Id;
	student temp;
	temp.DelFile(Id);
	system("pause");
	system("cls");
}

void menu::Sixth()
{
	bool flag = true;
	char gen;

	while (flag)
	{
		cout << "������� ������ (�, �): ";
		cin >> gen;

		if (!cin.fail())
		{
			if (gen != '�' && gen != '�')
				cout << "�������� ������. ������� ��� ���" << endl;
			else flag = false;
		}
	}

	student temp;
	temp.Individ(gen);
	system("pause");
	system("cls");
}