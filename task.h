/*
Author : Team Nirvana - Pranav and Chirag
*/

#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED
class task{
public:
    task();
    bool isCheck();
    void setCheck(bool flag);

    bool isCash();
    void setCash(bool flag);

    bool isInquiry();
    void setInquiry(bool flag);

    bool isDeposit();
    void setDeposit(bool flag);

    bool isWithdraw();
    void setWithdraw(bool flag);

    void setProcessingTime(double time);
    double getProcessingTime();

    void setAmount(double amt);
    double getAmount();

private:
    bool check;
    bool cash;
    bool inquiry;
    bool deposit;
    bool withdraw;
    double amount;
    double processingTime;
};


#endif // TASK_H_INCLUDED
