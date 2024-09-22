#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/decode-ways/description/
// NOTES :
//      Approach is similar to climbing stairs
//      Recursive approach -
//          Decision tree is to take 1 character or 2 character from the string.
//          At the end if string gets empty then it means we decoded successfully.
//          While doing so, need to take care of edge case of digit starting from 0
//          and it shoudn't be 0.
//      DP -
//          dp[0] = 1 becuase empty string can be decoded in 1 way
//          TODO : Space optimization is remaining

// Ref : https://www.youtube.com/watch?v=mJfqNKwUavE
// T: O(2^n)
// S: O(n) stack lenght
class Solution {
public:
    int n = 0;
    int numDecodings(string s) {
        n = s.size();
        return helper(s, 0);
    }

    int helper(string s, int i) {
        if (i == n) return 1;           // means reaching at the end so 1 way is found
        if (s[i] == '0') return 0;      // split is not possible

        int count1 = 0, count2 = 0;

        count1 = helper(s, i + 1);
        if (i < n - 1 && s.substr(i, 2) <= "26") {
            count2 = helper(s, i + 2);
        }

        return count1 + count2;
    }
};

// T: O(n)
// S: O(n)
class Solution2 {
public:
    int n = 0;
    int numDecodings(string s) {
        n = s.size();
        vector<int> dp(n + 1, -1);
        return helper(s, 0, dp);
    }

    int helper(string s, int i, vector<int>& dp) {
        if (i == n) return 1;
        if (s[i] == '0') return 0;

        if (dp[i] != -1)
            return dp[i];

        int count1 = 0, count2 = 0;

        count1 = helper(s, i + 1, dp);
        if (i < n - 1 && stoi(s.substr(i, 2)) <= 26) {
            count2 = helper(s, i + 2, dp);
        }

        return dp[i] = count1 + count2;
    }
};


// Ref : https://www.youtube.com/watch?v=FEkZxCl_-ik
// T: O(n)
// S: O(n)
class Solution3 {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);

        dp[0] = 1;
        if (s[0] == '0')
            dp[1] = 0;
        else
            dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            string oneDigit = s.substr(i-1, 1);
            string twoDigit = s.substr(i-2, 2);

            if (oneDigit >= "1")
                dp[i] = dp[i - 1];

            if (twoDigit >= "10" && twoDigit <= "26")
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};


int main() {
    string str1 = "226";
    cout << Solution().numDecodings(str1) << endl;
    cout << Solution2().numDecodings(str1) << endl;
    cout << Solution3().numDecodings(str1) << endl;
}