//
// Created by Lee on 2022/07/30.
//
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include "user.h"

typedef std::vector< std::tuple<std::string, int>> account_info;
typedef std::tuple<std::string, std::vector< std::tuple<std::string, int>>> user_info;

class System {
public:
    System();

    virtual ~System();

    bool check_card(const std::string &card_number);

    bool check_pin(const std::string &pin_number);

    bool check_accounts();

    BankUser *valid_user;

private:
    std::map<std::string, std::string> db;
    std::map<std::string, user_info> user_db;
    std::string card_num;
};


