#include "Date.h"

int main() {
    Date date(8, 31, 2024); 
    date.displayDate();

    date.setMonth(18);
    date.setDay(31);
    date.setYear(2023);
    date.displayDate();

    return 0;
}
