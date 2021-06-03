#pragma once
#include <fstream>
#include <vector>
#include "Record.h"
#include <map>
#include "Programer.h"

using namespace std;

class Computer
{
private:
	fstream file;
	vector<Record> records;
	vector<string> users;
	string name;

	
	//bool compettion(const Record &first, const Record &second);
	
public:

	Computer() {};

	Computer(string& path, vector<Programer> &programmers, int &amount);//, map<string, map<int, int>> &users, vector<string> &themes

	void drawTable();

	void choosed(string&);

	string getName() { return name; };

	vector<string> getUsers() { return users; }
	ostream& write_users(ostream&);

};

