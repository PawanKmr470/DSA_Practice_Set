#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
using namespace std;

template <class T>
class Graph
{
private:
    int NumVertices;
    unordered_map<T, list<T>> AdjLists;
    void DFS(T StartVertex, unordered_map<T, bool>& visited);
    void BFS(T StartVertex, unordered_map<T, bool>& visited);
public:
    Graph(int vertices) {
        NumVertices = vertices;
        //AdjLists = new list<T>[vertices];
        cout << "created adj list." << endl;
    }
    ~Graph() {
        //delete[] AdjLists;
    };
    void AddEdge(T, T);
    void BFS(T);
    void DFS(T);
    void PrintAdjLists();
};
template <class T>
void Graph<T>::AddEdge(T src, T dst) {
    AdjLists[src].push_back(dst);
    AdjLists[dst].push_back(src);   // This line is reverse arrow and not required if graph is directed.
}
template <class T>
void Graph<T>::PrintAdjLists() {
    for (auto element : AdjLists) {
        cout << "[" << element.first << "] -> ";
        for (auto& j : element.second) {
            cout << j << " ";
        }
        cout << endl;
    }
}
template <class T>
void Graph<T>::BFS(T StartVertex, unordered_map<T, bool> &visited) {
    queue<T> q;
    q.push(StartVertex);
    visited[StartVertex] = true;
    while (!q.empty()) {
        T CurVertex = q.front();
        q.pop();
        cout << CurVertex << " ";
        for (auto vertex : AdjLists[CurVertex]) {
            if (!visited[vertex]) {
                q.push(vertex);
                visited[vertex] = true;
            }
        }
    }
}
template <class T>
void Graph<T>::BFS(T StartVertex) {
    unordered_map<T, bool> visited;
    for (auto element : AdjLists) {
        visited[element.first] = false;
    }
    cout << "BFS: ";
    BFS(StartVertex, visited);
    for (auto visit : visited) {
        if (!visit.second) {
            BFS(visit.first, visited);
        }
    }
}
template <class T>
void Graph<T>::DFS(T StartVertex, unordered_map<T, bool>& visited) {
    visited[StartVertex] = true;
    cout << StartVertex << " ";
    for (auto vertex : AdjLists[StartVertex]) {
        if (!visited[vertex])
            DFS(vertex, visited);
    }
}
template <class T>
void Graph<T>::DFS(T StartVertex) {
    cout << endl;
    cout << "DFS: ";
    int disconnectedComponents = 0;
    unordered_map<T, bool> visited;
    for (auto element : AdjLists) {
        visited[element.first] = false;
    }
    DFS(StartVertex, visited);
    disconnectedComponents++;
    for (auto visit : visited) {
        if (!visit.second) {
            disconnectedComponents++;
            DFS(visit.first, visited);
        }
    }
    cout << endl;
    cout << "disconnectedComponents: " << disconnectedComponents << endl;
    cout << endl;
}
int main(int argc, char* argv[]) {
    Graph<string> g(8);
    g.AddEdge("city0", "city2");
    g.AddEdge("city0", "city4");
    g.AddEdge("city2", "city4");
    g.AddEdge("city2", "city3");
    g.AddEdge("city1", "city5");
    g.AddEdge("city6", "city7");
    g.PrintAdjLists();
    g.BFS("city2");
    g.DFS("city2");
    return 0;
}