#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUcache {
    private:
        int cacheSize;
        list<int> l;
        unordered_map<int, int> m;
    public:
        LRUcache(int capacity) {
            cacheSize = capacity;
        }
        ~LRUcache() {};

        void put(int key, int value) {
            if (m.find(key) == m.end()) {
                if (m.size() == cacheSize) {
                    int oldKey = l.back();
                    l.pop_back();
                    m.erase(key);
                }
            }
            else {
                m.erase(key);
                l.remove(key);
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
            cout << "Queue is -" << endl;
            for (auto &i : l) {
                cout << i << " " << m[i] << endl;
            }
        }
};

int main() {
    LRUcache cache(5);
    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);
    cache.put(4, 40);
    cache.put(5, 50);
    cache.printLRU();
    cache.put(4, 400);
    cache.printLRU();
    cache.put(6, 600);
    cache.printLRU();
}