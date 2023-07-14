#pragma once

#include <iostream>

using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

// Implementing a stack class using an array of size 100
class Stack {
private:
    // Private data members are the array and a variable that is used as the index of the top of the stack
    char arr[MAX_SIZE];
    int top;

public:
    // Public functions that are defined in the cpp file
    Stack();
    bool empty();
    bool full();
    void push(char value);
    char pop();
    char peek();
};