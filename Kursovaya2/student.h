#pragma once
#include "student.h"
#include <iostream>
#include <fstream>
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
	char gender;
	int quanity=0;
	int all=0;
	int startYear;
	int ksess;
	Session* sess;
public:
	char id[10];
	void Add();
	void Print();
	void PrintAll();
	void setDisp();
	void getDisp();
	void WriteFile(const char namefl[]);
	void ReadFile(char ID[10]);
	void DelFile(char ID[10]);
	void ChangeFile(char ID[10]);
	void Individ(char P);
};