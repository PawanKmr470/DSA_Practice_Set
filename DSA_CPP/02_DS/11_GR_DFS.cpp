#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
private:
    int NumVertices;
    list<int>* AdjLists;
public:
    Graph(int vertices){
        NumVertices = vertices;
        AdjLists = new list<int> [vertices];
        cout << "created adj list." << endl;
    }
    ~Graph(){};
    void AddEdge(int, int);
    void PrintAdjLists();
    void DFS(int);
    void PrintDFS(int, bool[]);
    void DFSRec(int);
    void PrintDFSRec(int, bool[]);
};

void Graph::AddEdge(int src, int dst){
    AdjLists[src].push_back(dst);
    //AdjLists[dst].push_back(src);   // This line is reverse arrow and not required if graph is directed.
}

void Graph::PrintAdjLists(){
    for (int i=0; i<NumVertices; i++){
        cout << "[" << i << "] -> ";
        for(auto &j:AdjLists[i]){
            cout << j << " ";
        }
        cout << endl;
    }
}

void Graph::PrintDFS(int StartVertex, bool visited[]){
    stack<int> s;

    s.push(StartVertex);
    visited[StartVertex] = true;

    cout << "DFS traversal - ";

    while (!s.empty()){
        int CurVertex = s.top();
        s.pop();
        cout << CurVertex << " ";

        for(auto &itr : AdjLists[CurVertex]){
            if (!visited[itr]){
                s.push(itr);
                visited[itr] = true;
            }
        }
    }
    cout << endl;
}

void Graph::DFS(int StartVertex){
    bool visited[NumVertices];
    for (int i = 0; i < NumVertices; i++){
        visited[i] = false;
    }
    int disconnected_graphs = 0;
    PrintDFS(StartVertex, visited);
    disconnected_graphs++;
    for (int i=0; i<NumVertices; i++){
        if (visited[i] == false){
            PrintDFS(i, visited);
            disconnected_graphs++;
        }
    }
    cout << "No of disconnected graphs : " << disconnected_graphs << endl;
}

void Graph::PrintDFSRec(int StartVertex, bool visited[]){
    visited[StartVertex] = true;
    cout << StartVertex << " ";
    for (auto &vertex: AdjLists[StartVertex]){
        if (!visited[vertex]){
            PrintDFSRec(vertex, visited);
        }
    }
}

void Graph::DFSRec(int StartVertex){
    bool visited[NumVertices];
    for (int i = 0; i < NumVertices; i++){
        visited[i] = false;
    }
    cout << "DFS Traversal Recursive - ";
    int disconnected_graphs = 0;
    PrintDFSRec(StartVertex, visited);
    disconnected_graphs++;
    for (int j=0; j<NumVertices; j++){
        if (visited[j] == false){
            PrintDFSRec(j, visited);
            disconnected_graphs++;
        }
    }
    cout << endl;
    cout << "No of disconnected graphs : " << disconnected_graphs << endl;
}

int main(){
    Graph g(4);         // 6 for disconnected graph
    g.AddEdge(0,1);
    g.AddEdge(0,2);
    g.AddEdge(1,2);
    g.AddEdge(2,0);     // comment it for undirected graph
    g.AddEdge(2,3);
    g.AddEdge(3,3);     // comment it for undirected graph
    //g.AddEdge(4,5);     // disconnected graph
    g.PrintAdjLists();
    g.DFS(2);
    g.DFSRec(2);

}
