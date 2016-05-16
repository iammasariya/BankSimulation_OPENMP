///*
//Author : Team Nirvana
//Disc: Driver Program
//*/
//#include <iostream>
//#include <time.h>
//#include <random>
//#include <vector>
//#include <queue>
//#include <omp.h>
//#include <boost/format.hpp>
//#include <boost/timer.hpp>
//#include <boost/foreach.hpp>
//#include <dos.h>
//#include "Customer.h"
//
//using namespace std;
//
////boost timer
//boost::timer waitTime;
//boost::timer timer1;
//
////functions prototype
//double proccessCustomer(int selection);
//
//int main()
//{
//	int response = 0;
//	double transact = 0.0f;
//
//	//Create the line the customers stand in
//    queue<customer> bankLineQueue;
//	vector<customer> vecCustomers;
//
//	//Create a customer object to store a current customer in
//	customer customerNow;
//
//	//Set id's and arrival times for each customer
//	for (int i = 1; i <= 50; i++)
//	{
//		//Create all 50 customers setting intial arrival times at 0
//		customer aCustomer;
//		//Add 50 customers to the queue
//		waitTime.restart();
//		aCustomer.setArrivalTime(0.0f);
//		aCustomer.setCustomerNumber(i);
//		bankLineQueue.push(aCustomer);
//	}
//
//	//use OpenMp threading
//	#pragma omp parallel for ordered
//	for (int n = 1; n <= 5; n++)
//	{
//		//create a ordered list
//		#pragma omp ordered
//		{
//			//Store the customer in a temp container
//			customerNow = bankLineQueue.front();
//			//Remove the customer from the queue
//			bankLineQueue.pop();
//			//Get the elapsed waiting time
//			double elapsed = waitTime.elapsed();
//			//Set the waiting time
//			customerNow.setWaitingTime(elapsed);
//
//			srand ( time(NULL) );
//			response = rand() % 5 + 1;
//			//pass the response to the customer proccess function
//			transact = proccessCustomer(response);
//			customerNow.setTransactionTime(transact);
//			vecCustomers.push_back(customerNow);
//
//			//cout << customerNow.getTransactionTime() << endl;
//			//cout << customerNow.getCustomerNumber() << endl;
//			//cout << customerNow.getWaitingTime() << endl;
//			//cout << omp_get_num_threads() << endl;
//		}
//	}
//	vector<customer>::iterator it;
//
//	for (it = vecCustomers.begin(); it < vecCustomers.end(); it++)
//	{
//		cout << endl;
//		cout << "Customer ID " << it->getCustomerNumber() << endl;
//		cout << "Customer arrival time " << it->getArrivalTime() << endl;
//		cout << "Customer line wait time " << it->getWaitingTime() << endl;
//		cout << "Customer transaction time " << it->getTransactionTime() << endl << endl;
//	}
//
//	system("pause");
//	return 0;
//}
//
//double proccessCustomer(int selection)
//{
//	double time = 0;
//	timer1.restart();
//	switch(selection)
//	{
//		case 1:
//			Sleep(5000);
//			cout << "selection 1" << endl;
//			break;
//		case 2:
//			Sleep(6000);
//			cout << "selection 2" << endl;
//			break;
//		case 3:
//			Sleep(8000);
//			cout << "selection 3" << endl;
//			break;
//		case 4:
//			Sleep(4000);
//			cout << "selection 4" << endl;
//			break;
//		case 5:
//			Sleep(5000);
//			break;
//			cout << "selection 5" << endl;
//		default:
//			cout << "invalid value";
//			break;
//	}
//	time = timer1.elapsed();
//	return time;
//}
