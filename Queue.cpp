/* 
 * Queue.cpp
 *
 * Description: Implementation of an template Queue class for data type sequence 
 *              with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: Guanhua Lao
 * Date: Mar 24th, 2022
 */

#include "Queue.h"

// Description:  Constructor
template<class ElementType>
Queue<ElementType>::Queue() : elementCount(0), capacity(INITIAL_CAPACITY), frontindex(0), backindex(0) {
    elements = new ElementType[INITIAL_CAPACITY];
} 

// Description: Destructor
template<class ElementType>
Queue<ElementType>::~Queue() {
    delete[] elements;
}

// Description: Returns "true" if this Queue is empty, otherwise "false".
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::isEmpty() const{
    return elementCount == 0;
}

// Description: Inserts newElement at the "back" of this Queue 
//              (not necessarily the "back" of its data structure) and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::enqueue(ElementType& newElement) {

    bool ableToInsert = false;

    if (!ableToInsert) {
        elementCount++;
        elements[backindex] = newElement;
        backindex = (backindex + 1) % capacity; //increment backindex and go back to index 0 if 
                                            //backindex reaches the capacity-1(the last element)  

        ableToInsert = true;
    }

    // if array is full, double the capacity (amotized to O(1))
    if (backindex == capacity-1) {
        capacity *= 2; // double the capacity

        ElementType * temp = new ElementType[capacity]; // temp array
        
        for (int i = 0; i < elementCount; i++) {   //copy the elements from old array to temp array
            int index = (frontindex + i) % capacity; //index from front to back of the old array
            temp[i] = elements[index];              
        }

        // update the front and back index
        frontindex = 0; // topmost element 
        backindex = elementCount; //the next element will be placed

        delete[] elements; //deallocate old array

        elements = temp; //point to temp array

    } 

    return ableToInsert;
}

// Description: Removes (but does not return) the element at the "front" of this Queue 
//              (not necessarily the "front" of its data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.   
// Time Efficiency: O(1)
template<class ElementType>
void Queue<ElementType>::dequeue() {
    if (isEmpty()) {
        throw EmptyDataCollectionException("dequeue() called with an empty Queue.");
    } else {
        elementCount--;
        frontindex = (frontindex + 1) % capacity; //increment frontindex and set back to index 0 if
                                                //frontindex reaches the last element
    }

}

// Description: Returns (but does not remove) the element at the "front" of this Queue
//              (not necessarily the "front" of its data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template<class ElementType>
ElementType& Queue<ElementType>::peek() const {
    if (isEmpty()) {
        throw EmptyDataCollectionException("peek() called with an empty Queue.");
    } else {
        return elements[frontindex];
    }
}

// Description: Prints the content of "this". 
// template<class ElementType>
// void Queue<ElementType>::printQueue() const { 
//    cout << "Printing the queue from front = " << frontindex << " to back = " << backindex << endl;
//    for ( int i = frontindex; i <= backindex; i++)
//       cout << elements[i];
//    cout << endl;
// } // end of printQueue