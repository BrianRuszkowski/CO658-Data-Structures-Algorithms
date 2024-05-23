#ifndef GRAPH_H
#define GRAPH_H

#include "Location.h"

// this class represents a graph data structure
class Graph {
private:
    int size; // maximum number of vertices in the graph
    int** adjMat; // storage of edges
    Location** vertices; // array of vertex pointers
    int numberVertices; // current number of verticies
public:
    Graph(int size);
    ~Graph();
    void AddVertex(Location* vertex);
    void AddEdge(int start, int end, int weight);
    void Display();
    Location* GetAdjacentUnvisitedVertex(Location* vertex);
    void ResetVisits();
    int GetNumberVertices(); 
};

#endif