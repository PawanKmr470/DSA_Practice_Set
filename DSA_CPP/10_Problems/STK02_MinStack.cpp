#include <iostream>
#include <string>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> min_st;
public:
    MinStack() {};
    
    void push(int val) {
        st.push(val);
        int min_val = val;
        if (!min_st.empty())
            min_val = min_st.top();
        val = min(val, min_val);
        min_st.push(val);
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


int main() {
    return 0;
}