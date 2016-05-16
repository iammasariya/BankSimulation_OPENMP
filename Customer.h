/*
Author : Team Nirvana - Pranav and Chirag
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "task.h"

class customer{
public:
    customer();
    task t;

    void setCustomerNumber(int customerID);
    int getCustomerNumber();

    void setArrivalTime(double arrTime);
    double getArrivalTime();

    void setTransactionTime(double time);
    double getTransactionTime();

    void setWaitingTime(double time);
    double getWaitingTime();

private:
    double arrivalTime;
    double waitTime;
    double transactionTime;
    int customerNumber;
};


#endif // CUSTOMER_H
