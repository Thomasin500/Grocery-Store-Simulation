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

	queue1.dequeue();

	queue1.enqueue(3);
	queue1.enqueue(4);

	queue1.dequeue();
	queue1.dequeue();

	queue1.enqueue(5);
	queue1.enqueue(6);

	queue1.dequeue();

	queue1.enqueue(5);
	queue1.enqueue(6);

	queue1.enqueue(9);
	queue1.enqueue(15);
	queue1.enqueue(62);

	queue1.dequeue();
	queue1.dequeue();


	cout << "****" << endl;

	queue1.display(cout);

	queue1.dequeue();
	queue1.dequeue();
	queue1.dequeue();
	queue1.dequeue();

	queue1.enqueue(9);
	queue1.enqueue(15);

	queue1.display(cout);
	
	cout << endl <<  "head and tail : " << endl;
	cout << queue1.getHead() << endl;
	cout << queue1.getTail() << endl;



	/*
	dynamic_queue<int> queue2;
	queue2.enqueue(9);
	queue2.enqueue(10);
	queue2.enqueue(11);

	//queue1 = queue2;

	queue1.display(cout);

	queue2.enqueue(99);

	queue1.display(cout);

	*/

	cin.ignore();


	return 0;
}



#endif