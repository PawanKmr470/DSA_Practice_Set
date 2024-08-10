#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {

    unordered_map<int, string> m1;
    m1['a'] = "apple";
    m1['b'] = "boy";
    m1['c'] = "cat";

    unordered_map<int, string> m2;
    m2['a'] = "amazon";
    m2['b'] = "bloomberg";
    m2['c'] = "crowdstrike";

    unordered_map<int, string>::iterator itr1;
    unordered_map<int, string>::iterator itr2;

    for (itr1 = m1.begin(), itr2 = m2.begin(); itr1 != m1.end(); itr1++, itr2++) {
        cout << itr1->first << " - " << itr1->second << endl;
        cout << itr2->first << " - " << itr2->second << endl;
    }

    for (auto &[key, value] : m1) {
        cout << key << " = " << value << "\n";
        cout << key << " - " << m2.at(key) << "\n";
    }

    string s = "hello";
    cout << s.length() << endl;
    cout << s.size() << endl;


    return 0;
}