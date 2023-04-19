#include <iostream>
#include <ctime>
#include "Queue.h"
using namespace std;

int main() {

//Simulation

	//Set RNG and Flag
		srand(time(NULL));
		bool transactionStarted = false;
	//User Variables
		int queueSize = 0;
		int generationChance = 0;
		int completionChance = 0;
		int clockTicks = 0;
	//Counters
		int clock = 0;
		int generatedCount = 0;
		int startedCount = 0;
		int completedCount = 0;

	//Ask user for all required values
	while (queueSize <= 0)
	{
		cout << "Please input a queue size: " << endl;
		cout << " >> ";
		cin >> queueSize;
	}

	while (generationChance < 1 || generationChance > 99)
	{
		cout << "Please input % chance of a new transaction being generated per tick (1-99): " << endl;
		cout << " >> ";
		cin >> generationChance;
	}

	while (completionChance < 1 || completionChance > 99)
	{
		cout << "Please input % chance of transaction ending (1-99): " << endl;
		cout << " >> ";
		cin >> completionChance;
	}

	while(clockTicks < 1)
	{
		cout << "Please input # of clock ticks: " << endl;
		cout << " >> ";
		cin >> clockTicks;
	}

	//Create Queue based on user input
	Queue q(queueSize);

	while (clock < clockTicks)
	{
		//Check if Queue is full
		if (q.isFull() == true)
		{
			cout << "Queue is full. Exiting... " << endl;
			break;
		}

		//Arrival
		int RNG = rand()% 100 + 1;
		if (RNG <= generationChance)
		{
			Transaction item;
			item.ID = "item";
			if (q.isFull() == false)
			{
				q.addElement(item);
				generatedCount++;
			}
		}

		//Processing
		if (transactionStarted == false)
		{
			if (q.isEmpty() == false)
			{
				q.deleteElement();
				transactionStarted = true;
				startedCount++;
			}
		}

		//Leaving
		if (transactionStarted == true)
		{
			int RNG = rand()% 100 + 1;
			if (RNG <= completionChance)
			{
				transactionStarted = false;
				completedCount++;
			}
		}

		clock++;
	}
	cout << "# clock ticks: " << clockTicks << endl;
	cout << "# transactions generated: " << generatedCount << endl;
	cout << "# transactions started: " << startedCount << endl;
	cout << "# transactions processed: " << completedCount << endl;
	cout << "# transactions left in queue: " << q.numberOfElements() << endl;
	//q.displayQueue();

	//Test code
//	int* arr;
//	arr = new int[2];
//	arr[0] = 12;
//	arr[1] = 27;
//	cout << arr[0] << arr[1];

//	Queue Amazon(10);
//
//	Transaction purchase1;
//	purchase1.ID = "DVD";
//	purchase1.workUnits = 1;
//
//	Transaction purchase2;
//	purchase2.ID = "HDMI Cord";
//	purchase2.workUnits = 1;
//
//	Transaction purchase3;
//	purchase3.ID = "Donuts";
//	purchase3.workUnits = 1;
//
//	Amazon.addElement(purchase1);
//	Amazon.addElement(purchase2);
//	Amazon.addElement(purchase3);
//	Amazon.displayQueue();
//	Amazon.deleteElement();
//	Amazon.displayQueue();

}
