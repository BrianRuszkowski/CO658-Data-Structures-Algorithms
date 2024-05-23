#pragma once
#ifndef STACK_H
#define STACK_H

#include "Location.h"

// this class represents the stack data structure
class Stack {
private:
    Location** data; // dynamic array to store stack elements
    int top; // index of the top element in the stack
    int size; // the max size of the stack
public:
    Stack(int size);  // start the stack with given size
    ~Stack(); // cleans up the allocated memory
    void Push(Location* value); // method to push element
    Location* Pop(); // method to pop an element
    Location* Peek(); // method to peek at the top element 
    bool IsFull(); // method to check if the stack is full
    bool IsEmpty(); // method to check if the stack is empty
};

#endif