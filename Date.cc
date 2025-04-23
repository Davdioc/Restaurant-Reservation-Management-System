#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

Date::Date(int d, int m, int y)
{
	setDate(d, m, y);
}

Date::~Date()
{
}

bool Date::validate(int d, int m, int y){
	Date time(d,m,y);
	if(y < 0){
		return false;
	}
	if(m <= 0|| m > 12){
		return false;
	}
	if(d <= 0){
		return false;
	}
	if(d>time.lastDayInMonth()){
		return false;
	}
	return true;
}

bool Date::lessThan(Date* d){
	if(year < d->year){
		return true;
	}else if(year == d->year){
		if(month < d->month){
			return true;
		}else if(month == d->month){
			if(day <= d->day){
				return true;
			}else{return false;}
		}else{
			return false;
		}
	}else{
		return false;
	}
}

bool Date::equals(Date* d){
	if(day == d->day && month == d->month && year == d->year){
		return true;
	}else{
		return false;
	}
}

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

void Date::print()
{
  cout<<setfill('0')<<setw(2)<<year<<"-"<<setfill('0')<<setw(2)<<month<<"-"<<setfill('0')<<setw(2)<<day;

}

int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

string Date::getMonthStr()
{
  string monthStrings[] = { 
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}

