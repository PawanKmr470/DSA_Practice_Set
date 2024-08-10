#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> hashmap = {
            {')', '('}, 
            {'}', '{'}, 
            {']', '['}
        };

        for (int i=0; i < s.length(); i++) {
            if (hashmap.find(s[i]) == hashmap.end())
                st.push(s[i]);

            else {
                if (!st.empty()) {
                    if (st.top() != hashmap[s[i]])
                        return false;
                    st.pop();
                }
                else
                    return false;
            }
        }

        if (st.empty())
            return true;
        else
            return false;
    }
};

int main() {
    string s = "((){}[[]])";
    cout << "output : " << Solution().isValid(s) << endl;
}