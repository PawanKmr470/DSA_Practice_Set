#include <iostream>
using namespace std;

// REF : https://leetcode.com/problems/group-anagrams/
// NOTES :
//      1. Brute force way
//          Generate all permutations of str1 and search each permuted string in the bigger str2.
//          T: O(n^2) + O(n!) for permutation
//      2. Convert problem to String Anagram problem
//          Find if any substring of s2 is anagram of s1
//          S1 Hashmap & S2 Hashmap of frequecies. Perform sliding window of s1 size on s2.
//          Hashmap comparision will tell that subtrings are anagram or not.
//          Either take unordered_map or array, both will solve same pupose.

// T: O(n1 + n2)
// S: O(1)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // s1 is substring & s2 is superstring
        if (s1.size() > s2.size()) return false;        // Edge case

        vector<int> count1(26, 0), count2(26, 0);       // Create freq hashmaps
        int i;
        for (i = 0; i < s1.size(); i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        if (count1 == count2) return true;              // Edge case

        int l = 0, r = i;   // i == 3
        while (r < s2.size()) {                         // Run window further to find substring
            count2[s2[r] - 'a']++;
            count2[s2[l] - 'a']--;

            if (count1 == count2) return true;

            // slide the window
            r++;
            l++;
        }

        return false;
    }                                                                                                                                                    
};