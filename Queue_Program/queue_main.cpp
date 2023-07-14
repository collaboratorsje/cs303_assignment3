#include "queue.h"

int main() {
    // Creating an empty queue
    queue<int> myQueue;

    // Inserting three int elements into the queue
    cout << "Inserting 10, 20, 30 into a queue of ints" << endl;
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // Getting the front element from the queue
    cout << "Getting the front element..." << endl;
    cout << "Front element: " << myQueue.front() << endl;

    // Removing and returning the front element from the queue
    cout << "Removing and returning the front element..." << endl;
    int frontElement = myQueue.dequeue();
    cout << "Removed element: " << frontElement << endl;

    // Checking if the queue is empty and outputting yes or no depending on the bool returned 
    cout << "Checking if the queue is empty..." << endl;
    // Uses conditional ternary operator to do this
    cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;

    // Checking the total number of elements with the size function
    cout << "Counting elements in the queue..." << endl;
    cout << "Total elements in the queue: " << myQueue.size() << endl;

    return 0;
}