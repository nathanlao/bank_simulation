/* 
 * PriorityQueue.cpp
 *
 * Description: Priority Queue data collection ADT class
 *              Minimum Binary Heap is the underlying data strucutre
 * Class Invariant: ... in FIFO order using a priority value
 *
 * Author: Nathan Lo
 * Date: Mar 25th, 2022
 */

#include "PriorityQueue.h"

// Description:  Constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue() {

    keyValuePairs = new BinaryHeap<ElementType>();
}

// Description:  Destructor
template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue() {
    delete keyValuePairs;
    keyValuePairs = NULL;
}

// Description: Returns "true" if this Priority Queue is empty, otherwise "false".
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {

    return (keyValuePairs -> getElementCount() == 0);
}

// Description: Inserts newElement in this Priority Queue and 
//              returns "true" if successful, otherwise "false".
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType& newElement) {
    return keyValuePairs -> insert(newElement);
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
template <class ElementType>
void PriorityQueue<ElementType>::dequeue() {
    try {
        keyValuePairs -> remove();
    } catch (EmptyDataCollectionException& anException) {
        throw EmptyDataCollectionException("Priority Queue is empty.");
    }
}

// Description: Returns (but does not remove) the element with the next 
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
template <class ElementType>
ElementType PriorityQueue<ElementType>::peek() const {
    try {
        return keyValuePairs -> retrieve();
    } catch (EmptyDataCollectionException& anException) {
        throw EmptyDataCollectionException("Priority Queue is empty.");
    }
}

// For testing purposes:
// Description: Display the content of this
// template <class ElementType>
// void PriorityQueue<ElementType>::displayContent() const {
//     keyValuePairs -> display();
// }
