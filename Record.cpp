#include "Record.h"
#include <algorithm>


Record Record::init()
{ 
	cout << "Enter the name: ";
	cin >> name;

	cout << "\nEnter the topic code: ";
	cin >> topic_code;

	while (!isDate(work_date)) {
		cout << "\nEnter the work date: ";
		cin >> work_date;
	}

	time.init();

	cout << '\n' << "Enter the interval in minutes: ";
	cin >> interval;

	return *this;
}

Record::Record(fstream& file,  vector<string>& users)
{

	file >> name >> topic_code >> work_date >> time.begining >> time.ending >> interval;

	//topic_code = file[TOPIC_CODE];

	//work_date = file[WORK_DATE];

	//time.begining = file[BEGIGNING];

	//time.ending = file[ENDING];
	//cout << file[INTERVALL] << endl;
	//interval = stod(file[INTERVALL]);
	
	if (not count(users.begin(), users.end(), name))
		users.push_back(name);
}

ostream& operator<<(ostream& stream, Record record)
{
	stream << left << "|" << setw(10) << record.name << "|" << setw(10) << record.topic_code << "|" << setw(10) << record.work_date << "|" << setw(10) << record.time << "|" << setw(10) << record.interval << "|"<< record.interval;
	return stream;
}

 
