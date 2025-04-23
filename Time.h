#ifndef TIME_H
#define TIME_H

class Time
{
  public:
    Time(int=0, int=0);
    Time(Time&);
    void print();
    static bool validate(int, int);
    bool lessThan(Time*);
    bool overlaps(Time* t1, Time* t2);
    void add(int hrs, int mins);

  private:
    int  hours;
    int  minutes;
    void setTime(int, int);
    int  convertToMins();
};

#endif
