
#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
#include <cstring>
using namespace std;

struct Transaction
{
	string ID;
};

class Queue {
private:
	int maxQueueSize; //variable to store the maximum queue size
	int numElements; //variable to store the number of elements in the queue
	int queueFront;   //variable to point to the first element of the queue
	int queueRear;//variable to point to the last element of the queue
	Transaction *list; //pointer to the array that holds the queue elements
		//the actual queue basically

public:
	Queue(int userQueueSize);

	int numberOfElements() { return numElements; }
	bool isFull();
	bool isEmpty();
	void addElement(Transaction &element);
	void deleteElement();
	void displayQueue();

	virtual ~Queue();
};

#endif /* QUEUE_H_ */
