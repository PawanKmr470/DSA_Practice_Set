#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string);
};

int Solution::lengthOfLongestSubstring(string s){
    int left = 0;
    int right = 0;
    int maxCount = 0;
    set<char> uniqueSet;
    while(right < s.length()){
        char ch = s[right];
        if (uniqueSet.count(ch) == 0){
            uniqueSet.insert(ch);
            maxCount = max(maxCount, right - left + 1);
            right++;
        }
        else {
            while(s[left] != ch){
                uniqueSet.erase(s[left]);
                left++;
            }
            uniqueSet.erase(ch);
            left++;
        }
    }
    return maxCount;
}

int main(){
    Solution s;
    int ret = s.lengthOfLongestSubstring("tmmzuxt");
    cout << "ret is : " << ret << endl;
}
