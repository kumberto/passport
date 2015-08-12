#pragma once
#include <string>
#include "date.h"

class NotSerial{};

class Passport {
    private:
        static int id[6];
        int number[6];
        static std::string serials;
        std::string serial;
        std::string name;
        std::string lastNam;
        Date date;
    public:
        Passport(std::string familyName, std::string name, int dDay, int mm, int dataYear);
        Passport( const Passport& b);
        Passport& operator=(const Passport& b);

        Date* getDate();
        int* getNumber();
        std::string getFamilyName()const;
        std::string getName ()const;
        std::string getSerial()const;
        void setSerial(std::string str);
        void initNumber();

        static std::string getSerials();
        static int* getId();
        static void newSerials(std::string str = "", int numberId = 0);
        static void  fillId(int numberId = 0, int size = 0);
        static void nullingId();
};