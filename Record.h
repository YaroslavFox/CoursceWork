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
	static bool isTime(string str) {
		return formCheck(str, "##.##");
	}
	struct workTime
	{
		string begining;
		string ending;
		void enterDate() {
			begining.erase();
			ending.erase();
			while (!isTime(ending)) {
				cout << '\n' << "Enter the ending time hh.mm: ";
				getline(cin, ending);
			}
			while (!isTime(begining)) {
				cout << '\n' << "Enter the begining time hh.mm: ";
				getline(cin, begining);
			}
		}
		void init() {
			enterDate();
		};
		friend ostream& operator<< (ostream& stream, workTime time) {
			
			stream << setw(10) << time.begining << "|" << setw(10) << time.ending;

			return stream;
		};

	};

	string name; // Student Full name 
	string computer;
	string topic_code;
	string work_date;
	workTime time = workTime();
	double interval; // in minutes

	//enum indexes
	//{NAME, TOPIC_CODE, WORK_DATE, BEGIGNING, ENDING, INTERVALL};

public:
	string getName() const { return name; }
	
	string getTopicCode() { return topic_code; }

	string getWorkDate() { return work_date; }

	workTime &getWorkTime() { return time; }

	double getInterval() { return interval; }

	friend ostream& operator<< (ostream&,const Record);

	Record init(fstream &file);

	Record(fstream& file, vector<string>& );
	Record() {};

	string getComputer() { return computer; }

	void writeIn(fstream& file);
};

