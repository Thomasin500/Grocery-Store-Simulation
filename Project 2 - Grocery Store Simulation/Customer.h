#pragma once

#include <iostream>

#include "Timer.h"

using namespace std;

class Customer {

	public:

		//default constructor
		Customer(){
		
			timeOfArrival = serviceTime = 0;
		}
		/*-----------------------------------------------------------------------
		constructor

		Precondition:  none
		Postcondition: a Customer object has been created
		-----------------------------------------------------------------------*/

		//specificconstructor
		Customer(const Timer &T, int serviceTime) {

			//record the customer's time of arrival
			timeOfArrival = T.timeRemaining();

			//set the service time
			this->serviceTime = serviceTime;
		}
		/*-----------------------------------------------------------------------
		specific constructor

		Precondition:  an object of class Timer and int serviceTime
		Postcondition: a Customer object has been created with its variables set to the passed it parameters
		-----------------------------------------------------------------------*/

		//copy constructor
		Customer(const Customer &copyCust) {

			timeOfArrival = copyCust.timeOfArrival;
			serviceTime = copyCust.serviceTime;

		}
		/*-----------------------------------------------------------------------
		copy constructor

		Precondition:  Customer object copyCrust
		Postcondition: a Customer object has been created with the varibales of the passed in object
		-----------------------------------------------------------------------*/

		//returns the arrival time
		int getArrivalTime() {

			return timeOfArrival;
		}
		/*-----------------------------------------------------------------------
		getArrivalTime

		Precondition:  none
		Postcondition: returns the timeOfArrival as an int
		-----------------------------------------------------------------------*/

		//returns a reference to the serviceTime
		int& getServiceTime()  {

			return serviceTime;
		}
		/*-----------------------------------------------------------------------
		getServiceTime

		Precondition:  none
		Postcondition: returns the serviceTime as an int reference
		-----------------------------------------------------------------------*/

		//sets the service time
		void setServiceTime(int time) {

			serviceTime = time;
		}
		/*-----------------------------------------------------------------------
		getServiceTime

		Precondition:  int time to be set to service time
		Postcondition: serviceTime is set to passed in variable
		-----------------------------------------------------------------------*/

		//decreases the serviceTime by 1
		void decrementServicetime() {

			//return serviceTime - 1;
			serviceTime--;
		}
		/*-----------------------------------------------------------------------
		decrementServiceTime

		Precondition:  none
		Postcondition: decrements the serviceTime by 1
		-----------------------------------------------------------------------*/

		//displays the object's variables
		void display(ostream &out) {

			out << "Arrival Time:	" << timeOfArrival << endl;
			out << "Service Time:	" << serviceTime << endl;
		}	
		/*-----------------------------------------------------------------------
		display

		Precondition:  the stream to be written to
		Postcondition: displays the arrivalTime and serviceTime of the object
		-----------------------------------------------------------------------*/

		//sets this object to the RHS one
		const Customer& operator=(const Customer &RHS) {

			if (this == &RHS) return *this;

			this->timeOfArrival = RHS.timeOfArrival;
			this->serviceTime = RHS.serviceTime;

			return *this;
		}
		/*-----------------------------------------------------------------------
		operator  = 

		Precondition: Customer object
		Postcondition: sets the LHS customer to the variables of the RHS customer object
		-----------------------------------------------------------------------*/

private: 
		//member variables
		int timeOfArrival;
		int serviceTime;
		

};