#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// https://onlinecourses.nptel.ac.in/noc24_cs79/progassignment?name=198
// https://www.codechef.com/problems/SMSDICT?tab=statement
// https://www.geeksforgeeks.org/find-possible-words-phone-digits/

typedef pair<int, int> mypair;

bool comp(const mypair &a, const mypair &b) {
    return a.second > b.second;
};

int wordsToNumber(int n, vector<string>& words) {
    int count = 0;
    unordered_map <mypair, vector<mypair>> temp_map;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < words[i].size(); j++) {
            if (words[i][j] == 'a' || words[i][j] == 'b' || words[i][j] == 'c') {
                count = count * 10 + 2;
            }
            else if (words[i][j] == 'd' || words[i][j] == 'e' || words[i][j] == 'f') {
                count = count * 10 + 3;
            }
            else if (words[i][j] == 'g' || words[i][j] == 'h' || words[i][j] == 'i') {
                count = count * 10 + 4;
            }
            else if (words[i][j] == 'j' || words[i][j] == 'k' || words[i][j] == 'l') {
                count = count * 10 + 5;
            }
            else if (words[i][j] == 'm' || words[i][j] == 'n' || words[i][j] == 'o') {
                count = count * 10 + 6;
            }
            else if (words[i][j] == 'p' || words[i][j] == 'q' || words[i][j] == 'r' || words[i][j] == 's') {
                count = count * 10 + 7;
            }
            else if (words[i][j] == 't' || words[i][j] == 'u' || words[i][j] == 'v') {
                count = count * 10 + 8;
            }
            else if (words[i][j] == 'w' || words[i][j] == 'x' || words[i][j] == 'y' || words[i][j] == 'z') {
                count = count * 10 + 9;
            }
        }
        temp_map[count]++;
        count = 0;
        
    }

    vector<mypair> v(temp_map.begin(), temp_map.end());
    // sort(v.begin(), v.end(), [](auto &a, auto &b) { return a.second > b.second; });
    sort(v.begin(), v.end(), comp);
    if (v.size() != 0) {
        auto top = v.pop_back();
        return top.first;
    }
    else {
        return 0;
    }
}

int main() {
    int n = 0;
    vector<string> words;
    
    cout << "Enter number of strings : ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    
    cout << wordsToNumber(n, words) << endl;
    return 0;
}