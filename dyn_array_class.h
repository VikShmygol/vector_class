#pragma once

class DynamicArray
{
public:
	DynamicArray(); //default consturctor
	DynamicArray(const DynamicArray& copied); //copy constructor
	DynamicArray& operator= (const DynamicArray& obj); //assignment operator overloading
	~DynamicArray(); //default destructor
	void PushBack(int element); //push back method
	void Insert(int index, int element); //insert method (puts new element before desired index)
	void Erase(int index); //erases element with desired index
	void Clear(); //deletes all data from array, reduces its size to 0
	int Find(int value); //finds first element with equal value, returns its index, if not found returns -1
	int& operator [] (int index); //subscript operator overloading for reading/writing the value
	
	int get_size() const; //++
	int get_capacity() const; //++
	int* get_data() const; //++
	
private:
	int size_ = 0;
	int capacity_ = 1;
	int* dyn_array_;
};

