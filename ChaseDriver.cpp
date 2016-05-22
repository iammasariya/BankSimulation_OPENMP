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

#define NUM_THREADS 5

using namespace std;

//boost timer;
boost::timer waitTime;
boost::timer timer1;

double proccessCustomer(int selection);
void serveCustomer(customer &cust, teller &tel);

int main()
{
    int nthreads;
    omp_set_num_threads(NUM_THREADS);

    //thread first(customerPop);
    //thread second(processCust);

    BankQueue<customer> bankLineQueue;
    vector<customer> vecCust;
    vector<teller> vecTeller;
    teller telArray[NUM_THREADS];
    vector<teller>::iterator it;

    for(int i=0;i<5;i++){
        teller tel;
        tel.setAvailable(true);
        tel.setStatus(true);
        tel.setTellerID(i);
        telArray[i] = tel;
    }
	std::ifstream  data("customer.csv");

	std::string line;
    while(std::getline(data,line))
	{
		std::stringstream  lineStream(line);
		std::string        cell;
		customer simCustomer;
        waitTime.restart();
        simCustomer.setArrivalTime(0.0f);
    while(std::getline(lineStream,cell,','))
    {
        int number = 0;
		std::istringstream iss(cell);
		if (!(iss >> number).fail())
        {
		  	simCustomer.setCustomerNumber(number);
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
        std::cout<<"custNum: "<<simCustomer.getCustomerNumber()<<" "<< cell<<endl;
    }

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
                        //printf("teller %d served customer %d\n",curTel.getTellerID(),custNow.getCustomerNumber());
                        //proccessCustomer(curTel.getTellerID());
                        serveCustomer(custNow,curTel);
                }
        }
    }
}

void serveCustomer(customer &cust, teller &tel)
{
    tel.setAvailable(false);
    if(cust.t.isCheck())
    {
        printf("Customer %d has been served by teller %d for check processing \n",cust.getCustomerNumber(),tel.getTellerID());
        usleep(500000);
    }
    if(cust.t.isInquiry())
    {
        printf("Customer %d has been served by teller %d for inquiry processing \n",cust.getCustomerNumber(),tel.getTellerID());
        usleep(100000);
    }
    if(cust.t.isDeposit())
    {
        printf("Customer %d has been served by teller %d for deposit processing \n",cust.getCustomerNumber(),tel.getTellerID());
        usleep(600000);
    }
    if(cust.t.isWithdraw())
    {
        printf("Customer %d has been served by teller %d for withdraw processing \n",cust.getCustomerNumber(),tel.getTellerID());
        usleep(300000);
    }
    tel.setAvailable(true);
}

double proccessCustomer(int selection)
{
	double time = 0;
	timer1.restart();
	switch(selection)
	{
		case 0:
			usleep(500000);
			cout << "selection 1" << endl;
			break;
		case 1:
			usleep(600000);
			cout << "selection 2" << endl;
			break;
		case 2:
			usleep(800000);
			cout << "selection 3" << endl;
			break;
		case 3:
			usleep(400000);
			cout << "selection 4" << endl;
			break;
		case 4:
			usleep(300000);
			cout << "selection 5" << endl;
			break;
		default:
			cout << "invalid value"<<endl;
			break;
	}
	time = timer1.elapsed();
	return time;
}
