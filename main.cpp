#include <iostream>
#include "passport.h"
std::ostream& operator<<( std::ostream& out, int number[]) {
    for( int i = 0; i < 6; ++i ) {
        out << number[i];
    }
    out<< std::endl;
}

int main() {
    Passport a("Kukin", "Petr", 3, 5, 1987);
    Passport b = a;

    std::cout << a.getName() << ' ' << a.getFamilyName() << ' ' << a.getDate()->getDay() << ' ' << a.getDate()->getNumberMonth() << ' ' << a.getDate()->getYear() << ' ' << a.getSerial() << ' ' << a.getNumber() << ' ' << a.getId() << std::endl;
    std::cout << b.getName() << ' ' << b.getFamilyName() << ' ' << b.getDate()->getDay() << ' ' << b.getDate()->getNumberMonth() << ' ' << b.getDate()->getYear() << ' ' << b.getSerial() << ' ' << b.getNumber() << ' ' << b.getId() << std::endl;
     Passport::newSerials("AM", 740360);
    Passport c("Reznichenko", "Roman", 29, 9, 1985);
    std::cout << c.getName() << ' ' << c.getFamilyName() << ' ' << c.getDate()->getDay() << ' ' << c.getDate()->getNumberMonth() << ' ' << c.getDate()->getYear() << ' ' << c.getSerial() << ' ' << c.getNumber() << ' ' << c.getId() << std::endl;

    Passport::newSerials("DD", 999999);
    Passport d("Ivanov", "Nikola", 9, 2, 2007);
    std::cout << d.getName() << ' ' << d.getFamilyName() << ' ' << d.getDate()->getDay() << ' ' << d.getDate()->getNumberMonth() << ' ' << d.getDate()->getYear() << ' ' << d.getSerial() << ' ' << d.getNumber() << ' ' << d.getId() << std::endl;
    Passport ryduk("Ruduk", "Tatyana", 1, 2, 1986);
    std::cout << ryduk.getName() << ' ' << ryduk.getFamilyName() << ' ' << ryduk.getDate()->getDay() << ' ' << ryduk.getDate()->getNumberMonth() << ' ' << ryduk.getDate()->getYear() << ' ' << ryduk.getSerial() << ' ' << ryduk.getNumber() << ' ' << ryduk.getId() << std::endl;
    
    return 0;
}