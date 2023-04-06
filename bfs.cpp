#include<bits/stdc++.h>
using namespace std;
 
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices
 
    // Pointer to an array containing adjacency
    // lists
    vector<list<int>> adj;  
public:
    Graph(int V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints BFS traversal from a given source s
    void BFS(int s); 
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(V,false);
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjecent: adj[s])
        {
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}
 
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(12);
    g.addEdge(0, 5);
    g.addEdge(0, 7);
    g.addEdge(1, 3);
    g.addEdge(1, 9);
    g.addEdge(1, 10);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 8);
    g.addEdge(3, 1);
    g.addEdge(3, 6);
    g.addEdge(3, 10);
    g.addEdge(3, 11);
    g.addEdge(4, 7);
    g.addEdge(4, 8);
    g.addEdge(4, 2);
    g.addEdge(4, 5);
    g.addEdge(5, 0);
    g.addEdge(5, 4);
    g.addEdge(5, 7);
    g.addEdge(5, 8);
    g.addEdge(5, 9);
    g.addEdge(6, 3);
    g.addEdge(7, 0);
    g.addEdge(7, 4);
    g.addEdge(8, 2);
    g.addEdge(8, 4);
    g.addEdge(8, 5);
    g.addEdge(9, 1);
    g.addEdge(9, 5);
    g.addEdge(9, 10);
    g.addEdge(10, 1);
    g.addEdge(10, 3);
    g.addEdge(10, 9);
    g.addEdge(11, 3);



 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(0);
 
    return 0;
}