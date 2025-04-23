#ifndef RESERVATION_H
#define RESERVATION_H

using namespace std;
#include "Table.h"
#include "Date.h"
#include "Time.h"
#include "defs.h"
#include <string>

class Reservation{
	public:
		Reservation(string = "Unknown",Date* = NULL, Time* = NULL, Table* = NULL);
		~Reservation();
		bool lessThan(Reservation*);
		int getReservedT();
		bool matchDate(Date*);
		bool overlaps(Date*,Time*); 
		void print();
	private:
		string patron;
		Date* date;
		Time* time;
		Table* table;
};
#endif
