#include <iostream>

class Account{
public:
    Account(const std::string &account_name, int balance);

    ~Account();

    void do_withdraw(const int value);

    void do_deposit(const int value);

    void check_balance();

    std::string get_account_name();

private:
    std::string account_name;
    int balance;
};
