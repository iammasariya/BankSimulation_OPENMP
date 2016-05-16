#include "task.h"
#include <time.h>

task::task()
{
    check = false;
    cash = false;
    inquiry = false;
    deposit = false;
    withdraw = false;
    amount = 0.0f;
    processingTime = 0.0f;
}

    bool task::isCheck(){
        return check;
    }

    void task::setCheck(bool flag){
        check = flag;
    }

    bool task::isCash(){
        return cash;
    }
    void task::setCash(bool flag){
        cash = flag;
    }

    bool task::isInquiry(){
        return inquiry;
    }

    void task::setInquiry(bool flag){
        inquiry = flag;
    }

    bool task::isDeposit(){
        return deposit;
    }

    void task::setDeposit(bool flag){
        deposit = flag;
    }

    bool task::isWithdraw(){
        return withdraw;
    }
    void task::setWithdraw(bool flag){
        withdraw = flag;
    }

    void task::setProcessingTime(double time){
        processingTime = time;
    }

    double task::getProcessingTime(){
        return processingTime;
    }

    void task::setAmount(double amt){
        amount = amt;
    }

    double task::getAmount(){
        return amount;
    }
