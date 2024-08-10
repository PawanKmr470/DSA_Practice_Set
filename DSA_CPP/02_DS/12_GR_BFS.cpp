#include <iostream>
#include <list>
#include <queue>
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
    void PrintBFS(int, bool[]);
    void BFS(int);
    void PrintAdjLists();
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

void Graph::PrintBFS(int StartVertex, bool visited[]){
    queue<int> q;
    //list<int>::iterator itr;

    q.push(StartVertex);
    visited[StartVertex] = true;

    cout << "BFS traversal - ";
    while (!q.empty()){
        int CurVertex = q.front();
        q.pop();
        cout << CurVertex << " ";

        // for (itr = AdjLists[CurVertex].begin(); itr != AdjLists[CurVertex].end(); itr++){
        //     if (!visited[*itr]){
        //         q.push(*itr);
        //         visited[*itr] = true;
        //     }
        // }
        for(auto &itr : AdjLists[CurVertex]){
            if (!visited[itr]){
                q.push(itr);
                visited[itr] = true;
            }
        }
    }
    cout << endl;
}

void Graph::BFS(int StartVertex){
    bool visited[NumVertices];
    for (int i = 0; i < NumVertices; i++){
        visited[i] = false;
    }
    int disconnected_graphs = 0;
    PrintBFS(StartVertex, visited);
    disconnected_graphs++;
    for (int i=0; i<NumVertices; i++){
        if (visited[i] == false){
            PrintBFS(i, visited);
            disconnected_graphs++;
        }
    }
    cout << "No of disconnected graphs : " << disconnected_graphs << endl;
}

int main(){
    Graph g(6);
    g.AddEdge(0,1);
    g.AddEdge(0,2);
    g.AddEdge(1,2);
    g.AddEdge(2,0);     // comment it for undirected graph
    g.AddEdge(2,3);
    g.AddEdge(3,3);     // comment it for undirected graph
    g.AddEdge(4,5);     // disconnected graph
    g.PrintAdjLists();
    g.BFS(2);

}
