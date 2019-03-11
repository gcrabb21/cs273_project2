#include <iostream>
#include "Vector.h"
using namespace cs273;

int main()
{
	Vector<int> *v1 = new Vector<int>();

	std::cout << v1->size()<< std::endl; //test size and capacity getters while also testing proper initialization
	std::cout << v1->capacity() << std::endl; //values should show 0 and 10 (for empty vector with capacity 10)

	std::cout << std::endl; //--------------------------------------------------

	for (int i = 0; i < 12; i++) 
	{
		v1->insert(i, i); //test insert and at functions, populate the vector with values.
		std::cout << v1->at(i) << " "; //should show values 0 through 11
	}
	
	std::cout << std::endl;//--------------------------------------------------

	v1->push_back(100); //test push back and at functions
	std::cout << v1->at(12) << std::endl; //should show value 100

	std::cout << std::endl;//--------------------------------------------------

	v1->insert(5, 200);

	for (int i = 0; i < v1->size(); i++) //test insert into a populated vector
	{
		std::cout << v1->at(i) << " "; //should show values 0 through 11 with 200 at index 5 and 100 at the end
	}

	std::cout << "\n";//--------------------------------------------------

	v1->assign(5, 500);

	for (int i = 0; i < v1->size(); i++) //test assign into a populated vector
	{
		std::cout << v1->at(i) << " "; //should show values 0 through 11 with 500 at index 5 and 100 at the end
	}

	std::cout << "\n";//--------------------------------------------------

	v1->erase(5);

	for (int i = 0; i < v1->size(); i++) //test erase in a populated vector
	{
		std::cout << v1->at(i) << " "; //should show values 0 through 11 with 100 at the end
	}

	std::cout << "\n";//--------------------------------------------------

	v1->pop_back();

	for (int i = 0; i < v1->size(); i++) //test pop_back function in a populated vector
	{
		std::cout << v1->at(i) << " "; //should show values 0 through 11
	}

	std::cout << "\n";//--------------------------------------------------

	std::cout << v1->size() << std::endl; //test getters for a populated, resized vector
	std::cout << v1->capacity() << std::endl; //should show 12 and 20 for vector of size 12 with capacity 20 (doubled capacity)


	Vector<int> *v2 = new Vector<int>(); // initializing new vector

	for (int i = 0; i < 12; i++) 
	{
		v2->insert(i, i+100); // inserting valus from 100 through 111
	}

	v1 = v2; // test of operator=

	for (int i = 0; i < v1->size(); i++) //test pop_back function in a populated vector
	{
		std::cout << v1->at(i) << " "; //should show values 100 through 111
	}

	std::cout << "\n";//--------------------------------------------------

	Vector<int> *v3 = new Vector<int>(*v2);

	for (int i = 0; i < v1->size(); i++) //test pop_back function in a populated vector
	{
		std::cout << v3->at(i) << " "; //should show values 100 through 111
	}


	system("pause");
	return 0;
	//end of line
}