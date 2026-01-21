#ifndef MULTIPLE_QUEUE_IMPL_H
#define MULTIPLE_QUEUE_IMPL_H

#include "MultipleQueue.h"
#include "Exception.h"

// -------------------------
// Constructors & Destructor
// -------------------------
template <class T>
MultipleQueue<T>::MultipleQueue(size_t n)
    : count(n)
{
    queues = new Queue<T>[count];
}

template <class T>
MultipleQueue<T>::~MultipleQueue() {
    // TODO: Implement
    
    delete[] queues;
}

// -------------------------
// Core Operations
// -------------------------
template <class T>
int MultipleQueue<T>::Enqueue(const T& value) {
    // TODO: Implement
    
    if(queues == NULL || count == 0){
        return -1;
    }
    
    size_t min = queues[0].GetSize();
    size_t index = 0;
    for (size_t i = 1; i < count; i++){
        if (min > queues[i].GetSize()){
            min = queues[i].GetSize();
            index = i;
        }
    }
    queues[index].Enqueue(value);
    return static_cast<int>(index);          //static_cast converts a value from one type to another at compile time.
    
}

template <class T>
T MultipleQueue<T>::Dequeue(size_t index) {
    // TODO: Implement
    
    if (index<0 || index>(count-1) ){
        throw IndexOutOfRangeException();
    }
    
    else{
        return queues[index].Dequeue();
    }
    
}

template <class T>
const Queue<T>& MultipleQueue<T>::GetQueue(size_t index) const {
    // TODO: Implement
    
    if (index<0 || index>(count-1) ){
        throw IndexOutOfRangeException();
    }
    
    else{
        Queue<T>& ref_queue = queues[index];
        return ref_queue;
    }
    
}

// -------------------------
// Utility
// -------------------------
template <class T>
size_t MultipleQueue<T>::GetNumberOfQueues() const {
    // TODO: Implement
    
    return static_cast<int>(count);
}

template <class T>
size_t MultipleQueue<T>::GetTotalSize() const {
    // TODO: Implement
    
    size_t total=0;
    for (size_t i = 0; i < count; i++){
        total += queues[i].GetSize();
    }
    return total;
}

template <class T>
size_t MultipleQueue<T>::GetSizeOfQueue(size_t index) const {
    // TODO: Implement
    
    if (index<0 || index>(count-1) ){
        return 0;
    }
    
    else{
        return queues[index].GetSize();
    }
}

// -------------------------
// Operator <<
// -------------------------
template <class T>
std::ostream& operator<<(std::ostream& os, const MultipleQueue<T>& mq) {
    for (size_t i = 0; i < mq.count; ++i) {
        os << "Queue " << i << ": " << mq.queues[i];
        if (i < mq.count - 1) {
            os << std::endl;
        }
    }
    return os;
}
#endif // MULTIPLE_QUEUE_IMPL_H