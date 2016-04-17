#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <assert.h>

//doesn't need a cpp file because it's made with templatization
template <typename T>
class Vector
{
public:
	T* vector = nullptr;
	int num_elements = 0;//amount of current elements it has
	int length = 10;//max capacity of the vector(h
public:

	Vector()
	{
		vector = new T[length];
	}

	Vector(const int num)
	{
		length = num;
		num_elements = num;

		vector = new T[num];

	}

	Vector(const Vector<T>& other)
	{
		num_elements = other.num_elements;

		if (length < other.length)
			vector = new T[other.length];

		length = other.length;

		for (int i = 0; i < num_elements; i++)
			vector[i] = other.vector[i];
	}

	~Vector()
	{
		delete[] vector;
	}

	T operator[](int pos) const
	{
		
		return vector[pos];

	}

	T& operator[](int pos)
	{

		
		return vector[pos];

	}

	void PushBack(const T& element)
	{


		if (num_elements == length)
		{
			T* new_elements;

			new_elements = new T[length + 10];

			for (int i = 0; i < length; i++)
				new_elements[i] = vector[i];

			length += 10;

			delete[] vector;
			vector = new_elements;
		}
		vector[num_elements] = element;
		num_elements++;
	}

	void PushFront(const T& element)
	{

		num_elements++;

		if (num_elements > length)
		{
			T* new_elements;
			length += 10;
			new_elements = new T[length];

			for (int i = num_elements; i >= 0; i--)
				new_elements[i + 1] = elements[i];


			delete[] vector;
			vector = new_elements;

		}

		else for (int i = num_elements; i > 0; i--)
			vector[i] = vector[i - 1];


		vector[0] = element;
		num_elements++;

	}

	bool Empty()
	{
		if (num_elements == 0)
			return true;
		else 
			return false;
	}

	void Clean()
	{
		num_elements = 0;
	}

	bool PopBack(T& value)
	{
		if (num_elements > 0)
		{
			num_elements--;
			value = vector[num_elements];

		}

		else 
			return false;
	}

	


};

#endif
