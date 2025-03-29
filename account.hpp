#ifndef FILM_HPP
#define FILM_HPP

#include <vector>
#include <string>
#include <iostream>
#include <cstdint>
#include "I_Printable.hpp"


class Account : public I_Printable {
private:
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
    std::vector<std::string> transaction_history;
public:
    Account(std::string = def_name, double balance = def_balance);
    //Account(double balance);
    Account(const Account &other);

    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual bool transfer(Account &to_account, double amount) = 0;
    virtual void print(std::ostream &os) const override;
    void print_transaction_history() const;
    virtual ~Account() = default;

    double get_balance() const;
};

class Savings_Account : public Account {
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_reward = 0.0;
protected:
    double reward;
public:
    Savings_Account(std::string name = def_name, double balance = def_balance, double reward = def_reward);
    //Savings_Account(double balance, double reward);

    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual bool transfer(Account &to_account, double amount) override;
    virtual void print(std::ostream &os) const override;

    virtual ~Savings_Account() = default;
};

class Checking_Account : public Account {
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);

    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual bool transfer(Account &to_account, double amount) override;
    virtual void print(std::ostream &os) const override;

    virtual ~Checking_Account() = default;
};

class Trust_Account : public Savings_Account {
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_reward = 0.0;
    static constexpr double def_bonus = 50.0;
    static constexpr double threshold = 5000.0;
    static constexpr double max_withdraw_percent = 0.2;
    static constexpr double max_withdraw_num = 3;
protected:
    uint8_t withdrawals_count;
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double reward = def_reward);

    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual bool transfer(Account &to_account, double amount) override;
    virtual void print(std::ostream &os) const override;

    virtual ~Trust_Account() = default;
};

#endif