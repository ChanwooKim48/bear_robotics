#pragma once
//Insert Card => PIN number => Select Account => See Balance/Deposit/Withdra

//database class
//keep users data

//map card number : account

#include <string>
#include <unordered_map>
#include "userdata.h"

class Database{
public:
    Database(){};
    ~Database(){};

    //add user data
    bool AddData(std::string card_number, int pin_number, std::string account_name, int balance);

    //return pointer to user data
    UserData* GetData(std::string card_number);

private:
    //card number (int) to UserAccount
    std::unordered_map<std::string, UserData> map;


};