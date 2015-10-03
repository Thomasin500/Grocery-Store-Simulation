#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H


template <class QueueElement>
class dynamic_queue {

public:

	//default constructor
	dynamic_queue() {}

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


	//returns the capacity of the dynamic array as an int
	int getCapacity() {

		//need to find a way to return the capacity of the array, not the number of elements in it
	}

	void display(ostream & out) const {
	
	
	}


	void enqueue(const QueueElement & value) {}


	void dequeue() {}


	bool swap(dynamic_queue&, dynamic_queue&) {}


	void clear() {}
	
	const dynamic_queue& operator=(const dynamic_queue&) {}


	friend ostream& operator<< <> (ostream&, const dynamic_queue<dynamic_queue>&) {}

private:
	/***** Data Members *****/
	int ihead,
		itail;
	int initial_capacity; // initial capacity of array
	int array_capacity; // current capacity of the array
	int array_size; // current size of queue stored in array
	QueueElement *myArray; // pointer to dynamically allocated array
}

#endif
