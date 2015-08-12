#include "date.h"
#include <cstdlib>
#include <cmath>
Date::Date(int dDay, int mm, int dataYear) {
	if ( mm > 12 && mm < 1 ) {
        throw BadDate();
    }
    validDay(dDay, mm, dataYear);
    month = mm;
    year = dataYear;
}
Date::Date(std::string date) {
	int data = atoi(date.c_str());
	int decade = 0;
	if (date.size() == 8) {
		decade = pow(10, 6);
	}
	int dDay = data / decade;
}
bool Date::validDay(int dDay, int mm, int dataYear) {
	if ( mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12 ) {
        if ( dDay > 31 ) {
            throw BadDate();
        }
        day = dDay;
    } else if (mm == 2 ) {
        if ( dataYear % 4 == 0 || dataYear % 100 == 0 || dataYear % 400 == 0 ) {
            if ( dDay > 29 ) {
                throw BadDate();
            }

        } else if ( dDay > 28 ) {
            throw BadDate();
        }
        day = dDay;

    } else if ( mm == 4 || mm == 6 || mm == 9 || mm == 11 ) {
        if ( dDay > 30 ) {
            throw BadDate();
        }
        day = dDay;
    }
}

int Date::getDay() const{
	return day;
}
int Date::getNumberMonth() const{
	return month;
}
int Date::getYear() const{
	return year;
}
std::string Date::getStringMonth() const{
	return Month[month];
}
void Date::setDay(int newDay) {
	if (validDay(newDay, month, year)) {
		day = newDay;
	} else {
		throw BadDate();
	}
}
void Date::setMonth(int newMonth) {
	if (newMonth > 0 && newMonth < 13) {
		month = newMonth;
	}
}
void Date::setYear(int newYear) {
	year = newYear;
}