// REF : https://leetcode.com/problems/daily-temperatures/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> st;

        for (int i = 0; i < temperatures.size(); i++) {

            while ( (!st.empty()) and (temperatures[i] > st.top().first) ) {
                int stackTemp = st.top().first;
                int stackInd = st.top().second;
                st.pop();
                res[stackInd] = (i - stackInd);
            }

            st.push(make_pair(temperatures[i], i));
        }

        return res;
    }
};


int main() {

    vector<int> t = {73,74,75,71,69,72,76,73};
    vector<int> out;
    out = Solution().dailyTemperatures(t);
    for (auto &i: out) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}