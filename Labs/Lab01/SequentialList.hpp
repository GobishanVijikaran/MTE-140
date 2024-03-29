#ifndef SEQUENTIAL_LIST_HPP
#define SEQUENTIAL_LIST_HPP

class SequentialList
{
    // Befriend so tests have access to variables.
    friend class SequentialListTest;

public:
    typedef int DataType;

public:
    SequentialList(unsigned int cap);
    ~SequentialList();

public:
    // Returns the number of elements in the list.
    unsigned int size() const;
    // Returns the maximum number of elements the list can hold.
    unsigned int capacity() const;
    // Returns true if the list is empty, false otherwise.
    bool empty() const;
    // Returns true if the list is at capacity, false otherwise.
    bool full() const;
    // Returns the value at the given index in the list. If index is invalid,
    // return the value of the last element.
    DataType select(unsigned int index) const;
    // Searches for the given value, and returns the index of this value if found.
    // Returns the size of the list otherwise
    unsigned int search(DataType val) const;
    // Prints all elements in the list to the standard output.
    void print() const;

public:
    // Inserts a value into the list at a given index.
    bool insert(DataType val, unsigned int index);
    // Inserts a value at the beginning of the list.
    bool insert_front(DataType val);
    // Inserts a value at the end of the list.
    bool insert_back(DataType val);
    // Deletes a value from the list at the given index.
    bool remove(unsigned int index);
    // Deletes a value from the beginning of the list.
    bool remove_front();
    // Deletes a value at the end of the list.
    bool remove_back();
    // Replaces the value at the given index with the given value.
    bool replace(unsigned int index, DataType val);
  
private:
    // A pointer to the block of memory allocated to store the list data.
    DataType *data_;
    // The capacity of the list 
    unsigned int capacity_;
    // The number of used elements in data_.
    unsigned int size_;
    

private:
    SequentialList(const SequentialList& rhs) {}
    SequentialList& operator=(const SequentialList& rhs) {return *this;}
};

#endif 
