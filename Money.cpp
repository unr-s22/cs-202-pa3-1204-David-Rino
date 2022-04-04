//PA3 CS 202
//Author: Rino David
//4 - 1 - 2022

#include"Money.h"

//Operator Overloads
std::ostream& operator<<(std::ostream &out, const Money &m) {

    std::stringstream ss;

    if (m.isNegative) {
        ss << "-";
    }
    
    ss << "$" << m.dollars << ".";

    if (m.cents < 10) {
        ss << "0" << m.cents;
    }
    else {
        ss << m.cents;
    }

    std::string output = ss.str();
    out << output;
    return out;
}

bool Money::operator<(const Money &m) const {
    return dollars < m.dollars || (dollars == m.dollars && cents < m.cents);
}

bool Money::operator>(const Money &m) const {
    return dollars > m.dollars || (dollars == m.dollars && cents > m.cents);
}

bool Money::operator<=(const Money &m) const {
    return dollars < m.dollars || (dollars == m.dollars && m.cents <= m.cents);
}

bool Money::operator>=(const Money &m) const {
    return dollars > m.dollars || (dollars == m.dollars && cents >= m.cents);
}

bool Money::operator!=(const Money &m) const {
    return dollars != m.dollars || cents != m.cents;
}

bool Money::operator==(const Money &m) const {
    return dollars == m.dollars && cents == m.cents;
}

Money Money::operator+(const Money &m) const {
    bool resultNeg;
    int dollarsSum, centsSum;
    
    if (isNegative == m.isNegative) {
        dollarsSum = dollars + m.dollars;
        centsSum = cents + m.cents;
        if (centsSum >= 100) {
            dollarsSum += 1;
            centsSum -= 100;
        }
        resultNeg = isNegative;
    } 
    else {
        dollarsSum = std::abs(dollars - m.dollars);
        centsSum = std::abs(cents - m.cents);
        resultNeg = dollars < m.dollars || (dollars == m.dollars && cents < m.cents) ? !isNegative : isNegative;
    }
   
    Money result(dollarsSum, centsSum, resultNeg);
    return result;
}

Money Money::operator-(const Money &m) const {
    bool resultNeg;
    int dollarsDif, centsDif;
    
    if (isNegative == m.isNegative) {
        
        dollarsDif = std::abs(dollars - m.dollars);
        centsDif = std::abs(cents - m.cents);
        resultNeg = dollars < m.dollars || (dollars == m.dollars && cents < m.cents) ? !isNegative : isNegative;
    } 
    else {
        dollarsDif = dollars + m.dollars;
        centsDif = dollars + m.dollars;
        if (centsDif >= 100) {
            dollarsDif += 1;
            centsDif -= 100;
        }
        resultNeg = isNegative;
    }
    
    Money result(dollarsDif, centsDif, resultNeg);
    return result;
}
