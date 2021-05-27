#pragma once
#include <fstream>
#include "Record.h"
#include <vector>
#include <algorithm>

class Database
{
private:
	vector<Record> records;
	fstream file;
public:
	Database();

	void drawTable();
	//~Database();
};

