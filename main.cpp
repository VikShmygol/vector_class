#include <iostream>
#include "dyn_array_class.h"

void Print(DynamicArray& arr)
{
	for (int i = 0; i < arr.get_size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	try
	{
		DynamicArray v;
		v.PushBack(1);
		v.PushBack(2);
		v.PushBack(7);
		v.PushBack(8);
	//	v.Clear();

		DynamicArray w(v);
		DynamicArray x = w;
		x.Insert(3, 111);
		Print(x);
		Print(w);
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what();
	}
	
	
	return 0;

}
