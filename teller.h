/*
Author : Team Nirvana - Pranav and Chirag
*/

#include "Customer.h"
#ifndef TELLER_H_INCLUDED
#define TELLER_H_INCLUDED

class teller{
public:
    teller();

    void setTellerID(int id);
    int getTellerID();

    bool isAvailable(); // teller is free to serve customer

    void serveCustomer(customer c);

    bool isOnline(); //teller is available at window

    void setStatus(bool status);
    void setAvailable(bool avail);

private:
    bool available;
    bool status;
    int tellerID;
    customer c;
};

#endif // TELLER_H_INCLUDED
