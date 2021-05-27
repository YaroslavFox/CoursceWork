#include "Record.h"

void Record::init()
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

	
	

}

Record::Record(vector<string> file)
{
	cout << file.size() << endl;

	for (int i = 0; i < file.size(); i++) {
		cout << file[i] << " ";
	}
	cout << "\n";

}
