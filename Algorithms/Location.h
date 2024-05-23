#pragma once
#ifndef LOCATION_H
#define LOCATION_H

// this class allows the representation of vertex in the graph
class Location {
public:
    int key; // this is a unique key to identify the location
    char name; // this is the name of the location
    bool wasVisited; // this check if the location has been visited
    Location* next; // this is the pointer to the next location
    Location(int k, char n) : key(k), name(n), wasVisited(false), next(nullptr) {}
};

#endif