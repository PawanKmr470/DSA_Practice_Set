#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;  

class Graph {
  private:
    int noOfVertices;
    list<int>* adjList;
  public:
    Graph(int vertices) {
      noOfVertices = vertices;
      adjList = new list<int> [vertices];
    }

    ~Graph() {};

    void addEdge(int src, int dst) {
      adjList[src].push_back(dst);
    }

    void printAdjList() {
      for (int i=0; i < noOfVertices; i++) {
        cout << "[" << i << "] : ";
        for (auto &nei : adjList[i]) {
          cout << nei << " ";
        }
        cout << endl;
      }
    }

    vector<int> topoSort() {
      vector<int> res;
      vector<int> indegree(noOfVertices, 0);

      for (int i=0; i < noOfVertices; i++) {
        for (auto &nei : adjList[i])
          indegree[nei]++;
      }

      queue<int> q;
      for (int i=0; i < noOfVertices; i++) {
        if (indegree[i] == 0)
          q.push(i);
      }

      while (!q.empty()) {
        int node = q.front();
        q.pop();
        res.push_back(node);

        for (auto &nei : adjList[node]) {
          indegree[nei]--;
          if (indegree[nei] == 0)
            q.push(nei);
        }
      }
      
      return res;
    }

    bool isCyclePresent() {
      vector<int> res = topoSort();
      if (res.size() != noOfVertices)
        return true;
      else
        return false;
    }

};

int main() {

    // 0 --------> 1
    // |           |
    // |           |
    //\|/         \|/
    // 2 --------> 3 -------> 4

    Graph g1(5);        // directed graph
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    g1.printAdjList();
    vector<int> res = g1.topoSort();
    for (auto &i : res) {
        cout << i << " ";
    }
    cout << endl;
    cout << "cycle present : " << g1.isCyclePresent() << endl;
}