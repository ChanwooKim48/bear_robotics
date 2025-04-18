//main file
#include <string>
#include <iostream>

#include "atm_controller.h"
#include "database.h"


int main(){

    //user 1
    std::string card_number = "1234123412341234";
    int pin_number = 1234;
    std::string account_name = "savings";
    int initial_balance = 500;    


    //data base
    Database db;
    db.AddData(card_number, pin_number, account_name, initial_balance); //input initial data

    //atm controller
    ATMController atm(&db);
    atm.ProcessRun(card_number, pin_number, 0, 0); //check balance
    atm.ProcessRun(card_number, 1233, 0, 0); //wrong pin number
    atm.ProcessRun("123231232", pin_number, 0, 0); //card number doesn't exist
    atm.ProcessRun("123231232", pin_number, 0, 0); //run it again

    atm.ProcessRun(card_number, pin_number, 0, 1, -100); //deposit negative money
    atm.ProcessRun(card_number, pin_number, 0, 1, 100);  //deposit positive money

    atm.ProcessRun(card_number, pin_number, 0, 2, -100); //withdraw negative money
    atm.ProcessRun(card_number, pin_number, 0, 2, 100);  //withdraw positive money

    atm.ProcessRun(card_number, pin_number, 0, 3, 100);  //undefined action

    return 0;
}