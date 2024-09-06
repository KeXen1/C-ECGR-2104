#ifndef DLL_H
#define DLL_H

#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
};

template<typename T>
class DoublyLinkedList{
    public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& dll);
    void operator=(const DoublyLinkedList& dll);
    
    void push(T data); 
    void pop(); 
    int size() const;
    void print() const;
    T& at(int idx) const;
    void insert(T data, int pos);
    void remove(int pos);
    
    private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int listSize;
};

void test();

#endif