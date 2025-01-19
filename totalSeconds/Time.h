// Fig. 17.4: Time.h
// Time class containing a constructor with default arguments.
// Member functions defined in Time.cpp.

#ifndef TIME_H
#define TIME_H

class Time
{
public:
    explicit Time(int = 0, int = 0, int = 0); // default constructor

    // set functions
    void setTime(int, int, int); // set hour, minute, second
    void setHour(int); // set hour (after validation)
    void setMinute(int); // set minute (after validation)
    void setSecond(int); // set second (after validation)

    // get functions
    unsigned int getHour() const; // return hour
    unsigned int getMinute() const; // return minute
    unsigned int getSecond() const; // return second

    void printUniversal() const; // output time in universal-time format
    void printStandard() const; // output time in standard-time format

private:
    unsigned int totalSeconds;
}; // end class Time

#endif
