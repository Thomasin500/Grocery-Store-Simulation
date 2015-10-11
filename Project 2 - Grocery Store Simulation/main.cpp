#ifndef MAIN_CPP
#define MAIN_CPP

///////////////////////////////////
//	Thomas Freeman
//	Data Structures Project 2 - Grocery Store Simulation
///////////////////////////////////

#include "DynamicQueue.h"

#include <iostream>

;using namespace std;

int main() {

	dynamic_queue<int> queue1;

	queue1.enqueue(1);
	queue1.enqueue(2);
	queue1.enqueue(3);
	queue1.enqueue(4);

	queue1.display(cout);

	cin.ignore();


	return 0;
}



#endif