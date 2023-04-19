#include <iostream>
#include <string>
#include "LL.h"
using namespace std;

int main() {

//my own test code~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	LL<string> test;
//	//testing push_back, successful
//	test.display_list();
//	test.push_back("jeff");
//	test.display_list();
//	test.push_back("jeff2");
//	test.push_back("jeff3");
//	test.push_back("jeff4");
//	test.push_back("jeff5");
//	test.push_back("jeff6");
//	test.display_list();
//	//testing retrieve_back, successful
//	cout << test.retrieve_back() << endl;
//	//testing display_nodes, successful
//	//testing destroy_list, successful
//	test.destroy_list();
//	test.display_list();	//looks like the list is empty
//	test.destroy_list();	//looks like the list is already empty
//	//testing list_length, success
//	cout << test.list_length() << endl;	//0
//	test.push_back("one");
//	test.push_back("two");
//	cout << test.list_length() << endl; //2
//	test.push_back("three");
//	test.push_back("four");
//	cout << test.list_length() << endl;	 //4
//	test.destroy_list();
//	cout << test.list_length() << endl;	//0
//	//testing search_list, successful
//	if (test.search_list("")) {cout << "Found! " << endl;}
//	else{cout << "Not Found. " << endl;}
//	test.push_back("hoopla");
//	if (test.search_list("junebug")) {cout << "Found! " << endl;}
//	else{cout << "Not Found. " << endl;}
//	if (test.search_list("hoopla")) {cout << "Found! " << endl;}
//	else{cout << "Not Found. " << endl;}
//	//testing delete_node, success
//	test.display_list();
//	test.push_back("uno");
//	test.push_back("dos");
//	test.display_list();
//	bool tf = test.delete_node("hoopla");
//	test.display_list();
//	cout << "That's all folks " << endl;

//main 1~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	LL ll1;
//	cout << "length of empty list - " << ll1.list_length() << endl;
//	ll1.display_list();
//	ll1.push_front("aaaaa");
//	ll1.push_back("bbbbb");
//	ll1.push_front("before aaaaa");
//	ll1.push_back("after bbbbb");
//	cout << "length of list after 4 pushes - " << ll1.list_length() << endl;
//	ll1.display_list();
//	cout << endl;
//
//	LL ll2;
//	ll2.push_front("33333");
//	ll2.push_front("22222");
//	ll2.push_front("11111");
//	ll2.push_back("44444");
//	ll2.push_back("55555");
//	ll2.push_back("66666");
//	ll2.display_list();

//main 2~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	LL <string> ll1;
//	cout << "main: length of empty list - " << ll1.list_length() << endl;
//	cout << "main: trying to display empty list 1" << endl;
//	ll1.display_list();
//	cout << "main: trying to display initial size of ll1 - " << ll1.list_length() << endl;
//	ll1.push_front("aaaaa");
//	ll1.push_back("bbbbb");
//	ll1.push_front("before aaaaa");
//	ll1.push_back("after bbbbb");
//	cout << "main: length of ll1 after 4 pushes - " << ll1.list_length() << endl;
//	cout << "main: now trying to display ll1 after 4 push's" << endl;
//	ll1.display_list();
//	cout << "main: displaying final size of ll1 - " << ll1.list_length() << endl;
//	cout << endl;
//
//	LL <string> ll2;
//	ll2.push_front("33333");
//	ll2.push_front("22222");
//	ll2.push_front("11111");
//	ll2.push_back("44444");
//	ll2.push_back("55555");
//	ll2.push_back("66666");
//	cout << "main: now trying to display ll2 after 6 push's" << endl;
//	ll2.display_list();

//main 3~~~~~~~~~~~~~~~~~~~~~~~~~~~

	LL <string> ll1;
	cout << "main: length of empty list - " << ll1.list_length() << endl;
	cout << "main: trying to display empty list 1" << endl;
	ll1.display_list();
	cout << "main: trying to display initial size of ll1 - " << ll1.list_length() << endl;
	ll1.push_front("aaaaa");
	ll1.push_back("bbbbb");
	ll1.push_front("before aaaaa");
	ll1.push_back("after bbbbb");
	cout << "main: length of ll1 after 4 pushes - " << ll1.list_length() << endl;
	cout << "main: now trying to display ll1 after 4 push's" << endl;
	ll1.display_list();
	cout << "main: displaying final size of ll1 - " << ll1.list_length() << endl;
	ll1.destroy_list();
	cout << "main: displaying size of list 1 after destroy - " << ll1.list_length() << endl;
	cout << endl;

	LL <string> ll2;

	ll2.push_front("33333");
	ll2.push_front("22222");
	ll2.push_front("11111");
	ll2.push_back("44444");
	ll2.push_back("55555");
	ll2.push_back("66666");
	cout << "main: now trying to display ll2 after 6 push's" << endl;
	ll2.display_list();
	cout << "main: now searching for node 44444" << endl;
	if (ll2.search_list("44444"))
	{
		cout <<"main: found node 44444" << endl;
	}
	else
	{
		cout << "main: did not find node 44444" << endl;
	}
	cout << "main: now searching for node 44445" << endl;		//error starts here
	if (ll2.search_list("44445"))
	{
		cout <<"main: found node 44445" << endl;
	}
	else
	{
		cout << "main: did not find node 44445" << endl;
	}
	cout << "main: now trying to delete node 44444" << endl;		//delete note starts here
	if (ll2.delete_node("44444"))					//should return true
	{
		cout <<"main: node 44444 deleted" << endl;
	}
	else
	{
		cout << "main: did not find 44444 for delete" << endl;		//this should not pop up
	}
	if (ll2.search_list("44444"))
	{
		cout <<"main: searched for 44444 after delete, found" << endl;
	}
	else
	{
		cout << "main: searched for 44444 after delete, not found" << endl;
	}
	cout << "main: displaying whole list after delete 44444" << endl;
	ll2.display_list();
	cout << "main: now trying to delete node 11111" << endl;
	if (ll2.delete_node("11111"))
	{
		cout <<"main: node 11111 deleted" << endl;
	}
	else
	{
		cout << "main: did not find node 11111 for delete" << endl;
	}
	cout << "main displaying whole list after delete 11111" << endl;
	ll2.display_list();
	ll2.destroy_list();

}
