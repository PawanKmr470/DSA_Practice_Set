#include <iostream>
#include <stack>
using namespace std;

// REF : https://leetcode.com/problems/validate-stack-sequences/
// NOTES :
//      Basic stack use case

// T: O(n) linear time but totally depend on the input k[k[k[]]] or k[k[]k[]k[]]
// S: O(n) for using explicit stack
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']')                         // Push char into stack until ] is hit
                st.push(s[i]);
            else {
                string substr = "";
                while (st.top() != '[') {            // Create string by popping until [ is hit
                    substr = st.top() + substr;
                    st.pop();
                }
                st.pop();

                string digit = "";
                while (!st.empty() && isdigit(st.top())) {  // Check the empty stack also
                    digit = st.top() +  digit;              // Find the digit chars
                    st.pop();
                }

                int digit_int = stoi(digit);
                string temp = "";
                for (int j = 0; j < digit_int; j++) {
                    temp = temp + substr;                   // Multiply string by digit times
                }

                for (char &ch : temp)
                    st.push(ch);                            // Push expanded string back into stack

            }
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;                     // Make result string out of stack
            st.pop();
        }

        return result;
    }
};