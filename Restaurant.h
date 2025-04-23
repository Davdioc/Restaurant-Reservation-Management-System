#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <string>

#include "Table.h"
#include "RsvList.h"
#include "defs.h"
using namespace std;
class Restaurant{
	public:
		Restaurant(string = "David's crib", int=0);
		~Restaurant();
		void addTable(Table* t);
		void reserveTable(string patron, int capacity, int year, int month, int day, int hour, int minute);
		void printReservations();
	private:
		string name;
		int numTables;
		Table* tables[MAX_ARR];
		RsvList* reservations;
		
};

#endif 
