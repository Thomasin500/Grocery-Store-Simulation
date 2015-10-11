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
	queue1.enqueue(5);
	queue1.enqueue(6); // should be full
	
	
	cout << queue1.getSize() << endl;


	queue1.dequeue();
	queue1.dequeue();
	queue1.dequeue();
	queue1.dequeue(); 
	queue1.dequeue(); // should have to resize here

	
	cout << queue1.getSize() << endl;
	

	queue1.display(cout);

	

	cin.ignore();


	return 0;
}



#endif