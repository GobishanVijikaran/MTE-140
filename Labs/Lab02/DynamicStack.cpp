#include "DynamicStack.hpp"
#include <iostream>
#include <stddef.h>

using namespace std; 


typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	size_ = 0; 
	capacity_ = 16; 
	init_capacity_ = 0; 
	items_ = new StackItem [capacity_]; 
}

DynamicStack::DynamicStack(unsigned int capacity)
{ 
	init_capacity_= capacity; 
	if (capacity == 0)
	{
		init_capacity_ = 16; 
	}
	capacity_ = init_capacity_; 
	size_= 0; 
	items_ = new StackItem (init_capacity_); 
}

DynamicStack::~DynamicStack()
{
	delete items_;  
}

bool DynamicStack::empty() const
{
	if (size_ == 0)
	{ 
		return true; 
	}
	else return false; 
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if (size_ >= capacity_)
	{
		capacity_ *= 2; 
		StackItem* temp = new StackItem [capacity_]; 
		for (int i = 0; i < size_; i++)
		{
			temp [i] = items_[i]; 
		}
		delete [] items_; 
		items_ = temp; 
		delete [] temp; 
		temp = NULL; 
	}
	
	items_[size_] = value; 
	size_++; 
}

StackItem DynamicStack::pop()
{
	if (size_ == 0)
	{
		return EMPTY_STACK; 
	}
	
	StackItem value = items_ [size_-1]; 
	size_ --; 
	return value; 
	
	if ((size_ <= 1/4*capacity_) && (capacity_/2 > init_capacity_))
	{
		StackItem* temp = new StackItem [capacity_/2]; 
		for (int i = 0; i < size_; i++)
		{
			temp[i] = items_[i]; 
		}
		delete [] items_; 
		items_ = temp; 
		delete [] temp; 
		temp = NULL; 
	}
}

StackItem DynamicStack::peek() const
{
		if (size_ == 0)
	{
		return EMPTY_STACK; 
	}
	
	StackItem value = items_ [size_-1]; 
	return value; 
}

void DynamicStack::print() const
{
	cout << "(" ; 
	for (int i=0; i<size_; i++)
	{
		cout << items_[i] << ","; 
	}
	cout << ")" << endl; 
}
