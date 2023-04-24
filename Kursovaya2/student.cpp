#include "student.h"
#include <iostream>
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

	cout << "Введите кафедра: ";
	cin >> department;

	cout << "Введите группа: ";
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
	cout << surname << " | " << name << " | " << otch << " | "
		<< faculty << " | " << department << " | " << group << " | "
		<< id << " | " << gender << " | " << startYear << " | "
		<< day << "." << month << "." << year << endl;
	this->getDisp();
}

void student::setDisp()
{
	cout << "Введите кол-во сессий:";
	cin >> ksess;
	sess = (Session*) new Session[ksess];
	for (int i = 0; i < ksess; i++)
	{
		cout << "Введите кол-во предметов: ";
		cin >> sess[i].kdisp;
		sess[i].disp = (Discipline*) new Discipline[sess[i].kdisp];

		for (int j = 0; j < sess[i].kdisp; j++)
		{
			cout << "Введите название предмета: ";
			cin >> sess[i].disp[j].subj;
			cout << "Введите оценку по " << sess[i].disp[j].subj << ": ";
			cin >> sess[i].disp[j].ch;
		}
	}

}

void student::getDisp()
{
	for (int i = 0; i < ksess; i++)
	{
		cout << "Сессия №" << i + 1 << endl;
		for (int j = 0; j < sess[i].kdisp; j++)
		{
			cout << "Предмет: " << sess[i].disp[j].subj << " | " << "Оценка: " << sess[i].disp[j].ch << endl;
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
}

void student::ReadFile()
{

	ifstream file;
	file.open("Student.bin", ios::binary);
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

	file.close();
}

bool student::Task(ifstream &file)
{
	if (file.read((char*)this, sizeof(student)))
	{
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
		return true;
	}
	else return false;
}

student student::Search(char ID[10], const char flname[])
{
	ifstream file;
	file.open(flname, ios::binary);
	student result, info;
	while (info.Task(file))
	{
		if (!(strcmp(info.id, ID)))
		{
			result = info;
		}
		else info.WriteFile("buf.bin");
	}
	file.close();
	return result;
}