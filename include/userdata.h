#pragma once
//user account class
//keep individual record of a user

#include <vector>
#include <string>

//Insert Card => PIN number => Select Account => See Balance/Deposit/Withdra
class UserData{
public:
    UserData(std::string card_number, int pin, std::string account_name = "default", int balance = 0)
    : card_number(card_number), pin(pin){
        accounts.push_back(account_name);
        balances.push_back(balance);
    }
    UserData(){}
    ~UserData(){}
    
    //show accounts
    std::vector<std::string> ShowAccounts();

    //returns balance
    //return -1 if idx doesn't exist
    //show balance of the index idx if successful
    int ReturnBalance(int idx);

    //deposit
    //return -1 if idx doesn't exist
    //return balance after deposit if successful 
    int Deposit(int idx, int dollar_amount);

    //withdraw
    //return -1 if idx doesn't exist
    //return -2 if balance is less than requested withdrawal amount
    //return remaining balance if successful
    int Withdraw(int idx, int dollar_amount);

private:
    std::string card_number;
    int pin;

    std::vector<int> balances;
    std::vector<std::string> accounts;
};