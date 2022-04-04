//PA3 CS202
//Author: Rino David
//4 - 1 - 2022

#include"Money.h"
#include"Account.h"

int main() {
    
    //Initial Balance and Deposits and Withdrawls in Order
    Money init(300,23);
    Money dep1(200,00);
    Money dep2(300,24);
    Money dep3(501,23);
    Money with1(300,10);
    Money with2(201,34);

    Account account(init);
    std::cout << account << std::endl;

    account.makeDeposit(dep1);
    account.makeDeposit(dep2);
    account.makeDeposit(dep3);

    std::cout << account << std::endl;

    account.makeWithdrawal(with1);
    account.makeWithdrawal(with2);

    std::cout << account << std::endl;

    //Testing Operators For Money Class
    Money test1(30,20);
    Money test2(45,10);
    //test for equality
    Money test3(30,20);

    //Greater Than
    //Expected Output test1 is not greater than test2
    if (test1 > test2) {
        std::cout << "test1 greater than test2" << std::endl;
    } else {
        std::cout << "test1 is not greater than test2" << std::endl;
    }

    // less than
    //Expected Output test1 less than test2
    if (test1 < test2) {
        std::cout << "test1 less than test2" << std::endl;
    } else {
        std::cout << "test1 is not less than test2" << std::endl;
    }
    
    //Equal to & not equal to
    //Expected Output test1 not equal to test2
    if (test1 == test2) {
        std::cout << "test1 is equal to test2" << std::endl;
    } else if (test1 != test2) {
        std::cout << "test1 not equal to test2" << std::endl;
    }
    
    //Greater than or equal to
    //Expected output test1 is greater than or equal to test
    if (test1 >= test3) {
        std::cout << "test1 is greater than or equal to test3" << std::endl;
    } else {
        std::cout << "test1 is not greater than or equal to test3" << std::endl;
    }
    
    //Less than or equal to
    //Expected Output test2 is not less than or equal to test3
    if (test2 <= test3) {
        std::cout << "test2 is less than or equal to test3" << std::endl;
    } else {
        std::cout << "test2 is not less than or equal to test3" << std::endl;
    }

    return 0;
}