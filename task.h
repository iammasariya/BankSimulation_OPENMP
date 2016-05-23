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

    bool isInquiry();
    void setInquiry(bool flag);

    bool isDeposit();
    void setDeposit(bool flag);

    bool isWithdraw();
    void setWithdraw(bool flag);

    void setAmount(double amt);
    double getAmount();

private:
    bool check;
    bool inquiry;
    bool deposit;
    bool withdraw;
    double amount;
};


#endif // TASK_H_INCLUDED
