/*
 * BankSimApp.cpp
 * 
 * Description: Drives the testing of the Queue, the PriorityQueue, the BinaryHeap
 *              the event and all the exceptions classes. 
 *
 * Author: Guanhua Lao
 * Last Modification Date: Mar 25th, 2022
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 
#include "Event.h"
#include "BinaryHeap.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"

using namespace std;

int main(int argc, char *argv[]) {

    // Purpose: cin from file
    int arrivalTime = 0;
    int transactionTime = 0;

    // Record the departure time
    int departureTime = 0;

    // Purpose: record the time it needs and calculate the average wait time
    int totaldepartureTime = 0;
    int totalArrivalTime = 0;
    int totalTransactionTime = 0;
    float totalWaitTime = 0.0;

    // 2 types of event
    static const char ARRIVAL = 'A';
	static const char DEPARTURE = 'D';

    Queue<Event>* bankLine = new Queue<Event>(); // Bank Line (empty queue)
    PriorityQueue<Event>* eventPriorityQueue = new PriorityQueue<Event>(); // Event Queue (empty PriorityQueue)

    bool tellerAvailable = true; // currently teller is available

/******* Read input (file) from the command line *******/
    int numberOfPeople = 0;
    // Create and add arrival events to event queue
    while (cin >> arrivalTime >> transactionTime) {

        // new object of arrival event
        Event newArrivalEvent(ARRIVAL, arrivalTime, transactionTime); 
        if(eventPriorityQueue -> enqueue(newArrivalEvent)) {
            numberOfPeople++;
        }

        // For the purpose of calculating the average waiting time later:
        // Record the total arrival time and transaction time
        totalArrivalTime += arrivalTime;
        totalTransactionTime += transactionTime;
    }

    // For Testing Purposes:
    //eventPriorityQueue -> displayContent();//

/***********************************************************/

/******* Event loop *******/

    cout << "Simulation Begins" << endl;

    while (!(eventPriorityQueue -> isEmpty())) {
        Event newEvent = eventPriorityQueue -> peek(); // get new Event with "highest" priority value
        // Get current time
        int currentTime = newEvent.getTime();
        
        // Check the event type
        if (newEvent.isArrival()) {

                /****** Preocessing an arrival event ********/

                cout << "Processing an arrival event at time: " << setw(5) << currentTime << endl;
                // Remove this event from the event queue
                eventPriorityQueue -> dequeue();
                
                if (bankLine -> isEmpty() && tellerAvailable) {
                    
                    // Transaction time of new event
                    transactionTime = newEvent.getLength();
                    
                    // departureTime is current time + transaction length
                    departureTime = currentTime + transactionTime;

                    // new departure event
                    Event newDepartureEvent(DEPARTURE, departureTime);
                    // teller is processing arrival event and add a departure event to the event queue
                    eventPriorityQueue -> enqueue(newDepartureEvent);
                    tellerAvailable = false;

                    // otherwise, simply go to bank line!
                } else {
                    bankLine -> enqueue(newEvent);
                }

                /****** Preocessing a departure event ********/

         } else {
                cout << "Processing a departure event at time: " << setw(4) << currentTime << endl;

                // Record the total departure time
                totaldepartureTime += departureTime;

                // Remove this event from the event queue
                eventPriorityQueue -> dequeue();

                if (!(bankLine -> isEmpty())) {
                    // Customer at front of bank line begins transaction
                    newEvent = bankLine -> peek();
                    
                    // Customer begins transaction
                    bankLine -> dequeue();

                    // Getting the transaction time of the customer
                    transactionTime = newEvent.getLength();

                    // departureTime is current time + transaction length of the customer
                    departureTime = currentTime + transactionTime;
                    // Add a departure event to the event queue
                    Event newDepartureEvent(DEPARTURE, departureTime);
                    eventPriorityQueue -> enqueue(newDepartureEvent);
    
                    // otherwise, teller is available
                } else {
                    tellerAvailable = true;
                }
         }

    }
/***********************************************************/

    // Calculate the total wait time
    totalWaitTime = totaldepartureTime - totalArrivalTime - totalTransactionTime;

    cout << "Simulation Ends" << endl;
    cout << "\nFinal Statistics: \n" << endl;
    cout << "    Total number of people processed: " << numberOfPeople << endl;
    cout << "    Average amount of time spent waiting: " << totalWaitTime/numberOfPeople << endl;
    cout << endl;

    delete bankLine;
    delete eventPriorityQueue;

    return 0;
}