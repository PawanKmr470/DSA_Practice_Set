#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// About this problem -
// If undirected graph cycle detection logic is used
// 0 -----> 1 <----- 2
// t,-1     t,0
//          t,0     t,-1
//          It is already visited & parent is not 2, it's a cycle but it's wrong
// Hence we need another solution - visited array + dfs visited array (i.e. visited array for
// current dfs path only. It will unvisit the vertices while exploring other paths. Sometimes
// it is called as local stack because it is local to a path.)

// 1st Approach - (DFS) is keep two visited arrays - visited & pathVisited (recursive & iterative).
// 2nd Approach - (DFS) is also known as graph coloring (recursive & iterative).
// 3rd Approach - (BFS) approach uses Topological Sort (Kahn's Algorithm)

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

        bool isCyclePresent() {
            bool visited[noOfVertices];
            for (int i=0; i < noOfVertices; i++) {
                visited[i] = false;
            }

            // Path stack / local stack to a path

            bool dfsVisited[noOfVertices];
            for (int i=0; i < noOfVertices; i++) {
                dfsVisited[i] = false;
            }

            for (int i=0; i < noOfVertices; i++) {
                if (!visited[i]) {
                    if (_dfs_Rec(i, visited, dfsVisited))
                        return true;
                }
            }
            return false;
        }

        bool _dfs_Rec(int curV, bool visited[], bool dfsVisited[]) {
            visited[curV] = true;
            dfsVisited[curV] = true;

            for (auto &i : adjList[curV]) {
                if (!visited[i]) {
                    if (_dfs_Rec(i, visited, dfsVisited))
                        return true;
                }
                else if (dfsVisited[i])     // modified dfs
                    return true;
            }

            dfsVisited[curV] = false;       // modified dfs
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
    cout << g1.isCyclePresent() << endl;

    // 0 --------> 1
    ///|\          |
    // |           |
    // |          \|/
    // 2 <------- 3 -------> 4

    Graph g2(5);        // directed graph
    g2.addEdge(0, 1);
    g2.addEdge(1, 3);
    g2.addEdge(3, 2);
    g2.addEdge(2, 0);
    g2.addEdge(3, 4);
    g2.printAdjList();
    cout << g2.isCyclePresent() << endl;
}