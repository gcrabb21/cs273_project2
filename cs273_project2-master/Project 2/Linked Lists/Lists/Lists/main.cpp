#include <iostream>
#include <list>
#include "Address.h"
using namespace std;

void sort(list<Address>& l1);
void merge(list<Address>& l1, list<Address>& l2);
void unique(list<Address>& l1);

int main()
{
	list<Address> lst1;
	list<Address> lst2; //second list to test merge

	Address a1("Almat", "hawthorne", 99251, "spokane", "washington", "ayeraly20");
	Address a2("Gunnar", "20th", 99206, "spokane valley", "washington", "gcrabb21");
	Address a3("Gunnar", "20th", 99206, "spokane valley", "washington", "gcrabb21"); //duplicate item to test unique

	lst1.push_back(a1);
	lst1.push_back(a2);
	lst1.push_back(a3); //adding all elements to the first list

	sort(lst1);

	unique(lst1);

	system("pause");
	return 0;
	//end of line
}

void sort(list<Address>& l1)
{
	l1.sort(); //sorts the list based on its parameters using the < operator, 
	// overloaded in Address.h to evaluate based on state, then city, then name in that order.
}

void merge(list<Address>& l1, list<Address>& l2)
{
	l1.sort(); //sorts the first list as previously specified.
	l2.sort(); //sorts the second list, both lists must be sorted in order for them to be merged.
	l1.merge(l2); //merge will take the 2nd list and move all of its elements into the first list into their sorted order, leaving l2 empty.
}

void unique(list<Address>& l1)
{
	l1.unique(); //compares all elements in a list using the overloaded == operator to determine if they are equal or not,
	//then will omit the items from the list that are equal with eachother, leaving only unique values.
}
