#include <string>
#include <cmath>
#include "passport.h"

std::string Passport::serials = "AA";
int Passport::id[] = {0, 0, 0, 0, 0, 0};

Passport::Passport(std::string familyName, std::string name, int dDay, int mm, int dataYear)
: lastNam(familyName)
, name(name)
, date(dDay, mm, dataYear)
{
    if ( id[5] < 9 ) {
        id[5] += 1;
    } else if ( id[4] < 9 ) {
        id[5] = 0;
        id[4] += 1;
    } else if ( id[3] < 9 ) {
        id[4] = 0;
        id[3] += 1;
    } else if ( id[2] < 9 ) {
        id[3] = 0;
        id[2] += 1;
    } else if ( id[1] < 9 ) {
        id[2] = 0;
        id[1] += 1;
    } else if ( id[0] < 9 ) {
        id[1] = 0;
        id[0] += 1;
    } else {
        newSerials(serials);
        id[5] = 1;
    }
    serial = serials;
    initNumber();

}
Passport::Passport(const Passport& b)
: date(b.date.getDay(), b.date.getNumberMonth(), b.date.getYear())
{
    name = b.name;
    lastNam = b.lastNam;
    if ( id[5] < 9 ) {
        id[5] += 1;
    } else if ( id[4] < 9 ) {
        id[5] = 0;
        id[4] += 1;
    } else if ( id[3] < 9 ) {
        id[4] = 0;
        id[3] += 1;
    } else if ( id[2] < 9 ) {
        id[3] = 0;
        id[2] += 1;
    } else if ( id[1] < 9 ) {
        id[2] = 0;
        id[1] += 1;
    } else if ( id[0] < 9 ) {
        id[1] = 0;
        id[0] += 1;
    } else {
        newSerials(serials);
        id[5] = 1;
    }
    serial = serials;
    initNumber();
}
Passport& Passport::operator=(const Passport& b)
{
    name = b.name;
    lastNam = b.lastNam;
    date.setDay(b.date.getDay());
    date.setMonth(b.date.getNumberMonth());
    date.setYear(b.date.getYear());
    
    if ( id[5] < 9 ) {
        id[5] += 1;
    } else if ( id[4] < 9 ) {
        id[5] = 0;
        id[4] += 1;
    } else if ( id[3] < 9 ) {
        id[4] = 0;
        id[3] += 1;
    } else if ( id[2] < 9 ) {
        id[3] = 0;
        id[2] += 1;
    } else if ( id[1] < 9 ) {
        id[2] = 0;
        id[1] += 1;
    } else if ( id[0] < 9 ) {
        id[1] = 0;
        id[0] += 1;
    } else {
        newSerials(serials);
        id[5] = 1;
    }
    serial = serials;
    initNumber();
    return *this;
}

std::string Passport::getFamilyName() const{
    return lastNam;
}
std::string Passport::getSerials() {
    return serials;
}
std::string Passport::getSerial() const{
    return serial;
}
void Passport::setSerial(std::string str) {
    serial = serials;
}
int* Passport::getNumber() {
    return number;
}
int* Passport::getId() {
    return id;
}

void Passport::initNumber() {
	for( int i = 0; i < 6; ++i) {
		number[i] = id[i];
	}
}

Date* Passport::getDate() {
    return &date;
}

std::string Passport::getName () const{
    return name;
}


int calculatingSize(int length) {
        if ( length < 10) {
            return 1;
        }
        if ( length < 100 ) {
            return 2;
        }
        if ( length < 1000) {
            return 3;
        }
        if ( length < 10000 ) {
            return 4;
        }
        if ( length < 100000) {
            return 5;
        }
        if ( length < 1000000 ) {
            return 6;
        }
        return 0;

}

void  Passport::nullingId() {
    
    for (int i = 0; i < 6; ++i ) {
        id[i] = 0;
    }
}

int lastNumber(int number, int length) {
    int last = 0;
	for (int i = length ; i > 0; --i) {
        last = number % (int)(pow(10.0, i));
    }
    return last;
}

void  Passport::fillId(int numberId, int size) {
	int count = 5 - size;
    nullingId();
    for (int i = 5; i > count; --i)
    {
        id[i] = lastNumber(numberId, size-1);
		numberId /= 10;
    }
}

void Passport::newSerials( std::string str, int numberId) {
    if(str != serials && str != "") {
        serials = str;
    }else if ( serials[1] < 'Z' ) {
        serials[1] += 1;
    } else if ( serials[0] < 'Z') {
        serials[0] += 1;
        serials[1] = 'A';
    } else {
        throw NotSerial();
    }
    if (numberId != 0) {
        int size = calculatingSize(numberId);
        fillId(numberId-1, size);
    } else {
        nullingId();
    }
}

