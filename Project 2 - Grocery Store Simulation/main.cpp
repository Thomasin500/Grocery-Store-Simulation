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

	dynamic_queue<int> queue1(4);

	queue1.enqueue(1);
	queue1.enqueue(2);
	queue1.enqueue(3);
	queue1.enqueue(4);
	queue1.enqueue(5);
	
	dynamic_queue<int> queue2;
	queue2.enqueue(9);
	queue2.enqueue(10);
	queue2.enqueue(11);

	queue1.swap(queue1, queue2);

	cout << "Queue 1 : ";

	queue1.display(cout);

	cout << "Queue 2 : ";
	queue2.display(cout);



	queue1.swap(queue1, queue1);
	

	cin.ignore();


	return 0;
}



#endif