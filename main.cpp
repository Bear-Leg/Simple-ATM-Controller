#include "include/system.h"

int main() {
    System bank_sys;

    std::string card_number = "93720930"; // PIN number : 0000

    // Insert Card------------------------------------------
    std::cout << "Please insert Card" << std::endl;
    if(!bank_sys.check_card(card_number)){ std::cout<<"please put in the another card"; return 0;}

    // Insert PIN Number------------------------------------------
    std::string pin_input;
    int error_cnt = 0;
    while(1){
        if (error_cnt > 2){ std::cout << "Please, Contact Us"; return 0;}

        std::cout << "Please input your PIN number : ";
        std::cin  >> pin_input;
        if (bank_sys.check_pin(pin_input)) { break; }
        else{std::cout << "Wrong PIN NUMBER, Try : " << ++error_cnt <<std::endl;}
    }

    // Select Account------------------------------------------
    int account_input;
    Account *my_account;
    while(1){
        if(bank_sys.valid_user->get_account_size() < 2){ break; }
        std::cout << "=====Your Account member===== " << std::endl;
        for (int i = 0; i < bank_sys.valid_user->get_account_size(); ++i){
            std::string account_name = bank_sys.valid_user->get_account_name(i);
            printf("%d.. %s\n",i+1, account_name.c_str());
        }
        std::cout << "Please Select Account : ";
        std::cin  >> account_input;
        if (account_input > 0 && account_input <5){
            my_account = new Account(bank_sys.valid_user->get_account(account_input -1 ));
            break;
        };
    }

    // Select Menu------------------------------------------
    int input;
    std::cout << "=====The menu===== \n"
              << "1.. display my balance \n"
              << "2.. deposit money into account \n"
              << "3.. withdraw money from account \n"
              << "4.. exit\n"
              << "Enter the number : ";
    std::cin  >> input;

    while(input != 4){
        switch (input) {
            case 1:
                my_account->check_balance();
                break;
            case 2:
                std::cout << "Deposit : How many money you want? " ;
                int deposit_money;
                std::cin >> deposit_money;
                my_account->do_deposit(deposit_money);
                std::cout << "The Deposit was Success" << std::endl;
                my_account->check_balance();
                break;
            case 3:
                std::cout << "Withdraw : How many money you want? " ;
                int withdraw_money;
                std::cin >> withdraw_money;
                my_account->do_withdraw(withdraw_money);
                std::cout << "The Withdraw was Success" <<std::endl;
                my_account->check_balance();
                break;
            case 4:
                std::cout << "ATM service is END" <<std::endl;
                break;
            default: std::cout<< "You input a wrong number, Please again" << std::endl;
                break;
        }
        std::cout<<"Enter choice : ";
        std::cin >> input;
    }
    return 0;
}
