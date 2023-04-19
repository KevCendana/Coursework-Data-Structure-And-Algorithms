#include <iostream>
using namespace std;

struct LLnode
{
	LLnode* fwdPtr;
	string theData = "";
};

void push_front(LLnode* & oldNode, string newData)
{
	LLnode* newNode = new LLnode;	//make new node
	newNode->theData = newData;		//give new node the data

	newNode->fwdPtr = oldNode;	//make new node's fwdptr the old node
	oldNode = newNode;	//new node now takes old node's spot

	return;
}

void push_back(LLnode* & oldNode, string newData)
{
//setting a pointer equal to another pointer does not change it's address, only points to the same value


	//get space for new node
	LLnode* newNodePointer = new LLnode;

	//set new node's fwd pointer to null
	newNodePointer->fwdPtr = 0;

	//add data to new node
	newNodePointer->theData = newData;

	//make last node point to new node using for loop
	//to do this, we need to look at all of the nodes until the fwd ptr is null
	LLnode* tempNodePointer = new LLnode;
	tempNodePointer = oldNode;

	while (tempNodePointer->fwdPtr != nullptr)
	{
		tempNodePointer = tempNodePointer->fwdPtr;
		//cout << "Temp Pointer is currently: " << tempNodePointer->theData << endl;
	}

	tempNodePointer->fwdPtr = newNodePointer;

}

int list_length(LLnode* node)
{
	LLnode* tempNodePointer = new LLnode;
	tempNodePointer = node;

	int counter = 0;

	while (tempNodePointer!= nullptr)
	{
		tempNodePointer = tempNodePointer->fwdPtr;
		counter++;
	}

	return counter;
}

string retrieve_front(LLnode* frontNode)
{
	try
	{
		if (!frontNode)
		{
			throw string ("**Error: Cannot call retrieve_front on empty list.");
		}
	}
	catch(string &x)
	{
		cout << x << endl;
	}

	return frontNode->theData;
}

string retrieve_back(LLnode* node)
{
	string backName;

	LLnode* tempNodePointer = new LLnode;
	tempNodePointer = node;

	try
	{
		if (!node)
		{
			throw string ("**Error: Cannot call retrieve_back on empty list.");
		}
	}
	catch(string &x)
	{
		cout << x << endl;
	}

	while (tempNodePointer->fwdPtr != nullptr)
	{
		tempNodePointer = tempNodePointer->fwdPtr;
		backName = tempNodePointer->theData;
	}
		return backName;
}

void display_nodes(LLnode* node)
{
	LLnode* tempNodePointer = new LLnode;
	tempNodePointer = node;

	if (list_length(node) <= 0)
	{
		cout << "Looks like the list is empty! " << endl;
	}

	while (tempNodePointer != nullptr)
	{
		cout << tempNodePointer->theData << endl;
		tempNodePointer = tempNodePointer->fwdPtr;
	}

}

int main() {
	//~~~~~~~~~~~~~~~~~~~~TEACHER TEST CODE~~~~~~~~~~~~~~~~~~~
		LLnode* theLLHeader1;

		cout << "Main:  number of nodes in empty list " << list_length(theLLHeader1) << endl;
		display_nodes(theLLHeader1);
		push_front (theLLHeader1, "aaaaa");
		push_back (theLLHeader1, "bbbbb");
		push_front (theLLHeader1, "before aaaaa");
		push_back (theLLHeader1, "after bbbbb");
		cout << "Main:  number of nodes after 4 pushes - " << list_length(theLLHeader1) << endl;
		display_nodes (theLLHeader1);
		cout << "Main:  retrieve front: " << retrieve_front (theLLHeader1) << endl;
		cout << "Main:  retrieve back: " << retrieve_back (theLLHeader1) << endl;
		cout << endl;

		LLnode * theLLHeader2 = nullptr;

		push_front (theLLHeader2, "33333");
		push_front (theLLHeader2, "22222");
		push_front (theLLHeader2, "11111");
		push_back (theLLHeader2, "44444");
		push_back (theLLHeader2, "55555");
		push_back (theLLHeader2, "66666");
		display_nodes (theLLHeader2);

		return 0;
}
