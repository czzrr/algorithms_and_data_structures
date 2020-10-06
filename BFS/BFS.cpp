#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int V, E;
  cin >> V;
  cin >> E;

  vector<vector<int>> neighbors(V);
    
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u;
    cin >> v;
    neighbors[u].push_back(v);
    neighbors[v].push_back(u);
  }

  vector<int> d(V);
  vector<bool> visited(V);
  for (int i = 0; i < V; i++) {
    d[i] = 0;
    visited[i] = false;
  }

  queue<int> q;
  q.push(0);
  visited[0] = true;
  
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

  for (int i = 0; i < V; i++) {
    cout << "d[" << i << "] = " << d[i] << "\n";
  }
  

  
  
  
}
