/*
Author : Team Nirvana - Pranav and Chirag
*/

class task{
public:
    task(){};
     bool isCheck(){
        return check;
    }

    void setCheck(bool flag){
        check = flag;
    }

    bool isInquiry(){
        return inquiry;
    }

    void setInquiry(bool flag){
        inquiry = flag;
    }

    bool isDeposit(){
        return deposit;
    }

    void setDeposit(bool flag){
        deposit = flag;
    }

    bool isWithdraw(){
        return withdraw;
    }
    void setWithdraw(bool flag){
        withdraw = flag;
    }

    void setAmount(double amt){
        amount = amt;
    }

    double getAmount(){
        return amount;
    }

private:
    bool check = false;
    bool inquiry = false;
    bool deposit = false;
    bool withdraw = false;
    double amount = 0.0f;
};