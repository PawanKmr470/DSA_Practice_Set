#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
// Algo pseudo code
// Initialize result
mst_weight = 0

// Create V single item sets
for each vertex v
    parent[v] = v;
    rank[v] = 0;

Sort all edges into non decreasing 
order by weight w

for each (u, v) taken from the sorted list  E
    do if FIND-SET(u) != FIND-SET(v)
        print edge(u, v)
        mst_weight += weight of edge(u, v)
        UNION(u, v)
*/

// NOTE : we are going to sort by weight so while making the adj list
//        make the weight value first then src and dst. won't need cmp function.
//        vector<pair<wt, pair<int, int>>> adjList. But writing cmp you should know
//        OR vector<vector<int>> edges can also work
//        edges[u][0] --> u    edges[u][1] --> v    edges[u][2] --> wt

// O(T) : Amortized complexity O(alpha(n)) ~ nearly constant time
// O(T) : O(logn) without path compression
// O(S) : O(n)
class Graph {
    private:
        int noOfVertices;
        vector<pair<int, pair<int,int>>> edges;
        vector<int> parent;
        vector<int> rank;

        // vector<list>* adjList;
        // vector<pair<int, int>> *adjList;
        // vector<vector<pair<int,int>>> adjList;
        // adj list can be taken this way also. Refer : 11_GR_PrintGraph.cpp
    public:
        Graph(int vertices) {
                noOfVertices = vertices;
            }
        ~Graph() {};

        void addEdge(int src, int dst, int wt) {
            edges.push_back({wt, {src, dst}});
        }

        void printEdges() {
            for (auto &i : edges) {
                cout << i.second.first << " : " << i.second.second << " - " << i.first << endl;
            }
            
        }

        int findSet (int u) {
            if (parent[u] == u)
                return u;
            return parent[u] = findSet(parent[u]); // return findSet(parent[u])
        }                                          // is without path compression (O(logn))

        // Iterative version
        // int findSet (int u) {
        //     while (parent[u] != u) {
        //         parent[u] = parent[parent[u]];  // path compression. 
        //         u = parent[u];
        //     }
        //     return u;
        // }

        void unionSet (int u, int v) {
            u = findSet(u);
            v = findSet(v);

            if (rank[u] < rank[v])
                parent[u] = v;  // if u's rank is lower then make v the parent of it
            else if (rank[u] > rank[v])
                parent[v] = u;
            else
                parent[v] = u;  // make either one parent but make sure to increase it's rank
                rank[u]++;      // If we do rank[u] += rank[v], Given rank arr was initialized with 1's
        }                       // then it's a Union By Size

        vector<pair<int, pair<int,int>>> kruskal() {
            vector<pair<int, pair<int,int>>> out;
            int minWeight = 0;

            // make each vertex as self parent initially and rank 0
            for (int i=0; i < noOfVertices; i++) {
                parent.push_back(i);
                rank.push_back(0);
            }

            sort(edges.begin(), edges.end());               // Sorting due to Kruskal Algorithm

            for (int i = 0; i < edges.size(); i++) {
                int uP = findSet(edges[i].second.first);    // find src parent
                int vP = findSet(edges[i].second.second);   // find dst parent
                int wt = edges[i].first;

                if (uP != vP) {                             // If parents are same, it's a cycle
                    out.push_back(edges[i]);                // In Kruskal, we ignore this condition
                    unionSet(uP, vP);
                    minWeight += wt;
                }
                // else {
                //     cout << "cycle is detected." << endl;
                // }
            }
            cout << "MST weight : " << minWeight << endl;
            return out;
        }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
    g.printEdges();
    vector<pair<int, pair<int,int>>> ret = g.kruskal();
    for (auto &i : ret) {
        cout << i.second.first << " to " << i.second.second << endl;
    }
    return 0;
}