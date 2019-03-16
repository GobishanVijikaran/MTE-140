#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

class DoublyLinkedList
{
    friend class DoublyLinkedListTest;
    
public:
    typedef int DataType;
    static const unsigned int CAPACITY = 65536;

private:
    struct Node {
        Node(DataType value);
        DataType value;
        Node* next;
        Node* prev;
    };
    Node* getNode(unsigned int index) const;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

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
    // returns the size of the list otherwise.
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
    // A pointer to the head node of the list.
    Node* head_;
    // A pointer to the tail node of the list.
    Node* tail_;
    // The number of elements in the list.
    unsigned int size_;
    
private:
    DoublyLinkedList(const DoublyLinkedList& rhs) {}
    DoublyLinkedList& operator=(const DoublyLinkedList& rhs) {return *this;}
};

#endif
