//
// Created by Lee on 2022/07/30.
//
#include "account.h"

Account::Account(const std::string & _account_name, const int _balance){
    account_name = _account_name;
    balance      = _balance;
}

Account::~Account(){
}

void Account::check_balance() {
    std::cout<<"Your Account's Balance is "<<balance<<std::endl;
}

void Account::do_deposit(const int value) {
    balance += value;
}

void Account::do_withdraw(const int value) {
    balance -= value;
}

std::string Account::get_account_name(){
    return account_name;
}