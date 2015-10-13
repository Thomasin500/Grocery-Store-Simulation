#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#include <iostream>

using namespace std;


template <class QueueElement>
class dynamic_queue {

public:

	//default constructor
	dynamic_queue(int capacity = 10) {
		
		if (capacity <= 0) {
		
			itail = 0;
			ihead = 0;
			initial_capacity = 1;
			array_capacity = 1;
			myArray = new QueueElement[initial_capacity];
		}
		else {

			itail = 0;
			ihead = 0;
			initial_capacity = capacity;
			array_capacity = capacity;
			myArray = new QueueElement[initial_capacity];
		}
	}

	//copy constructor
	dynamic_queue(const dynamic_queue &copyQueue) {	
	
		array_capacity = copyQueue.array_capacity;
		array_size = copyQueue.array_size;

		myArray = new int[array_capacity];

		for (int i = 0; i < array_capacity; i++) {

			myArray[i] = copyQueue.myArray[i];
		}

		ihead = copyQueue.ihead;
		itail = copyQueue.itail;		
	}

	//default destructor
	//TODO if any of the array elements are created dynamically on the heap then each
	//element needs to be explicitly deleted
	~dynamic_queue() {
	
		delete[] myArray;	
	}

	QueueElement getHead() {

		if (array_size != 0) {

			return myArray[ihead % array_capacity];
		}
	}

	QueueElement getTail() {
	
		if (array_size != 0) {

			return myArray[itail % array_capacity];
		}
	}

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

	//creates a new array with double the capacity of the current array and copy each element into the new array
	void increaseSize() {

		QueueElement * newArray;
		newArray = new QueueElement[getCapacity() * 2];

		//copy each element of the old array
		int temp = ihead;
		for (int i = 0; i < getSize(); i++) {

			newArray[i] = myArray[temp];
			temp = (temp + 1) % array_capacity;
		}

		//delete any dynamically created elements of the old array
		delete[] myArray;
		//point myArray variable to the newly created array
		myArray = newArray;

		array_capacity *= 2;
		ihead = 0;
		itail = array_size - 1;
	};

	//creates a new array with half the capacity of the current array and copy each element into the new array
	void decreaseSize() {		
	
		//cannot reduce the capacity of the array to below the intial capacity
		if ((array_capacity / 2) < initial_capacity) {

			cout << "cannot reduce capacity below intial capacity" << endl;
			return;
		}

		QueueElement * newArray;
		newArray = new QueueElement[array_capacity / 2];

		//copy each element of the old array
		int temp = ihead;
		for (int i = 0; i < getSize(); i++) {

			newArray[i] = myArray[temp];
			temp = (temp + 1) % array_capacity;
		}

		//delete any dynamically created elements of the old array
		delete[] myArray;
		//point myArray variable to the newly created array
		myArray = newArray;

		array_capacity /= 2;
		ihead = 0;
		itail = array_size - 1;
	};


	//returns the capacity of the dynamic array as an int
	int getCapacity() {		

		return array_capacity;
	}

	//displays each 'active' element of the array (i.e. ignores elements that are actually in the array, but are not in the queue)
	void display(ostream &out) const {

		cout << endl << "The current contents of the list are: " << endl << endl;

		if (array_size == 0) {

			cout << "Queue is empty" << endl;
			return;
		}
		
		for (int i = 0; i < getSize(); i++) {

			cout << myArray[(i + ihead) % array_capacity] << endl;
		}		
	}

	//adds a new element at the tail of the queue
	void enqueue(const QueueElement &value) {

		if (isFull() != true) {

			if (isEmpty() == true) {
				
				myArray[itail] = value;						
			}
			else {

				itail = (itail + 1) % array_capacity;
				myArray[itail] = value;							
			}
			
			array_size++;
		}
		else {

			increaseSize();
			enqueue(value);
		}
	}

	//increments the head tracker to 'remove' the oldest queue element
	void dequeue() {
		
		ihead = (ihead + 1) % array_capacity;
		
		array_size--;

		//make sure the size of the array can never be less than 0
		if (array_size <= 0) array_size = 0;

		if (getSize() <= (.25 * array_capacity)) {

			decreaseSize();
		}
	}

	//switches all the member variables of a to b and vice versa
	bool swap(dynamic_queue &a, dynamic_queue &b) {

		if (a.myArray != b.myArray) {			

			dynamic_queue<QueueElement> temp;

			temp = a;
			a = b;
			b = temp;

			return true;
		}
		else {
			
			return false;
		}
	
	}

	//Empties the queue and resizes it to the intial capacity
	void clear() {

		delete[] myArray;

		QueueElement * newArray;
		newArray = new QueueElement[initial_capacity];

		myArray = newArray;
		array_size = 0;
		itail = 0;
		ihead = 0;		
	}
	
	const dynamic_queue& operator=(const dynamic_queue &RHS) {
	
		if (myArray == RHS.myArray) return *this;

		array_capacity = RHS.array_capacity;
		array_size = RHS.array_size;

		myArray = new int[array_capacity];

		for (int i = 0; i < array_capacity; i++) {

			myArray[i] = RHS.myArray[i];
		}

		ihead = RHS.ihead;
		itail = RHS.itail;

		return *this;
	}



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
