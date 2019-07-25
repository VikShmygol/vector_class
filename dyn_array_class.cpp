#include "dyn_array_class.h"
#include <stdexcept>
#include <algorithm>

DynamicArray::DynamicArray() : dyn_array_(new int[capacity_]) {}

DynamicArray::DynamicArray(const DynamicArray& copied_arr)
	: size_(copied_arr.get_size()), 
	capacity_(copied_arr.get_capacity()),
	dyn_array_(new int[copied_arr.get_capacity()]) 
{
	std::copy(copied_arr.get_data(), copied_arr.get_data() + copied_arr.get_size(), dyn_array_);
}

DynamicArray& DynamicArray::operator= (const DynamicArray& obj)
{
	if (&obj != this) {
		size_ = obj.get_size();
		capacity_ = obj.get_capacity();
		delete[] dyn_array_;
		dyn_array_ = new int[capacity_];
		std::copy(obj.get_data(), obj.get_data() + size_, dyn_array_);
	}
	return *this;
}

DynamicArray::~DynamicArray()
{
	if (dyn_array_ != nullptr) {
		delete[] dyn_array_;
		dyn_array_ = nullptr;
	}
}

void DynamicArray::PushBack(int element)
{
	if (size_ == capacity_)
	{
		capacity_ *= 2;
		int* temp = new int[capacity_];
		for (int i = 0; i < size_; ++i)
		{
			temp[i] = dyn_array_[i];
		}
		delete[] dyn_array_;
		dyn_array_ = temp;
		temp = nullptr;
	}
	dyn_array_[size_++] = element;
}

void DynamicArray::Insert(int index, int element)
{
	int new_size = index + 1;

	if (new_size > capacity_ || index < 0) {
		throw std::invalid_argument("wrong insertion index");
	}

	if (size_ == capacity_)
	{
		capacity_ *= 2;
		int* temp = new int[capacity_];
		for (int i = 0; i < index; ++i)
		{
			temp[i] = dyn_array_[i];
		}

		for (int i = index + 1; i <= size_; ++i)
		{
			temp[i] = dyn_array_[i-1];
		}

		temp[index] = element;
		size_++;

		delete[] dyn_array_;
		dyn_array_ = temp;
		temp = nullptr;
	} else {
		int* temp = new int[capacity_];
		for (int i = 0; i < index; ++i)
		{
			temp[i] = dyn_array_[i];
		}	

		for (int i = index + 1; i <= size_; ++i)
		{
			temp[i] = dyn_array_[i-1];
		}

		size_++;
		temp[index] = element;

		delete[] dyn_array_;
		dyn_array_ = temp;
		temp = nullptr;
	}
}

void DynamicArray::Erase(int index)
{
	if ((index + 1) > size_ || index < 0) {
		throw std::invalid_argument("wrong erase index");
	}

	int* temp = new int[capacity_];

	for (int i = 0; i < index; ++i)
	{
		temp[i] = dyn_array_[i];
	}

	for (int i = index + 1; i < size_; ++i)
	{
		temp[i-1] = dyn_array_[i];
	}

	size_--;
	delete[] dyn_array_;
	dyn_array_ = temp;
	temp = nullptr;
}

void DynamicArray::Clear()
{
	size_ = 0;
	capacity_ = 1;
	delete[] dyn_array_;
	dyn_array_ = new int[capacity_];
}

int DynamicArray::Find(int value)
{
	for (int i = 0; i < size_; ++i)
	{
		if (dyn_array_[i] == value) { return i; }
	}

	return -1;
}

int DynamicArray::get_size() const
{
	return size_;
}

int& DynamicArray::operator[] (int index)
{
	if ((index + 1) > size_ || index < 0) {
		throw std::invalid_argument("wrong index while indexing");
	}

	return dyn_array_[index];
}

int DynamicArray::get_capacity() const
{
	return capacity_;
}

int* DynamicArray::get_data() const
{
	return dyn_array_;
}
