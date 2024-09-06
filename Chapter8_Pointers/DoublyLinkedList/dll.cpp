#include "dll.h"
#define DEBUG

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    head = nullptr;
    tail = nullptr;
    listSize = 0;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    #ifdef DEBUG
        cout << "Destructor called!" << endl;
    #endif
    
    while(head != nullptr){
        Node<T>* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& dll){
    #ifdef DEBUG
        cout << "Copy Constructor called!" << endl;
    #endif
    
    head = nullptr;
    tail = nullptr;
    listSize = 0;
    
    for(int i = 0; i < dll.size(); i++){
        push(dll.at(i));
    }
}

template<typename T>
void DoublyLinkedList<T>::operator=(const DoublyLinkedList& dll){
    #ifdef DEBUG
        cout<< "Assignment Operator Override called!" << endl;
    #endif
    
    while(head != nullptr){
        Node<T>* nextNode = head->next;
        delete head;
        head = nextNode;
    }
    
    head = nullptr;
    tail = nullptr;
    listSize = 0;
    
    for(int i = 0; i < dll.size(); i++){
        push(dll.at(i));
    }
}

template<typename T>
void DoublyLinkedList<T>::push(T data){
    listSize++;
    
    // Empty list case:
    if(head == nullptr){
        head = new Node<T>;
        tail = head;
        head->data = data;
        head->next = nullptr;
        head->prev = nullptr;
        return;
    }
    
    Node<T>* currentNode = head;
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }
    
    currentNode->next = new Node<T>;
    tail = currentNode->next;
    (currentNode->next)->data = data;
    (currentNode->next)->next = nullptr;
    (currentNode->next)->prev = currentNode;
}

template<typename T>
void DoublyLinkedList<T>::pop(){
    // Empty list case:
    if(head == nullptr){
        return;
    }
    
    listSize--;
    
    //One element case
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        delete tail;
        tail = nullptr;
        return;
    }
    
    Node<T>* currentNode = tail->prev;
    delete tail;
    tail = currentNode;
    currentNode->next = nullptr;
}

template<typename T>
int DoublyLinkedList<T>::size() const{
    return listSize;
}

template<typename T>
void DoublyLinkedList<T>::print() const{
    Node<T>* currentNode = head;
    int i = 0;
    while(i < listSize){
        cout << currentNode->data << endl;
        currentNode = currentNode->next;
        i++;
    }
}

template<typename T>
T& DoublyLinkedList<T>::at(int idx) const{
    Node<T>* currentNode = head;
    for(int i = 0; i < idx;i++){
        currentNode = currentNode->next;
    }
    
    return currentNode->data;
}

template<typename T>
void DoublyLinkedList<T>::insert(T data, int pos){
    
    // Out of range
    if (pos > listSize || pos < 0){
        cout << "Insertion failed: Invalid Position" << endl;
        return;
    }
    
    // Insertion at beginning
    if (pos == 0){
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = head;
        newNode->prev = nullptr;
        head->prev = newNode;
        head = newNode;
        listSize++;
        return;
    }
    
    
    // Insertion at the end
    if (pos == listSize){
        push(data);
        return;
    }
    
    // Insertion in between
    Node<T>* currentNode = head;
    Node<T>* prevNode = currentNode->prev;
    for(int i = 0; i < pos;i++){
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    
    Node<T>* newNode = new Node<T>;
    newNode->data = data;
    newNode->prev = prevNode;
    newNode->next = currentNode;
    prevNode->next = newNode;
    currentNode->prev = newNode;
    listSize++;
}

template<typename T>
void DoublyLinkedList<T>::remove(int pos){
    
    // Out of range
    if (pos >= listSize || pos < 0){
        cout << "Deletion failed: Invalid Position" << endl;
        return;
    }
    
    // Deletion at beginning
    Node<T>* nextNode = head->next;
    if (pos == 0){
        delete head;
        head = nextNode;
        head->prev = nullptr;
        listSize--;
        return;
    }
    
    // Deletion at the end
    if ((pos + 1) == listSize){
        pop();
        return;
    }
    
    // Deletion in between
    Node<T>* currentNode = head;
    for(int i = 0; i < pos;i++){
        currentNode = currentNode->next;
    }
    
    (currentNode->prev)->next = (currentNode->next);
    (currentNode->next)->prev = (currentNode->prev);
    delete currentNode;
    listSize--;
}

void test(){
    DoublyLinkedList<int> dll;
    
    dll.push(1);
    dll.push(2);
    dll.push(3);
    
    DoublyLinkedList<int> dllCopy = dll;
    
    dllCopy.push(4);
    dllCopy.remove(1);
    dllCopy.remove(0);
    dllCopy.insert(5, 1);
    
    dll.print();
    dllCopy.print();
    
    dll = dllCopy;
    dll.print();
}