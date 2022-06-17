/*
 * Event.cpp
 *
 * Description: Models arrival or departure event.
 *
 * Class Invariant: Arrival events have type 'A'
 * 					Departure event have type 'D'
 *
 * Author: AL
 * Last Modified: March 2022
 */

#include <iostream>
#include "Event.h"

using namespace std;


// Constructor
Event::Event() {
	type = ARRIVAL;
	time = 0;
	length = 0;
}

Event::Event(char aType, int aTime) {
	type = aType;
	time = aTime;
	length = 0;
}

Event::Event(char aType, int aTime, int aLength) {
	type = aType;
	time= aTime;
	length = aLength;
}

// Getters
char Event::getType() const {
	return type;
}

int Event::getTime() const {
	return time;
}

// Postcondition: The length makes sense only when the type is "A".
int Event::getLength() const {
	return length;
}

// Setters
// Not expected to be used in this simulation
void Event::setType( char aType ) {
	type = aType;
}

void Event::setTime( int aTime ) {
	time = aTime;
}

void Event::setLength( int aLength ) {
	if( type == ARRIVAL )
	   length = aLength;
	else
	   length = 0;
}


// Description: Return true if this event is an arrival event, false otherwise.
bool Event::isArrival(){
	return type == ARRIVAL;
}

// Overloaded Operators
// Description: Comparison <= operator. 
bool Event::operator<=(const Event& rhs) {

	// Compare both Event objects
	if (time == rhs.getTime() )
		if ((type == rhs.getType()) || (type == ARRIVAL && rhs.getType() == DEPARTURE) )
			return true;
		else
			return false;
	else
	    if (time < rhs.getTime() )
			return true;
		else
			return false;

	return false;
} // end of operator<=


// For Testing Purposes
// Description: Prints the content of "rhs".
ostream& operator<<(ostream & os, const Event& rhs) {

   	os << "Event - Type: " << rhs.getType();
   	os << ", Time: " << rhs.getTime();
   	if ( rhs.getType() == Event::ARRIVAL ) os << ", Length: " << rhs.getLength();
   	os << endl << endl;

	return os;
}
// end of operator <<
