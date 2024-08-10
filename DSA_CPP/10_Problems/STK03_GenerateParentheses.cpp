// REF : https://leetcode.com/problems/generate-parentheses/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        stack<char> st;
        backtrack(0, 0, n, st, res);
        return res;
    }

    void backtrack(int open_cnt, int close_cnt, int &n, stack<char> &st, vector<string> &res) {
        if (open_cnt == close_cnt and close_cnt == n) {
            string ans;
            for (stack<char> temp_st = st; !temp_st.empty(); temp_st.pop()) {
                ans.push_back(temp_st.top());
            }
            string rev = string(ans.rbegin(), ans.rend());
            res.push_back(rev);
            return;
        }

        if (open_cnt < n) {
            st.push('(');
            backtrack(open_cnt + 1, close_cnt, n, st, res);
            st.pop();
        }

        if (close_cnt < open_cnt) {
            st.push(')');
            backtrack(open_cnt, close_cnt + 1, n, st, res);
            st.pop();
        }
    }

};


class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }

        if (n > 0)
            addingpar(v, str+"(", n-1, m+1); 

        if (m > 0)
            addingpar(v, str+")", n, m-1);
    }
};


int main() {

    // vector<string> out = Solution().generateParenthesis(3);
    vector<string> out = Solution2().generateParenthesis(3);
    cout << "output : " << endl;
    for (auto &i : out) {
        cout << i << endl;
    }
    return 0;
}