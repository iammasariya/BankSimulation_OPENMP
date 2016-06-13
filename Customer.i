%module Customer
%{
#include "Customer.h"
#include <time.h>
extern void setCustomerNumber(int customerID);
extern int getCustomerNumber();
extern void setArrivalTime(double time);
extern double getArrivalTime();
extern void setWaitingTime(double time);
extern double getWaitingTime();
extern void setTransactionTime(double time);
extern double getTransactionTime();
%}

%include "Customer.h"
%include "task.h"
extern void setCustomerNumber(int customerID);
extern int getCustomerNumber();
extern void setArrivalTime(double time);
extern double getArrivalTime();
extern void setWaitingTime(double time);
extern double getWaitingTime();
extern void setTransactionTime(double time);
extern double getTransactionTime();
