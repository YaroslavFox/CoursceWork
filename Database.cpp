#include "Database.h"

Database::Database()
{
	file.open("database.txt");
	string raw_report;

	
	while (!file.eof())
	{
		getline(file, raw_report);
		cout << raw_report << endl;
	}


}
//
//Database::~Database()
//{
//	file.close();
//}
