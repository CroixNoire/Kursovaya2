#include <iostream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include "student.h"
#include "menu.h"
using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");
	student stud;
	/*stud.Add();
	stud.Print();*/
	menu men;
	men.startMenu();
	return 0;
}