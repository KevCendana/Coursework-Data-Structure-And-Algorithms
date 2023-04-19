#include <iostream>
#include <fstream>	//file i/o
#include <string>	//stoi
#include <algorithm> //.erase
#include <utility>
using namespace std;

void buildArray(int array[], int arraySize, string pathName)
{
	//read file
	ifstream myfile (pathName.c_str());
	string line;	//line to read in
	string s;	//save line to a variable

	if (myfile.is_open())
	{
		while(getline(myfile,line)) //get data line by line
		{
			s = line;
		}
		    myfile.close();
	}
	else
			cout << "Unable to open file";

	//populate array
		unsigned int counter = 0;
		int i = 0;

		while(counter < s.size())
		{
			if (i == arraySize + 1)
			{
				break;
			}
			int data = stoi(s.substr(counter,3)); //take 3 integers from the string and turn into int
			array[i] = data;
			counter += 3; //counter increments by 3 since we want 3 integers per int
			i++;
		}
		cout << endl;
}

void displayArray(int array[], int low, int high)
{
	int counter = 0;
	for (int i = low; i < high + 1; i++)
	{
		cout << "[" << i << "]: " << array[i] << " ";
		counter++;
		if (counter == 10)
		{
			cout << endl;
			counter = 0;
		}
	}
}

bool checkIfHeap(int array[], int low, int high)
{
	for (int i = low; i < (high - 2) / 2; i++) //once you reach the middle of the array, you're good
	{
		//check left child
		if (array[2 * i + 1] > array[i])
		{
			return false;
		}

		//check right child
		if (high > 2 * i + 2 && array[2*i+2] > array[i])
		{
			return false;
		}
	}
	return true;
}

void heapify(int array[], int low, int high)
{
	int largeIndex;
	int temp = array[low]; //copy root node
	largeIndex = 2 * low + 1; //left child node

	while (largeIndex <= high) //while left child is smaller than max
	{
		if (largeIndex < high)
		{
			if (array[largeIndex] < array[largeIndex +1]) //if left is smaller than right
			{
				largeIndex = largeIndex + 1; //..turn right into largest child
			}
		}
		if (temp > array[largeIndex]) //if root > large index, we're done, heap is created
		{
			break;
		}
		else
		{
			array[low] = array[largeIndex];	//larger child is now root
			low = largeIndex;
			largeIndex = 2 * low + 1;
		}
	}

	array[low] = temp;
}

void buildHeap(int array[], int low, int high)
{
	for (int i = high / 2 - 1; i >= 0; i--)
	{
		heapify(array, i, high - 1);
	}
}

void heapSort(int array[], int low, int high) //may be incorrect!
{
	buildHeap(array, low, high);

    for (int i = high; i >= 0; i--)
    {
    	int temp;
    	temp = array[i];
    	array[i] = array[0];
    	array[0] = temp;
    	heapify(array, 0, i - 1);
    }
}

int main()
{

//Professor Test Code~~~~~~~~~~~~~~~~~~~~
	int low, high;
	low = 0;			// low array index
	high = 99;			// high array index
	bool b;
	int list[100];
	//string p ="c:/CS20/a81data.txt";
	string p = "a81data.txt";
	cout << "main: building first array (from a81data.txt)" << endl;
	buildArray (list, 100, p);
	cout << "main: displaying first array" << endl << endl;
	displayArray (list, low, high);
	cout << endl;
	b=checkIfHeap (list, low, high);
	if (b)
		cout << "main: the first array is already a heap" << endl << endl;
	else
		cout << "main: the first array is not a heap" << endl << endl;
	cout << "main: now building heap" << endl;
	buildHeap (list, low, high);
	cout << "main: now displaying first array after heaping" << endl << endl;
	displayArray (list, low, high);
	b=checkIfHeap (list, low, high);
	if (b)
		cout << endl << "main: after heaping, the first array is a heap" << endl << endl;
	else
	{
		cout << endl << "main: after heaping, the first array is not a heap" << endl;
		return 4;
	}
	//p ="c:/CS20/a82data.txt";
	p = "a82data.txt";
	cout << "main: building second array (from a72data.txt)" << endl;
	buildArray (list, 100, p);
	cout << "main: displaying second array" << endl << endl;
	displayArray (list, low, high);
	heapSort (list, low, high);
	cout << endl << "main: displaying second array, which should now be sorted" << endl << endl;
	displayArray (list, low, high);
	return 0;
}

