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
	//map< string, int> computer_indexes;
	//string command_list = "add or + - add new one \n draw - show tables \n choose - schoose computer \n commands - show the list again \n exit - exit\n";
	map<string, vector<string>> computers;//map<computer name, user names>
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
	//vector<string> themes;
	int allReportAmount = 0;

	void addRecord();

	void rewriteData();
};

