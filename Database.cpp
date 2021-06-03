#include "Database.h"

string param_theme;

Database::Database()
{
	file.open("data\\compuer_list.txt");
	string raw_string;
	
	while (file >> raw_string)
	{ 
		file >> raw_string;
		computers.push_back(Computer(raw_string, programmers, allReportAmount));//, users, themes
		computer_indexes[computers[computers.size() - 1].getName()] =(int) computers.size();

	}


}

bool amountCompare(Programer &first, Programer &second) {
	return first.amount > second.amount;
}

bool intervalCompare(Programer &first, Programer &second) {
	cout << second.time[param_theme] << endl;
	return first.time[param_theme] > second.time[param_theme];
}

void Database::drawTable()
{
	/*for (Computer computer : computers) {
		computer.drawTable();
	}*/

	for (int i = 0; i < computers.size(); i++) {
		computers[i].drawTable();
	}
}

void Database::drawUsers() {
	for (Programer programmer : programmers)
		cout << programmer << "\n";
}

void Database::chooseUser(string &command) {
	while (true) {
		cout << "\n Enter 'back' to go back \n or enter User Name to go for it: ";
		getline(cin, command);
		if (command == "back")
			return;

		for (Programer programmer : programmers)
			if (programmer.name == command) {
				programmer.drawRecords();
				return;
			}
		cout << " User programmer with name'" << command << "' hasn't been found";
	}
}

void Database::chooseSort(string& command)
{
	while (true) {
		cout << "\n Enter 'back' to go back \n or enter Sort Type : Amount - Amount of reports, Time - interval: ";
		getline(cin, command);
		if (command == "back")
			return;
		if (command == "Amount") {
			sort(programmers.begin(), programmers.end(), amountCompare);
			return;
		}
		else if (command == "Time") {
			cout << " Enter theme: ";
			cin >> param_theme;

			sort(programmers.begin(), programmers.end(), intervalCompare);
			return;
		}
		cout << " sort Type '" << command << "' hasn't been found";
	}
}

void Database::chooseComputer(string &command) {
	while (true) {
		cout << "\n Enter 'back' to go back \n or enter Computer Name to go for it: ";
		getline(cin, command);
		if (command == "back")
			return;

		if (computer_indexes.find(command) == computer_indexes.end()) {
			cout << " Table '" << command << "' doesn't exist\n";
			continue;
		}
		else
			computers[computer_indexes["command"]].choosed(command);
	}
}

void Database::addUser()
{
	//users.push	
}



void Database::choose(string &command)
{	
	while (cin.get() != '\n');
	//bool not_skip = true;
	//cin.clear();
	while (true) {
		cout << "\n Enter one of the commands below \n\t'back' to go back \n\t'computer' - to got to computers\n\t'draw users' - to draw users information\n\t'reports' - reports amount\n\t user - choose user ): ";
		getline(cin, command);

		if (command == "back")
			return;
		else if (command == "computer") {
			chooseComputer(command);
			//continue;
		}
		else if (command == "draw users") {
			drawUsers();
			//continue;
		}
		else if (command == "user") {
			chooseUser(command);
			//continue;
		}
		else if (command == "reports") {
			cout << " Amount of reports: " << allReportAmount << "\n";
		}
		else if (command == "sort") {
			chooseSort(command);
		}
		
		else cout << "Command '" << command << "' doesn't exist\n";

	}
}
//Database::~Database()
//{
//	file.close();
//}
