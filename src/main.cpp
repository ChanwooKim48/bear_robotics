//main file
#include <string>
#include <iostream>

#include "atm_controller.h"
#include "database.h"

//test
struct User{
    User(std::string card_number, int pin_number, std::string account_name,int initial_balance):
    card_number(card_number), pin_number(pin_number), account_name(account_name), initial_balance(initial_balance){}
    
    std::string card_number;
    int pin_number;
    std::string account_name;
    int initial_balance;
};


int main(){
    bool pass = true;
    bool test = false;

    User user1("1111111111111111", 1234, "savings", 500);  //correct
    User user2("2222222222222222", 1111, "savings", -500); //wrong cannot have negative initial deposit
    User user3("3333333333333333", 43122, "savings", 500); //wrong pin number must be 4 digits
    User user4("4444444444444444", 1234, "checking", 0); //correct

    //data base
    Database db;
    test = db.AddData(user1.card_number, user1.pin_number, user1.account_name, user1.initial_balance); //add user1
    pass = pass || (test == true); //expects true

    test = db.AddData(user1.card_number, user1.pin_number, user1.account_name, user1.initial_balance); //add same user again -> error
    pass = pass || (test == false); //expects false

    test = db.AddData(user2.card_number, user2.pin_number, user2.account_name, user2.initial_balance); //add user2 -> error
    pass = pass || (test == false); //expects false

    test = db.AddData(user3.card_number, user3.pin_number, user3.account_name, user3.initial_balance); //add user3 -> error
    pass = pass || (test == false); //expects false

    test = db.AddData(user4.card_number, user4.pin_number, user4.account_name, user4.initial_balance); //add user4
    pass = pass || (test == true); //expects true

    //atm controller
    ATMController atm(&db);
    
    //wrong credit card number
    test = atm.ProcessRun(user2.card_number, user2.pin_number, 0, 0); //user2 doesn't exist -> error
    pass = pass || (test == false); //expects false

    //wrong pin number
    test = atm.ProcessRun(user1.card_number, 1233, 0, 0); //user1 forgets pin number -> error
    pass = pass || (test == false); //expects false

    //check balance
    test = atm.ProcessRun(user1.card_number, user1.pin_number, 0, 0); //user1 check balance
    pass = pass || (test == true); //expects true

    test = atm.ProcessRun(user4.card_number, user4.pin_number, 0, 0, 500); //user4 check balance with random amount number
    pass = pass || (test == true); //expects true

    //deposit
    test = atm.ProcessRun(user1.card_number, user1.pin_number, 0, 1, 500); //user1 deposits 500 dollars
    pass = pass || (test == true); //expects true

    test = atm.ProcessRun(user1.card_number, user1.pin_number, 0, 1, -500); //user1 deposits -500 dollars
    pass = pass || (test == false); //expects false

    test = atm.ProcessRun(user4.card_number, user4.pin_number, 0, 1, 0); //user4 deposits 0 dollars -> 0 dollar deposit is not allowed too
    pass = pass || (test == false); //expects false

    //withdrawal
    test = atm.ProcessRun(user1.card_number, user1.pin_number, 0, 2, 1500); //user1 withdraw 1500 dollars -> error not enough deposit
    pass = pass || (test == false); //expects false

    test = atm.ProcessRun(user1.card_number, user1.pin_number, 0, 2, 777); //user1 withdraw 777 dollars
    pass = pass || (test == true); //expects true

    test = atm.ProcessRun(user1.card_number, user1.pin_number, 0, 2, -777); //user1 withdraw -777 dollars
    pass = pass || (test == false); //expects false


    std::cout<<"final pass result: " << pass << std::endl;
    return 0;
}