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

void transfer_to_account(Account &account, Account &to_acc, double amount) {
    std::cout << "\n===Transfering to Accounts =================" << std::endl;
    std::cout << "\nAccount info before transfer: " << account << '\n';
    std::cout << "Transfered Account info before transfer: " << to_acc << '\n';
        if(account.transfer(to_acc, amount)) {
            std::cout << "Trasfered " << amount << " from " << account << " to " << to_acc << std::endl;
            std::cout << "\nAccount info before transfer: " << account << '\n';
            std::cout << "Transfered Account info after transfer: " << to_acc << '\n';
        }else {
            std::cout << "Failed Transfer of " << amount << " to " << to_acc << std::endl;
        }
}

void transfer_to_all(std::vector<Account *> &account, Account &to_acc, double amount) {
    std::cout << "\n===Transfering to all Accounts =================" << std::endl;
    for(const auto &i : account) {
        if(i->transfer(to_acc, amount)) {
            std::cout << "Transferred " << amount << " from " << *i << " to " << to_acc << std::endl;
        }else {
            std::cout << "Failed Transfer of " << amount << " from " << *i << " to " << to_acc << std::endl;
        }
    }
}