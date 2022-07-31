//
// Created by Lee on 2022/07/30.
//
#include "system.h"

System::System() {
    // get user info using bank api(card_number, PIN)
    db.insert({"93720930", "0000"});
    db.insert({"11111111", "1111"});
    db.insert({"22317189", "2222"});
    db.insert({"26189123", "2323"});

    // get user database information tuple(name, (account1, balance1), (account2,balance2), ....)
    account_info Lee_info = {  std::tuple<std::string, int>("account1", 343),
                            std::tuple<std::string, int>("account2", 100),
                            std::tuple<std::string, int>("account3", 4)};

    account_info Cho_info = { std::tuple<std::string, int>("account1", 343),
                            std::tuple<std::string, int>("account2", 0),
                            std::tuple<std::string, int>("test2", 23) };

    account_info Park_info   = {std::tuple<std::string, int>("test1", 13)};

    account_info Davide_info = {std::tuple<std::string, int>("test1", 123),
                             std::tuple<std::string, int>("test2", 2423)};

    user_db.insert({"93720930", user_info("Lee",     Lee_info)});
    user_db.insert({"11111111", user_info("Cho",     Cho_info)});
    user_db.insert({"22317189", user_info("Park",    Park_info)});
    user_db.insert({"26189123", user_info("Davide",  Davide_info)});
}

System::~System() {

}

bool System::check_card(const std::string &card_number) {
    if(db.find(card_number) != db.end()){
        std::cout << "Find Account" << std::endl;
        card_num = card_number;
        return true;
    }
    else{
        std::cout << "Not Find the Account" << std::endl;
        return false;
    }
}

bool System::check_pin(const std::string &pin_number){
    std::string PIN = db.find(card_num)->second;
    if(PIN == pin_number){
        user_info info = user_db.find(card_num)->second;
        std::string user_name = std::get<0>(info);
        account_info acc_info = std::get<1>(info);
        valid_user = new BankUser(user_name, acc_info);
        return true;
    }
    else{
        return false;
    }
}
