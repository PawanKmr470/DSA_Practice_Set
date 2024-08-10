// REF : https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> res;
        if (s.size() < p.size())
            return {};

        vector<int> s_count(26, 0);
        vector<int> window(26, 0);

        for (int i = 0; i < p.size(); i++) {
            s_count[s[i] - 'a']++;
            window[p[i] - 'a']++;
        }

        if (s_count == window)
            res.push_back(0);
            
        for (int j = p.size(); j < s.size(); j++) {
            s_count[s[j] - 'a']++;
            s_count[s[j - p.size()] - 'a']--;

            if (s_count == window)
                res.push_back(j - p.size() + 1);
        }
        return res;
    }
};

int main() {
    string s = "eba";
    string p = "abc";
    vector<int> ans;
    ans = Solution().findAnagrams(s, p);
    for (auto &i: ans)
        cout << i << " ";
    cout << endl;
    return 0;
}