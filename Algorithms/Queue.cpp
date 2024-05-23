#include "Queue.h"
#include <iostream>

// this constructor initilises the queue with a given size
CircularQueue::CircularQueue(int size) {
    this->size = size;
    data = new Location * [size]; // allocate memory for the queue
    front = 0; // this section initialises the front and rear index along with the count of elements
    rear = -1;
    count = 0;
}

// clean up allocated memory
CircularQueue::~CircularQueue() {
    delete[] data;
}

// method to insert an element into the queue
void CircularQueue::Insert(Location* item) {
    if (!IsFull()) {
        rear = (rear + 1) % size; // circular increment of rear index
        data[rear] = item; // add item to the queue
        count++; // count of the elements
    }
    else {
        std::cout << "Queue is full" << std::endl; // error handling 
    }
}

// method to remove an element from the queue
Location* CircularQueue::Remove() {
    if (!IsEmpty()) {
        Location* item = data[front];
        front = (front + 1) % size;
        count--;
        return item;
    }
    else {
        std::cout << "Queue is empty" << std::endl; // error handling
        return nullptr;
    }
}

// method to check if the queue is empty
bool CircularQueue::IsEmpty() {
    return count == 0;
}

// method to check if the queue is full
bool CircularQueue::IsFull() {
    return count == size;
}