/*
Author : Team Nirvana - Pranav and Chirag
*/
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
#include "Customer.h"
#include "task.h"
#include "teller.h"
#include "CustomerQueue.h"
#include <thread>

#define NUM_THREADS 3

using namespace std;

boost::timer waitTime;
boost::timer timer1;

int ledgerDep = 0;
int ledgerWit = 0;
int totalLedger = 10000;

void serveCustomer(customer &cust, teller &tel);

int main()
{
    omp_set_num_threads(NUM_THREADS);

    BankQueue<customer> bankLineQueue;
    vector<customer> vecCust;
    teller telArray[NUM_THREADS];

    for(int i=0;i<omp_get_max_threads();i++){
        teller tel;
        tel.setAvailable(true);
        tel.setStatus(true);
        tel.setTellerID(i);
        telArray[i] = tel;
    }

    /* Reading from the CSV file*/
	std::ifstream  data("customer.csv");
    int custNum = 1;
	std::string line;
    while(std::getline(data,line))
	{
		std::stringstream  lineStream(line);
		std::string        cell;
		customer simCustomer;
        waitTime.restart();
        simCustomer.setCustomerNumber(custNum);
        custNum++;
        simCustomer.setArrivalTime(0.0f);
    while(std::getline(lineStream,cell,','))
    {
        int number = 0;
		std::istringstream iss(cell);
		if (!(iss >> number).fail())
        {
		  	simCustomer.t.setAmount(number);
        }
        else
        {
			if(cell == "inquiry")
			{
				simCustomer.t.setInquiry(true);
			}
			else if(cell == "deposit")
			{
				simCustomer.t.setDeposit(true);
			}
			else if(cell == "check")
			{
				simCustomer.t.setCheck(true);
			}
			else
			{
				simCustomer.t.setWithdraw(true);
			}
        }

    }
        bankLineQueue.Enqueue(simCustomer);
        std::cout<<"custNum: "<<simCustomer.getCustomerNumber()<<" "<<simCustomer.t.getAmount()<<" "<< cell<<endl;
    }

    /*Parallel block*/
    #pragma omp parallel
    {   customer custNow;
        int id = omp_get_thread_num();
        #pragma omp for
        for(int i=id;i< omp_get_max_threads();i++)
        {
                teller curTel = telArray[i];
                while(bankLineQueue.ElemNum()>0 && curTel.isAvailable())
                {
                        custNow = bankLineQueue.Dequeue();
                        double elapsed = waitTime.elapsed();
                        custNow.setWaitingTime(elapsed);
                        serveCustomer(custNow,curTel);
                        vecCust.push_back(custNow);
                }
        }
    }
    std::cout<<ledgerDep<<" "<<ledgerWit<<" "<<totalLedger<<endl;
}

void serveCustomer(customer &cust, teller &tel)
{
    double time;
    tel.setAvailable(false);
    timer1.restart();
    if(cust.t.isCheck())
    {
        usleep(5000);
        time = timer1.elapsed();
        cust.setTransactionTime(time);
        printf("Customer %d has been served by teller %d for check processing \n",cust.getCustomerNumber(),tel.getTellerID());

    }
    if(cust.t.isInquiry())
    {
        usleep(1000);
        time = timer1.elapsed();
        cust.setTransactionTime(time);
        printf("Customer %d has been served by teller %d for inquiry processing \n",cust.getCustomerNumber(),tel.getTellerID());

    }
    if(cust.t.isDeposit())
    {
        usleep(6000);
        time = timer1.elapsed();
        cust.setTransactionTime(time);
        printf("Customer %d has been served by teller %d for deposit processing \n",cust.getCustomerNumber(),tel.getTellerID());

    }
    if(cust.t.isWithdraw())
    {
        usleep(3000);
        time = timer1.elapsed();
        cust.setTransactionTime(time);
        printf("Customer %d has been served by teller %d for withdraw processing \n",cust.getCustomerNumber(),tel.getTellerID());

    }
    tel.custServed();
    tel.setAvailable(true);
    #pragma omp critical
    {
        if(cust.t.isDeposit())
        {
            ledgerDep+=cust.t.getAmount();
            totalLedger+=cust.t.getAmount();
        }
        if(cust.t.isWithdraw())
        {
            ledgerWit+=cust.t.getAmount();
            totalLedger-=cust.t.getAmount();
        }
    }
}
