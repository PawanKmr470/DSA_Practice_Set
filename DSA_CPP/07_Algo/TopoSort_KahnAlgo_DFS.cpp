#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

// REF : https://www.youtube.com/watch?v=cIBFEhD77b4
// NOTES :
//      Topological sort gives a linear ordering of vertices in a directed acyclic graph
//      It's used to solve dependency problem.
//      *FIXME* Using DFS it is not able to detect cycle.

// O(T) : O(V+E)
// O(S) : O(V)

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
            adjList[src].push_back(dst);    // only src -> dst
        }

        void printAdjList() {
            for (int i=0; i < noOfVertices; i++) {
                cout << "[" << i << "] : ";
                for(auto &j : adjList[i]) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }

        vector<int> topoSort() {
            vector<bool> visited (noOfVertices, false);
            stack<int> s;

            for (int i; i < noOfVertices; i++) {    // Run from all nodes to cover
                if (!visited[i]) {                  // disconnected components
                    dfs(i, s, visited);
                }
            }

            vector<int> result;
            while (!s.empty()) {
                result.push_back(s.top());          // collect the result
                s.pop();
            }
            return result;
        }

        void dfs(int i, stack<int>& s, vector<bool>& visited) {     // Normal DFS
            visited[i] = true;
            for (auto &nei : adjList[i]) {
                if (!visited[nei]) {
                    dfs(nei, s, visited);
                }
            }
            s.push(i);                              // JUST THIS LINE
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

    Graph g(6); // gfg
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.printAdjList();
    vector<int> ret = g.topoSort();
    for (auto &i : ret) {
        cout << i << " ";
    }
    cout << endl;
    cout << "cycle present : " << g.isCyclePresent() << endl;


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


    // 0 --------> 1
    ///|\          |
    // |           |
    // |          \|/
    // 2 <------- 3 -------> 4

    Graph g2(5);        // directed graph with cycle
    g2.addEdge(0, 1);
    g2.addEdge(1, 3);
    g2.addEdge(3, 2);
    g2.addEdge(2, 0);
    g2.addEdge(3, 4);
    g2.printAdjList();
    vector<int> out = g2.topoSort();
    for (auto &i : out) {
        cout << i << " ";
    }
    cout << endl;
    cout << "cycle present : " << g2.isCyclePresent() << endl;
}