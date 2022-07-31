//
// Created by Lee on 2022/07/31.
//
#include <iostream>
#include <vector>
#include "account.h"

typedef std::vector< std::tuple<std::string, int>> account_info;
typedef std::tuple<std::string, std::vector< std::tuple<std::string, int>>> user_info;

class BankUser {
public:
    BankUser(const std::string &user_name, const account_info &accounts);

    const int get_account_size();

    const std::string get_account_name(int idx);

    Account get_account(int idx);

private:
    std::string user_name;
    std::vector<Account> accounts;
    int accounts_size;
};


