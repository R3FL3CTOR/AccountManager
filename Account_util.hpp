#include <vector>
#include "I_Printable.hpp"
#include "film.hpp"

void display(const std::vector<Account *> &accounts);
void deposit(std::vector<Account *> &accounts, double amount);
void withdraw(std::vector<Account *> &accounts, double amount);
void transfer_to_account(Account &account, Account &to_acc, double amount);
void transfer_to_all(std::vector<Account *> &account, Account &to_acc, double amount);