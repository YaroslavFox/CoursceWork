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
