#include <iostream>
#include <stack>
using namespace std;

// REF : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
// NOTES :
//      Basic stack use case

// T: O(n)
// S: O(n)
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && st.top() == s[i]) {
                st.pop();
            }
            else
                st.push(s[i]);
        }

        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        
        return result;
    }
};

// Using temp string only
// T: O(n)
// S: O(n)
class Solution2 {
public:
    string removeDuplicates(string s) {
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            if (temp.size() != 0 && temp.back() == s[i]) {
                temp.pop_back();
            }
            else
                temp.push_back(s[i]);
        }

        return temp;
    }
};

int main() {
    Solution s1;
    cout << s1.removeDuplicates("abbaca") << endl;
    Solution2 s2;
    cout << s2.removeDuplicates("abbaca") << endl;
}