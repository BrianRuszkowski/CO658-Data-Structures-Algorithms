#include <iostream>
#include "Graph.h"
#include "Queue.h"
#include "Stack.h"

// Function declarations for BFS and DFS
void BFS(Graph& graph, Location* start);
void DFS(Graph& graph, Location* start);

int main() {
    Graph graph(10); // create a graph with the amount of set verticies

    // This section creates location (nodes) with unique keys and names
    Location* locA = new Location(0, 'A');
    Location* locB = new Location(1, 'B');
    Location* locC = new Location(2, 'C');
    Location* locD = new Location(3, 'D');
    Location* locE = new Location(4, 'E');
    Location* locF = new Location(5, 'F');
    Location* locG = new Location(6, 'G');
    Location* locH = new Location(7, 'H');
    Location* locI = new Location(8, 'I');
    Location* locJ = new Location(9, 'J');

    // these are the added verticies that are displayed on the graph
    graph.AddVertex(locA);
    graph.AddVertex(locB);
    graph.AddVertex(locC);
    graph.AddVertex(locD);
    graph.AddVertex(locE);
    graph.AddVertex(locF);
    graph.AddVertex(locG);
    graph.AddVertex(locH);
    graph.AddVertex(locI);
    graph.AddVertex(locJ);

    // this section is for setting the edges to create connections between vertices
    graph.AddEdge(0, 1, 1); // A-B
    graph.AddEdge(0, 2, 1); // A-C
    graph.AddEdge(1, 3, 1); // B-D
    graph.AddEdge(1, 4, 1); // B-E
    graph.AddEdge(2, 5, 1); // C-F
    graph.AddEdge(2, 6, 1); // C-G
    graph.AddEdge(3, 7, 1); // D-H
    graph.AddEdge(4, 8, 1); // E-I
    graph.AddEdge(5, 9, 1); // F-J
    graph.AddEdge(6, 7, 1); // G-H
    graph.AddEdge(7, 8, 1); // H-I
    graph.AddEdge(8, 9, 1); // I-J

    // This section displays the graph strucutre
    std::cout << "Graph Display:" << std::endl;
    graph.Display();

    // Perform BFS traversal starting from node A
    std::cout << "BFS Traversal starting from A:" << std::endl;
    BFS(graph, locA);

    // Perfrom DFS traversal starting from node A
    std::cout << "DFS Traversal starting from A:" << std::endl;
    DFS(graph, locA);

    // This section cleans up allocated memory
    delete locA;
    delete locB;
    delete locC;
    delete locD;
    delete locE;
    delete locF;
    delete locG;
    delete locH;
    delete locI;
    delete locJ;

    return 0;
}

// below is the BFS section
void BFS(Graph& graph, Location* start) {
    CircularQueue queue(graph.GetNumberVertices()); // this starts the queue
    start->wasVisited = true; // mark the start node as visited
    queue.Insert(start); // insert the start node into the queue 

    while (!queue.IsEmpty()) {
        Location* current = queue.Remove(); // remove the fron node from the queue
        std::cout << current->name << " "; // print the node's name
        Location* adj = nullptr; // goes through all the near unvisited nodes
        while ((adj = graph.GetAdjacentUnvisitedVertex(current)) != nullptr) {
            adj->wasVisited = true; // mark the near node as visited
            queue.Insert(adj); // insert the close node into the queue
        }
    }
    std::cout << std::endl;
    graph.ResetVisits(); // reset the visited status for all nodes
}

// below is the DFS section
void DFS(Graph& graph, Location* start) {
    Stack stack(graph.GetNumberVertices()); // this code starts the initialsation of the stack
    start->wasVisited = true; // mark the start node as visited
    stack.Push(start); // push the start node onto the stack

    while (!stack.IsEmpty()) {
        Location* current = stack.Pop(); // pop the top node from the stack
        std::cout << current->name << " "; // print the name of the node
        Location* adj = nullptr; // find and visit all near unvisited nodes
        while ((adj = graph.GetAdjacentUnvisitedVertex(current)) != nullptr) {
            adj->wasVisited = true; // mark the node as visited
            stack.Push(adj); // push the nearest node onto the stack
        }
    }
    std::cout << std::endl;
    graph.ResetVisits(); // reset the visited status for all nodes
}