#include <iostream>
#include <list>
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
        ~Graph() {
            delete[] adjList;
        };

        void addEdge(int src, int dst) {
            adjList[src].push_back(dst);
        }

        void printAdjList() {
            for (int i=0; i < noOfVertices; i++) {
                cout << "[" << i << "] : ";
                for (auto &j : adjList[i]) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }


        void bfs_Itr(int startV) {
            bool visited[noOfVertices];
            for (int i=0; i < noOfVertices; i++) {
                visited[i] = false;
            }
            cout << "BFS traversal itr - ";
            _bfs_Itr(startV, visited);
            cout << endl;
        }

        void _bfs_Itr(int startV, bool visited[]) {
            queue<int> q;                               // Only queue is used, rest is same
            q.push(startV);
            visited[startV] = true;

            while (!q.empty()) {
                int curV = q.front();
                q.pop();
                cout << curV << " ";

                for (auto& i : adjList[curV]) {
                    if (!visited[i]) {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }

        void numOfComponents() {
            bool visited[noOfVertices];
            for (int i=0; i < noOfVertices; i++) {
                visited[i] = false;
            }
            int count = 0;
            
            _bfs_Itr(0, visited);   // 0 is start vertex. can be taken as arg
            count++;

            for (int i=0; i < noOfVertices; i++) {
                if (!visited[i]) {
                    _bfs_Itr(i, visited);
                    count++;
                }
            }
            cout << "No of components : " << count << endl;
        }

};

int main() {

    // 0 --------- 1
    // |           |
    // |           |
    // |           |
    // 2 --------- 3 -------- 4

    Graph g1(6);        // Undirected graph
    g1.addEdge(0, 1);   // forward arrow
    g1.addEdge(1, 0);   // reverse arrow
    g1.addEdge(0, 2);
    g1.addEdge(2, 0);
    g1.addEdge(1, 3);
    g1.addEdge(3, 1);
    g1.addEdge(2, 3);
    g1.addEdge(3, 2);
    g1.addEdge(3, 4);
    g1.addEdge(4, 3);
    g1.addEdge(5, 5);   // for making 2 graphs
    g1.printAdjList();
    g1.bfs_Itr(0);
    // g1.dfs_Rec(0);
    g1.numOfComponents();
    cout << "*********************************" << endl;
}