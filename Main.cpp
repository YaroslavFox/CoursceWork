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

	/*string a = "bbbbb", b = "abbbbb";
	cout << (a < b);
	
	return 0;*/


	Database database = Database();
	const char* commands_list = " add or + - add new one \n draw - show tables \n choose - schoose computer \n commands - show the list again \n exit - exit\n";

	string command;
	database.drawTable();
	cout << commands_list;

	while (true) {
		cout << " Enter command: ";
		cin >> command;

		if (command == "add" || command == "+") {
			continue;
		}
		else if (command == "draw") {
			database.drawTable();
		}
		else if (command == "choose") {
			database.choose(command);
			cout<<"\n" << commands_list;

		}
		else if (command == "commands") {
			cout << commands_list;
		}
		else if (command == "exit") {
			break;
		}
		else {
			cout << " Command " << command << " doesn't exist\n ";
			cout << "\n" << commands_list;

		}
		
	}


	//system("pause");
	return 0;
}