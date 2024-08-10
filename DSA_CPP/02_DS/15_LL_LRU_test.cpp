#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

// We need only hashmap to store the key & value.
// when key,value comes for put operation, we'll add the pair in hashmap.
// for get operation, we'll return key's value.
// BUT for element eviction we need to find out what is the least accessed element,
// we need to remove that.
// For that we need Linked List kind of data structure in queue fashion.
// where last element will be the least accessed element and first element most accessed.

class LRUCache {
    private:
        int cacheSize;
        list<int> l;                // will store key
        unordered_map<int, int> m;  // will store key, value
    
    public:
        LRUCache(int capacity) {
            cacheSize = capacity;
        }
        ~LRUCache() {};

        void put(int key, int value) {              // **** Need to cover 3 cases ****
            if (m.find(key) == m.end()) {
                if (m.size() == cacheSize) {        // 3. Inserting pair when key is not present
                    int oldKey = l.back();          //    And cache is full
                    l.pop_back();
                    m.erase(oldKey);
                }
            }
            else {                                  // 2. Inserting pair when key is already present
                m.erase(key);                       //    And cache is not full
                l.remove(key);
            }

            m[key] = value;                         // 1. Inserting first pair
            l.push_front(key);
        }

        int get(int key) {                          // **** Need to cover 2 cases ****
            if (m.find(key) == m.end()) {           // 1. Key is not present
                return -1;
            }
            
            l.remove(key);                          // 2. Key is present
            l.push_front(key);
            return m[key];
        }

        // void printLRU() {
        //     cout << "Queue : ";
        //     for (auto &i : l) {
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }

        void printLRU() {
            cout << "Queue is -" << endl;
            for (auto &i : l) {
                cout << i << " " << m[i] << endl;
            }
        }
};

int main() {
    LRUCache cache(5);
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