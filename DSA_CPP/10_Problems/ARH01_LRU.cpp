#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache
{
private:
    unsigned int cachesize;
    list<int> l;
    unordered_map<int, int> m;
public:
    LRUCache(int capacity){
        cachesize = capacity;
        //l.clear();
        //m.clear();
    }
    ~LRUCache() {};
    void put(int, int);
    int get(int);
    void printLRU();
    void printHash();
};

void LRUCache::put(int key, int value){
    if (m.find(key) == m.end()){
        if (l.size() == cachesize){
            int old_key = l.back();
            l.pop_back();
            m.erase(old_key);
        }
    }
    else{
        l.remove(key);
        m.erase(key);
    }
    l.push_front(key);
    m[key] = value;
}

int LRUCache::get(int key){
    if (m.find(key) == m.end()){
        return -1;
    }
    else{
        l.remove(key);
        l.push_front(key);
        return m[key];
    }
}

void LRUCache::printLRU(){
    cout << "Queue : ";
    for (auto &i:l){
        cout << i << " ";
    }
    cout << endl;
}

void LRUCache::printHash(){
    cout << "Hash Table -" << endl;
    for (auto &element:m){
        cout << element.first << " " << element.second;
        cout << endl;
    }
    cout << endl;
}

int main(){
    LRUCache cache(3);
    cache.put(10,10000);
    cache.put(20,20000);
    cache.put(30,30000);
    cache.put(40,40000);
    cache.printLRU();
    cache.printHash();
    cache.get(30);
    cache.printLRU();
    cache.printHash();
}