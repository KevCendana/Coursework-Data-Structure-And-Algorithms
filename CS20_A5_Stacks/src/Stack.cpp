#include <iostream>
#include "Stack.h"
using namespace std;
Stack::Stack(int s)
{
	size = s;	//user determines size
	string *arr = new string[size]; //create dynamic array of string pointers
	arrPtr.push_back(arr);	//add it to list
	topElement = 0;
	countOfArrays = 1;
}
bool Stack::push(string s){
	if(topElement==size)	//if current array is full
	{
		//cout << "push:   Looks like the array is full, making another... " << endl;
		string *arr=new string[size]; //make a new one
		arr[0] = s;
		arrPtr.push_back(arr);
		topElement = 1;
		countOfArrays++; //array counter, not needed, helps
	}
	else //if current array is not full
	{
		arrPtr.back()[topElement] = s; //add string to back
		topElement++;
	}
}
bool Stack::pop(string &s){
	//cout << "pop: Deleting element " << s << endl;
	if(topElement==0)
	{
		if(countOfArrays==1)
			return false;
		else
		{
			//cout << "pop: Current array empty, deleting and moving to previous array " << endl;
			delete[]arrPtr.back(); // delete back of list, remember, there is a dynamic array in the list
			arrPtr.pop_back();  // removes the last element in the list container
			countOfArrays--;
			topElement = size - 1;
			s = arrPtr.back()[topElement];  // accessing last element from previous array since we deleted one
			return true;
		}
	}
	else
	{
		topElement--;
		s=s = arrPtr.back()[topElement]; //retrieve previous data from current array
		return true;
	}
}
bool Stack::top(string &s)
{
	if(topElement==0)
	{
		if(countOfArrays==1) //stack is empty if topElement is 0 AND only 1 array
			return false;
	}
	else
	{
		//topElement--;
		s=s = arrPtr.back()[topElement-1];
		return true;
	}
}
void Stack::destroy()
{
	delete[]arrPtr.back();  // delete current array
	arrPtr.pop_back(); // remove its pointer
	arrPtr.push_back(NULL);
	countOfArrays--;
	topElement = size;
}
Stack::~Stack(){
	// free up them memory by deleting all arrays pointing by nodes
	for(int i = 0; i < countOfArrays; i++)
	{
		delete[]arrPtr.back();  // remove empty array
		arrPtr.pop_back();  // remove the pointer also
	}
	arrPtr.push_back(NULL); //fill array with...nothing
	countOfArrays=0;
	size=0;
}
