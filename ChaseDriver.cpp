/*
Author : Team Nirvana - Pranav and Chirag
*/

#include <iostream>
#include <time.h>
//#include <random>
#include <vector>
#include <omp.h>
#include <boost/format.hpp>
#include <boost/timer.hpp>
#include <boost/foreach.hpp>
#include "Customer.h"
#include "task.h"
#include "teller.h"
#include "CustomerQueue.h"

#define NUM_THREADS 5

using namespace std;

//boost timer;
boost::timer waitTime;
boost::timer timer1;

int main()
{
    omp_set_num_threads(NUM_THREADS);

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
        //vecTeller.push_back(tel);
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

    #pragma omp parallel
    {
        std::cout<<"aaaa: "<<" "<< omp_get_max_threads()<<endl;
        int tid = omp_get_thread_num();
        std::cout<<bankLineQueue.ElemNum()<<endl;
        #pragma omp ordered
        for(int i=tid;i<bankLineQueue.ElemNum();i+=NUM_THREADS)
        {
            std::cout<<tid<<endl;
        }
    }
}
