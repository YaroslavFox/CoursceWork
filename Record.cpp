#include "Record.h"
#include <algorithm>


Record Record::init(fstream &file)
{ 

	cout << "Enter the name: ";
	getline(cin, name);
	file << name <<'|';
	cout << "\nEnter the Computer: ";
	getline(cin, computer);
	file << computer << '|';
	cout << "\nEnter the topic code: ";
	getline(cin, topic_code);
	file << topic_code << '|';




	while (!isDate(work_date)) {
		cout << "\nEnter the work date dd.mm.yyyy: ";
		getline(cin, work_date);
	}
	file << work_date << '|';

	time.init(file);

	cout << '\n' << "Enter the interval in minutes: ";
	cin >> interval;
	file << interval;
	return *this;
}

Record::Record(fstream& file,  vector<string>& users)
{

	//file >> name >> computer >> topic_code >> work_date >> time.begining >> time.ending >> interval;
	getline(file,name, '|');
	
	//if((int)name[0]==(int)(char)"\n")
	name.erase(name.begin());
	getline(file, computer, '|');
	getline(file, topic_code, '|');
	getline(file, work_date, '|');
	getline(file, time.begining, '|');
	getline(file, time.ending, '|');
	file >> interval;
	/*string temp;
	file >> temp;
	cout << temp;*/
	/*string temp;

	getline(file, temp, '|');

	interval = stod()*/
		
	if (not count(users.begin(), users.end(), name))
		users.push_back(name);
}

ostream& operator<<(ostream& stream, Record record)
{
	stream << left << "|" << setw(10) << record.name << "|" << setw(10) << record.computer << "|" << setw(10) << record.topic_code << "|" << setw(10) << record.work_date << "|" << setw(10) << record.time << "|" << setw(10) << record.interval << "|";
	return stream;
}

 
