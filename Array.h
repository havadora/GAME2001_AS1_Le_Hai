#pragma once
#include <cassert>
#include <iostream>
using namespace std;

template <class T>
class ArrayBased
{
public:
	// Contrustor
	ArrayBased(int size, int growBy = 1) : arrays(NULL), maxArray(0), growArray(0), numArray(0)
	{
		if (size)
		{
			maxArray = size;
			arrays = new T[maxArray];
			memset(arrays, 0, sizeof(T) * maxArray);
			growArray = ((growArray > 0) ? growBy : 0);
		}
	}
	//Destructor
	~ArrayBased()
	{
		if (arrays != nullptr)
		{
			delete[] arrays;
			arrays = nullptr;
		}
	}
	//Get Function


	//Set Function
	

protected:

	T*  arrays;
	int numArray;
	int maxArray;
	int growArray;

};

template <class T>
 class UnorderArray : public ArrayBased<T>
{
public:
	UnorderArray(int sizeArray) : ArrayBased<T>(sizeArray){}
	
	~UnorderArray() {}

	//push
	void push(T val)
	{
		//assert(this->arrays != nullptr);
		if (check(val) == true)
		{
			if (this->numArray >= this->maxArray)
			{
				Expand();
			}
			this->arrays[this->numArray] = val;
			this->numArray++;
		}
		if (check(val) == false)
		{
			cout << "This number alreay in the array" << endl;
		}

	}

	void pop()
	{
		if (this->numArray > 0)
		{
			this->numArray--;
		}
	}

	void remove(int index)
	{
		assert(this->arrays != nullptr);

		if (index >= this->numArray)
		{
			return;
		}

		for (int i = index; i < this->numArray; i++)
		{
			this->arrays[i] = this->arrays[i + 1];
		}
	}
	int search(T num)
	{
		assert(this->arrays != nullptr);

		for (int i = 0; i < this->numArray; i++)
		{
			if(this->arrays[i] == num)
			{
				return i;
			}

		}
		return -1;
	 }

	T& operator[](int index)
	{
		assert(this->arrays != nullptr && index < this->numArray);
		return this->arrays[index];
	}

	void clear()
	{
		this->numArray = 0;
	}

	bool Expand()
	{
		if (this->growArray <= 0)
		{
			return false;
		}

		T* temp = new T[this->maxArray + this->growArray];
		assert(temp != nullptr);
		memcpy(temp, this->arrays, sizeof(T) * this->maxArray);
		delete[] this->arrays;

		this->arrays = temp;
		temp = nullptr;

		this->maxArray += this->growArray;
		return true;
	}
	

	bool check(T num)
	{
		//assert(this->arrays != nullptr);

		for (int i = 0; i <= this->numArray; i++)
		{
			if (this->arrays[i] == num)
			{
				return false;
			}
			else
               return true;
		}
		return true;
	}
	void print()
	{
		for (int i = 0; i < this->numArray; i++)
		{
			cout << this->arrays[i] << " ";
		}
		cout << endl;
	}

	void expansion(int time)
	{
		for (int i = 0; i < time; i++)
		{
			T temp;
			temp = this->arrays[i] * 2;
			push(temp);
		}
	}
private:
	
	
};
template <class T>
class OrderArray : public ArrayBased<T>
{
public:
	OrderArray(int sizeArray) : ArrayBased<T>(sizeArray)
	{}
	~OrderArray() {}

	//push

	void print()
	{
		for (int i = 0; i < this->maxArray; i++)
		{
			cout << this->arrays[i] << " ";
		}
		cout << endl;
	}

	void push(T val)
	{
		assert(this->arrays != nullptr);
		if (check(val) == true)
		{
			if (this->numArray >= this->maxArray)
			{
				Expand();
			}

			this->arrays[this->numArray] = val;
			this->numArray++;
		}
		if (check(val) == false )
		{
			cout << "This number alreay in the array" << endl;
		}

	}

	void pop()
	{
		if (this->numArray > 0)
		{
			this->numArray--;
		}
	}

	void remove(int index)
	{
		assert(this->arrays != nullptr);

		if (index >= this->numArray)
		{
			return;
		}

		for (int i = index; i < this->numArray; i++)
		{
			this->arrays[i] = this->arrays[i + 1];
		}
	}
	int search(T num)
	{
		assert(this->arrays != nullptr);

		for (int i = 0; i < this->numArray; i++)
		{
			if (this->arrays[i] == num)
			{
				return i;
			}

		}
		return -1;
	}

	T& operator[](int index)
	{
		assert(this->arrays != nullptr && index <= this->numArray);
		return this->arrays[index];
	}

	void clear()
	{
		this->numArray = 0;
	}

	bool Expand()
	{
		if (this->growArray <= 0)
		{
			return false;
		}

		T* temp = new T[this->maxArray + this->growArray];
		assert(temp != nullptr);
		memcpy(temp, this->arrays, sizeof(T) * this->maxArray);
		delete[] this->arrays;

		this->arrays = temp;
		temp = nullptr;

		this->maxArray += this->growArray;
		return true;
	}
	

	bool check(T num)
	{
		assert(this->arrays != nullptr);

		for (int i = 0; i <= this->numArray; i++)
		{
			if (this->arrays[i] == num)
			{
				return false;
			}
			return true;
		}
		return true;
	}
	void sorting()
	{
		
		int temp;
		for (int i = 0; i < this->numArray; i++)
		{
			for (int j = 0; j < this->numArray - 1; j++)
			{
				if (this->arrays[j] > this->arrays[j+1])
				{
					temp = this->arrays[j];
					this->arrays[j] = this->arrays[j+1];
					this->arrays[j+1] = temp;
				}

			}
		}
		
	}
private:
	//int growsArray;
};