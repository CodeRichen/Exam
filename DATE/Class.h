#ifndef DATE_H
#define DATE_H

#include<iostream>
using namespace std;

class Date {
public:
    Date(int m, int d, int y);
    void setM(int m);           
    void setD(int d);              
    void setY(int y);                                    
    void nextDay();
    void displayDate() const;
private:
    int m=1;
    int d=2;
    int y = 2000;
    unsigned int checkDay(int) const;
};

#endif
