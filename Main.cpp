#include <iostream>
//#include <iomanip>
//#include <ctime>
//#include <string>
#include <Windows.h>
#include "Database.h"




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Database database = Database();

	const string commands_list = "add или + - добавить нового \nchange - изменить \nshow - отобразить спсиок повторно ";

	string command;
	
	

	while (true) {


		cin >> command;

	}


	system("pause");
	return 0;
}