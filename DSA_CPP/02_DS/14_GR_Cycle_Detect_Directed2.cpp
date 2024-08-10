#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// Graph coloring (recursive & iterative)
// WHITE : Vertex is not processed yet. Initially, all vertices are WHITE.
// GRAY  : Vertex is being processed (DFS for this vertex has started, 
//         but not finished which means that all descendants (in DFS tree) of 
//         this vertex are not processed yet (or this vertex is in the function call stack)
// BLACK : Vertex and all its descendants are processed. While doing DFS, 
//         if an edge is encountered from current vertex to a GRAY vertex, 
//         then this edge is back edge and hence there is a cycle.

enum color { WHITE, GRAY, BLACK };  // instead of enum 0,1,2 in an int array
                                    // will also work.
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

            color colorArr[noOfVertices];
            for (int i=0; i < noOfVertices; i++) {
                colorArr[i] = WHITE;
            }

            for (int i=0; i < noOfVertices; i++) {
                if (colorArr[i] == WHITE) {
                    if (_dfs_Rec(i, colorArr))
                        return true;
                }
            }
            return false;
        }

        bool _dfs_Rec(int curV, color colorArr[]) {
            colorArr[curV] = GRAY;

            for (auto &i : adjList[curV]) {

                if (colorArr[i] == GRAY)
                    return true;

                if (colorArr[i] == WHITE) {
                    if (_dfs_Rec(i, colorArr))
                        return true;
                }
            }

            colorArr[curV] = BLACK;
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
    cout << "cycle present : " << g1.isCyclePresent() << endl;

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
    cout << "cycle present : " << g2.isCyclePresent() << endl;
}