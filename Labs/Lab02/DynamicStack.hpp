#ifndef DYNAMIC_STACK_HPP
#define DYNAMIC_STACK_HPP

class DynamicStack
{
    friend class DynamicStackTest;
    
public:
    typedef int StackItem; 
    static const StackItem EMPTY_STACK;

    // Default capacity is 16.
    DynamicStack();
    DynamicStack(unsigned int capacity);
    ~DynamicStack();
    
    void push(StackItem value);
    StackItem pop();
    bool empty() const;
    int size() const;
    StackItem peek() const;
    void print() const;
  
private:
    DynamicStack(const DynamicStack& other) {}
    DynamicStack operator=(const DynamicStack& other) {}

private:
    StackItem* items_;
    int capacity_;
    int size_;
    int init_capacity_;
};

#endif
