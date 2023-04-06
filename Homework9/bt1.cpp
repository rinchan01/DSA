#include <iostream>
#include <vector>
using namespace std;

void DFSUtil(vector<int> vertices[], int v, bool visited[]) {
    //visit neighbors of a vertex 
    //and neighbors' neighbors
    for (int i = 0; i < vertices[v].size(); i++) {
        if (visited[vertices[v][i]] == false) {
            visited[vertices[v][i]] = true;
            DFSUtil(vertices, vertices[v][i], visited);
            
        }
    }
}

int main() {
    int n, m, x, y;
    int count = 0;
    cin >> n >> m;

    //a vector for vertices
    //each element in this vector is a vertex
    //each vertex has its neighbors
    //input index start from 1
    vector<int> vertices[n+1];
    bool visited[n+1] = {false};

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        vertices[x].push_back(y);
    }

    for (int i = 0; i < n; i++) {
        //visit a vertex
        if (visited[i+1] == false) {
            DFSUtil(vertices, i+1, visited);
            count++;
        }
    }
    cout << count;

    return 0;

}