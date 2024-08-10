#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// Kahn's Algorithm
// A DAG has at least 1 vertex with 0 in-degree and 1 vertex with 0 out-degree.
// Topological sort gives a linear ordering of vertices in a directed acyclic graph
// such that, for every directed edge a -> b, vertex ‘a’ comes before vertex ‘b’.
// There could be multiple valid topological orders of a given problem.
// It's used to solve dependency problem.

// Algorithm -
// Step-1: Compute in-degree (number of incoming edges) for each of the vertex present
//         in the DAG and initialize the count of visited nodes as 0.
// Step-2: Pick all the vertices with in-degree as 0 and add them into a queue.
// Step-3: Dequeue a vertex
//         (Increment the count of visited nodes by 1 (not mnaintained here.
//          Though it is maintained to compare at the end whether we visited all the nodes or not.
//          so that we can conclude that topo sort is possible or not))
//         Add this vertex to the result.
//         Decrease in-degree by 1 for all its neighbouring nodes.
//         If the in-degree of neighbouring nodes is reduced to zero, then add it to the queue.
//         (In other words - Enqueue the neighbouring vertices with in-degree of 0)
// Step 4: Repeat Step 3 until the queue is empty.
// Step 5: If the count of visited nodes is not equal to the number of nodes in the graph
//         then the topological sort is not possible for the given graph.

// InDegree calculation -
//     for each node in Nodes
//         indegree[node] = 0;
//     for each edge(src, dest) in Edges
//         indegree[dest]++

// Kahn's Alogrithm is only applicable on DAG - directed acyclic graph
// Reverse we can say, If Algo doesn't hold true then it's directed cyclic graph
// output will be an invalid topological sort in case of cycle.

// Applications - course schedule, task schedule, circuit design, software dependencies etc.

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
            vector<int> res;
            vector<int> indegree(noOfVertices, 0);

            for (int i=0; i < noOfVertices; i++) {
                for (auto &dst : adjList[i])
                    indegree[dst]++;                // increment dst's indegree
            }

            queue<int> q;
            for (int i=0; i < noOfVertices; i++) {
                if (indegree[i] == 0)
                    q.push(i);                      // push vertices into Q which have 0 indegree
            }

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                res.push_back(node);                // Pop & add it into result

                for (auto &nei : adjList[node]) {
                    indegree[nei]--;                // All nei's indegree will get reduced by 1
                    if (indegree[nei] == 0)         // If indegree is becoming 0, then add it into Q
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