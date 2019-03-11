#include <iostream>
#include <list>
#include "Address.h"
using namespace std;

void sort(list<Address>& l1);
void merge(list<Address>& l1, list<Address>& l2);
void unique(list<Address>& l1);

int main()
{
	list<Address> lst;

	Address a1("Almat", "hawthorne", 99251, "spokane", "washington", "ayeraly20");

	lst.push_back(a1);

	system("pause");
	return 0;
}

void sort(list<Address>& l1)
{
	l1.sort();
}

void merge(list<Address>& l1, list<Address>& l2)
{

}

void unique(list<Address>& l1)
{

}
