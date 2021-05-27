#include <iostream>
//#include <iomanip>
//#include <ctime>
//#include <string>
#include <Windows.h>
#include "Database.h"
#include <io.h>
#include <fcntl.h>




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Database database = Database();
	const char* commands_list = "add or + - add new one \nchange - change existing \nshow - show the list again \nexit - exit\n";
	string command;
	cout << commands_list;
	

	while (true) {

		
		cin >> command;

		if (command == "add" || command == "+") {
			continue;
		}
		else if (command == "change") {
			continue;
		}
		else if (command == "show") {
			cout << commands_list;
		}
		else if (command == "exit") {
			break;
		}
		
	}


	system("pause");
	return 0;
}