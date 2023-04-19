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
	void push_back_helper(T newData, LLnode* & node);	//new helper
	int list_length();
	int list_length_helper(LLnode* & node);
	T retrieve_front();
	T retrieve_back();
	T retrieve_back_helper(LLnode* & node);	//new helper
	void display_list();
	void display_list_helper(LLnode* & node);
	//part 3
	void destroy_list();
	void destroy_list_helper(LLnode* & node);	//new helper
	bool search_list (T value);
	bool search_list_helper (T value, LLnode* & data);
	bool delete_node(T value);
	bool delete_node_helper(T value, LLnode* & node);

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
	LLnode* newNode = new LLnode;		//make new node
	newNode->theData = newData;		//give new node the data
	newNode->fwdPtr = llh;			//make new node's fwdptr the old node (element 0 is moved to 1)
	llh = newNode;				//new node now takes old node's spot	(element 1 is moved to 0)
}

template <class T>
void LL<T>::push_back(T newData)
{
	if(!llh)	//if llh is empty..
	{
		llh = new LLnode;
		llh->theData = newData; //it will now only have the new data given by user
		llh->fwdPtr = nullptr;	//and will point to nothing since it's the last one
		return;
	}
	//if it's not empty, we need to search each individual node recursively.
	//i would need to end back both the newData and the actual node so i need a helper w/ 2 parameters
	push_back_helper(newData, llh);
}

template <class T>
void LL<T>::push_back_helper(T newData, LLnode* & node)
{

	if (node->fwdPtr)//if the fwdPtr for the node we're currently searching is not null, we want the one after
	{
		push_back_helper(newData, node->fwdPtr);	//keep sending fwdPtr until it's null, which means we're at the end
	}
	else
	{
		LLnode* newNodePointer = new LLnode;	//get space for new node

		newNodePointer->fwdPtr = 0;	//set new node's fwd pointer to null

		newNodePointer->theData = newData;		//add data to new node

		//the node we're currently searching is now pointing to the new node given
		node->fwdPtr = newNodePointer;
		cout << "Just pushed back " << newData << endl;
		return;
	}
}

template <class T>
int LL<T>::list_length()
{
	return list_length_helper(llh);
}

template <class T>
int LL<T>::list_length_helper(LLnode* & node)
{
	if (!node)	//if node is null, reached the end
	{
		return 0;
	}
	else
	{
		return 1 + list_length_helper(node->fwdPtr);	//increment value by 1 and move to next node
	}
}

template <class T>
T LL<T>::retrieve_front()
{
	if (!llh)
	{
		throw string ("**Error: Cannot call retrieve_front on empty list.");
	}

	return llh->theData;
}

template <class T>
T LL<T>::retrieve_back()
{
	if (!llh)	//if llh is empty
	{
		throw string ("**Error: Cannot call retrieve_back on empty list.");
	}
	return retrieve_back_helper(llh);	//need a helper since this function has no parameter
}

template <class T>
T LL<T>::retrieve_back_helper(LLnode* & node)
{
	if (node->fwdPtr)	//if there's a fwdPtr at our current node, we aren't at the end yet
	{
		return retrieve_back_helper(node->fwdPtr);
	}
	else	//fwdPtr is null so we reached the end
	{
		return node->theData;
	}
}

template <class T>
void LL<T>::display_list()
{
	if (list_length() <= 0)
	{
		cout << "display_list: Looks like the list is empty! " << endl;
	}
	else
	{
		display_list_helper(llh);
	}
}
template<class T>
void LL<T>::display_list_helper(LLnode* & node)
{
	cout << node->theData << endl;
	if (node->fwdPtr)	//if fwdPtr is not null
	{
		display_list_helper(node->fwdPtr);
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~STEP 3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template <class T>
void LL<T>::destroy_list()
{
	if(!llh)	//if header is null
	{
		cout << "destroy_list: Looks like the list is already empty! " << endl;
		return;
	}
	else
	{
		destroy_list_helper(llh);
	}
}

template <class T>
void LL<T>::destroy_list_helper(LLnode* & node)
{
	if (!node)	//if the entire list is destroyed
	{
		node = nullptr;
		return;
	}
	else
	{
		LLnode* deleter = new LLnode; //destroy this variable instead so we keep fwdPtr
		deleter = node;	//variable shares address so it will be deleted
		node = node->fwdPtr;	//move the list "forward"
		delete deleter;
		destroy_list_helper(node);	//keep going until it's empty
	}
}

template <class T>
bool LL<T>::search_list(T value)
{
	if (!llh)
	{
		cout << "search_list: List is empty, nothing to search! " << endl;
		return false;
	}
		return search_list_helper(value, llh);
}

template <class T>
bool LL<T>::search_list_helper(T value, LLnode* & node)
{
	if (node)	//if node is not null
	{
		if (node->theData == value)
		{
			//cout << value << " found, returning true... " << endl;
			return true;
		}
		else	//if the node being searched doesn't have the value, move to next node
		{
			return search_list_helper(value, node->fwdPtr);
		}
	}
	return false;	
}

template <class T>
bool LL<T>::delete_node(T value)
{
	//case 1: empty list
	if(!llh)
	{
		cout << "delete_node: Linked List is empty. " << endl;
		return false;
	}

	//case 2: header has key
	if (llh->theData == value)
	{
		LLnode* current = new LLnode;
		current = llh;
		llh = llh->fwdPtr;
		delete current;
		return true;
	}

	//case 3: header is not empty and does not have key
	return delete_node_helper(value, llh);

}

template <class T>
bool LL<T>::delete_node_helper(T value, LLnode* & node)
{
	if (node)	//if node is not null
	{
		cout << "Checking " << node->fwdPtr->theData << endl;

		if (node->fwdPtr->theData == value)	//if 2 has value
		{
			if (!node->fwdPtr->fwdPtr)	//if node we're looking at doesn't have a fwdPtr, it must be at the end, which means it should be replaced by null
			{
				LLnode* temp = new LLnode;
				temp = node->fwdPtr;	//create copy of 2
				node->fwdPtr = nullptr;	//if we're deleting a node at the end, fill spot with nullptr
				delete temp;
				return true;
			}
			LLnode* temp = new LLnode;
			temp = node->fwdPtr;	//create copy of 2
			node->fwdPtr = node->fwdPtr->fwdPtr; // 1 now links to 3
			delete temp;	//delete 2
			return true;
		}
		else
		{
			return delete_node_helper(value, node->fwdPtr);
		}
	}
	return false;
}


#endif
