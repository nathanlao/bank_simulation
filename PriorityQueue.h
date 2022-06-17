/* 
 * PriorityQueue.h
 *
 * Description: Priority Queue data collection ADT class
 *              Minimum Binary Heap is the underlying data strucutre
 * Class Invariant: ... in FIFO order using a priority value
 *
 * Author: Nathan Lo
 * Date: Mar 25th, 2022
 */

#pragma once

#include "BinaryHeap.h"

template <class ElementType>
class PriorityQueue {

    private:
        BinaryHeap<ElementType>* keyValuePairs;

    public:
        // Description:  Constructor
        PriorityQueue();

        // Description:  Destructor
        ~PriorityQueue(); 

        /******* Start of Priority Queue Public Interface *******/

        // Description: Returns "true" if this Priority Queue is empty, otherwise "false".
        // Postcondition: This Priority Queue is unchanged by this operation.
        // Time Efficiency: O(1)
        bool isEmpty() const;

        // Description: Inserts newElement in this Priority Queue and 
        //              returns "true" if successful, otherwise "false".
        bool enqueue(ElementType& newElement);

        // Description: Removes (but does not return) the element with the next
        //              "highest" priority value from the Priority Queue.
        // Precondition: This Priority Queue is not empty.
        // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
        void dequeue();
        
        // Description: Returns (but does not remove) the element with the next 
        //              "highest" priority from the Priority Queue.
        // Precondition: This Priority Queue is not empty.
        // Postcondition: This Priority Queue is unchanged by this operation.
        // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty. 
        ElementType peek() const; 
/*******  End of Priority Queue Public Interface *******/

        // For testing purposes:
        // Description: Display the content of this
        // void displayContent() const;
};

#include "PriorityQueue.cpp" // include Priority Queue's implementation
