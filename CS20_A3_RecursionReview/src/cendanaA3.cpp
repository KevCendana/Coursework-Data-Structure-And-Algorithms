#include <iostream>
using namespace std;

int fact(int i);
int fib(int i);
void prime(int i);
bool primeChecker(int i, int checker = 2);
int mult(int i, int n);
string reverseString(string s);
string reverseStringHelper(string s);
int countOccurrences(string s, string c);
int countOccurrencesHelper(string s, string c, int counter, int wordSize);

int main() {

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Hrycewicz Test Code~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
	// factorial
		int count;
		int f=5;
		cout << "factorial of " << f << " is " << fact(f) << endl << endl;
	// Fibonocci
		for (count=0;count < 10;count++)
		{
			cout << "Fibonocci sequence number " << count+1 << " is " << fib(count+1) << endl;
		}
	// primes
		prime (10);
	// multiplication
		int a=6, b=5;
		cout << endl << "product of " << a << " and " << b << " is " << mult(a,b) << endl << endl;
	// string reversal
		string s = "abcde";
		cout << "original string " << s << " reversed string " << reverseString(s) << endl << endl;
	// character counting
		string t="a";
		cout << "number of occurrences of " << t[0] << " in " << s << " is " << countOccurrences(s,t) << endl;

	    return 0;
}

int fact(int i)
{
	//base case
	if (i == 1)
	{
		return 1;
	}

	return i*fact(i-1);

}

int fib(int i)
{
	//base cases
	if (i <= 0)
	{
		return 0;
	}

	if (i == 1 or i == 2)
	{
		return 1;
	}

	return fib(i-1) + fib(i-2);
}

void prime(int i)
{
	int counter = 0;
	int amount = 0;

	while (!(amount == i))
	{
		if (primeChecker(counter) == true)
		{
			cout << counter << " ";
			amount++;
		}
		counter++;
	}
}

bool primeChecker(int i, int checker)
{
	//base case: number is 1
	if (i == 1)
	{
		return false;
	}

	//base case: number is less than 2 (excluding the number 1)
	if (i <= 2)
	{
		return true;
	}

	//the checker increments by 1 every time then divides the number by the checker.
	//so, if checker ever reaches the given number, the number is prime
	//ex) if number = 7 and checker == 7, we have attempted to divide number by 1, 2, 3, 4, 5, and 6, with all of them having a remainder, so it's prime
	if (checker >= i)
	{
		return true;
	}

	if (i % checker == 0)
	{
		return false;
	}

	primeChecker(i, checker+1);
}

int mult(int i, int n)
{
	if (n == 0)
	{
		return 0;
	}
	return mult(i, n-1) + i;
}

string reverseString(string s)
{
	if (s.length() == 1)
	{
		return s;
	}
	string newString = reverseStringHelper(s);
	return newString;
}

string reverseStringHelper(string s)
{
	if (s.length() == 1)
	{
		return s.substr(0,1);
	}
	string firstLetter = s.substr(s.length()-1,s.length()-1);	//first letter of "ABC" is 'C'
	s = s.substr(0, s.length()-1);	//"ABCDEF" becomes "ABCDE"
	return firstLetter + reverseStringHelper(s);
}
int countOccurrences(string s, string c)
{
	int total;
	total = countOccurrencesHelper(s, c, 0, s.length());
	return total;
}
int countOccurrencesHelper(string s, string c, int counter, int wordSize)
{
	if(counter == wordSize)
	{
		return 0;
	}
	if(s.substr(counter, 1) == c)
	{
		return 1 + countOccurrencesHelper(s, c, counter+1, wordSize);
	}
	else
	{
		return countOccurrencesHelper(s, c, counter+1, wordSize);
	}
}
