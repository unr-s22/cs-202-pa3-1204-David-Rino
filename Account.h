//PA3 - CS202 
//Rino David
//4 - 1 - 2022

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<vector>
#include<iostream>
#include<sstream>
#include"Money.h"

class Account : public Money {

private:
    std::vector<Money> numDeposits;
    std::vector<Money> numWithdrawals;
    bool balanceUpdate = false;
    Money initialBalance;
    Money currentBalance;

    void updateAccount();

public:
    Account(Money &m);
    friend std::ostream& operator<<(std::ostream &out, Account &rhs);
    void makeDeposit(Money &m);
    void makeWithdrawal(Money &m);
    Money getBalance();
    

};

#endif 