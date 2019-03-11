//Code produced by Gunnar Crabb and Almat Yeraly
//All code is our own unless otherwise specified below
//code last modified on 3/7/2019 at 3:55pm
/*
Summary of our code: 
The Vector class is developed to mimic the properties of stl::vector built into C++. It acts as a dynamic array that can be automatically
or manually resized, have values inserted into it, have values deleted from it, and can output these values at their indexes.
*/

#ifndef VECTOR_H_
#define VECTOR_H_

namespace cs273
{
	template<typename Type>

	class Vector {
	private:
		Type * the_data;
		int current_capacity;
		int num_items;
	public:
		Vector<Type>(); // default constructor
		virtual ~Vector<Type>(); // default destructor
		Vector<Type>(Vector<Type> &other); // copy constructor

		Vector<Type> &operator=(Vector<Type> &other); // used to set vectors equal to eachother

		Type &operator[] (int index); // uses the brackets to get and return data from a certain index
		Type at(int index); // uses an at function to get and return a piece of data at a provided index

		void resize(int n); // used to manually resize the vector, will delete items in the vector if resized smaller than num_items. 
							//Called by insert function to double the array size if current_capacity = num_items.
		int size(); // gets the size of the vector by returning num_items
		int capacity(); // gets the capacity of the vector by returning current_capacity
		void assign(int index, Type element); // alters a value at the index of the vector
		void insert(int index, Type element); // shifts the values of the vector over and places a new value at the index, incrementing num_items
		void push_back(Type element); // build off of insert, placing an item at the front of the vector.
		void pop_back(); // build off of erase, removing the item at the front of the vector.
		void erase(int index); // shifts the items in the vector backward to the index, erasing it. Decriments num_items.
		void swap(Vector<Type> &other); // Swaps pointers between vectors

	};
#endif



	template<typename Type>
	inline Vector<Type>::Vector()
	{
		current_capacity = 10;
		num_items = 0;
		the_data = new Type[current_capacity];
	}

	template<typename Type>
	inline Vector<Type>::~Vector()
	{
		delete[] the_data;
	}


	template<typename Type>
	inline Vector<Type>::Vector(Vector<Type>& other)
	{
		// Took and modified this code from https://codereview.stackexchange.com/questions/60484/stl-vector-implementation 
		delete[] the_data;
		current_capacity = other.capacity();
		num_items = other.size();
		the_data = new Type[current_capacity];
		for (int i = 0; i < num_items; i++)
		{
			the_data[i] = other[i];
		}
	}

	template<typename Type>
	inline Vector<Type>& Vector<Type>::operator=(Vector<Type>& other)
	{
		swap(other);
		return *this;
	}

	template<typename Type>
	inline Type & Vector<Type>::operator[](int index)
	{
		// Took this from the powerpoint 
		if (index < 0 || index >= num_items)
		{
			throw std::invalid_argument("index invalid");
		}
		return the_data[index];
	}

	template<typename Type>
	inline Type Vector<Type>::at(int index)
	{
		// Took this from the powerpoint 
		if (index < 0 || index >= num_items)
		{
			throw std::invalid_argument("index invalid");
		}
		return the_data[index];
	}

	template<typename Type>
	inline void Vector<Type>::resize(int n)
	{
		// Took and modified this from the powerpoint
		Type *new_data = new Type[n];
		if (num_items <= n) {
			for (int i = 0; i < num_items; i++) {
				new_data[i] = the_data[i];
			}
		}
		else if (num_items > n) {
			for (int i = 0; i < n; i++) {
				new_data[i] = the_data[i];
			}
			num_items = n;
		}

		delete[] the_data;
		the_data = new_data;
		current_capacity = n;
	}

	template<typename Type>
	inline int Vector<Type>::size()
	{
		return num_items;
	}

	template<typename Type>
	inline int Vector<Type>::capacity()
	{
		return current_capacity;
	}

	template<typename Type>
	inline void Vector<Type>::assign(int index, Type element)
	{
		the_data[index] = element;
	}

	template<typename Type>
	inline void Vector<Type>::insert(int index, Type element)
	{
		if (index - num_items > 1)
		{
			throw std::invalid_argument("index invalid");
		}

		if (num_items == current_capacity)
		{
			this->resize(2 * current_capacity);
		}
		if (index != num_items) {
			for (int i = num_items; i >= index; i--)
			{
				the_data[i + 1] = the_data[i];
			}
		}

		num_items++;
		this->assign(index, element);
	}

	template<typename Type>
	inline void Vector<Type>::push_back(Type element)
	{
		this->insert(num_items, element);
	}

	template<typename Type>
	inline void Vector<Type>::pop_back()
	{
		this->erase(num_items);
	}

	template<typename Type>
	inline void Vector<Type>::erase(int index)
	{
		if (index > num_items)
		{
			throw std::invalid_argument("index invalid");
		}
		for (int i = index; i < num_items; i++)
		{
			the_data[i] = the_data[i + 1];
		}
		num_items = num_items - 1;
	}

	template<typename Type>
	inline void Vector<Type>::swap(Vector<Type>& other)
	{
		Vector<Type> temp;
		*this->temp;
		other->*this;
		temp->other;
	}

}