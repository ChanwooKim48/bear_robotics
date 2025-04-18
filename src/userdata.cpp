#include "userdata.h"


//show accounts
std::vector<std::string> UserData::GetAccountNames(){
    return accounts;
}

//returns balance
//return -1 if idx doesn't exist
//show balance of the index idx if successful
int UserData::ReturnBalance(int idx){
    if(idx<0 || idx >= balances.size())
        return -1;
    return balances[idx];
}

//deposit
//return -1 if idx doesn't exist
//return balance after deposit if successful 
int UserData::Deposit(int idx, int dollar_amount){
    if(idx<0 || idx >= balances.size())
        return -1;
    balances[idx] += dollar_amount;
    return balances[idx];
}

//withdraw
//return -1 if idx doesn't exist
//return -2 if balance is less than requested withdrawal amount
//return remaining balance if successful
int UserData::Withdraw(int idx, int dollar_amount){
    if(idx<0 || idx >= balances.size())
        return -1;
    //not enough balance
    if(balances[idx] < dollar_amount){
        return -2;
    }
    
    balances[idx] -= dollar_amount;
    return balances[idx];
}

//check if pin is correct
bool UserData::Checkpin(int pin_to_check){
    return (pin==pin_to_check);
}