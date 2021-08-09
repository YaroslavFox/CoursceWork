#include "Record.h"
#include <algorithm>

Record Record::init(fstream &file)
{ 

	cout << "Enter the name: ";
	getline(cin, name);
	cout << "\nEnter the Computer: ";
	getline(cin, computer);
	cout << "\nEnter the topic code: ";
	getline(cin, topic_code);
	while (!isDate(work_date)) {
		cout << "\nEnter the work date dd.mm.yyyy: ";
		getline(cin, work_date);
	}

	time.init();
	cout << '\n' << "Enter the interval in minutes: ";
	cin >> interval;

	writeIn(file);
	return *this;
}

Record::Record(fstream& file,  vector<string>& users)
{
	getline(file, name, '|');
	getline(file, computer, '|');
	getline(file, topic_code, '|');
	getline(file, work_date, '|');
	getline(file, time.begining, '|');
	getline(file, time.ending, '|');

	file.read((char*)&interval, sizeof(interval));
		
	if (not count(users.begin(), users.end(), name))
		users.push_back(name);
}

void Record::writeIn(fstream& file)
{
	char sepearator = '|';
	file.write(name.c_str(), name.size());
	file.write(&sepearator, sizeof(char));
	file.write((computer).c_str(), computer.size());
	file.write(&sepearator, sizeof(char));
	file.write((topic_code).c_str(), topic_code.size());
	file.write(&sepearator, sizeof(char));
	file.write((work_date).c_str(), work_date.size());
	file.write(&sepearator, sizeof(char));
	file.write((time.begining).c_str(), time.begining.size());
	file.write(&sepearator, sizeof(char));
	file.write((time.ending).c_str(), time.ending.size());
	file.write(&sepearator, sizeof(char));
	file.write((char*) &interval, sizeof(interval));
}

ostream& operator<<(ostream& stream, Record record)
{
	stream << left << "|" << setw(14) << record.name << "|"  << setw(8) << record.topic_code << "|" << setw(10) << record.work_date << "|" << setw(10) << record.time << "|" << setw(11) << record.interval << "|";
	return stream;
}