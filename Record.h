#pragma once
#include <string>
#include <iostream>
#include <vector>


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
	};

	string name; // Student Full name 
	string topic_code;
	string work_date;
	workTime time = workTime();
	string interval; // in minutes

public:
	string getName() { return name; }
	
	string getTopicCode() { return topic_code; }

	string getWorkDate() { return work_date; }

	workTime getWorkTime() { return time; }

	string getInterval() { return interval; }

	void init();

	Record(vector<string> file);

	
};

