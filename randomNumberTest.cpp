#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
     srand(time(NULL));
     cout <<  rand() % 10 + 1 << endl;  //number between 1 and 10

     return 0;
}
