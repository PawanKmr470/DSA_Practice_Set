#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
    private:
        int cacheSize;
        list<int> l;
        unordered_map<int, int> m;
    public:
        LRUCache(int capacity) {
            cacheSize = capacity;
        }
        ~LRUCache() {};

        void put(int key, int value) {
            if (m.find(key) != m.end()) {
                l.remove(key);
                m.erase(key);
            }
            else {
                if (m.size() == cacheSize) {
                    int oldKey = l.back();
                    l.pop_back();
                    m.erase(oldKey);
                }
            }

            m[key] = value;
            l.push_front(key);
        }

        int get(int key) {
            if (m.find(key) == m.end())
                return -1;
            
            l.remove(key);
            l.push_front(key);
            return m[key];
        }

        void printLRU() {
            for (auto &i : l) {
                cout << i << " ";
            }
            cout << endl;
        }
};

int main() {

}