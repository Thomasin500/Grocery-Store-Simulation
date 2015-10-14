#pragma once

#include <iostream>

#include "Timer.h"

using namespace std;

class Customer {

	public:

		Customer(){
		
			timeOfArrival = serviceTime = 0;
		}

		Customer(const Timer &T, int serviceTime) {

			//record the customer's time of arrival
			timeOfArrival = T.timeRemaining();

			//set the service time
			this->serviceTime = serviceTime;
		}

		Customer(const Customer &copyCust) {

			timeOfArrival = copyCust.timeOfArrival;
			serviceTime = copyCust.serviceTime;

		}

		int getArrivalTime() {

			return timeOfArrival;
		}

		int& getServiceTime()  {

			return serviceTime;
		}

		void setServiceTime(int time) {

			serviceTime = time;
		}

		void decrementServicetime() {

			//return serviceTime - 1;
			serviceTime--;
		}

		void display(ostream &out) {

			out << "Arrival Time:	" << timeOfArrival << endl;
			out << "Service Time:	" << serviceTime << endl;
		}	

		const Customer& operator=(const Customer &RHS) {

			if (this == &RHS) return *this;

			timeOfArrival = RHS.timeOfArrival;
			serviceTime = RHS.serviceTime;

			return *this;
		}

private: 
		int timeOfArrival;
		int serviceTime;
		

};