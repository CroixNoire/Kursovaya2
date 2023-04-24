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
		cout << "������� �������: ";
		cin >> surname;
		if (CheckName(surname))
			flag = false;
		else cout << "�������� �������. ������� ��� ���" << endl;
	}
	flag = true;

	while (flag)
	{
		cout << "������� ���: ";
		cin >> name;
		if (CheckName(name))
			flag = false;
		else cout << "�������� ���. ������� ��� ���" << endl;
	}
	flag = true;

	while (flag)
	{
		cout << "������� ��������: ";
		cin >> otch;
		if (CheckName(otch))
			flag = false;
		else cout << "�������� ��������. ������� ��� ���" << endl;
	}
	flag = true;

	cout << "������� ���������: ";
	cin >> faculty;

	cout << "������� �������: ";
	cin >> department;

	cout << "������� ������: ";
	cin >> group;

	cout << "������� ����� ������������� ������: ";
	cin >> id;

	while (flag)
	{
		cout << "������� ������ (�, �): ";
		cin >> gender;

		if (!cin.fail())
		{
			if (gender != '�' && gender != '�')
				cout << "�������� ������. ������� ��� ���" << endl;
			else flag = false;
		}
	}
	flag = true;

	while (flag)
	{

		cout << "������� ��� �����������: ";
		cin >> startYear;

		if (!cin.fail())
		{
			flag = false;
		}
		else
		{
			cout << "�������� ��� �����������. ������� ��� ���" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	flag = true;

	while (flag)
	{
		cout << "������� ���� �������� (����, �����, ���): ";
		cin >> day >> month >> year;

		if (!cin.fail())
		{
			if (month > 12 || month < 1 || day > 31 || day < 1 || year < 1970 || year > 2016)
				cout << "�������� ����. ������� ��� ���" << endl;
			else flag = false;
		}
		else
		{
			cout << "�������� ����. ������� ��� ���" << endl;
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
	cout << "������� ���-�� ������:";
	cin >> ksess;
	sess = (Session*) new Session[ksess];
	for (int i = 0; i < ksess; i++)
	{
		cout << "������� ���-�� ���������: ";
		cin >> sess[i].kdisp;
		sess[i].disp = (Discipline*) new Discipline[sess[i].kdisp];

		for (int j = 0; j < sess[i].kdisp; j++)
		{
			cout << "������� �������� ��������: ";
			cin >> sess[i].disp[j].subj;
			cout << "������� ������ �� " << sess[i].disp[j].subj << ": ";
			cin >> sess[i].disp[j].ch;
		}
	}

}

void student::getDisp()
{
	for (int i = 0; i < ksess; i++)
	{
		cout << "������ �" << i + 1 << endl;
		for (int j = 0; j < sess[i].kdisp; j++)
		{
			cout << "�������: " << sess[i].disp[j].subj << " | " << "������: " << sess[i].disp[j].ch << endl;
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