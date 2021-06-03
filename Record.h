#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>


using namespace std;



class Record
{
private:

	static bool formCheck(string form, string key){
		if (form.length() != key.length())
			return false;
		for (int i = 0; i < key.length(); i++) {
			switch (key[i])
			{
				case '#': continue;

				default:
					if (form[i] != key[i]) return false;
					break;
			}
		}
		return true;
	}

	static bool isDate(string date) {
	

		return formCheck(date, "##.##.####");
	}

	struct workTime
	{
		string begining;
		string ending;
		void init() {
			while (!isDate(begining)) {
				cout << '\n' << "Enter the begining time dd.mm.yyyy: ";
				cin >> begining;
			}

			while (!isDate(ending)) {
				cout << '\n' << "Enter the ending time dd.mm.yyyy: ";
				cin >> ending;
			}
		};
		friend ostream& operator<< (ostream& stream, workTime time) {
			
			stream << setw(10) << time.begining << "|" << setw(10) << time.ending;

			return stream;
		};

	};

	string name; // Student Full name 
	string topic_code;
	string work_date;
	workTime time = workTime();
	double interval; // in minutes

	enum indexes
	{NAME, TOPIC_CODE, WORK_DATE, BEGIGNING, ENDING, INTERVALL};

public:
	string getName() const { return name; }
	
	string getTopicCode() { return topic_code; }

	string getWorkDate() { return work_date; }

	workTime getWorkTime() { return time; }

	double getInterval() { return interval; }

	friend ostream& operator<< (ostream&,const Record);

	Record init();

	Record(fstream& file, vector<string>& );

	
};

