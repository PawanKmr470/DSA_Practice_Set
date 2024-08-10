#include <iostream>
using namespace std;

// REF : https://leetcode.com/problems/longest-repeating-character-replacement/description/
// NOTES :
//      Ex. s = "ABAB" k = 2 -> 4 "AAAA", s = "AABABBA" k = 1 -> 4
//      Sliding Window
//          Create Hashmap of freqency (array can work)
//          Exapand if chars can be changed is < k and if > k then shrink
//          WindowLen - MaxFreqOfCharFromHashmap <= k
//          If condition <= k, increment right pointer
//          If condition > k, increment left pointer

// T: O(26n)
// S: O(26)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, maxFreq = 0;
        unordered_map<char, int> mp;
        int res = -1;

        while (r < n) {
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);

            int windowLen = r - l + 1;
            if (windowLen - maxFreq <= k) {
                res = max(res, windowLen);
                r++;
            }
            else {
                mp[s[l]]--;
                r++;            // why this is needed ?? Due to this window won't shrink. It will be only shifted.
                l++;
            }
        }

        return res;
    }
};