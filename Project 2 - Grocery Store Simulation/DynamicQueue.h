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
		//memset(myArray, 0, initial_capacity);
	}

	//copy constructor
	dynamic_queue(const dynamic_queue&) {}

	//default destructor
	~dynamic_queue() {}

	QueueElement getHead() {

		if (array_size != 0) {

			cout << endl << "ihead index: " << ihead % array_capacity << endl;
			return myArray[ihead % array_capacity];
		}
	}

	QueueElement getTail() {
	
		if (array_size != 0) {

			cout << endl << "itail index: " << itail % array_capacity << endl;
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

	//creates a new array with double the capacity of the current array and copies each element into the new array
	//creates a new array with double the capacity of the current array and copies each element into the new array
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

		display(cout);
		cout << "size : " << array_size << endl;

	};

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


	void enqueue(const QueueElement &value) {

		cout << endl;
		if (isFull() != true) {

			if (isEmpty() == true) {
				
				myArray[itail] = value;
				cout << "val of itail: " << myArray[itail] << endl;
				cout << "itail: " << itail << endl;			
			}
			else {

				itail = (itail + 1) % array_capacity;
				myArray[itail] = value;
				cout << "val of itail: " << myArray[itail] << endl;
				cout << "itail: " << itail << endl;				
			}
			
			array_size++;
		}
		else {

			increaseSize();
			enqueue(value);
		}
	}

	void dequeue() {
		cout << endl;
		ihead = (ihead + 1) % array_capacity;
		
		cout << "ihead: " << ihead << endl;
		cout << "val of ihead: " << myArray[ihead] << endl;
		array_size--;

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

	//TODO...the project says this has to be in O(1) time, this is in O(n) time because of fill()
	//4. clear() 
	//	Delete the existing stack array, then reset data members to initial empty state.
	void clear() {

		fill(myArray, myArray + getSize(), 0);

		QueueElement * newArray;
		newArray = new QueueElement[initial_capacity];

		myArray = newArray;
		array_size = 0;
		itail = 0;
		ihead = 0;		
	}
	
	/*const dynamic_queue& operator=(const dynamic_queue &RHS) {
	
		if (this = RHS) return;

		this->ihead = RHS->ihead;
		this->itail = RHS->itail;
		this->initial_capacity = RHS->initial_capacity;
		this->array_capacity = RHS->array_capacity;
		this->array_size = RHS->array_size;

		myArray = RHS->myArray;

		return this;
	}*/


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
