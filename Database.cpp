#include "Database.h"
#include <algorithm>
string param_theme;
namespace dataBase {
	bool compareByAlhpabet(Record first, Record second) {
		if (first.getName() == second.getName())
			return first.getWorkDate() < second.getWorkDate();
		return first.getName() < second.getName();
	}
}
Database::Database()
{
	file.open("Database.dat", ios::in|ios::binary);
	string raw_string;
	if (!file.is_open()) {
		return;
	}
	while (!file.eof())
	{ 
		Record new_record = Record(file, userss);
		if (new_record.getName().size() == 0)
			return;
		records.push_back(new_record);//, users, themes
		computers[new_record.getComputer()].push_back(new_record.getName());

		//computer_indexes[records[records.size() - 1].getName()] =(int) records.size();

	}
	//file.close();
	sort(records.begin(), records.end(), dataBase::compareByAlhpabet);
	file.close();


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
	string line_separator = "\n-------------------------------------------------------------------\n";
	cout << line_separator;
	for (Record record : records)
		cout << record << line_separator;
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

		if (computers.find(command) == computers.end()) {
			cout << " Table '" << command << "' doesn't exist\n";
			continue;
		}
		else
			cout << computers[command].size() << endl;
	}
}
 
void Database::addRecord()
{
	file.open("Database.dat", ios::app | ios::binary);
	if (file.is_open())
		cout << "Can't open" << endl;
	records.push_back(Record().init(file));
	file.close();
}



void Database::choose(string &command)
{	
	//while (cin.get() != '\n');
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

void Database::change(string &command) {
	Record record;
	while (true) {
		cout << "\n Enter one of the commands below \n\t'back' to go back \n\t'name' - searh by name\n\t'computer' - search by computer code\n\t'date' - search by date\n\t";
		getline(cin, command);

		if (command == "back")
			return;
		if (command == "name") {
			cout << "Enter name: ";
			getline(cin, command);
			for (Record temp : records)
				if (record.getName() == command)
					record = temp;
		}
	
		else if (command == "computer") {
			cout << "Enter computer code: ";
			getline(cin, command);
			for (Record temp : records)
				if (record.getComputer() == command)
					record = temp;
		}
		if (command == "date") {
			cout << "Enter date: ";
			getline(cin, command);
			for (Record temp : records)
				if (record.getWorkDate() == command)
					record = temp;
		}
		record.getWorkTime().enterDate();
	}
}

//Database::~Database()
//{
//	file.close();
//}
