#include <iostream>
using namespace std;

// brute force -
//     get all substrings and check each substring for palindrom and keep track of greatest substring
//     T - O(n^2 * n) - extra n for checking palindrom
//     S - O(1)

// Expand fron centre -
//     T - O(n^2)
//     S - O(1)

class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0;
        int right = 0;
        string res = "";
        int resLen = 0;
        for (int i=0; i < s.length(); i++) {
            // For odd lenght
            left = i;
            right = i;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if ((right - left + 1) > resLen) {
                    resLen = right - left + 1;
                    res = s.substr(left, resLen);
                }
                left -= 1;
                right += 1;
            }

            // For even lenght
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if ((right - left + 1) > resLen) {
                    resLen = right - left + 1;
                    res = s.substr(left, resLen);
                }
                left -= 1;
                right += 1;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string result = s.longestPalindrome("bbadab");
    cout << "Longest palindrom is : " << result << endl;
    return 0;
}