#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Exactly same as TopoSort_KahnAlgo_DFS2.cpp but adjList is directly passed.

class Solution {
  void findTopoSort(int node, vector<int> &vis, stack<int>& st, vector<int> adj[]) {
    vis[node] = 1;

    for (auto &i: adj[node]) {
      if (!vis[i]) {
        findTopoSort(i, vis, st, adj);
      }
    }
    st.push(node);
  }

  public:
    vector<int> topoSort(int N, vector<int> adj[]) {
      stack<int> st;
      vector<int> vis(N, 0);
      for (int i = 0; i < N; i++) {
        if (vis[i] == 0) {
          findTopoSort(i, vis, st, adj);
        }
      }
      vector<int> topo;
      while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
      }
      return topo;

    }
};

// { Driver Code Starts.
int main() {

  int N = 6;

  vector<int> adj[N];

  adj[5].push_back(2);
  adj[5].push_back(0);
  adj[4].push_back(0);
  adj[4].push_back(1);
  adj[2].push_back(3);
  adj[3].push_back(1);

  Solution obj;
  vector<int> res = obj.topoSort(N, adj);

  cout << "Toposort of the given graph is:" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;

  return 0;
} 