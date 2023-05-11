#include "student.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

bool CheckName(string _name)
{
	string alp = "0123456789";
	for (int i = 0; i < _name.length(); i++)
	{
		for (int j = 0; j < alp.length(); j++)
		{
			if (_name[i] == alp[j]) return false;
		}
	}
	return true;
}

void student::Add()
{
	bool flag = true;

	while (flag)
	{
		cout << "Введите фамилию: ";
		cin >> surname;
		if (CheckName(surname))
			flag = false;
		else cout << "Неверная фамилия. Введите ещё раз" << endl;
	}
	flag = true;

	while (flag)
	{
		cout << "Введите имя: ";
		cin >> name;
		if (CheckName(name))
			flag = false;
		else cout << "Неверное имя. Введите ещё раз" << endl;
	}
	flag = true;

	while (flag)
	{
		cout << "Введите отчество: ";
		cin >> otch;
		if (CheckName(otch))
			flag = false;
		else cout << "Неверное отчество. Введите ещё раз" << endl;
	}
	flag = true;

	cout << "Введите факультет: ";
	cin >> faculty;

	cout << "Введите кафедру: ";
	cin >> department;

	cout << "Введите группу: ";
	cin >> group;

	cout << "Введите номер студенческого билета: ";
	cin >> id;

	while (flag)
	{
		cout << "Введите гендер (М, Ж): ";
		cin >> gender;

		if (!cin.fail())
		{
			if (gender != 'М' && gender != 'Ж')
				cout << "Неверный гендер. Введите ещё раз" << endl;
			else flag = false;
		}
	}
	flag = true;

	while (flag)
	{

		cout << "Введите год поступления: ";
		cin >> startYear;

		if (!cin.fail())
		{
			flag = false;
		}
		else
		{
			cout << "Неверный год поступления. Введите ещё раз" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	flag = true;

	while (flag)
	{
		cout << "Введите дату рождения (день, месяц, год): ";
		cin >> day >> month >> year;

		if (!cin.fail())
		{
			if (month > 12 || month < 1 || day > 31 || day < 1 || year < 1970 || year > 2016)
				cout << "Неверная дата. Введите ещё раз" << endl;
			else flag = false;
		}
		else
		{
			cout << "Неверная дата. Введите ещё раз" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	this->setDisp();
}

void student::Print()
{
	cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
	cout << "   Фамилия: " << surname << endl;
	cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
	cout << "   Имя: " << name << endl;
	cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
	cout << "   Отчество: " << otch << endl;
	cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
	cout << "   Факультет: " << faculty << endl;
	cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
	cout << "   Кафедра: " << department << endl;
	cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
	cout << "   Группа: " << group << endl;
	cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
	cout << "   Номер студ. билета: " << id << endl;
	cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
	cout << "   Гендер: " << gender << endl;
	cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
	cout << "   Год поступления: " << startYear << endl;
	cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
	cout << "   Дата рождения: " << day << "." << month << "." << year << endl;
	cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;

	this->getDisp();
}

void student::setDisp()
{
	cout << "\nВведите кол-во сессий: ";
	cin >> ksess;
	sess = (Session*) new Session[ksess];
	for (int i = 0; i < ksess; i++)
	{
		cout << "\nВведите кол-во предметов: ";
		cin >> sess[i].kdisp;
		sess[i].disp = (Discipline*) new Discipline[sess[i].kdisp];

		for (int j = 0; j < sess[i].kdisp; j++)
		{
			cout << "Введите название предмета: ";
			cin >> sess[i].disp[j].subj;
			cout << "Введите оценку по " << sess[i].disp[j].subj << ": ";
			cin >> sess[i].disp[j].ch;
			if (sess[i].disp[j].ch == 3)
				quanity++;
		}
		all += sess[i].kdisp;
	}

}

void student::getDisp()
{
	for (int i = 0; i < ksess; i++)
	{
		cout << "   Сессия №" << i + 1 << endl;
		cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
		for (int j = 0; j < sess[i].kdisp; j++)
		{
			cout << "   Предмет: " << sess[i].disp[j].subj << " | " << "Оценка: " << sess[i].disp[j].ch << endl;
			cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
		}
	}
}

void student::WriteFile(const char namefl[])
{
	ofstream bin;
	bin.open(namefl, ios::binary | ios::app);
	bin.write((char*)this, sizeof(student));
	bin.write((char*)sess, sizeof(sess));
	for (int i = 0; i < ksess; i++)
	{
		bin.write((char*)&sess[i].kdisp, sizeof(int));
		for (int j = 0; j < sess[i].kdisp; j++)
		{
			bin.write((char*)&sess[i].disp[j].subj, sizeof(sess[i].disp[j].subj));
			bin.write((char*)&sess[i].disp[j].ch, sizeof(int));
		}
	}
	bin.close();

	int s;
	ifstream reader1("enum.bin", ios::in | ios::binary);
	reader1 >> s;
	reader1.close();

	s++;

	ofstream reader2("enum.bin", ios::binary | ios::out);
	reader2 << s;
	reader2.close();
	
	ofstream three("Three.bin", ios::binary | ios::app);
	three << quanity;
	three.close();

	ofstream ind("All.bin", ios::binary | ios::app);
	ind << all;
	ind.close();
}

void student::ReadFile(char ID[10])
{
	bool flag = false;
	int k;
	ifstream reader1("enum.bin", ios::in | ios::binary);
	reader1 >> k;
	reader1.close();

	if (k == 0)
	{
		cout << "Нет студентов в базе данных" << endl;
		flag = true;
	}
	ifstream file;
	file.open("Student.bin", ios::binary);
	for (int i = 0; i < k; i++)
	{
		file.read((char*)this, sizeof(student));
		sess = (Session*) new Session[ksess];
		file.read((char*)sess, sizeof(sess));
		for (int i = 0; i < ksess; i++)
		{
			file.read((char*)&sess[i].kdisp, sizeof(int));
			sess[i].disp = (Discipline*) new Discipline[sess[i].kdisp];
			for (int j = 0; j < sess[i].kdisp; j++)
			{
				file.read((char*)&sess[i].disp[j].subj, sizeof(sess[i].disp[j].subj));
				file.read((char*)&sess[i].disp[j].ch, sizeof(sess[i].disp[j].ch));
			}
		}
		if (!strcmp(id, ID))
		{
			Print();
			flag = true;
		}
	}
	if (!flag) cout << "Ошибка. Студент с таким ID не найден" << endl;
	file.close();
}

void student::PrintAll()
{
	bool flag = false;
	int k;
	ifstream reader1("enum.bin", ios::in | ios::binary);
	reader1 >> k;
	reader1.close();

	if (k == 0)
	{
		cout << "Нет студентов в базе данных" << endl;
		flag = true;
	}

	ifstream file;
	file.open("Student.bin", ios::binary);
	for (int i = 0; i < k; i++)
	{
		file.read((char*)this, sizeof(student));
		sess = (Session*) new Session[ksess];
		file.read((char*)sess, sizeof(sess));
		for (int i = 0; i < ksess; i++)
		{
			file.read((char*)&sess[i].kdisp, sizeof(int));
			sess[i].disp = (Discipline*) new Discipline[sess[i].kdisp];
			for (int j = 0; j < sess[i].kdisp; j++)
			{
				file.read((char*)&sess[i].disp[j].subj, sizeof(sess[i].disp[j].subj));
				file.read((char*)&sess[i].disp[j].ch, sizeof(sess[i].disp[j].ch));
			}
		}
		Print();
		cout << "\n\n";
	}
	file.close();
}

void student::DelFile(char ID[10])
{
	bool fl = false;
	bool flag = false;
	int k;
	ifstream three("Three.bin", ios::binary);
	ifstream ind("All.bin", ios::binary);
	ifstream reader1("enum.bin", ios::in | ios::binary);
	reader1 >> k;
	reader1.close();

	ofstream bin;
	bin.open("buffer.bin", ios::binary | ios::trunc);
	bin.close();

	bin.open("ThreeBuff.bin", ios::binary | ios::trunc);
	bin.close();

	bin.open("AllBuff.bin", ios::binary | ios::trunc);
	bin.close();

	if (k == 0)
	{
		cout << "Нет студентов в базе данных" << endl;
		flag = true;
	}
	ifstream file;
	file.open("Student.bin", ios::binary);
	for (int i = 0; i < k; i++)
	{
		three.read((char*)&quanity, sizeof(quanity));
		ind.read((char*)&all, sizeof(all));

		file.read((char*)this, sizeof(student));
		sess = (Session*) new Session[ksess];
		file.read((char*)sess, sizeof(sess));
		for (int i = 0; i < ksess; i++)
		{
			file.read((char*)&sess[i].kdisp, sizeof(int));
			sess[i].disp = (Discipline*) new Discipline[sess[i].kdisp];
			for (int j = 0; j < sess[i].kdisp; j++)
			{
				file.read((char*)&sess[i].disp[j].subj, sizeof(sess[i].disp[j].subj));
				file.read((char*)&sess[i].disp[j].ch, sizeof(sess[i].disp[j].ch));
			}
		}

		if (strcmp(id, ID))
		{	
			bin.open("buffer.bin", ios::binary | ios::app);
			bin.write((char*)this, sizeof(student));
			bin.write((char*)sess, sizeof(sess));
			for (int i = 0; i < ksess; i++)
			{
				bin.write((char*)&sess[i].kdisp, sizeof(int));
				for (int j = 0; j < sess[i].kdisp; j++)
				{
					bin.write((char*)&sess[i].disp[j].subj, sizeof(sess[i].disp[j].subj));
					bin.write((char*)&sess[i].disp[j].ch, sizeof(int));
				}
			}
			bin.close();

			bin.open("ThreeBuff.bin", ios::binary | ios::app);
			bin.write((char*)&quanity, sizeof(quanity));
			bin.close();

			bin.open("AllBuff.bin", ios::binary | ios::app);
			bin.write((char*)&all, sizeof(all));
			bin.close();
		}
		else fl = true;
	}

	if (fl == true)
	{
		int s;
		reader1.open("enum.bin", ios::in | ios::binary);
		reader1 >> s;
		reader1.close();

		s = s - 1;

		ofstream reader2("enum.bin", ios::binary | ios::out);
		reader2 << s;
		reader2.close();

		ifstream bin_in("buffer.bin", ios::in | ios::binary);
		ofstream bin_out("Student.bin", ios::trunc | ios::binary);
		bin_out << bin_in.rdbuf();
		bin_out.close();
		bin_in.close();

		bin_in.open("ThreeBuff.bin", ios::in | ios::binary);
		bin_out.open("Three.bin", ios::trunc | ios::binary);
		bin_out << bin_in.rdbuf();
		bin_out.close();
		bin_in.close();

		bin_in.open("AllBuff.bin", ios::in | ios::binary);
		bin_out.open("All.bin", ios::trunc | ios::binary);
		bin_out << bin_in.rdbuf();
		bin_out.close();
		bin_in.close();

		flag = true;

		cout << "Удаление прошло успешно\n";
	}

	if (!flag) cout << "Ошибка. Студент с таким ID не найден" << endl;
	file.close();
	three.close();
	ind.close();
}

void student::ChangeFile(char ID[10])
{
	bool fl = false;
	bool flag = false;
	bool flag3 = false;
	int k;
	ifstream three("Three.bin", ios::binary);
	ifstream ind("All.bin", ios::binary);
	ifstream reader1("enum.bin", ios::in | ios::binary);
	reader1 >> k;
	reader1.close();

	ofstream bin;
	bin.open("buffer.bin", ios::binary | ios::trunc);
	bin.close();

	bin.open("ThreeBuff.bin", ios::binary | ios::trunc);
	bin.close();
	bin.open("All.bin", ios::binary | ios::trunc);
	bin.close();

	if (k == 0)
	{
		cout << "Нет студентов в базе данных" << endl;
		flag = true;
	}
	ifstream file;
	file.open("Student.bin", ios::binary);
	for (int i = 0; i < k; i++)
	{
		three.read((char*)&quanity, sizeof(quanity));
		ind.read((char*)&all, sizeof(all));

		file.read((char*)this, sizeof(student));
		sess = (Session*) new Session[ksess];
		file.read((char*)sess, sizeof(sess));
		for (int i = 0; i < ksess; i++)
		{
			file.read((char*)&sess[i].kdisp, sizeof(int));
			sess[i].disp = (Discipline*) new Discipline[sess[i].kdisp];
			for (int j = 0; j < sess[i].kdisp; j++)
			{
				file.read((char*)&sess[i].disp[j].subj, sizeof(sess[i].disp[j].subj));
				file.read((char*)&sess[i].disp[j].ch, sizeof(sess[i].disp[j].ch));
			}
		}

		if (strcmp(id, ID))
		{
			bin.open("buffer.bin", ios::binary | ios::app);
			bin.write((char*)this, sizeof(student));
			bin.write((char*)sess, sizeof(sess));
			for (int i = 0; i < ksess; i++)
			{
				bin.write((char*)&sess[i].kdisp, sizeof(int));
				for (int j = 0; j < sess[i].kdisp; j++)
				{
					bin.write((char*)&sess[i].disp[j].subj, sizeof(sess[i].disp[j].subj));
					bin.write((char*)&sess[i].disp[j].ch, sizeof(int));
				}
			}
			bin.close();

			bin.open("ThreeBuff.bin", ios::binary | ios::app);
			bin.write((char*)&quanity, sizeof(quanity));
			bin.close();

			bin.open("AllBuff.bin", ios::binary | ios::app);
			bin.write((char*)&all, sizeof(all));
			bin.close();
		}
		else
		{
			bool flag2 = true;
			bool fl = true;
			int act;
			while (flag2)
			{
				cout << "\n";
				Print();
				cout << "\n";
				cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
				cout << "|1 - Фамилия"; cout.width(29); cout.fill(' '); cout << "|" << endl;
				cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
				cout << "|2 - Имя"; cout.width(33); cout.fill(' '); cout << "|" << endl;
				cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
				cout << "|3 - Отчество"; cout.width(28); cout.fill(' '); cout << "|" << endl;
				cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
				cout << "|4 - Факультет"; cout.width(27); cout.fill(' '); cout << "|" << endl;
				cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
				cout << "|5 - Кафедра"; cout.width(29); cout.fill(' '); cout << "|" << endl;
				cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
				cout << "|6 - Группа"; cout.width(30); cout.fill(' '); cout << "|" << endl;
				cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
				cout << "|7 - Гендер"; cout.width(30); cout.fill(' '); cout << "|" << endl;
				cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
				cout << "|8 - Год поступления"; cout.width(21); cout.fill(' '); cout << "|" << endl;
				cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
				cout << "|9 - Дата рождения"; cout.width(23); cout.fill(' '); cout << "|" << endl;
				cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
				cout << "|10 - Данные о сессии"; cout.width(20); cout.fill(' '); cout << "|" << endl;
				cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << endl;
				cout << "|0 - Завершение изменений"; cout.width(16); cout.fill(' '); cout << "|" << endl;
				cout << "|"; cout.width(40); cout.fill('-'); cout << "|" << "\n\n";

				while (fl)
				{

					cout << "Что хотите изменить(0 - 10): ";
					cin >> act;

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

				switch (act)
				{
				case 1:
					system("cls");
					while (flag)
					{
						cout << "Введите фамилию: ";
						cin >> this->surname;
						if (CheckName(surname))
							flag = false;
						else cout << "Неверная фамилия. Введите ещё раз" << endl;
					}
					flag = true;
					system("cls");
					break;
				case 2:
					system("cls");
					while (flag)
					{
						cout << "Введите имя: ";
						cin >> this->name;
						if (CheckName(name))
							flag = false;
						else cout << "Неверное имя. Введите ещё раз" << endl;
					}
					flag = true;
					system("cls");
					break;
				case 3:
					system("cls");
					while (flag)
					{
						cout << "Введите отчество: ";
						cin >> this->otch;
						if (CheckName(otch))
							flag = false;
						else cout << "Неверное отчество. Введите ещё раз" << endl;
					}
					flag = true;
					system("cls");
					break;
				case 4:
					system("cls");
					cout << "Введите факультет: ";
					cin >> faculty;
					system("cls");
					break;
				case 5:
					system("cls");
					cout << "Введите кафедру: ";
					cin >> department;
					system("cls");
					break;
				case 6:
					system("cls");
					cout << "Введите группу: ";
					cin >> group;
					system("cls");
					break;
				case 7:
					system("cls");
					while (flag)
					{
						cout << "Введите гендер (М, Ж): ";
						cin >> gender;

						if (!cin.fail())
						{
							if (gender != 'М' && gender != 'Ж')
								cout << "Неверный гендер. Введите ещё раз" << endl;
							else flag = false;
						}
					}
					flag = true;
					system("cls");
					break;
				case 8:
					system("cls");
					while (flag)
					{

						cout << "Введите год поступления: ";
						cin >> startYear;

						if (!cin.fail())
						{
							flag = false;
						}
						else
						{
							cout << "Неверный год поступления. Введите ещё раз" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					}
					flag = true;
					system("cls");
					break;
				case 9:
					system("cls");
					while (flag)
					{
						cout << "Введите дату рождения (день, месяц, год): ";
						cin >> day >> month >> year;

						if (!cin.fail())
						{
							if (month > 12 || month < 1 || day > 31 || day < 1 || year < 1970 || year > 2016)
								cout << "Неверная дата. Введите ещё раз" << endl;
							else flag = false;
						}
						else
						{
							cout << "Неверная дата. Введите ещё раз" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					}
					flag = true;
					system("cls");
					break;
				case 10:
					system("cls");
					setDisp();
					system("cls");
					break;
				case 0:
					system("cls");
					flag2 = false;
					flag3 = true;
					cout << "Изменение данных прошло успешно\n";
					system("pause");
					system("cls");
				default:
					system("cls");
					cout << "Неверное число. Введите ещё раз" << "\n\n";
					break;
				}

			}

			bin.open("buffer.bin", ios::binary | ios::app);
			bin.write((char*)this, sizeof(student));
			bin.write((char*)sess, sizeof(sess));
			for (int i = 0; i < ksess; i++)
			{
				bin.write((char*)&sess[i].kdisp, sizeof(int));
				for (int j = 0; j < sess[i].kdisp; j++)
				{
					bin.write((char*)&sess[i].disp[j].subj, sizeof(sess[i].disp[j].subj));
					bin.write((char*)&sess[i].disp[j].ch, sizeof(int));
				}
			}
			bin.close();

			bin.open("ThreeBuff.bin", ios::binary | ios::app);
			bin.write((char*)&quanity, sizeof(quanity));
			bin.close();

		}
	}

	if (flag3 == true)
	{
		ofstream bin_out("Student.bin", ios::out | ios::binary);
		ifstream bin_in("buffer.bin", ios::in | ios::binary);
		bin_out << bin_in.rdbuf();
		bin_out.close();
		bin_in.close();

		bin_in.open("ThreeBuff.bin", ios::in | ios::binary);
		bin_out.open("Three.bin", ios::trunc | ios::binary);
		bin_out << bin_in.rdbuf();
		bin_out.close();
		bin_in.close();

		bin_in.open("AllBuff.bin", ios::in | ios::binary);
		bin_out.open("All.bin", ios::trunc | ios::binary);
		bin_out << bin_in.rdbuf();
		bin_out.close();
		bin_in.close();

		flag = true;
	}

	if (!flag) cout << "Ошибка. Студент с таким ID не найден" << endl;
	file.close();
	three.close();
	ind.close();
}

void student::Individ(char P)
{
	bool flag = false;
	int k;
	float ind = 0;

	ifstream three("Three.bin", ios::binary);
	ifstream quant("All.bin", ios::binary);

	ifstream reader1("enum.bin", ios::in | ios::binary);
	reader1 >> k;
	reader1.close();

	if (k == 0)
	{
		cout << "Нет студентов в базе данных" << endl;
		flag = true;
	}
	ifstream file;
	file.open("Student.bin", ios::binary);
	for (int i = 0; i < k; i++)
	{
		three.read((char*)&quanity, sizeof(quanity));
		quant.read((char*)&all, sizeof(all));

		file.read((char*)this, sizeof(student));
		sess = (Session*) new Session[ksess];
		file.read((char*)sess, sizeof(sess));
		for (int i = 0; i < ksess; i++)
		{
			file.read((char*)&sess[i].kdisp, sizeof(int));
			sess[i].disp = (Discipline*) new Discipline[sess[i].kdisp];
			for (int j = 0; j < sess[i].kdisp; j++)
			{
				file.read((char*)&sess[i].disp[j].subj, sizeof(sess[i].disp[j].subj));
				file.read((char*)&sess[i].disp[j].ch, sizeof(sess[i].disp[j].ch));
			}
		}
		if (gender == P)
		{
			ind = (float)quanity / (float(all));
			if (ind <= 0.25)
			{
				Print();
				cout << "\n\n";
				flag = true;
			}
		}
	}
	if (!flag) cout << "Ошибка. Таких студентов нет в базе данных" << endl;
	file.close();
	three.close();
	quant.close();

}