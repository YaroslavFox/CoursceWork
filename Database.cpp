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
		file.open("Database.dat", ios::out | ios::binary);
		file.close();
		return;
	}
	while (!file.eof())
	{ 
		Record new_record = Record(file, userss);
		if (new_record.getName().size() == 0)
			return;
		allReportAmount += 1;
		records.push_back(new_record);//, users, themes
		computers[new_record.getComputer()].push_back(new_record.getName());
		bool hadBeenUpdated = false;

		for (Programer& programmer : programmers) {
			if (programmer.name == new_record.getName()) {
				programmer.addRecord( new_record);
				hadBeenUpdated = true;
				break;
			}
		}
		if (not hadBeenUpdated)
			programmers.push_back(Programer(new_record));

	}
	
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
	string header = " -----------------------------------------------------------------------------"
		"\n|     ФИО      |  Шифр  |   Дата   |     Время     |    Время     |  Интервал |"
		"\n| программиста |  темы  |  работы  | начала работы | конца работы | в минутах |"
		"\n ------------------------------------------------------------------------------\n";

	string line_separator = "\n -----------------------------------------------------------------------------\n";
	cout << header;
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
		if (computers.find(command) == computers.end()) 
			cout << " Table '" << command << "' doesn't exist\n";
		else
			cout << computers[command].size() << endl;
	}
}
 
void Database::addRecord()
{
	file.close();
	file.open("Database.dat", ios::app | ios::binary);
	records.push_back(Record().init(file));
	file.close();
}

void Database::rewriteData()
{
	file.close();
	file.open("Database.dat",ios::out|ios::binary);
	for (Record record : records)
		record.writeIn(file);
	file.close();
}



void Database::choose(string &command)
{	
	while (true) {
		cout << "\n Enter one of the commands below \n\t'back' to go back \n\t'computer' - to got to computers\n\t'draw users' - to draw users information\n\t'reports' - reports amount\n\t user - choose user ): ";
		getline(cin, command);

		if (command == "back")
			return;
		else if (command == "computer") {
			chooseComputer(command);
		}
		else if (command == "draw users") {
			drawUsers();
		}
		else if (command == "user") {
			chooseUser(command);
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

bool compString(const string& first, const string& second) {
	if (first.size() != second.size())
		return false;
	for (int i = 0; i < first.size(); i++) {
		if (first[i] != second[i]) {
			cout << first[i] << " | " << second<<endl;
			return false; 
		}
	}
	return true;
}

void Database::change(string &command) {
	Record *record = NULL;
	vector<int> temp_records;
	bool is_found = false;
	while (true) {
		

		
		cout << "Enter name: ";
		getline(cin, command);
		if (command == "back")
			return;
		for (int i = 0; i < records.size(); i++)
			if (compString(command, records[i].getName())) {
				temp_records.push_back(i);
			}

		cout << "Enter computer code: ";
		getline(cin, command);
		for (int i = 0; i < temp_records.size(); i++)
			if (!compString(records[temp_records[i]].getComputer(), command))
				{
					temp_records.erase(temp_records.begin() + i);
				}

		cout << "Enter date: ";
		getline(cin, command);
		for (int i = 0; i < temp_records.size(); i++)
			if (!compString(records[temp_records[i]].getWorkDate(), command))
			{
				temp_records.erase(temp_records.begin() + i);
				is_found = true;
			}
		
		if (!is_found) {
			cout << " Record with this params wasn't found" << endl;
			continue;
		}

		records[temp_records[0]].getWorkTime().enterDate();

			break;
		
	}
	rewriteData();
}
