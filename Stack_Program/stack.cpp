#include "stack.h"

    // Initialize the top of the stack
    Stack::Stack() {
        top = -1;
    }

    // Check if the stack is empty
    bool Stack::empty() {
        return (top == -1);
    }

    // Check if the stack is full
    bool Stack::full() {
        return (top == MAX_SIZE - 1);
    }

    // Increment top and add the value to the stack
    void Stack::push(char value) {
        if (full()) {
            cout << "Stack is full, cannot push " << value << endl;
            return;
        }

        arr[++top] = value; 
    }

    // Return the value and decrement top
    char Stack::pop() {
        if (empty()) {
            cout << "Stack is empty, cannot pop from an empty stack" << endl;
            return '\0';
        }

        return arr[top--];
    }

    // Return the value at the top of the stack
    char Stack::peek() {
        if (empty()) {
            cout << "The stack is empty" << endl;
            return '\0';
        }

        return arr[top];
    }