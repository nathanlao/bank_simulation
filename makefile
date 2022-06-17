all: bsim

bsim: Event.o EmptyDataCollectionException.o Queue.h BinaryHeap.h PriorityQueue.h BankSimApp.o
	g++ -o bsim BankSimApp.o Event.o EmptyDataCollectionException.o

BankSimApp.o: BankSimApp.cpp
	g++ -c BankSimApp.cpp

Event.o: Event.cpp Event.h
	g++ -c Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -c EmptyDataCollectionException.cpp

clean:
	rm -f bsim *.o