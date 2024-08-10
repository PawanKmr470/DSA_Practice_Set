// REF : 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool is_palindrome(string &s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                string skipL = s.substr(l+1, r-l);
                string skipR = s.substr(l, r-l);
                // string skipL_rev = string(skipL.rbegin(), skipL.rend());
                // string skipR_rev = string(skipR.rbegin(), skipR.rend());

                // if ( (skipL == skipL_rev) || (skipR == skipR_rev) )
                //     return true;
                // else
                //     return false;

                if ( is_palindrome(skipL) || is_palindrome(skipR) )
                    return true;
                else
                    return false;

            }
            l++;
            r--;
        }
        return true;
    }
};


int main() {
    string s = "abc";
    cout << Solution().validPalindrome(s) << endl;
    return 0;
}