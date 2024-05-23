#include "Stack.h"
#include <iostream>

// start the stack with a given szie
Stack::Stack(int size) {
    this->size = size;
    data = new Location * [size]; // allocate memory for the stack
    top = -1; // the top index
}

// clean up the allocated memory
Stack::~Stack() {
    delete[] data; // deallocate memory
}

//method to push an element onto the stack
void Stack::Push(Location* value) {
    if (top < size - 1) {
        data[++top] = value; // increment top and add value
    }
    else {
        std::cout << "Stack is full" << std::endl; // error handling
    }
}

// method to pop an element
Location* Stack::Pop() {
    if (top >= 0) {
        return data[top--]; // return the top element 
    }
    else {
        std::cout << "Stack is empty" << std::endl; // error handling
        return nullptr; 
    }
}

// method to peek at the top element of the stack without removing it
Location* Stack::Peek() {
    if (top >= 0) {
        return data[top];
    }
    else {
        std::cout << "Stack is empty" << std::endl; // error handling
        return nullptr;
    }
}

// method to check if the stack is full
bool Stack::IsFull() {
    return top == size - 1; // check i ftop is at last index
}

// method to check if the stack is empty
bool Stack::IsEmpty() {
    return top == -1; // check if top is at the initial index
}