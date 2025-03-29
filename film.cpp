#include "film.hpp"
#include <string> 
#include <vector>
#include <iostream>


Account::Account(std::string name, double balance) : name(name), balance(balance) {}
Account::Account(const Account &other) : name(other.name), balance(other.balance) {}

bool Account::deposit(double amount) {
    if(amount < 0) {
        return false;
    }else {
        balance += amount;
        transaction_history.emplace_back("Account Deposit: " + std::to_string(amount));
        return true;
    }
}

bool Account::withdraw(double amount) {
    if(balance >= amount) {
        balance -= amount;
        transaction_history.emplace_back("Account Withdraw: " + std::to_string(amount));
        return true;
    }else {
        return false;
    }
}

bool Account::transfer(Account &to_account, double amount) {
    if(withdraw(amount)) {
        return to_account.deposit(amount);
    }
    return false;
}

void Account::print_transaction_history() const {
    std::cout << "\n===Transaction History ======================" << std::endl;
    for(const auto& str : transaction_history) {
        std::cout << str << '\n';
    }
    std::cout << std::endl;
}

double Account::get_balance() const {
    return balance;
} 

void Account::print(std::ostream &os) const {
    os << "[Account: " << this->name << ": " << this->balance << " ]";
}


Savings_Account::Savings_Account(std::string name, double balance, double reward) : Account(name, balance), reward(reward) {}

bool Savings_Account::deposit(double amount)  {
    amount = amount + reward;
    transaction_history.emplace_back("Savings Account Deposit (with reward): " + std::to_string(amount));
    return Account::deposit(amount);
}

bool Savings_Account::withdraw(double amount) {
    transaction_history.emplace_back("Savings Account Withdraw: " + std::to_string(amount));
    return Account::withdraw(amount);
}

bool Savings_Account::transfer(Account &to_account, double amount) {
    if(amount < 0) {
        return false;
    }
    return Account::transfer(to_account, amount);
}

void Savings_Account::print(std::ostream &os) const {
    os << "[Savings_Account: " << this->name << ": " << this->balance << ", " << this->reward << " ]";
}


Checking_Account::Checking_Account(std::string name, double balance) : Account(name, balance) {}

bool Checking_Account::withdraw(double amount) {
    amount += per_check_fee;
    transaction_history.emplace_back("Checking Account Withdraw (with fee): " + std::to_string(amount));
    return Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount) {
    transaction_history.emplace_back("Checking Account Deposit: " + std::to_string(amount));
    return Account::deposit(amount);
}

bool Checking_Account::transfer(Account &to_account, double amount) {
    double total = amount += per_check_fee;
    if(withdraw(total)) {
        return to_account.deposit(amount);
    }
    return false;
}

void Checking_Account::print(std::ostream &os) const {
    os << "[Checking_Account: " << this->name << ": " << this->balance << " ]";
}


Trust_Account::Trust_Account(std::string name, double balance, double reward) : Savings_Account(name, balance, reward), withdrawals_count{0} {}

bool Trust_Account::deposit(double amount) {
    if(amount >= threshold) {
        amount += def_bonus;
        transaction_history.emplace_back("Trust Account Deposit (with bonus if applicable): " + std::to_string(amount));
    }
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    int count = 0;
    if(amount > balance * max_withdraw_percent || withdrawals_count >= max_withdraw_num) {
        return false;
    }
    else{
        ++withdrawals_count;
        transaction_history.emplace_back("Trust Account Withdraw: " + std::to_string(amount));
        return Savings_Account::withdraw(amount);
    }
}

bool Trust_Account::transfer(Account &to_account, double amount) {
    if(amount > balance * max_withdraw_percent || withdrawals_count >= max_withdraw_num) {
        return false;
    }
    if(Savings_Account::transfer(to_account, amount)) {
        ++withdrawals_count;
        return true;
    }
    return false;
}

void Trust_Account::print(std::ostream &os) const {
    os << "[Trust_Account: " << this->name << ": " << this->balance << ", " << this->reward << ", " << this->withdrawals_count << " ]";
}

