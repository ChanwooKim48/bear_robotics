#include "database.h"
#include <iostream>

bool Database::AddData(std::string card_number, int pin_number, std::string account_name, int balance){
    //return false if card already exists
    if(map.find(card_number) != map.end()){
        std::cout<<"[Error in AddData] cannot add same card number ("<<card_number<<") twice! "<<std::endl;
        return false;
    }

    if(balance < 0){
        std::cout<<"[Error in AddData] you cannot have initial balance of " << balance <<"! negative balance is not allowed "<<std::endl;
        return false; 
    }

    if(pin_number < 0 || pin_number > 9999){
        std::cout<<"[Error in AddData] pin number " << pin_number<<" is not allowed! must be 4 digit integer! "<<std::endl;
        return false;
    }
    
    std::cout<<"successfully added card number "<< card_number <<" with balance "<<balance<<std::endl;
    map[card_number] = {card_number, pin_number, account_name, balance};
    return true;
}

//return pointer to user data
UserData* Database::GetData(std::string card_number){
    //return false if card doesn't exist
    if(map.find(card_number) == map.end()){
        std::cout<<"[Error in GetData] card number ("<<card_number<<") does not exist! "<<std::endl;
        return nullptr;
    }

    return &map[card_number];
}