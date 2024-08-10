#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

class Graph {
private:
    int noOfVertices;
    list<int> *adjList;
public:
    Graph(int vertices) {
        noOfVertices = vertices;
        adjList = new list<int> [noOfVertices];
    }

    void addEdge(int src, int dst) {
        adjList[src].push_back(dst);
    }

    void printAdjList() {
        for (int i = 0; i < noOfVertices; ++i) {
            cout << i << " : ";
            for (auto &j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    vector<int> topoSort() {
        vector<int> result;

        vector<bool> visited(noOfVertices, false);
        // stack<int> s;

        for (int i = 0; i < noOfVertices; ++i) {
            if (!visited[i]) {
                dfs(i, result, visited);
            }
        }

        // while (!s.empty()) {
        //     result.push_back(s.top()); s.pop();
        // }
        return result;
    }

    void dfs(int curV, vector<int> &result, vector<bool> visited) {
        visited[curV] = true;

        for (int &nei : adjList[curV]) {
            if (!visited[nei]) {
                dfs(nei, result, visited);
            }
        }
        result.push_back(curV);
    }

    // bool isCyclePresent() {
    //     vector<int> res = topoSort();
    //     if (res.size() == noOfVertices)
    //         return false;
    //     else
    //         return true;
    // }
};


int main() {
    Graph g1(3);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    // g1.addEdge(2, 0);
    g1.addEdge(0, 2);
    g1.printAdjList();
    vector<int> res = g1.topoSort();
    for (auto &i : res) {
        cout << i << " ";
    }
    cout << endl;
    // cout << "cycle present : " << g1.isCyclePresent() << endl;
}