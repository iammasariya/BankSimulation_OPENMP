/*
Author : Team Nirvana - Pranav and Chirag
*/

#include <iostream>
#include <time.h>
//#include <random>
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
		    if (!(iss >> number).fail()) {
		    	simCustomer.setCustomerNumber(number);
		    }
		    else{
			if(cell == "inquiry"){
				simCustomer.t.setInquiry(true);	
			}
			else if(cell == "deposit"){
				simCustomer.t.setDeposit(true);
			}
			else if(cell == "check"){
				simCustomer.t.setCheck(true);
			}
			else{
				simCustomer.t.setWithdraw(true);
			}
		    }

		}
                bankLineQueue.Enqueue(simCustomer);
                std::cout<<"custNum: "<<simCustomer.getCustomerNumber()<<" "<< cell<<endl;
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
