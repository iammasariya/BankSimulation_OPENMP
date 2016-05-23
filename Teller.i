%module Teller
%{
#include "teller.h"
#include "Customer.h"
#include <time.h>
extern void setTellerID(int id);
extern int getTellerID();
extern bool isAvailable();
extern void serveCustomer(customer cust);
extern bool isOnline();
extern void setStatus(bool status);
extern void setAvailable(bool avail);
extern void custServed();
extern int getCustomerServed();
%}

%include "teller.h"
%include "Customer.h"

extern void setTellerID(int id);
extern int getTellerID();
extern bool isAvailable();
extern void serveCustomer(customer cust);
extern bool isOnline();
extern void setStatus(bool status);
extern void setAvailable(bool avail);
extern void custServed();
extern int getCustomerServed();
