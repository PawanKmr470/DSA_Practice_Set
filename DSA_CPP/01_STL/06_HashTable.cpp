#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

// Notes :
//      This HashTable uses separate chaining collision avoidance method.
//      why vector<list<pair<string, string>>> ?
//      Because vector's key will be hash key and it's value should be a linked list for separate chaining
//      and value will be pair of actual key and value store togather.

class HashTable {
private:
    vector<list<pair<string, string>>> table;
    int table_size;

    int hash_fun(string key) {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 * ch) % table_size;
        }
        return hash;
    }

public:
    HashTable(int size) : table_size(size) {
        table.resize(size);
    }

    void insert(const string key, const string value) {
        int hash_index = hash_fun(key);
        table[hash_index].push_back({key, value});
    }

    string search(const string key) {
        int hash_index = hash_fun(key);
        for (auto &i : table[hash_index]) {
            if (i.first == key)
                return i.second;
        }
        return "Not found";
    }

};

int main() {
    HashTable t1(5);
    t1.insert("Paul", "Walker");
    t1.insert("Danzel", "Washington");
    t1.insert("Dwayne", "The Rock");
    cout << t1.search("Paul") << endl;
    cout << t1.search("John") << endl;
    return 0;
}
