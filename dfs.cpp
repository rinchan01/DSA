// C++ program to print DFS traversal from
// a given vertex in a  given graph
#include <bits/stdc++.h>
using namespace std;
 
// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}
 
// Driver's code
int main()
{
    // Create a graph given in the above diagram
    // Create a graph given in the above diagram
    Graph g;
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


 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
 
    // Function call
    g.DFS(0);
 
    return 0;
}
 
// improved by Vishnudev C