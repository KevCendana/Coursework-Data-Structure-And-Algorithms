#include <list>
#include <string>
using namespace std;
class Stack
{
private:
	int size;
	list<string*> arrPtr;
	int topElement;
	int countOfArrays;	//not necessary but makes things easier
public:
	Stack(int);
	bool push(string);
	bool top(string&);
	bool pop(string&);
	void destroy();
	~Stack();  
};
