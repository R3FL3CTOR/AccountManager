#include "Account_util.hpp"
#include <iostream>
#include <vector>

void display(const std::vector<Account *> &accounts) {
    std::cout << "\n===Account ======================" << std::endl;
    for(const auto i : accounts) {
        std::cout << *i << std::endl;
    }
}
void deposit(std::vector<Account *> &accounts, double amount) {
    std::cout << "\n===Depositing to Accounts =================" << std::endl;
    for(auto i : accounts) {
        if(i->deposit(amount)) {
            std::cout << "Deposited " << amount << " to " << *i << std::endl; 
        }else {
            std::cout << "Failed Deposit of " << amount << " to " << *i << std::endl;
        }
    }
}
void withdraw(std::vector<Account *> &accounts, double amount){
    std::cout << "\n===Withdrawing to Accounts =================" << std::endl;
    for(auto i : accounts) {
        if(i->withdraw(amount)) {
            std::cout << "Withdrew " << amount << " from " << *i << std::endl;
        }else {
            std::cout << "Failed Withdraw of " << amount << " from " << *i << std::endl;
        }
    }
}

void transfer(std::vector<Account *> &accounts, Account &acc, double amount) {
    std::cout << "\n===Transfering to Accounts =================" << std::endl;
    for(auto i : accounts) {
        if(i->transfer(acc, amount)) {
            std::cout << "Trasfered " << amount << " to " << acc << std::endl;
        }else {
            std::cout << "Failed Transfer of " << amount << " to " << acc << std::endl;
        }
    }
}