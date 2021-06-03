#include "Programer.h"



void Programer::addRecord(string& m_name, Record& record)
{
	amount += 1;
	records[m_name].push_back(record);
	time[record.getTopicCode()] += record.getInterval();
	for (Computer &computer : computers) {
		if (computer.name == m_name) { 
			computer.addRecord(record);
			return;
		}
	}
	computers.push_back(Computer(m_name, record));
}

void Programer::Computer::addRecord(Record& record)
{
	for (Theme &theme : themes) {
		if (theme.name == record.getTopicCode()) {
			theme.amount += 1;
			return;
		}
	}
	themes.push_back(Theme(record.getTopicCode()));


}

ostream& operator<<(ostream& stream, const Programer::Computer::Theme theme)
{
	stream << "\t\tTheme: " << theme.name << "\t Amount: " << theme.amount;
	return stream;
}

ostream& operator<<(ostream& stream, const Programer::Computer computer)
{
	stream << "\tComputer name: " << computer.name<<"\n";
	for (Programer::Computer::Theme theme : computer.themes)
		stream << theme <<"\n";
	return stream;

}

ostream& operator<<(ostream& stream, const Programer programer)
{
	stream << "User Name: " << programer.name << "\tAmount works: "<< programer.amount << "\n";
	for (Programer::Computer computer : programer.computers)
		stream << computer;
	return stream;

}
