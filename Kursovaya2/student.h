#pragma once
class Data
{
protected:
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Discipline
{
	char subj[20];
	int ch;
};

class Session
{
public:
	int kdisp;
	Discipline* disp;
};

class student: public Data
{
	char surname[20];
	char name[20];
	char otch[20];
	char faculty[20];
	char department[20];
	char group[20];
	char id[10];
	char gender;
	int startYear;
	int ksess;
	Session* sess;
public:
	void Add();
	void Print();
	void setDisp();
	void getDisp();
	void WriteFile(const char namefl[]);
	void ReadFile();
	bool Task(ifstream &file);
	static student Search(char ID[10], const char flname[]);
};

