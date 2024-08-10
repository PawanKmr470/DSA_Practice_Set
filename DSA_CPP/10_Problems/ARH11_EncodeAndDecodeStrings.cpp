// REF : https://leetcode.com/problems/encode-and-decode-strings/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for (auto &s : strs) {
            ans = ans + to_string(s.size()) + '#' + s;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int word_len = stoi(s.substr(i, j));
            res.push_back(s.substr(j+1, word_len)); // only word_len is required
            i = j + 1 + word_len;                   // in python it's start idx & end idx
        }                                           // in c++ it's start idx and len
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));


int main() {
    return 0;
}