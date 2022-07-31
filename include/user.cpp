//
// Created by Lee on 2022/07/31.
//

#include "user.h"


BankUser::BankUser(const std::string &_user_name, const account_info &_accounts){
    user_name = _user_name;
    for (auto _info : _accounts){
        std::string account_name = std::get<0>(_info);
        int account_balance      = std::get<1>(_info);
        accounts.push_back(Account(account_name, account_balance));
    }
    accounts_size = _accounts.size();
}

const std::string BankUser::get_account_name(const int idx){
    return accounts[idx].get_account_name();
}

Account BankUser::get_account(const int idx){
    return accounts[idx];
}

const int BankUser::get_account_size(){
    return accounts_size;
}
