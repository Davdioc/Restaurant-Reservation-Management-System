#include "Restaurant.h"
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

Restaurant::Restaurant(string n, int num){
	name = n;
	numTables = num;
}

Restaurant::~Restaurant(){
	for(int i = 0; i < numTables; i++){
		delete tables[i];
	}
}

void Restaurant::addTable(Table* t){
	tables[numTables] = t;
	numTables++;
}

void Restaurant::reserveTable(string patron, int capacity, int year, int month, int day, int hour, int minute){
	int tableCap = 0;
	if(Date::validate(day,month,year) == false){
		cout<<"ERROR:  Reserevation date "<<setfill('0')<<setw(2)<<year <<"-"<<setfill('0')<<setw(2)<<month<<"-"<<setfill('0')<<setw(2)<<day<<" is invalid"<<endl;
		return;
	}
	if(Time::validate(hour, minute) == false){
		cout<<"ERROR:  Reserevation time "<<setfill('0')<<setw(2) <<hour<<":"<<setfill('0')<<setw(2)<<minute<<" is invalid"<<endl;
		return;
	}
	if(hour < OPEN_HR || hour > CLOSE_HR){
		cout<<"ERROR:  The requested time "<<setfill('0')<<setw(2) <<hour<<":"<<setfill('0')<<setw(2)<<minute<<" is outside of business hours "<<endl;
		return;
	}
	
	Date* d = new Date(day,month,year);
	Time* t = new Time(hour, minute);
	if(capacity < 0 || capacity > 6){
		cout<<"The request for "<<capacity<<" cannot be accomodated"<<endl;
		return;
	}else{
		switch(capacity){
			case 1:
			case 3:
			case 5:
				tableCap = capacity+1;
			default:
				tableCap = capacity;
		}
	} 
	Reservation* tempArr[MAX_ARR];
	reservations->convertToArray(tempArr, numTables);
	for(int i = 0; i < numTables; i++){
		if(tempArr[i]->overlaps(d,t) == true && tempArr[i]->getReservedT() == tableCap){
			cout<<" No available table could be found for "<<capacity<<" people on";
			d->print();
			cout<<" @ ";
			t->print();
			cout<<endl;
			return;
		}
		
		if(tempArr[i]->overlaps(d,t) == false && tempArr[i]->getReservedT() == tableCap){
			Reservation* r = new Reservation(patron, d, t, tables[(tempArr[i]->getReservedT())-1]);
			reservations->add(r);
			return;
		}
	}

	
}

void Restaurant::printReservations(){
	cout<<name<<endl;
	reservations->print();
}
