#include "Computer.h"
#include <algorithm>
#include <map>
#include <string>

bool compareByAlhpabet(Record first, Record second) {
	if (first.getName() == second.getName())
		return first.getWorkDate() < second.getWorkDate();
	return first.getName() < second.getName();
}



int getThemeIndex(vector<string>& themes, string theme) {
	vector<string>::iterator it = find(themes.begin(), themes.end(), theme);

	if (find(themes.begin(), themes.end(), theme) == themes.end()) {
		themes.push_back(theme);
		return themes.size() - 1;
	}
	return distance(themes.begin(), it);
}

Computer::Computer(string& path, vector<Programer>& programmers, int &allUsersAmount)// , map<string, map<int, int>> &ussers, vector<string> &themes
{
	
	file.open("data\\evm_"+path+".txt");

	string raw_string;
	vector<string> params = vector<string>();
	getline(file, name);


	while (file >> raw_string)
	{
		params.push_back(raw_string);

		//if (params.size() % 7 == 0) {
			allUsersAmount += 1;
			Record new_record = Record(file, users);
			records.push_back(new_record);
			params.clear();
			bool hadBeenUpdated = false;
			for (Programer &programmer : programmers) {
				if (programmer.name == new_record.getName()) {
					programmer.addRecord(name ,new_record);
					hadBeenUpdated = true;
					break;
				}
			}
			if (not hadBeenUpdated)
				programmers.push_back(Programer(name, new_record));

			/*int index = getThemeIndex(themes, new_record.getTopicCode());

			if (ussers.find(new_record.getName()) == ussers.end()) {
				ussers[new_record.getName()] = { {index, 1} };
			}
			else {
				if (ussers[new_record.getName()].find(index) == ussers[new_record.getName()].end()) 
					ussers[new_record.getName()] = { {index, 1} };
				else ussers[new_record.getName()][index] += 1;
			}
			cout << "User: " << new_record.getName() << " Theme: " << themes[index] << " Amount: " << ussers[new_record.getName()][index] << endl;*/

		//}
	}
	sort(records.begin(), records.end(), compareByAlhpabet);


}



void Computer::drawTable()
{
	cout << "\n Name: " << name;
	string header = "";
	string line_separator = "\n-------------------------------------------------------------------\n";
	cout << line_separator;
	for (Record record : records) 
		cout << record <<   line_separator;
}

void Computer::choosed(string &command)
{

	
	while (true) {
		//if (not_skip) 
		cout << "\n all - print out the whole table \n users - print users list\n To go back enter 'back'\n Enter the command: ";
		getline(cin, command);

		if (command == "back")
			return;
		if (command == "users")
			write_users(cout);
		else if (command == "all")
			drawTable();

	}
}

ostream& Computer::write_users(ostream& stream)
{
	for (string user : users)
		stream << user << "\n";
		return stream;
}
