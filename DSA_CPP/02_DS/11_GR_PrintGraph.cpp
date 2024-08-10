#include <iostream>
#include <vector>
#include <list>
using namespace std;

// typedef pair<int, int> Pair;

// Unweighted Graph class with adj list dynamcially allocated.
class Graph {
    private:
        int noOfVertices;
        vector<int>* adjList;
    public:
        Graph(int vertices) {
                noOfVertices = vertices;
                adjList = new vector<int> [vertices];
            }
        ~Graph() {
            delete[] adjList;
        }

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
};

// Weighted Graph class with adj list dynamcially allocated.
class wtGraph {
    private:
        int noOfVertices;
        vector<pair<int, int>> *adjList;
    public:
        wtGraph(int vertices) {
                noOfVertices = vertices;
                adjList = new vector<pair<int, int>> [vertices];
            }
        ~wtGraph() {
            delete[] adjList;
        }

        void addEdge(int src, int dst, int wt) {
            adjList[src].push_back(make_pair(dst, wt));
            adjList[dst].push_back(make_pair(src, wt));
        }

        void printAdjList() {
            for (int i=0; i < noOfVertices; i++) {
                cout << "[" << i << "] : ";
                for(auto &j : adjList[i]) {
                    cout << j.first << "/" << j.second << "  ";
                }
                cout << endl;
            }
        }
};

// Unweighted Graph class with adj list without using new.
// though vector itself create dynamic array
class Graph2 {
    private:
        // static const int MAX_VERTICES = 100; // maximum number of vertices
        // int numVertices;
        // vector<int> adjList[MAX_VERTICES];
        int noOfVertices;
        vector<vector<int>> adjList;
    public:
        Graph2(int vertices) {
                noOfVertices = vertices;
                adjList.resize(noOfVertices);   // omitting this is seg fault
            }
        ~Graph2() {};

        void addEdge(int src, int dst) {
            adjList[src].push_back(dst);
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
};

// Weighted Graph class with adj list without using new.
// though vector itself create dynamic array
class Graph3 {
    private:
        // static const int MAX_VERTICES = 100; // maximum number of vertices
        // int numVertices;
        // vector<pair<int, int>> adjList[MAX_VERTICES];
        int noOfVertices;
        vector<vector<pair<int,int>>> adjList;
    public:
        Graph3(int vertices) {
                noOfVertices = vertices;
                adjList.resize(noOfVertices);   // omitting this is seg fault
            }
        ~Graph3() {};

        void addEdge(int src, int dst, int wt) {
            adjList[src].push_back(make_pair(dst,wt));
            adjList[dst].push_back(make_pair(src,wt));
        }

        void printAdjList() {
            for (int i=0; i < noOfVertices; i++) {
                cout << "[" << i << "] : ";
                for(auto &j : adjList[i]) {
                    cout << j.first << "/" << j.second << "  ";
                }
                cout << endl;
            }
        }
};

// Or to avoid vector of pair of vector of pair etc, we can create Edge class
// ChatGPT code :D
class Edge {
public:
    int to_vertex;
    int weight;
    Edge(int to_vertex, int weight) : to_vertex(to_vertex), weight(weight) {}
};

class WeightedGraph {
private:
    int num_vertices_;
    std::vector<std::vector<Edge>> adj_list_;

public:
    WeightedGraph(int num_vertices) : num_vertices_(num_vertices), adj_list_(num_vertices_) {}

    void add_edge(int u, int v, int weight) {
        adj_list_[u].push_back(Edge(v, weight));
        adj_list_[v].push_back(Edge(u, weight));
    }

    void print_graph() {
        for (int i = 0; i < num_vertices_; i++) {
            std::cout << "Vertex " << i << " : ";
            for (Edge edge : adj_list_[i]) {
                std::cout << "(" << edge.to_vertex << ", " << edge.weight << ") ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {

    // 0 --------- 1
    // |           |
    // |           |
    // |           |
    // 2 --------- 3 -------- 4

    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.printAdjList();
    cout << "----------------" << endl;

    wtGraph g1(5);
    g1.addEdge(0, 1, 100);
    g1.addEdge(0, 2, 200);
    g1.addEdge(1, 3, 300);
    g1.addEdge(2, 3, 400);
    g1.addEdge(3, 4, 500);
    g1.printAdjList();
    cout << "----------------" << endl;

    Graph2 g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 3);
    g2.addEdge(2, 3);
    g2.addEdge(3, 4);
    g2.printAdjList();
    cout << "----------------" << endl;

    Graph3 g3(5);
    g3.addEdge(0, 1, 100);
    g3.addEdge(0, 2, 200);
    g3.addEdge(1, 3, 300);
    g3.addEdge(2, 3, 400);
    g3.addEdge(3, 4, 500);
    g3.printAdjList();
    cout << "----------------" << endl;

    WeightedGraph graph(5);
    graph.add_edge(0, 1, 10);
    graph.add_edge(0, 2, 20);
    graph.add_edge(1, 3, 30);
    graph.add_edge(2, 3, 40);
    graph.add_edge(3, 4, 50);
    graph.print_graph();
    cout << "----------------" << endl;

    return 0;
}