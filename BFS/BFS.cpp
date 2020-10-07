#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  // Read in number of vertices V and number of edges E
  int V, E;
  cin >> V;
  cin >> E;

  vector<vector<int>> neighbors(V); // Adjacency list
  // Read in edges and store them in the adjacency list
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u;
    cin >> v;
    neighbors[u].push_back(v);
    neighbors[v].push_back(u);
  }

  // Vectors to keep track of distances from source and if vertices have been visited
  vector<int> d(V);
  vector<bool> visited(V);
  for (int i = 0; i < V; i++) {
    d[i] = 0;
    visited[i] = false;
  }

  // Queue of next vertices to update distances from
  queue<int> q;
  q.push(0);
  visited[0] = true;

  /* While the queue is not empty, pop the vertex in front of the queue,
     update the distances of all its unvisited neighbors, mark them as visited
     and push them into the queue
   */
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : neighbors[v]) {
      if (!visited[u]) {
        d[u] = d[v] + 1;
        visited[u] = true;
        q.push(u);
      }
    }
  }
  // At this point d[u] is the distance from 0 to u
  
  for (int i = 0; i < V; i++)
    cout << "d[" << i << "] = " << d[i] << "\n";

  return 0;
}
