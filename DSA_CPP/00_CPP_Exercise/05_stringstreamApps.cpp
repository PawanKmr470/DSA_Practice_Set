#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

// Two operations for stringstream object : Insertion & Extraction
// Common methods & operators : <<, >>, ss.str(), ss.clear()

void countWords() {
    string str = "Alice Bob John";

    int count = 0;
    string word;
    stringstream ss(str);

    while (ss >> word) {
        count++;
    }

    cout << "Number of words : " << count << endl;
}

void freqOfWords() {
    string str = "Geeks For Geeks Quiz Geeks Quiz Practice Practice";

    unordered_map<string, int> mp;
    string word;
    stringstream ss(str);

    while (ss >> word) {
        mp[word]++;
    }

    for (auto &i : mp) {
        cout << i.first << " : " << i.second << endl;
    }
}

void intToString() {
    int x = 123;
    stringstream ss;
    int res1;                           // NOTE : stringstream will give output as integer
    string res2;                        // NOTE : stringstream will give output as string

    ss << x;
    ss >> res1;

    cout << "output as int : " << res1 + 111 << endl;

    ss.clear();                         // Need to clear it before reassigning
    ss << x;
    ss >> res2;
    cout << "output as string : " << res2 << endl;
}


int main() {
    countWords();
    freqOfWords();
    intToString();
    return 0;
}