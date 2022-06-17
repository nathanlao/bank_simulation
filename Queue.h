/* 
 * Queue.h
 *
 * Description: Implementation of an template Queue class for data type sequence 
 *              with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: Guanhua Lao
 * Date: Mar 24th, 2022
 */

#pragma once

#include <iostream>
#include "EmptyDataCollectionException.h"

using namespace std;

// Class Invariant:  FIFO or LILO order
template <class ElementType>
class Queue {

    private:
        static unsigned const INITIAL_CAPACITY = 6;     // Constant INITIAL_CAPACITY
        ElementType* elements;             
        unsigned int elementCount;                      // Number of elements in the Queue
        unsigned int capacity;                          // Actual capacity of the data structure (number of cells in the array)
        unsigned int frontindex;                        // Index the topmost element
        unsigned int backindex;                         // Index where the next element will be placed     
              
    public:
        // Description:  Constructor
        Queue();

        // Description:  Destructor
        ~Queue(); 
        
/******* Start of Queue Public Interface *******/

        // Description: Returns "true" if this Queue is empty, otherwise "false".
        // Postcondition: This Queue is unchanged by this operation.
        // Time Efficiency: O(1)
        bool isEmpty() const;
        
        // Description: Inserts newElement at the "back" of this Queue 
        //              (not necessarily the "back" of its data structure) and 
        //              returns "true" if successful, otherwise "false".
        // Time Efficiency: O(1)
        bool enqueue(ElementType& newElement);
        
        // Description: Removes (but does not return) the element at the "front" of this Queue 
        //              (not necessarily the "front" of its data structure).
        // Precondition: This Queue is not empty.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
        // Time Efficiency: O(1)
        void dequeue(); 
        
        // Description: Returns (but does not remove) the element at the "front" of this Queue
        //              (not necessarily the "front" of its data structure).
        // Precondition: This Queue is not empty.
        // Postcondition: This Queue is unchanged by this operation.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.
        // Time Efficiency: O(1)
        ElementType& peek() const;  

        // For testing purposes:
        // Description: Prints the content of "this". 
        // void printQueue() const; 
};

/******* End of Queue Public Interface *******/
#include "Queue.cpp"  // Including "Queue.cpp" (Implementation)