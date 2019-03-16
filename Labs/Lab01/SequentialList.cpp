#include "SequentialList.hpp"
#include <iostream>
#include <string>

using namespace std;
SequentialList::SequentialList(unsigned int cap)
{
	capacity_ = cap;
	size_ = 0;
	data_ = new DataType[cap];
}

SequentialList::~SequentialList()
{
	delete data_;
	data_ = NULL;
}

bool SequentialList::empty() const
{
	return size_ == 0;
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::full() const
{
	return size_ == capacity_;
}

void SequentialList::print() const
{
	cout << "(";
	if (size_ == 0)
		cout << ")" << endl;

	else
	{
		for (unsigned i = 0; i < size_; i++)
			cout << data_[i] << "->";
		cout << ")" << endl;
	}

}

bool SequentialList::insert_front(DataType val)
{
	if (size_ == capacity_ || capacity_ == 0)
		return false;
	else
	{
		for (unsigned i = size_; i > 0; i--)
			data_[i + 1] = data_[i];
		data_[0] = val;
		size_++;
		return true;
	}
}

bool SequentialList::remove_front()
{
	if (size_ == 0)
		return false;
	else
	{
		data_[0] = 0;
		for (unsigned i = 0; i < size_; i++)
			data_[i] = data_[i + 1];
		size_--;
		return true;
	}
}

bool SequentialList::insert_back(DataType val)
{
	if (size_ == capacity_)
		return false;
	else
	{
		data_[size_ + 1] = val;
		size_++;
		return true;
	}
}

bool SequentialList::remove_back()
{
	if (size_ == 0)
		return false;
	else
	{
		size_--;
		return true;
	}
}

bool SequentialList::insert(DataType val, unsigned int index)
{
	if (size_ == capacity_)
		return false;
	if (index > size_ || index < 0)
		return false;
	else
	{
		for (unsigned i = size_; i > index; i--)
			data_[i + 1] = data_[i];
		data_[index] = val;
		size_++;
	}
}

bool SequentialList::remove(unsigned int index)
{
	if (size_ == 0)
		return false;
	if (index > size_ || index < 0)
		return false;
	else
	{
		data_[index] = 0;
		for (unsigned i = index; i < size_; i++)
			data_[i] = data_[i + 1];
		size_--;
		return true;
	}
}

unsigned int SequentialList::search(DataType val) const
{
	if (size_ == 0)
		return size_;
	unsigned index = 0;
	DataType check = 0;
	while (index < size_)
	{
		check = data_[index];
		if (check = val)
			return index;
		index++;
	}
	return size_;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if (index > size_ || index < 0)
		return data_[size_];
	else
		return data_[index];

}

bool SequentialList::replace(unsigned int index, DataType val)
{
	if (index > size_ || index < 0)
		return false;

	else
	{
		data_[index] = val;
		return true;
	}
}
