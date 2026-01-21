#ifndef SORTED_DOUBLY_LINKED_LIST_IMPL_H
#define SORTED_DOUBLY_LINKED_LIST_IMPL_H

#include "SortedDoublyLinkedList.h"
#include "Exception.h"

// -------------------------
// Node Implementation
// -------------------------
template <class T>
DLLNode<T>::DLLNode(const T& item, DLLNode<T>* nextNode, DLLNode<T>* prevNode)
    : item(item), next(nextNode), prev(prevNode) {}

// -------------------------
// Constructors & Destructor
// -------------------------
template <class T>
SortedDoublyLinkedList<T>::SortedDoublyLinkedList() {
    head = new DLLNode<T>(T());
    tail = new DLLNode<T>(T());
    head->next = tail;
    tail->prev = head;
}

template <class T>
SortedDoublyLinkedList<T>::~SortedDoublyLinkedList() {
    // TODO: Implement
    
    Clear();
    delete head;
    delete tail;
    
}

template <class T>
SortedDoublyLinkedList<T>::SortedDoublyLinkedList(const SortedDoublyLinkedList<T>& other) {
    // TODO: Implement
    
    head = new DLLNode<T>(T());
    tail = new DLLNode<T>(T());
    head->next = tail;
    tail->prev = head;
    
    DLLNode<T>* current = head;
    DLLNode<T>* other_cur = other.head->next;
    
    while ( other_cur != other.tail){
        current->next = new DLLNode<T>(other_cur->item, tail, current);
        current = current->next;
        other_cur = other_cur->next;
    }
    
    
    
    /*
    head = new DLLNode<T>(T()); 
    tail = new DLLNode<T>(T());
    head->next = tail;
    tail->prev = head;
    
    if ( other.GetSize() >=1 ) {
        DLLNode<T>* cur_other;
        cur_other = (other.head)->next;
        while (cur_other != NULL && cur_other != other.tail){
            InsertItem(cur_other->item);
            cur_other = cur_other->next;
        }
    }
    */
    
}

template <class T>
SortedDoublyLinkedList<T>& SortedDoublyLinkedList<T>::operator=(const SortedDoublyLinkedList<T>& other) {
    // TODO: Implement
    
    if ( this != &other){
        
        Clear();
        
        DLLNode<T>* current = head;
        DLLNode<T>* other_cur = other.head->next;
        
        while ( other_cur != other.tail){
            current->next = new DLLNode<T>(other_cur->item, tail, current);
            current = current->next;
            other_cur = other_cur->next;
        }
    }
    
    
    
    /*
    if (this != &other){
        Clear();
    
        if ( other.GetSize() >=1 ){
            DLLNode<T>* cur_other;
            cur_other = (other.head)->next;
            while (cur_other != NULL && cur_other != other.tail){
                
                InsertItem(cur_other->item);
                cur_other = cur_other->next;
            }
        
        }
    }
    
    return *this;
    */
        
}

// -------------------------
// Core Operations
// -------------------------
template <class T>
void SortedDoublyLinkedList<T>::InsertItem(const T& item) {
    // TODO: Implement
    
    DLLNode<T>* current = head;
    while (current->next != tail && current->next->item <= item ){
        current = current->next;
    }
    
    current->next = new DLLNode<T>(item, current->next, current);
    current->next->next->prev = current->next;
    
    
    
    /*
    DLLNode<T>* current = head;
    if (head->next == tail){
        current->next = new DLLNode<T>(item, current->next, current);
        current->next->next->prev = current->next;
    }
    
    else{
        while ( (current->next != tail) && (item >= ((current->next)->item)) ){     // >= olmalı mantıken ??????????????????
            current = current->next;
        }    
        current->next = new DLLNode<T>(item, current->next, current);
        current->next->next->prev = current->next;
    }
    */
}

