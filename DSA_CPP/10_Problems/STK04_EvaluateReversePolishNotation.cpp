// REF : https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
using namespace std;

class Solution {
private:
    stack<int> st;
public:
    int evalRPN(vector<string>& tokens) {
        set<string> opr = {"+", "-", "*", "/"};
        for (auto x : tokens) {
            if (opr.find(x) == opr.end()) {
                st.push(stoi(x));
            }
            else if (x == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a + b);
            }
            else if (x == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if (x == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b * a);
            }
            else if (x == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);
            }
        }

        return st.top();
    }
};


int main() {
    return 0;
}