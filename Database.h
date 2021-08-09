#pragma once
#include <fstream>
//#include "Computer.h"
#include <map>
#include "Programer.h"
#include <algorithm>
class Database
{
private:
	fstream file;
	vector<Record > records = vector<Record>();
	map<string, vector<string>> computers;
	map<string, int> themes;
	vector< Programer> programmers;
	vector<string> userss;

public:
	Database();

	void drawTable();
	void drawUsers();

	void chooseUser(string& command);
	void chooseSort(string& command);
	void choose(string&);
	void change(string& command);
	void chooseComputer(string&);
	map<string, map<int, int>> users;// user->theme-index->amount
	int allReportAmount = 0;

	void addRecord();

	void rewriteData();
};

