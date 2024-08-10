#include <iostream>
using namespace std;

// O(T) : Amortized complexity O(alpha(n)) ~ nearly constant time
// O(T) : O(logn) without path compression
// O(S) : O(n)
class DisjointSet {
private:
    int* parent;
    int* rank;
public:
    DisjointSet(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i; i < n; i++) {
            parent[i] = i;                  // parent of itself initially
            rank[i] = 0;                    // rank of all is 0 initially
        }
    }

    int findParent(int a) {
        if (parent[a] == a)
            return a;
        return parent[a] = findParent(parent[a]);
    }

    void Union(int x, int y) {
        int xP = findParent(x);
        int yP = findParent(y);

        if (xP == yP) return;           // we want to do union only if parents are different

        if (rank[xP] > rank[yP])
            parent[yP] = xP;            // Make xP parent of yP as xP's rank is higher
        else if (rank[xP] < rank[yP])
            parent[xP] = yP;
        else
            parent[yP] = xP;
            rank[xP]++;                 // whichever is becoming parent, increase it's rank
                                        // rank[xP] += rank[yP] is the Union by Size
    }
};

int main() {
    DisjointSet obj(5);
    obj.Union(0, 2);
    obj.Union(4, 2);
    obj.Union(3, 1);

    if (obj.findParent(4) == obj.findParent(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    if (obj.findParent(1) == obj.findParent(0))
        cout << "Yes\n";
    else
        cout << "No\n";
}