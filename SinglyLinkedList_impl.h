#ifndef SINGLY_LINKED_LIST_IMPL_H
#define SINGLY_LINKED_LIST_IMPL_H

#include "SinglyLinkedList.h"
#include "Exception.h"

// -------------------------
// Node Implementation
// -------------------------
template <class T>
SLLNode<T>::SLLNode(const T& data, SLLNode<T>* next)
    : data(data), next(next) {}

// -------------------------
// Constructors & Destructor
// -------------------------
template <class T>
SinglyLinkedList<T>::SinglyLinkedList() {
    // dummy head node
    head = new SLLNode<T>(T(), NULL);
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    // TODO: Implement
    
    SLLNode<T>* current = head;
    SLLNode<T>* temp = NULL;
    while (current != NULL){
        temp = current;
        current = current->next;
        delete temp;
    }
    head = NULL;
    
    
    
    /*
    Clear();
    delete head;
    */
}

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& other) {
    // TODO: Implement
    
    head = new SLLNode<T>(T(), NULL);       //head may be uninitialized and holds garbage value, dont forget to add 
    
    SLLNode<T>* current = head;
    SLLNode<T>* other_cur = other.head->next;
    
    while ( other_cur != NULL){
        current->next = new SLLNode<T>(other_cur->data, NULL);
        current = current->next;
        other_cur = other_cur->next;
    }
    
    
}

template <class T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& other) {
    // TODO: Implement
    
    if ( this != &other){
        Clear();
    
        SLLNode<T>* current = head;
        SLLNode<T>* other_cur = other.head->next;
        
        while ( other_cur != NULL){
            current->next = new SLLNode<T>(other_cur->data, NULL);
            current = current->next;
            other_cur = other_cur->next;
        }
    }
    
    return *this;
   
}

// -------------------------
// Basic Operations
// -------------------------
template <class T>
void SinglyLinkedList<T>::PushFront(const T& value) {
    // TODO: Implement
    
    head->next = new SLLNode<T>(value, head->next);
    
}

template <class T>
void SinglyLinkedList<T>::PushBack(const T& value) {
    // TODO: Implement
    
    SLLNode<T>* current = head;
    while ( current->next != NULL){
        current = current->next;
    }
    current->next = new SLLNode<T>(value, NULL);
    
    
}

template <class T>
T SinglyLinkedList<T>::PopFront() {
    // TODO: Implement
    
    if (head->next == NULL){
        throw EmptyCollectionException();
    }
    
    SLLNode<T>* temp = head->next;
    T value = temp->data;
    head->next = head->next->next;
    delete temp;
    return value;
    
}

template <class T>
T SinglyLinkedList<T>::PopBack() {
    // TODO: Implement
    
    
    if ( head->next == NULL){
        throw EmptyCollectionException();
    }
    
    SLLNode<T>* current = head;
    while ( current->next->next != NULL){
        current = current->next;
    }
    SLLNode<T>* temp = current->next;
    T value = temp->data;
    current->next = NULL;
    delete temp;
    
    return value;
    
    
    
}

// -------------------------
// Accessors
// -------------------------
template <class T>
bool SinglyLinkedList<T>::IsEmpty() const {
    
    if ( head->next == NULL){
        return true;
    }
    return false;
    
}

template <class T>
size_t SinglyLinkedList<T>::GetSize() const {
    // TODO: Implement
    
    SLLNode<T>* current = head->next;
    int size = 0;
    while ( current != NULL){
        size++;
        current = current->next;
    }
    
    return size;
    
}

template <class T>
T& SinglyLinkedList<T>::Front() {
    // TODO: Implement
    
    if (head->next == NULL){
        throw EmptyCollectionException();
    }
    
    else{
        return (head->next)->data;
    }
}

template <class T>
const T& SinglyLinkedList<T>::Front() const {
    // TODO: Implement
    
    if (head->next == NULL){
        throw EmptyCollectionException();
    }
    
    else{
        return (head->next)->data;
    }
}

template <class T>
T& SinglyLinkedList<T>::Back() {
    // TODO: Implement
    
    if (head->next == NULL){
        throw EmptyCollectionException();
    }
    
    else{
        SLLNode<T>* current;
        current = head;
        while (current->next != NULL){
            current = current->next;
        }
        return current->data;
    }
}

template <class T>
const T& SinglyLinkedList<T>::Back() const {
    // TODO: Implement
    
    if (head->next == NULL){
        throw EmptyCollectionException();
    }
    
    else{
        SLLNode<T>* current;
        current = head;
        while (current->next != NULL){
            current = current->next;
        }
        return current->data;
    }
}

// -------------------------
// Searching & Removal
// -------------------------
template <class T>
bool SinglyLinkedList<T>::Contains(const T& value) const {
    // TODO: Implement
    
    SLLNode<T>* current = head->next;
    while (current != NULL){
        if( current->data == value){
            return true;
        }
        current = current->next;
    }
    
    return false;
    
}

template <class T>
bool SinglyLinkedList<T>::Remove(const T& value) {
    // TODO: Implement
    
    SLLNode<T>* current = head;
    while (current->next != NULL){
        if( current->next->data == value){
            SLLNode<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }
        current = current->next;
    }
    
    return false;
    
}

// -------------------------
// Utility
// -------------------------
template <class T>
void SinglyLinkedList<T>::Clear() {
    // TODO: Implement
    
    SLLNode<T>* current = head->next;
    SLLNode<T>* temp = NULL;
    while (current != NULL){
        temp = current;
        current = current->next;
        delete temp;
    }
    head->next = NULL;
    
    
    
/*  MORE EFFICIENT THAN MY CLEAR

    SLLNode<T>* current = head->next; 
    while (current != NULL) {
        SLLNode<T>* nodeToDelete = current;
        current = current->next; 
        delete nodeToDelete; 
    }
    head->next = NULL;
*/

}

template <class T>
void SinglyLinkedList<T>::Reverse() {
    // TODO: Implement
    
    if ( head!=NULL && head->next!=NULL){
        
        SLLNode<T>* prev = NULL;
        SLLNode<T>* current = head->next;
        SLLNode<T>* Next = head->next->next;
        
        while ( current->next != NULL){
            current->next = prev;
            prev = current;
            current = Next;
            Next = Next->next;
         
        }
        current->next = prev;
        head->next = current;
        
        
    }
    
    
    /*
    int size = GetSize();
    if (head->next != NULL && head->next->next != NULL){
        SLLNode<T>* current;
        SLLNode<T>* last;
        SLLNode<T>* node = head;
        for (int i=0; i<size-1; i++){
            current = head;
            while (current->next->next != NULL){
                current = current->next;
            }
            last = current->next;
            current->next = NULL;
            last->next = node->next;
            node->next = last;
            node = node->next;   
        }
    }
    */
}

// -------------------------
// Operator << Overload
// -------------------------
template <class T>
std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<T>& list) {
    if (list.head->next == NULL) {
        os << "Empty";
        return os;
    }
    SLLNode<T>* curr = list.head->next; 
    while (curr != NULL) {
        os << curr->data;
        if (curr->next != NULL)
            os << " -> ";
        curr = curr->next;
    }
    return os;
}

#endif // SINGLY_LINKED_LIST_IMPL_H