template <class T>
void SortedDoublyLinkedList<T>::InsertItemPrior(const T& item) {
    // TODO: Implement
    
    DLLNode<T>* current = head;
    while (current->next != tail && current->next->item < item ){
        current = current->next;
    }
    
    current->next = new DLLNode<T>(item, current->next, current);
    current->next->next->prev = current->next;
    
    
    /*
    DLLNode<T>* current = head;
    if (head->next == tail){
        current->next = new DLLNode<T>(item, current->next, current);
        current->next->next->prev = current->next;
    }
    
    else{
        while ( (current->next != tail) && (item > ((current->next)->item)) ){
            current = current->next;
        }    
        current->next = new DLLNode<T>(item, current->next, current);
        current->next->next->prev = current->next;
    }
    */
}

template <class T>
T SortedDoublyLinkedList<T>::RemoveFirstItem() {
    // TODO: Implement
    
    if ( head->next == tail){
        throw EmptyCollectionException();
    }
    
    DLLNode<T>* temp = head->next;
    T value = temp->item;
    head->next = temp->next;
    temp->next->prev = head;
    delete temp;
    return value;
    

}

template <class T>
T SortedDoublyLinkedList<T>::RemoveFirstItem(int priority) {
    // TODO: Implement
    
    if ( head->next == tail){
        throw EmptyCollectionException();
    }
    
    DLLNode<T>* current = head;
    while (current->next != tail && current->next->item != priority){
        current = current->next;
    }
    
    if (current->next == tail){
        throw NotFoundException();
    }
    
    DLLNode<T>* temp = current->next;
    T value = temp->item;
    current->next = temp->next;
    temp->next->prev = current;
    delete temp;
    return value;
    
    
    /*
    if (head->next == tail){
        throw EmptyCollectionException();
    }
    
    DLLNode<T>* current;
    current = head;
    while (current->next != tail){
        if ((current->next)->item == priority){
            DLLNode<T>* temp;
            temp = current->next;
            T value = temp->item;
            current->next = temp->next;
            temp->next->prev = current;
            delete temp;
            return value;
        }
        current = current->next;
    }
    
    throw NotFoundException();
    */
}

template <class T>
T SortedDoublyLinkedList<T>::RemoveLastItem(int priority) {
    // TODO: Implement
    
    if ( head->next == tail){
        throw EmptyCollectionException();
    }
    
    DLLNode<T>* current = head;
    DLLNode<T>* prev_node = NULL;
    
    while (current->next != tail ){
        if (current->next->item == priority){
            prev_node = current;
        }
        current = current->next;
    }
    
    if (prev_node == NULL){
        throw NotFoundException();
    }
    
    DLLNode<T>* temp = prev_node->next;
    T value = temp->item;
    prev_node->next = temp->next;
    temp->next->prev = prev_node;
    delete temp;
    return value;
    
    /*
    if (head->next == tail){
        throw EmptyCollectionException();
    }
    
    DLLNode<T>* current;
    current = head;
    
    DLLNode<T>* prev_node = NULL;
    DLLNode<T>* temp = NULL;
    T value;
            
    while (current->next != tail){
        if ((current->next)->item == priority){
            prev_node = current;
            temp = current->next;
            value = temp->item;
        }
        current = current->next;
    }
    
    if (temp == NULL){
        throw NotFoundException();
    }
    
    else{
        prev_node->next = temp->next;
        temp->next->prev = prev_node;
        delete temp;
        return value;
    }
    */
}

// -------------------------
// Query
// -------------------------
template <class T>
const T& SortedDoublyLinkedList<T>::FirstItem() const {
    // TODO: Implement
    
    if (head->next == tail){
        throw EmptyCollectionException();
    }
    
    else{
        return (head->next)->item;
    }
}

template <class T>
const T& SortedDoublyLinkedList<T>::LastItem() const {
    // TODO: Implement
    
    if (head->next == tail){
        throw EmptyCollectionException();
    }
    
    else{
        return (tail->prev)->item;
    }
}

template <class T>
bool SortedDoublyLinkedList<T>::IsEmpty() const {
    // TODO: Implement
    if (head->next == tail){
        return true;
    }
    return false;
}

