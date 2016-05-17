all:
	g++ -std=c++11  -fopenmp -o main ChaseDriver.cpp Customer.cpp task.cpp teller.cpp
