#include "atm_controller.h"


bool ATMController::ProcessRun(std::string card_number, int pin_number, int account_idx, int action_idx, int amount){
    //check if card number is in database
    UserData* userdata = db->GetData(card_number);
    if(userdata == nullptr){
        std::cout<<"card number is not in database! "<<std::endl;
        return false;
    }

    //check pin
    bool b_pin = userdata->Checkpin(pin_number);
    if(!b_pin){
        std::cout<<"pin is not correct! "<<std::endl;
        return false;
    }

    //pick account
    std::vector<std::string> account_names = userdata->GetAccountNames();
    bool b_account = (account_idx >= 0) && (account_idx < account_names.size());
    if(!b_account){
        std::cout<<"account doesn't exist! "<<std::endl;
        return false;
    }

    //do stuff
    if(action_idx == 0){
        //balance
        int balance = userdata->ReturnBalance(account_idx);
        std::cout<<"your balance is " << balance << " dollars! " << std::endl;
        return true;
    }
    else if(action_idx == 1){
        //deposit
        if(amount > 0){
            int balance_after = userdata->Deposit(account_idx, amount);
            std::cout<<"successfully deposited " << amount << " dollars! " << std::endl;
            std::cout<<"balance after deposit is " << balance_after << " dollars! " << std::endl;
            return true;
        }
        else{
            std::cout<<"cannot deposit " << amount <<" dollars! (negative deposits aren't allowed)"<<std::endl;
            return false;
        }
    }
    else if(action_idx == 2){
        //withdraw
        if(amount > 0){
            int balance_after = userdata->Withdraw(account_idx, amount);
            std::cout<<"successfully withdraw " << amount << " dollars! " << std::endl;
            std::cout<<"balance after withdraw is " << balance_after << " dollars! " << std::endl;
            return true;
        }
        else{
            std::cout<<"cannot withdraw " << amount <<" dollars! (negative withdrawals aren't allowed)"<<std::endl;
            return false;
        }
    }
    else{
        std::cout<<"undefined action! "<<std::endl;
        return false;
    }

    return false;
}