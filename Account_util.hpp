#include <vector>
#include "I_Printable.hpp"
#include "film.hpp"

void display(const std::vector<Account *> &accounts);
void deposit(std::vector<Account *> &accounts, double amount);
void withdraw(std::vector<Account *> &accounts, double amount);
void transfer(std::vector<Account *> &accounts, Account &acc, double amount);