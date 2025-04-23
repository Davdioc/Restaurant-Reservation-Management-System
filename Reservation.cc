#include "Reservation.h"
using namespace std;
#include <iostream>
#include <string>

Reservation::Reservation(string p, Date* d, Time* t, Table* tl){
	patron = p;
	date = new Date;
	date = d;
	time = new Time; 
	time = t;
	table = tl;
}

Reservation::~Reservation(){
	delete date;
	delete time;
}

bool Reservation::lessThan(Reservation* r){

	if(date->equals(r->date) == true){
		if(time->lessThan(r->time) == true){
			return true;
		}else{
			return false;
		}
	}else{
		if(r->date->lessThan(date) == false){
			return true; 
		}else{
			return false;
		}	
	
	}
	
}

int Reservation::getReservedT(){
	return table->getNum();
}

bool Reservation::overlaps(Date* d,Time* t){
	if(date->equals(d)==true){
		Time* tempTime1(t);
		Time* tempTime2(time);
		tempTime1->add(RSV_HR,0);
		tempTime2->add(RSV_HR,0);
		if(time->overlaps(t,tempTime1)== true || t->overlaps(time,tempTime2) == true){
			return true;
		}else{
			return false;
		} 
	}else{
		return false;
	}
	
}

bool Reservation::matchDate(Date* d){
	if(date->equals(d)){
		return true;
	}else{return false; }
}

void Reservation::print(){
	cout<< patron;
	cout<<"  ||  ";
	date->print();
	cout<<" @@ ";
	time->print();
	cout<<"       Table:"<< table->getNum();
	cout<<endl;
}
