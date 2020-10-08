#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int V, E;
vector<vector<int>> neighbors; // Adjacency list
vector<int> d; // discovery start time
vector<int> f; // discovery finish time
vector<bool> visited; // whether vertices are visited
vector<int> parent; // parents of vertices in DFS tree
int t = 0;

void dfs();
void dfs_visit(int);

int main() {
  // Read in number of vertices V and number of edges E
  cin >> V;
  cin >> E;
  neighbors.resize(V);
  d.resize(V);
  f.resize(V);
  visited.resize(V);
  parent.resize(V);
  
  // Read in edges and store them in the adjacency list
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u;
    cin >> v;
    neighbors[u].push_back(v);
    neighbors[v].push_back(u);
  }

  dfs();

  // Print discovery times and parent of each vertex
  for (int v = 0; v < V; v++)
    cout << v << ": d = " << d[v] << ", f = " << f[v] << ", parent = " << parent[v] << "\n";
  
  return 0;
}

void dfs() {
  // Initialization
  for (int i = 0; i < V; i++) {
    d[i] = 0;
    visited[i] = false;
    parent[i] = -1; 
  }
  // Make sure to visit all vertices (graph might be a tree)
  for (int v = 0; v < V; v++)
    if (!visited[v])
      dfs_visit(v);
}
/* Update the discovery start time of v and mark v as visited.
   Then, for each neighbor unvisited neighbor u of v,
   mark v as the parent of u and run DFS from u.
   After processing all neighbors of v, mark the discovery finish
   time of v.
 */
void dfs_visit(int v) {
  d[v] = ++t;
  visited[v] = true;
  for (int u : neighbors[v]) {
    if (!visited[u]) {
      parent[u] = v;
      dfs_visit(u);
    }
  }
  f[v] = ++t;
}
