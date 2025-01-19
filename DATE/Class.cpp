#include "Class.h"


Date::Date(int m, int d, int y) {
    displayDate();
    setM(m);
    setD(d);
    setY(y);
}


void Date::setM(int m) {
    if (m >= 1 and m <= 12)
        this->m = m;
    else
        cout << "Invalid,then re-enter";
}

void Date::setD(int d) {
    int q = checkDay(d);
    if (q==-1)
        cout << "Invalid,then re-enter";
    else
        this->d  = q;
}
unsigned int Date::checkDay(int testDay) const
{
    static const int dPerMonth[13] =
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (testDay > 0 && testDay <= dPerMonth[m])
        return testDay;
    if (m == 2 && testDay == 29 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)))
        return testDay;
    return -1;
}
void Date::setY(int y) {
    if (y <1)
        cout << "Invalid,then re-enter";
    else
        this->y = y;
}

void Date::nextDay() {
    static const int dPerMonth[13] =
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && d == 28 && (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)))
        d++;
    else if (d < dPerMonth[m])
        d++;
    else {
        d = 1;
        if (m < 12)
            m++;
        else {
            m = 1;
            y++;
        }
    }
    displayDate();
}
void Date::displayDate() const {
    cout <<y<<"/"<< m << "/" << d << endl;
}
