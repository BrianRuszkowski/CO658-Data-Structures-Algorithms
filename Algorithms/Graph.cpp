#include "Graph.h"
#include <iostream>
#include <climits>

// constructor to initialise the graph with a given size
Graph::Graph(int size) : size(size), numberVertices(0) {
    vertices = new Location * [size]; // allocate memory for verticies
    adjMat = new int* [size]; // allocate memory adjacency matrix
    for (int i = 0; i < size; i++) {
        adjMat[i] = new int[size];
        for (int j = 0; j < size; j++) {
            adjMat[i][j] = INT_MAX; // Representing no edge
        }
    }
}

// clean up allocated memory
Graph::~Graph() {
    for (int i = 0; i < size; i++) {
        delete[] adjMat[i];
    }
    delete[] adjMat;
    delete[] vertices;
}

// method to add a vertex to the graph
void Graph::AddVertex(Location* vertex) {
    vertices[numberVertices++] = vertex;
}

// method to add an edge between two vertices
void Graph::AddEdge(int start, int end, int weight) {
    adjMat[start][end] = weight; // add an edge from start to end
    adjMat[end][start] = weight; // If the graph is undirected
}

// method that displays the graph
void Graph::Display() {
    for (int i = 0; i < numberVertices; i++) {
        std::cout << vertices[i]->name << ": ";
        for (int j = 0; j < numberVertices; j++) {
            if (adjMat[i][j] != INT_MAX) {
                std::cout << vertices[j]->name << "(" << adjMat[i][j] << ") ";
            }
        }
        std::cout << std::endl;
    }
}

// method to reset the visited status of all vertices
Location* Graph::GetAdjacentUnvisitedVertex(Location* vertex) {
    for (int j = 0; j < numberVertices; j++) {
        if (adjMat[vertex->key][j] != INT_MAX && !vertices[j]->wasVisited) {
            return vertices[j];
        }
    }
    return nullptr;
}

// method to reset the visited status of all vertices
void Graph::ResetVisits() {
    for (int i = 0; i < numberVertices; i++) {
        vertices[i]->wasVisited = false;
    }
}

// method to get the number of vertices
int Graph::GetNumberVertices() { 
    return numberVertices; // return the current number of vertices
}