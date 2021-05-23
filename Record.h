#pragma once
#include <string>

using namespace std;



class Record
{
private:
	struct WorkTime
	{
		string begining;
		string ending;
	};

	string name; // Student Full name 
	string topic_code;
	string work_date;
	WorkTime time;

public:

};

