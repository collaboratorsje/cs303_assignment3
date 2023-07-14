#include "queue.h"

// Constructor creates an empty queue with front and rear nodes set to the nullptr and size 0
template<typename T>
queue<T>::queue() {
    frontNode = nullptr;
    rearNode = nullptr;
    queueSize = 0;
}

// Enqueue function
// Makes a new node and adds it to the queue, rear node points to it if the queue isn't empty
template<typename T>
void queue<T>::enqueue(const T& element) {
    Node* newNode = new Node;
    newNode->data = element;
    newNode->next = nullptr;

    if (isEmpty()) {
        frontNode = newNode;
        rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    // increment the queue size after a node is added
    queueSize++;
}

// Dequeue function
// Stores that data in front node in a variable and then makes a temp node so the front node can be removed
template<typename T>
T queue<T>::dequeue() {
    if (isEmpty()) {
        cerr << "Error: Queue is empty." << endl;
        exit(1);
    }

    T frontElement = frontNode->data;
    Node* temp = frontNode;
    frontNode = frontNode->next;

    if (frontNode == nullptr) {
        rearNode = nullptr;
    }
    // Decrements the queue size
    delete temp;
    queueSize--;

    return frontElement;
}

// Front function
// Returns the data of the front node as long as it isn't empty
template<typename T>
T queue<T>::front() {
    if (isEmpty()) {
        cerr << "Error: Queue is empty." << endl;
        exit(1);
    }

    return frontNode->data;
}

// isEmpty function
// Returns a bool (true if the queue is empty -- frontNode is the nullptr)
template<typename T>
bool queue<T>::isEmpty() {
    return (frontNode == nullptr);
}

// size function
// Returns the queueSize data member that gets incremented or decremented when adding or removing from the queue
template<typename T>
int queue<T>::size() {
    return queueSize;
}

// Instantiating some queue data types for the template functions to compile in the separate cpp file
template class queue<int>;   // Example for 'int'
template class queue<double>;   // Example for 'double'
template class queue<char>;   // Example for 'char'