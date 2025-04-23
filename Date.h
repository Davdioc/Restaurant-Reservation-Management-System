#ifndef DATE_H
#define DATE_H
#include <string>
class Date
{
  public:
    Date(int=0, int=0, int=2000);
    ~Date();
    void setDate(int, int, int);
    void print();
    bool lessThan(Date*);
    static bool validate(int,int,int);
    bool equals(Date*);
    

  private:
    int day;
    int month;
    int year;
    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr();
};

#endif
