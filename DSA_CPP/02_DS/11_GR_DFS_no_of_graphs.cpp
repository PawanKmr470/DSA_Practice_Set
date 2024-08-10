#include <iostream>
#include <list>
#include <stack>
using namespace std;

// Here node value is index itself. If we want to store specific values
// in nodes then two structures will be required. something like below -
// struct Node {
//     int value;
//     Node* next;
// };
// struct graphEdge {
//     int source, destination;
// };

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
            adjList[src].push_back(dst);    // adjList is a ptr to array of linked list.
                                            // dereference it -> go to that specific list and add item.
            // adjList[dst].push_back(src); // This is reverse arrow. Not used here but it's a way.
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


        void dfs_Rec(int startV) {
            bool visited[noOfVertices];
            for (int i=0; i < noOfVertices; i++) {
                visited[i] = false;
            }
            cout << "DFS traversal rec - ";
            _dfs_Rec(startV, visited);
            cout << endl;
        }

        void _dfs_Rec(int curV, bool visited[]) {
            cout << curV << " ";
            visited[curV] = true;

            for (auto& i : adjList[curV]) {
                if (!visited[i]) {
                    _dfs_Rec(i, visited);
                }
            }
        }


        void dfs_Itr(int startV) {
            bool visited[noOfVertices];     // int vector init is easier 0/1
            for (int i=0; i < noOfVertices; i++) {
                visited[i] = false;
            }
            cout << "DFS traversal itr - ";
            _dfs_Itr(startV, visited);
            cout << endl;
        }

        void _dfs_Itr(int startV, bool visited[]) {
            stack<int> s;
            s.push(startV);
            visited[startV] = true;

            while (!s.empty()) {
                int curV = s.top();
                s.pop();
                cout << curV << " ";

                for (auto& i : adjList[curV]) {
                    if (!visited[i]) {
                        s.push(i);
                        visited[i] = true;
                    }
                }
            }
        }


        // For number of graphs, we start dfs from each vertex.
        void numOfComponents() {
            bool visited[noOfVertices];
            for (int i=0; i < noOfVertices; i++) {
                visited[i] = false;
            }
            int count = 0;
            
            _dfs_Itr(0, visited);   // 0 is start vertex. can be taken as arg
            count++;

            for (int i=0; i < noOfVertices; i++) {
                if (!visited[i]) {
                    _dfs_Itr(i, visited);
                    count++;
                }
            }
            cout << "No of components : " << count << endl;
        }
};

int main() {

    // This is simple dfs and in this we don't require any extra DS except visited array.
    // Approach is same for Undirected and Directed graphs here.
    // all paths, cycle detection, shortest path etc would just modify this approach
    // with extra DS.

    //    0 <-----> 2
    //    |       //\
    //    |     /   |    __
    //   \|/ /     \|/ /    \
    //   1          3        |
    //               /\\ ___ /

    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    g.addEdge(4,4);     // added to increase number of graphs
    g.printAdjList();
    g.dfs_Itr(0);
    g.dfs_Rec(0);
    g.numOfComponents();
    cout << "*********************************" << endl;

    // 0 --------- 1
    // |           |
    // |           |
    // |           |
    // 2 --------- 3 -------- 4

    Graph g1(5);        // Undirected graph
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
    g1.printAdjList();
    g1.dfs_Itr(0);
    g1.dfs_Rec(0);
    g1.numOfComponents();
    cout << "*********************************" << endl;

    Graph g2(5);        // Directed graph
    g2.addEdge(0, 1);   // forward arrow
    g2.addEdge(0, 2);
    g2.addEdge(1, 3);
    g2.addEdge(2, 3);
    g2.addEdge(3, 4);
    g2.printAdjList();
    g2.dfs_Itr(0);
    g2.dfs_Rec(0);
    g2.numOfComponents();
}