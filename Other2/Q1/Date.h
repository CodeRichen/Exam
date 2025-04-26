#ifndef Date_h
#define Date_h

class Date
{
    public:
        Date();
        Date(int, int, int);
        Date& setM(int);
        Date& setD(int);
        Date& setY(int);
        void nextDay();

    private:
        int month;
        int day;
        int year;
        int daysInMonth(int);
        bool leapYear(int);
};

#endif