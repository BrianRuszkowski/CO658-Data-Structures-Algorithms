#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include "Location.h"

// this class represents the queue data structure
class CircularQueue {
private:
    Location** data; // array to store queue elements
    int front, rear, count, size; // indices and counters for the queue
public:
    CircularQueue(int size);
    ~CircularQueue();
    void Insert(Location* item);
    Location* Remove();
    bool IsEmpty();
    bool IsFull();
};

#endif