#pragma once
//atm controller class that handles 


#include <string>
#include <iostream>
#include "database.h"

class ATMController{
public:
    ATMController(){}
    ~ATMController(){}

    //main function
    //Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw
    //action_idx (0 = see balance, 1 = deposit, 2 = withdraw), for balanace, amount is ignored
    bool ProcessRun(std::string card_number, int pin_number, int account_idx, int action_idx, int amount){
        //insert card
        bool b_card = InsertCard(card_number);
        if(!b_card){
            std::cout<<"card did not accept! "<<std::endl;
            return false;
        }

        //check pin
        bool b_pin = CheckPin(card_number, pin_number);
        if(!b_pin){
            std::cout<<"pin is not correct! "<<std::endl;
            return false;
        }

        //pick account
        bool b_account = PickAccount(card_number, account_idx);
        if(!b_account){
            std::cout<<"account doesn't exist! "<<std::endl;
            return false;
        }

        //do stuff
        if(action_idx == 0){
            //balance

        }
        else if(action_idx == 1){
            //deposit

        }
        else if(action_idx == 2){
            //withdraw

        }
        else{
            std::cout<<"undefined action! "<<std::endl;
            return false;
        }
        
        return false;
    }

private:
    //return false if card number doesn't exist
    //return true if card number exist
    bool InsertCard(std::string card_number);

    //check if pin is right for the card
    bool CheckPin(std::string card_number, int pin);

    //pick account
    bool PickAccount(std::string card_number, int account_idx);
};