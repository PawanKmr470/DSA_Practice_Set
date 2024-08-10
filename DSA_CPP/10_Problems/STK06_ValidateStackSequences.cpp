#include <iostream>
#include <stack>
using namespace std;

// REF : https://leetcode.com/problems/validate-stack-sequences/
// NOTES :
//      Two arrays are given - pushed & popped
//      Approach -
//          Take elements from pushed array and push them on a Stack one by one
//          After every push in Stack, we'll check if stack.top == popped.start
//          Till this condition keeps getting satisfied we'll keep popping elements from the Stack.
//          we won't pop from 'popped' array, we'll use traverse it using index.
//          At the end Stack should be emtpy for true and non-empty for false.

// T: O(n)
// S: O(n) for using explicit stack

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int k = 0;
        stack<int> s;
        for (int i = 0; i < pushed.size(); i++) {
            s.push(pushed[i]);
            while (k < popped.size() && !s.empty() && s.top() == popped[k]) {
                s.pop();
                k++;
            }
        }
        return s.size() == 0 ? true : false;
    }
};