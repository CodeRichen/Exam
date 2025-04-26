#include "Date.h"
#include <iostream>

using namespace std;

Date& Date::setM(int m)
{   
    if(m >= 1 && m <= 12)
        month = m;
    else
    {
        cout<<"Invalid. Please re-enter: ";
        cin>>m;
    }
    return *this;
}

Date& Date::setD(int d)
{
    if(d >= 1 && d <= daysInMonth(month))
        day = d;
    else
    {
        cout<<"Invalid. Please re-enter: ";
        cin>>d;
    }
    return *this;
}

Date& Date::setY(int y)
{
    year = y;
    return *this;
}

void Date::nextDay()
{
    if(day == daysInMonth(month))
    {
        if(month == 12)
        {
            month = 1;
            day = 1;
            year++;
        }
        else
        {
            month++;
            day = 1;
        }
    }
    else
        day++;
    cout<<year<<"/"<<month<<"/"<<day<<endl;
}

int Date::daysInMonth(int m)
{
    switch(m)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return leapYear(year) ? 29 : 28;
    }
}

bool Date::leapYear(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}


Date::Date()
{
    month = 1;
    day = 1;
    year = 2000;
}

Date::Date(int m, int d, int y)
{
    this->setY(y).setM(m).setD(d);
}