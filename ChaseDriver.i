/*
Author : Team Nirvana - Pranav and Chirag
interface file for swig
*/
%module ChaseDriver
%{
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <random>
#include <unistd.h>
#include <vector>
#include <omp.h>
#include <sstream>
#include <fstream>
#include <string>
#include <boost/format.hpp>
#include <boost/timer.hpp>
#include <boost/foreach.hpp>
#include "teller.h"
#include "Customer.h"
#include "CustomerQueue.h"
#include <thread>
#define NUM_THREADS 3
 
/*variable & function declarations*/
extern int ledgerDep;
extern int ledgerWit;
extern int totalLedger;
extern int main();
extern void run();
extern void serveCustomer(customer* cust, teller* tel);

%}

#define NUM_THREADS 3
%include <std_string.i>
%include "teller.h"
%include "Customer.h"
%include "CustomerQueue.h"
extern int ledgerDep;
extern int ledgerWit;
extern int totalLedger;
extern int main();
extern void run();
extern void serveCustomer(customer* cust, teller* tel);

