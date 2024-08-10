// REF : https://leetcode.com/problems/valid-palindrome/description/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size();
        while (l < r) {
            while ( (! isalnum(s[l])) && (l < r) ) {
                l++;
            }
            while ( (! isalnum(s[r])) && (l < r) ) {
                r--;
            }

            if ( tolower(s[l]) != tolower(s[r]) )
                return false;
            
            l++;
            r--;
        }
        return true;
    }
};


int main() {

    string s = "A man, a plan, a canal: Panama";
    cout << Solution().isPalindrome(s) << endl;
    return 0;
}