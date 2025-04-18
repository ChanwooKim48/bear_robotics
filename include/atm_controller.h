#pragma once
//atm controller class that handles 


#include <string>
#include <iostream>
#include "database.h"

class ATMController{
public:
    ATMController(Database* db):db(db){}
    ~ATMController(){}

    //main function
    //Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw
    //action_idx (0 = see balance, 1 = deposit, 2 = withdraw), for balanace, amount is ignored
    bool ProcessRun(std::string card_number, int pin_number, int account_idx, int action_idx, int amount=0);

private:
    Database* db;
};