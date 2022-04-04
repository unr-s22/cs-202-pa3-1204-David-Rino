//PA3 CS 202
//Author: Rino David
//4 - 1 - 2022

#ifndef MONEY_H
#define MONEY_H

#include<iostream>
#include<sstream>

class Money {

private:
    int dollars;
    int cents;
    bool isNegative;

    public:
    Money()
        : dollars{0}, cents{0}, isNegative{false} {};
    Money(int d, int c)
        : dollars{d}, cents{c}, isNegative{false} {};
    Money(int d, int c, bool neg)
        : dollars {d}, cents {c}, isNegative {neg} {};

    friend std::ostream& operator<<(std::ostream &out, const Money &m);

    bool operator<(const Money &m) const;
    bool operator>(const Money &m) const;
    bool operator<=(const Money &m) const;
    bool operator>=(const Money &m) const;
    bool operator!=(const Money &m) const;
    bool operator==(const Money &m) const;
    
    Money operator+(const Money &m) const;
    Money operator-(const Money &m) const;

};

#endif 
