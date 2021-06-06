#pragma once
#include <vector>
#include <map>
#include <string>
#include "Record.h"
using namespace std;
class Programer
{
public:
	string name;
	Programer(Record& record) { this->name = record.getName(); addRecord(record); }
	void addRecord( Record& record);
	friend ostream& operator<< (ostream&, const Programer);
	class Computer {
	private: 
	public:
		class Theme {
		public:
			string name;
			int amount = 1;
			Theme(string name) { this->name = name; };
			friend ostream& operator<< (ostream&, const Theme);

		};
		string name;
		vector<Theme> themes;
		Computer(Record& record) { this->name = record.getComputer(); addRecord(record); }
		friend ostream& operator<< (ostream&, const Computer);

		void addRecord(Record& record);
	};
	int amount = 0;
	map<string, vector<Record>> records;
	map<string, double> time;
	void drawRecords() {/*
		for (Record& record : records)
			cout << record<<"\n";*/
		for (Computer computer : computers) {
			cout << "Computer name: " << computer.name << "\n";
			for(Record record: records[computer.name])
				cout << record << "\n";
		}
	}
private:

	vector<Computer> computers = vector<Computer>();
	//vector<string> computers_list;

};

