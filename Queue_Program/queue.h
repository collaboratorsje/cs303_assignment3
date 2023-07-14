#pragma once
#include <iostream>

using namespace std;

// Making a queue class with template type
template<typename T>
class queue {
private:
    // Creating a node with data type T and next pointer
    struct Node {
        T data;
        Node* next;
    };
    // Declaring private data members the front and rear nodes and the size of the queue
    Node* frontNode;
    Node* rearNode;
    int queueSize;

public:
    // Declaring the functions defined in the cpp file 
    queue();
    void enqueue(const T& element);
    T dequeue();
    T front();
    bool isEmpty();
    int size();
};
