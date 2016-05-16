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

int main()
{
    int nthreads;
    omp_set_num_threads(NUM_THREADS);

    //thread first(customerPop);
    //thread second(processCust);

    BankQueue<customer> bankLineQueue;
    vector<customer> vecCust;
    vector<teller> vecTeller;
    customer custNow;
    teller telArray[NUM_THREADS];
    vector<teller>::iterator it;

    for(int i=0;i<5;i++){
        teller tel;
        tel.setAvailable(true);
        tel.setTellerID(i);
        telArray[i] = tel;
    }

    for(int i = 0;i<100;i+=1)
    {
        customer simCustomer;
        waitTime.restart();
        simCustomer.setArrivalTime(0.0f);
        simCustomer.setCustomerNumber(i);
        simCustomer.t.setCheck(true);
        bankLineQueue.Enqueue(simCustomer);
        std::cout<<"custNum: "<<simCustomer.getCustomerNumber()<<endl;
     }

    nthreads = omp_get_max_threads();
    #pragma omp parallel
    {
        for(int i=0;i<omp_get_max_threads();i++)
        {

                int id = omp_get_thread_num();
               // printf("Thread number: %d\n",id);
               teller curTel = telArray[id];
               #pragma omp critical
               {
                    while(bankLineQueue.ElemNum()>0)
                    {
                        custNow = bankLineQueue.Dequeue();
                        double elapsed = waitTime.elapsed();
                        custNow.setWaitingTime(elapsed);
                        printf("teller %d served customer %d\n",curTel.getTellerID(),custNow.getCustomerNumber());
                        proccessCustomer(curTel.getTellerID());
                    }

               }

        }
    }
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
