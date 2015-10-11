#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#include <iostream>

using namespace std;


template <class QueueElement>
class dynamic_queue {

public:

	//default constructor
	dynamic_queue() {
		
		itail = 0;
		ihead = 0;
		initial_capacity = 3;	//temp
		array_capacity = 3;
		myArray = new QueueElement [initial_capacity];
		memset(myArray, 0, initial_capacity);
	}

	//copy constructor
	dynamic_queue(const dynamic_queue&) {}

	//default destructor
	~dynamic_queue() {}

	QueueElement * getHead() {}

	//method to return the size of the dynamic array
	int getSize() const {
	
		return array_size;
	}

	//returns a boolean staing whether the dynamic array is empty or not
	bool isEmpty() const {
	
		if (array_size == 0) {

			return true;
		}
		else {
		
			return false;
		}
	}

	bool isFull() {
	
		if (getSize() == array_capacity) return true;
		else return false;	
	}

	//creates a new array with double the capacity of the current array and copies each element into the new array
	void increaseSize() {
	
		QueueElement * newArray;
		newArray = new QueueElement [getCapacity() * 2];

		//copy each element of the old array
		for (int i = 0; i < getSize(); i++) {

			newArray[i] = myArray[i];
		}

		//delete any dynamically created elements of the old array
		/*for (int i = 0; i < getSize(); i++) {

			delete myArray[i];
		}*/

		//point myArray variable to the newly created array
		myArray = newArray;	

		array_capacity *= 2;

		
	};

	void decreaseSize() {		
	
		//cannot reduce the capacity of the array to below the intial capacity
		if ((array_capacity / 2) < initial_capacity) {

			cout << "cannot reduce capacity below intial capacity" << endl;
			return;
		}


		QueueElement * newArray;
		newArray = new QueueElement[array_capacity / 2];

		for (int i = 0; i < getSize(); i++) {
		
			newArray[i] = myArray[i];		
		}	

		//delete any dynamically created elements of the old array
		/*for (int i = 0; i < getSize(); i++) {

		delete myArray[i];
		}*/

		//point myArray variable to the newly created array
		myArray = newArray;

		array_capacity /= 2;		
	};


	//returns the capacity of the dynamic array as an int
	int getCapacity() {		

		return array_capacity;
	}

	void display(ostream &out) const {
		
		cout << endl << "The current contents of the list are: " << endl << endl;

		int i = 0;
		for (i = 0; i < getSize(); i++) {
		
			cout << myArray[i] << endl;
		}

		if (i == 0) {
		
			cout << "Array is Empty" << endl;
		
		}	
	}


	void enqueue(const QueueElement &value) {

		if (isFull() != true) {

			itail++;
			myArray[itail - 1 % getCapacity()] = value;					
			array_size++;
		}
		else {
		
			increaseSize();
			enqueue(value);		
		}
	}


	void dequeue() {
	
		--ihead;
		--array_size;

		//make sure the size of the array can never be less than 0
		if (array_size <= 0) array_size = 0;

		if (getSize() <= (.25 * array_capacity)) {
		
			decreaseSize();		
		}	
	}


	bool swap(dynamic_queue &a, dynamic_queue &b) {
	
		QueueElement *temp = NULL;

		if (temp) {

			temp = a;
			a = b;
			b = temp;

			return true;
		}
		else {

			return false;
		}
	
	}


	void clear() {
	
		
	}
	
	const dynamic_queue& operator=(const dynamic_queue&) {}


	friend ostream& operator<< <> (ostream&, const dynamic_queue<dynamic_queue>&) {}

private:
	/***** Data Members *****/
	int ihead;
	int	itail;
	int initial_capacity; // initial capacity of array
	int array_capacity; // current capacity of the array
	int array_size; // current size of queue stored in array
	QueueElement *myArray; // pointer to dynamically allocated array
}

#endif
