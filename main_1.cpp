#include "film.hpp"
#include "Account_util.hpp"
#include "I_Printable.hpp"
#include <iostream>
#include <vector>
#include <algorithm>


int main() {

    Checking_Account frank {"Frank", 4000};
    std::cout << frank << std::endl;

    Account *trust = new Trust_Account("James");
    std::cout << *trust << std::endl;

    Account *p2 = new Savings_Account("Rama");
    Account *p3 = new Checking_Account("Filan");
    Account *p4 = new Trust_Account();

    std::vector<Account *> acc = {p2, p3, p4};

    display(acc);
    deposit(acc, 3000);
    withdraw(acc, 1000);
    transfer(acc, frank, 500.37);

    display(acc);

    delete p2;
    delete p3;
    delete p4;

    // p1->withdraw(2000);
    // p2->withdraw(2000);
    // p3->withdraw(2000);
    // p4->withdraw(2000);

    // std::vector<Account *> acc_ptrs {p2, p3, p4};
    // for(auto i : acc_ptrs) {
    //     i->withdraw(2000);
    // }

    // delete p1;
    // delete p2;
    // delete p3;
    // delete p4;

    return 0;
}