#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

struct EmployeeData
{
	int SSN = 0;
	string firstName = "NULL";
	string lastName = "NULL";
	vector<EmployeeData*> chain;
};

void PrintEmployeeDataArray(EmployeeData arr[], int size)
{
	int counter = 0;

	//neat formatting
	cout << " 			Employees " << endl;
	for (int i = 0; i < 60; i++) { cout << "="; }
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		if (arr[i].SSN!= 0) //if array index is not empty
		{
			cout << "Hash Table Entry [" << i << "] -";
			cout << " Employee: " << arr[i].SSN;
			cout << " Name: " << arr[i].firstName << " " << arr[i].lastName << endl;

			//no chain? print nothing
			if(arr[i].chain.empty())
			{
				//cout << "	there is no chain from this entry " << endl;	//actually let's not print this out, looks better
			}

			//chain isn't empty? print out array[i].chain data
			else
			{
				for (unsigned int j = 0; j < arr[i].chain.size(); j++) //need nested loop for array w/ vector
				{
					cout << "	Chain -";
					cout << " Employee: " << arr[i].chain[j]->SSN;
					cout << " Name: " << arr[i].chain[j]->firstName << " " << arr[i].chain[j]->lastName << endl;
					counter++;
				}
			}
			counter++;
		}
	}
	cout << " ***End of list. There are a total of " << counter << " employees. " << endl;
	for (int i = 0; i < 60; i++) { cout << "="; }
	cout << endl;
}

void AddEmployeeData(EmployeeData arr[], int index, EmployeeData eD)
{
	if (arr[index].SSN == 0) //if array[i] is empty, add data to that position
	{
		arr[index] = eD;
	}
	else	//if array[i] is NOT empty, add data to it's chain
	{
		EmployeeData* eDpointer = new EmployeeData;
		(*eDpointer).SSN = eD.SSN;
		(*eDpointer).firstName = eD.firstName;
		(*eDpointer).lastName = eD.lastName;
		arr[index].chain.push_back(eDpointer);
	}
}

int HashFunction(int SSN)
{
	//int i = SSN % 100;	//really simple formula, less painful for me when manually create SSNs that cause collisions
	int i = SSN % 97;
	return i;
}

string RemoveSpaces(string &input) //not required, but it makes printing out employee names look nice :)
{
	input.erase(remove(input.begin(),input.end(),' '),input.end());
	return input;
}

bool UserInputInt(string word) //check if user inputs a valid SSN that is only digits
{
	//scan every single char in string, check if it's a digit
	for (unsigned int i = 0; i < word.length(); i++)
	{
		char c = word[i]; //basically, strings are just arrays of chars
		if (isdigit(c) == false)
		{
			cout << "	String contains characters that are not numbers. " << endl;
			return false;
		}
	}
	return true;
}

int main()
{
//Part 1: Populating the structure
	//create array
	EmployeeData dataArray[100];

	//read file
	string line;
	ifstream myfile ("Test.txt");
	EmployeeData eD; //data to add to array

	if (myfile.is_open())
	{
		while(getline(myfile,line))
		{
			//Data records always have the same format and position
			// so we can use substr to identify SSN, first name, and last name.
			eD.SSN = stoi(line.substr(0,9));	//convert string of numbers (SSN) into int
			eD.firstName = line.substr(9,10);
				RemoveSpaces(eD.firstName); 	//remove spaces between first and last name, look nicer
			eD.lastName = line.substr(19,14);
			AddEmployeeData(dataArray, HashFunction(eD.SSN), eD); //add data to array
		}
	    myfile.close();
	}
	else
		cout << "Unable to open file";
//infile>>tmp>>temp2

//Part 2: Display the employees
	PrintEmployeeDataArray(dataArray, 100);

//Part 3: Query the employee structure

	string rawUserSSN;
	int userSSN = 1;
	bool found = false;

	while (true)
	{
		found = false;

		while (true)
		{
			cout << "Enter employee SSN: ";
			cin >> rawUserSSN;
			bool validNumber = UserInputInt(rawUserSSN); //check if user input a string that can be converted to a number
			if (validNumber == true)
			{
				userSSN = stoi(rawUserSSN);	//if user input valid int, convert string to int, break
				break;
			}
		}

		if (userSSN == 0){ break;}

		for (int i = 0; i < 100; i++)
		{
			if (userSSN == dataArray[i].SSN) //linear search array for SSN
			{
				cout << "	Found: " << dataArray[i].firstName << " " << dataArray[i].lastName << endl;
				found = true;
			}
			if (!dataArray[i].chain.empty())	//check if there is a chain in array[i] as well
			{
				for (unsigned int j = 0; j < dataArray[i].chain.size(); j++) //i used a vector, so we need a nested for loop
				{
					if (userSSN == dataArray[i].chain[j]->SSN)
					{
						cout << "	Found: " << dataArray[i].chain[j]->firstName << " " << dataArray[i].chain[j]->lastName << endl;
						found = true;
					}
				}
			}
		}
		if (found == false)
		{
			cout << "	Not found. " << endl;
		}
	}
	cout << "	0 inputted, exiting. Thank you and have a nice day :) " << endl;
}
