/*
Author : Team Nirvana
Disc: Customer Class base
*/

#include "Customer.h"

customer::customer()
{
    arrivalTime = 0.0f;
    waitTime = 0.0f;
    transactionTime = 0.0f;
    customerNumber = 0;
}

void customer::setCustomerNumber(int customerID)
{
    customerNumber = customerID;
}

int customer::getCustomerNumber()
{
    return customerNumber;
}

void customer::setArrivalTime(double time)
{
    arrivalTime = time;
}

double customer::getArrivalTime()
{
    return arrivalTime;
}

void customer::setWaitingTime(double time)
{
    waitTime = time;
}

double customer::getWaitingTime()
{
    return waitTime;
}

void customer::setTransactionTime(double time)
{
    transactionTime = time;
}

double customer::getTransactionTime()
{
    return transactionTime;
}
