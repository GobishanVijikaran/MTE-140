#ifndef CIRCULAR_QUEUE_HPP
#define CIRCULAR_QUEUE_HPP

class CircularQueue
{
    friend class CircularQueueTest;
    
public:
    typedef int QueueItem;
    static const QueueItem EMPTY_QUEUE;

    CircularQueue();
    CircularQueue(unsigned int capacity);
  
    ~CircularQueue();
    bool enqueue(QueueItem value);
    QueueItem dequeue();
    QueueItem peek() const;
    bool empty() const;
    bool full() const;
    int size() const;
    void print() const;
  
private:
    CircularQueue(const CircularQueue& other) {}
    CircularQueue operator=(const CircularQueue& other) {}

private:
    QueueItem *items_;
    
    int head_, tail_;
    int capacity_;
    int size_;
};

#endif
