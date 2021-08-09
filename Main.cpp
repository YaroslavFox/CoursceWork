#include <iostream>
#include <Windows.h>
#include "Database.h"



int main()
{
	setlocale(LC_ALL, "Russian");
	Database database = Database();
	const char* commands_list = " add or + - add new one \n draw - show tables \n choose - schoose computer \n commands - show the list again \n exit - exit\n";

	string command;
	database.drawTable();
	cout << commands_list;

	while (true) {
		cout << " Enter command: ";
		getline(cin, command);
		if (command == "add" || command == "+") {
			system("CLS");
			database.addRecord();
			while (cin.get() != '\n');
			continue;
		}
		else if (command == "draw") {
			system("CLS");
			database.drawTable();
		}
		else if (command == "choose") {
			system("CLS");
			database.choose(command);
			cout << "\n" << commands_list;

		}
		else if (command == "commands") {
			system("CLS");
			cout << commands_list;

		}
		else if (command == "change") {
			database.change(command);
		}
		else if (command == "exit") {
			break;
		}
		else {
			cout << " Command " << command << " doesn't exist\n ";
			cout << "\n" << commands_list;
		}
	}
	return 0;
}