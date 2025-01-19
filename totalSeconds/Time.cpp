// Fig. 17.5: Time.cpp
// Member-function definitions for class Time.
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

// Time constructor initializes each data member
Time::Time(int hour, int minute, int second)
{
    setTime(hour, minute, second);
}

// set new Time value using universal time
void Time::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}

// set hour value
void Time::setHour(int h)
{
    if (h >= 0 && h < 24)
        totalSeconds = (h * 3600) + (getMinute() * 60) + getSecond();
    else
        throw invalid_argument("hour must be 0-23");
}

// set minute value
void Time::setMinute(int m)
{
    if (m >= 0 && m < 60)
        totalSeconds = (getHour() * 3600) + (m * 60) + getSecond();
    else
        throw invalid_argument("minute must be 0-59");
}

// set second value
void Time::setSecond(int s)
{
    if (s >= 0 && s < 60)
        totalSeconds = (getHour() * 3600) + (getMinute() * 60) + s;
    else
        throw invalid_argument("second must be 0-59");
}

// return hour value
unsigned int Time::getHour() const
{
    return totalSeconds/3600;
}

// return minute value
unsigned int Time::getMinute() const
{
    return (totalSeconds / 60)%60;
}

// return second value
unsigned int Time::getSecond() const
{
    return totalSeconds %60;
}

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() const
{
    cout << setfill('0') << setw(2) << getHour() << ":"
        << setw(2) << getMinute() << ":" << setw(2) << getSecond();
}

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard() const
{
    cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
        << ":" << setfill('0') << setw(2) << getMinute()
        << ":" << setw(2) << getSecond() << (getHour() < 12 ? " AM" : " PM");
}
