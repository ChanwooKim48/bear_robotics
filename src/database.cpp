#include "database.h"

bool Database::AddData(std::string card_number, int pin_number, std::string account_name, int balance){
    //return false if card already exists
    if(map.find(card_number) != map.end()){
        return false;
    }
    
    map[card_number] = {card_number, pin_number, account_name, balance};
    return true;
}

//return pointer to user data
UserData* Database::GetData(std::string card_number){
    //return false if card doesn't exist
    if(map.find(card_number) == map.end()){
        return nullptr;
    }

    return &map[card_number];
}