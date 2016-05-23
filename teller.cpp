#include "teller.h"
#include "Customer.h"
#include <time.h>

teller::teller()
{
    available = false;
    status = false;
    tellerID = 0;
    customerServed = 0;
    c;
}

    void teller::setTellerID(int id){
        tellerID = id;
    }
    int teller::getTellerID()
    {
        return tellerID;
    }

    bool teller::isAvailable(){
        return available;
    }

    void teller::serveCustomer(customer cust){
        c = cust;
        available = false;
    }

    bool teller::isOnline(){
        return status;
    }

    void teller::setStatus(bool status)
    {
        this->status = status;
    }

    void teller::setAvailable(bool avail){
        available = avail;
    }

    void teller::custServed()
    {
        this->customerServed++;
    }

    int teller::getCustomerServed()
    {
        return customerServed;
    }
