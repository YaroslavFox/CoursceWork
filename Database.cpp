#include "Database.h"

Database::Database()
{
	file.open("database.txt");
	string raw_report;
	//stringstream stream();
	vector<string> params = vector<string>();
	
	int counter = 0;

	while (file>>raw_report)
	{
		params.push_back(raw_report);

		if (params.size() % 7 == 0) {
			records.push_back(Record(params));
			params.clear();
		}


		/*file.getline(stream,12 );
		if (getline(ss, tmp, ' ').fail()) {
			words.push_back(s);
		}
		while (getline(ss, tmp, ' ')) {
			words.push_back(tmp);
		}*/

		
	}


}
void Database::drawTable()
{
	
}
//
//Database::~Database()
//{
//	file.close();
//}
