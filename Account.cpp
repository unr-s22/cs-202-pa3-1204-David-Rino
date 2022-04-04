//PA3 - CS202
//Author: Rino David
//4 - 1 - 2022

#include "Account.h"
#include "Money.h"

//Constructors

Account::Account(Money &m) {
    initialBalance = m;
    currentBalance = m;
};

//Functions

void Account::makeDeposit(Money &m) {
    numDeposits.push_back(m);
    balanceUpdate = true;
};

void Account::makeWithdrawal(Money &m) {
    numWithdrawals.push_back(m);
    balanceUpdate = true;
}

Money Account::getBalance() {
    if (!balanceUpdate) {
        return currentBalance;
    }

    Money balanceCalc = initialBalance;
    for (Money m: numDeposits) {
        balanceCalc = balanceCalc + m;
    }

    for (Money m : numWithdrawals) {
        balanceCalc = balanceCalc - m;
    }

    currentBalance = balanceCalc;
    balanceUpdate = false;
    return balanceCalc;
}

//Operators

std::ostream &operator<<(std::ostream &out, Account &rhs) {

    std::stringstream ss;

    int i;
    Money currentBalance = rhs.getBalance();
    int currentDeposits = rhs.numDeposits.size();
    int currentWithdrawals = rhs.numWithdrawals.size();

    ss <<"Account Details" << '\n';
    ss << "--------------------------" << "\n";
    ss << "Current Balance: " << currentBalance << '\n';
    ss << "--------------------------" << "\n";
    ss << "Number of Deposits: " << currentDeposits << '\n';
    ss << "--------------------------" << "\n";

    for (i = 0; i < currentDeposits; i++) {
        Money m = rhs.numDeposits[i];
        ss << "(" << i + 1 << ") " << m << '\n';
    }
   
    ss << "--------------------------" << '\n';
    ss << "Number of Withdrawls: " << currentWithdrawals << '\n';
    ss << "--------------------------" << '\n';

    for (i = 0; i < currentWithdrawals; i++) {
        Money m = rhs.numWithdrawals[i];
        ss << "(" << i + 1 << ") " << m << '\n';
    }

    std::string output = ss.str();
    out << output;
    return out;    

}