template <class T>
size_t SortedDoublyLinkedList<T>::GetSize() const {
    // TODO: Implement
    
    int size = 0;
    DLLNode<T>* current = head->next;
    while ( current != tail){
        size++;
        current = current->next;
    }
    return size;
    
}

// -------------------------
// Modification
// -------------------------
template <class T>
void SortedDoublyLinkedList<T>::SplitByPriority(SortedDoublyLinkedList<T>& low,
                                                SortedDoublyLinkedList<T>& high,
                                                int pivotPriority) {
    // TODO: Implement  
    
    DLLNode<T>* current = head->next;
    while ( current != tail && current->item <= pivotPriority){
        low.tail->prev->next = new DLLNode<T>(current->item, low.tail, low.tail->prev);
        low.tail->prev = low.tail->prev->next;
        current = current->next;
    }
    
    while ( current != tail){
        high.tail->prev->next = new DLLNode<T>(current->item, high.tail, high.tail->prev);
        high.tail->prev = high.tail->prev->next;
        current = current->next;
    }
    
    
    
    /*
    DLLNode<T>* current;
    current = head->next;
    while (current->item <= pivotPriority){
        low.InsertItem(current->item);
        current = current->next;
    }
    
    while (current != tail){
        high.InsertItem(current->item);
        current = current->next;
    }
    */

}

template <class T>
void SortedDoublyLinkedList<T>::SplitAlternating(SortedDoublyLinkedList<T>& listA,
                                                 SortedDoublyLinkedList<T>& listB) {
    // TODO: Implement
    
    DLLNode<T>* current = head->next;
    while ( current != tail){
        listA.tail->prev->next = new DLLNode<T>(current->item, listA.tail, listA.tail->prev);
        listA.tail->prev = listA.tail->prev->next;
        current = current->next;
        if ( current != tail){
            listB.tail->prev->next = new DLLNode<T>(current->item, listB.tail, listB.tail->prev);
            listB.tail->prev = listB.tail->prev->next;
            current = current->next;
        }
    }
    
    /*
    DLLNode<T>* current;
    current = head->next;
    while (current != tail){
        listA.InsertItem(current->item);
        current = current->next;
        if (current != tail){
            listB.InsertItem(current->item);
            current = current->next;
        }
    }
    */
}

template <class T>
SortedDoublyLinkedList<T>
SortedDoublyLinkedList<T>::Merge(const SortedDoublyLinkedList<T>& a,
                                 const SortedDoublyLinkedList<T>& b) {
    // TODO: Implement
    
    SortedDoublyLinkedList<T> newlist;
    
    DLLNode<T>* current = a.head->next;
    while (current != a.tail){
        newlist.InsertItem(current->item);
        current = current->next;
    }
    
    current = b.head->next;
    while (current != b.tail){
        newlist.InsertItem(current->item);
        current = current->next;
    }
    
    return newlist;
    
    
}

// -------------------------
// Modification
// -------------------------
template <class T>
void SortedDoublyLinkedList<T>::Clear() {
    // TODO: Implement
    
    DLLNode<T>* current = head;
    while (current->next != tail){
        DLLNode<T>* temp = current->next;
        current->next = temp->next;
        temp->next->prev = current;
        delete temp;
    }
    
    /*
    DLLNode<T>* current = head->next; 
    while (current->next != NULL) {
        DLLNode<T>* nodeToDelete = current;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        current = current->next; 
        delete nodeToDelete; 
    }
    */
}

// -------------------------
// Operator <<
// -------------------------
template <class T>
std::ostream& operator<<(std::ostream& os, const SortedDoublyLinkedList<T>& list) {
    if (list.head->next == list.tail) {
        os << "Empty";
        return os;
    }
    DLLNode<T>* curr = list.head->next;
    while (curr != list.tail) {
        os << curr->item;
        if (curr->next != list.tail)
            os << " -> ";
        curr = curr->next;
    }
    return os;
}

#endif // SORTED_DOUBLY_LINKED_LIST_IMPL_H
