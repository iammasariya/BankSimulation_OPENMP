/*
Author : Team Nirvana - Pranav and Chirag
*/

#include "task.h"

class customer{
public:
    customer(){};
    task t;

void setCustomerNumber(int customerID)
{
    customerNumber = customerID;
}

int getCustomerNumber()
{
    return customerNumber;
}

void setArrivalTime(double time)
{
    arrivalTime = time;
}

double getArrivalTime()
{
    return arrivalTime;
}

void setWaitingTime(double time)
{
    waitTime = time;
}

double getWaitingTime()
{
    return waitTime;
}

void setTransactionTime(double time)
{
    transactionTime = time;
}

double getTransactionTime()
{
    return transactionTime;
}


private:
    double arrivalTime = 0.0f;
    double waitTime = 0.0f;
    double transactionTime = 0.0f;
    int customerNumber = 0;
};
