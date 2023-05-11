#pragma once
#include "student.h"
#include <iostream>
#include <fstream>
using namespace std;
class menu
{
	void First();
	void Second();
	void Third();
	void Fourth();
	void Fifth();
	void Sixth();

public:
	menu()
	{
		int x1, x2;
		ifstream number("enum.bin", ios::in | ios::binary);
		if (number.is_open())
		{
			number >> x2;
			if (x2 != 0) x1 = x2;
			number.close();
		}
		else
		{
			x1 = 0;
			number.close();
		}

		ofstream amounth("enum.bin", ios::binary | ios::out);
		amounth << x1;
		amounth.close();

		number.open("Three.bin", ios::in | ios::binary);
		if (!number.is_open())
		{
			number.close();
			amounth.open("Three.bin", ios::binary | ios::out);
			amounth.close();
		}

		number.open("All.bin", ios::in | ios::binary);
		if (!number.is_open())
		{
			number.close();
			amounth.open("All.bin", ios::binary | ios::out);
			amounth.close();
		}
	}

	void startMenu();
};