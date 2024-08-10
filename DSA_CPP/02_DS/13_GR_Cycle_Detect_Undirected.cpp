#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// Logic is - In dfs traversal, if node is already found visited AND
// it's not parent then there is a cycle. Break dfs and return ture.
// In DFS iterative method STACK will store node + parent
// In BFS iterative method QUEUE will store node + parent
// Approach will be same.
// This is one of the example of modified dfs & bfs.
// Similarlly, other application can be -
//      - find path fromm A to B (dfs will be prefered)
//              need to backtrack and try other way to get to B
//              means need to unmark the nodes in visited array.
//      - find shortest path from A to B (bfs will be prefered)
//      - print all paths from A to B

class Graph {
    private:
        int noOfVertices;
        list<int>* adjList;
        // unordered_map<int, list<int>> adjList;   // adj list other way
    public:
        Graph(int vertices) {
                noOfVertices = vertices;
                adjList = new list<int> [vertices];
            }
        ~Graph() {};

        void addEdge(int src, int dst) {
            adjList[src].push_back(dst);
            adjList[dst].push_back(src);
        }

        void printAdjList() {
            for (int i=0; i < noOfVertices; i++) {
                cout << "[" << i << "] : ";
                for(auto &j : adjList[i]) {     // traverse each ith adjList
                    cout << j << " ";
                }
                cout << endl;
            }
        }

        bool isCyclePresent() {
            bool visited[noOfVertices];
            for (int i=0; i < noOfVertices; i++) {
                visited[i] = false;
            }

            // This loop is required if multiple components are there.
            // Else we could have done simply call _dfs_Rec(0, -1, visited) for single component.
            
            for (int i=0; i < noOfVertices; i++) {
                if (!visited[i]) {
                    if (_dfs_Rec(i, -1, visited))
                    // if (_dfs_Itr(i, -1, visited))    // -1 is not required here but let's keep it
                    // if (_bfs_Itr(i, -1, visited))
                        return true;
                }
            }
            return false;
        }

        bool _dfs_Rec(int curV, int parentV, bool visited[]) {
            visited[curV] = true;

            for (auto &i : adjList[curV]) {
                if (!visited[i]) {
                    if (_dfs_Rec(i, curV, visited))
                        return true;
                }
                else if (i != parentV)  // Only this is extra condition
                    return true;        // Except parent if node is already visited -> cycle
            }
            return false;
        }


        bool _dfs_Itr(int startV, int parentV, bool visited[]) {
            stack<pair<int, int>> s;
            s.push({startV, parentV});
            // s.push(make_pair(startV, parentV));
            // s.push(pair<int, int>(startV, parentV));
            visited[startV] = true;

            while (!s.empty()) {
                pair<int, int> curV = s.top();
                s.pop();

                for (auto &i : adjList[curV.first]) {
                    if (!visited[i]) {
                        s.push({i, curV.first});
                        visited[i] = true;
                    }
                    else if (i != curV.second)
                        return true;
                }
            }
            return false;
        }


        bool _bfs_Itr(int startV, int parentV, bool visited[]) {
            queue<pair<int, int>> q;
            q.push({startV, parentV});
            visited[startV] = true;

            while (!q.empty()) {
                pair<int, int> curV = q.front();
                q.pop();

                for (auto &i : adjList[curV.first]) {
                    if (!visited[i]) {
                        q.push({i, curV.first});
                        visited[i] = true;
                    }
                    else if (i != curV.second)
                        return true;
                }
            }
            return false;
        }
};

int main() {

    // 0 --------- 1
    // |           |
    // |           |
    // |           |
    // 2 --------- 3 -------- 4

    Graph g1(5);        // Undirected graph
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    g1.printAdjList();
    cout << g1.isCyclePresent() << endl;
}