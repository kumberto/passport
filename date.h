#pragma once
#include <string>

class BadDate{};

class Date {
	private:
		int day;
        int month;
        int year;
   		std::string Month[13] = { "notMonth",
								"January",
								"February",
								"March",
								"April",
								"May",
								"June",
								"July",
								"August",
								"September",
								"October",
								"November",
								"December"
		};
    public:
    	Date(int dDay, int mm, int dataYear);
    	Date(std::string date);
    	bool validDay(int dDay, int mm, int dataYear);
        int getDay() const;
        int getNumberMonth() const;
        int getYear() const;
        std::string getStringMonth() const;
        void setDay(int newDay);
        void setMonth(int newMonth);
        void setYear(int newYear);

};