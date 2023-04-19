#ifndef LLnode_H_	//makes sure that this .h file isn't used more than once
#define LLnode_H_
#include <iostream>
using namespace std;

template <class T>
class LL
{
private:
	struct LLnode
	{
		LLnode* fwdPtr;
		T theData = "";
	};

	LLnode* llh;
public:
	LL();	//constructor
	void push_front(T newData);
	void push_back(T newData);
	int list_length();
	string retrieve_front();
	string retrieve_back();
	void display_list();
	//part 3
	void destroy_list();
	bool search_list (T value);
	bool delete_node(T value);

};

//~~~~~~~~~~~~~~~~~~~~~~~ .cpp file would normally start here~~~~~~~~~~~~~~~~~~~~~~~~~~

template <class T>
LL<T>::LL()
{
	llh = nullptr;
}

template <class T>
void LL<T>::push_front(T newData)
{
	//my way
	LLnode* newNode = new LLnode;	//make new node
	newNode->theData = newData;		//give new node the data
	newNode->fwdPtr = llh;	//make new node's fwdptr the old node (element 0 is moved to 1)
	llh = newNode;	//new node now takes old node's spot	(element 1 is moved to 0)
}

template <class T>
void LL<T>::push_back(T newData)
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
	tempNodePointer = llh;

	while (tempNodePointer->fwdPtr != nullptr)
	{
		tempNodePointer = tempNodePointer->fwdPtr;
		//cout << "Temp Pointer is currently: " << tempNodePointer->theData << endl;
	}

	tempNodePointer->fwdPtr = newNodePointer;

}

template <class T>
int LL<T>::list_length()
{
	LLnode* tempNodePointer = new LLnode;
	tempNodePointer = llh;

	int counter = 0;

	while (tempNodePointer!= nullptr)
	{
		tempNodePointer = tempNodePointer->fwdPtr;
		counter++;
	}

	return counter;
}

template <class T>
string LL<T>::retrieve_front()
{
	if (!llh)
	{
		throw string ("**Error: Cannot call retrieve_front on empty list.");
	}
	return llh->theData;
}

template <class T>
string LL<T>::retrieve_back()
{
	string backName;

	LLnode* tempNodePointer = new LLnode;
	tempNodePointer = llh;

	if (!llh)
	{
		throw string ("**Error: Cannot call retrieve_back on empty list.");
	}

	while (tempNodePointer->fwdPtr != nullptr)
	{
		tempNodePointer = tempNodePointer->fwdPtr;
		backName = tempNodePointer->theData;
	}
	return backName;
}

template <class T>
void LL<T>::display_list()
{
	LLnode* tempNodePointer = new LLnode;
	tempNodePointer = llh;

	if (list_length() <= 0)
	{
		cout << "Looks like the list is empty! " << endl;
	}

	while (tempNodePointer != nullptr)
	{
		cout << tempNodePointer->theData << endl;
		tempNodePointer = tempNodePointer->fwdPtr;
	}

}

//~~~~~~~~~~~~~~~~~~~~~~~~~STEP 3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template <class T>
void LL<T>::destroy_list()
{
	if(!llh)	//if header is null
	{
		cout << "destroy_list: Looks like the list is empty! " << endl;
		return;
	}
	while (llh)	//if header is not null
	{
		LLnode* filler = new LLnode;
		filler = llh;
		llh = llh->fwdPtr;
		delete filler;	//not the same pointer but they share the same address
	}

	llh = nullptr; 	//reset
}

template <class T>
bool LL<T>::search_list(T value)
{
	if(!llh)
	{
		cout << "search_list: Nothing to search from. " << endl;
		return false;	//if the list is empty, we're pretty much done
	}

	LLnode* filler = new LLnode;	//initialize outside of while loop
	filler = llh;

	while (filler)
	{
		//cout << "test  " << endl;
		if (filler->theData == value)
		{
			return true;
		}
		//cout << "T " << endl;
		filler = filler->fwdPtr;
	}
	//cout << "Search_List called: Nothing found. " << endl;
	return false;
}

template <class T>
bool LL<T>::delete_node(T value)
{
	//case 1: empty list
	if(!llh)
	{
		return false;	//if the list is empty, we're pretty much done
	}

	//case 2: header has key
	LLnode* current = new LLnode;
	current = llh;

	if (current->theData == value)
	{
		//cout << "Delete_Node called, now deleting " << current->theData << "..." << endl;
		llh = llh->fwdPtr;
		delete current;
		return true;
	}

	//case 3: header does not have key
	LLnode* next = new LLnode;	
	next = llh->fwdPtr;

	while (next)	//while next is not null
	{
		if (next->theData == value)
		{
			LLnode* last = new LLnode;
			last = next->fwdPtr;
			delete next;
			current->fwdPtr = last;		//bridge the "gap" left behind by deleting next
			return true;
		}
		next = next->fwdPtr;
		current = current->fwdPtr;
	}

	//case 4: key isn't found literally anywhere
	return false;
}


#endif
