#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class HashTable {
private:
    vector<list<pair<string, string>>> table;
    int table_size;

    
public:
    HashTable(int size) : table_size(size) {
        table.resize(size);
    }

};

int main() {

    
}
