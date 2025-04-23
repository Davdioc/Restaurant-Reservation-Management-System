#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"

Time::Time(int h, int m)
{
  setTime(h, m);
}

Time::Time(Time& t){
	hours = t.hours;
	minutes = t.minutes;
}

void Time::setTime(int h, int m)
{
  hours   = ( h >= 0 && h < 24) ? h : 0;
  minutes = ( m >= 0 && m < 60) ? m : 0;
}

int Time::convertToMins() 
{
  return (hours*60 + minutes);
}

bool Time::validate(int h, int m)
{
	if(h < 0 || h >= 24){
		return false;
	}
	if(m < 0 || m >= 60){
		return false;
	}
	return true;
}

bool Time::lessThan(Time* t){
	if(hours < t->hours){
		return true;
	}else if(hours == t->hours){
		if(minutes < t->minutes){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}

void Time::print() 
{
  cout<<setfill('0')<<setw(2)<<hours<<":"
      <<setfill('0')<<setw(2)<<minutes;
}

bool Time::overlaps(Time* t1, Time* t2)
{
	if(lessThan(t1)==true){
		return false;
	} 
	if(lessThan(t2)==false){
		return false;
	}
	
	return true;
}

void Time::add(int hrs, int mins){
	if(validate(hours + hrs, mins + minutes) == false)
	{
		hours += hrs;
		minutes += mins;
	}else{
		if((minutes + mins) >= 60){
			hours += ((mins+mins) / 60)+ hrs;
			minutes = (mins+mins) % 60;
		}else{
			return;
		}
		
	}
}
