// REF : https://leetcode.com/problems/valid-palindrome-iv/description/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool makePalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        int count = 0;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
                continue;
            }
            else {
                if (count < 2) {
                    l++;
                    r--;
                    count++;
                    continue;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};


int main() {
    return 0;
}