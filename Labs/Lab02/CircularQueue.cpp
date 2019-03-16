#include<cstring>
#include<iostream>
#include "CircularQueue.hpp"

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

using namespace std; 

CircularQueue::CircularQueue()
{
	capacity_ = 16; 
	size_ = 0; 
	head_ = 0; 
	tail_ = 0; 
	items_ = new QueueItem [capacity_]; 
}

CircularQueue::CircularQueue(unsigned int capacity)
{
	capacity_ = capacity; 
	size_ = 0; 
	head_ = 0; 
	tail_ = 0; 
	items_ = new QueueItem [capacity]; 
}

CircularQueue::~CircularQueue()
{
	delete items_; 
}

bool CircularQueue::empty() const
{    
	if (size_ == 0)
	{
		return true; 
	}
	
	else return false; 
}

bool CircularQueue::full() const
{
	if (size_ == capacity_)
	{
		return true; 
	}
	else return false; 
}

int CircularQueue::size() const
{  
	return size_; 
}

bool CircularQueue::enqueue(QueueItem value)
{
	if (full())
	{
		return false; 
	}
	
	else
	{
		items_[tail_] = value;
		tail_++; 
		tail_ %= capacity_; 
		size_++; 
		return true; 
	}
}

QueueItem CircularQueue::dequeue()
{
	if (size_ == 0)
	{
		return EMPTY_QUEUE;
	}

	else
	{
		QueueItem temp = items_[head_]; 
		head_++; 
		head_ %= capacity_; 
		size_--; 
		return temp; 
	}
}

QueueItem CircularQueue::peek() const
{
	if (size_ == 0)
	{
		return EMPTY_QUEUE; 
	}
	QueueItem value = items_[head_]; 
	return value; 
}

void CircularQueue::print() const
{
	cout << "(" ; 
	for (int i=0; i<size_; i++)
	{
		cout << items_[i] << ","; 
	}
	cout << ")" << endl; 
}
