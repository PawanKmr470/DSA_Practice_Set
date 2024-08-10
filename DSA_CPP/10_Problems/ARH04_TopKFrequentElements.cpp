#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// By Sorting
// By Max Heap
// By Min Heap
// By Bucket sort
// By Quick Select sort

// Checkout -
//      Top K frequent elements.
//      Kth largest elements in an array.
//      Kth largest elements in an stream.
//      k-way merge

// Will do MinHeap in (O(nlogk)) then Bucket Sort in (O(n))

// REF : https://leetcode.com/problems/top-k-frequent-elements/description/
// NOTES :
//          1. Hashmap + Sorting
//              Create Frequecy Hashmap O(n) & sort O(nlogn) on freq basis. Return top k elements O(k).
//              Can be done using Array. Same logic. BUT both way T:(nlogn) & we want < O(nlogn)
//          2. Max Heap + Hashmap
//              Create Frequecy Hashmap O(n) & Build heap on freq basis O(n).
//              Pop k elements from heap O(k * logn) => O(n) + O(n) + O(klogn) => O(2n + klogn) => O(n + klogn)
//              S: O(2n) => O(n)
//              Here space is consumed more than Min Heap approach becuase we are filling all the elements
//              in the Max Heap
//          3. Min Heap + Hashmap
//              Create Frequecy Hashmap O(n) + Build heap of size k on freq basis. O(k)
//              Push will be for n-k elements & pop will be for n-k elements. O((n-k)logk)
//              In the end, all results will be in the heap i.e. pop k elements. O(klogk) ~ can be ignored
//              O(n + k + (n-k)logk) => k & klogk constants then ================================> O(n + nlogk)
//              Overall :
//                  T: O(n + nlogk + klogk) Hashmap + Minheap + result  => O(nlogk)
//                  S: O(n + k)             Hashmap + Minheap           => O(n)
//          Ref : https://www.youtube.com/watch?v=Wh3A29psE_Y
//                  As per this Max Heap is better
//                  But Min Heap is discussed ?? conflicting
//
//          4. Bucket Sort
//              Create Hashmap of element:frequency
//              Create Vector where index is frequency & value is element(s).
//                  Since there could be multiple elements => vector<vector<int>>
//              Start parsing vector<vector<int>> from the end till Kth position to find the element.

// T: O(n) using Bucket Sort
// S: O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        vector<vector<int>> freq(nums.size());
        for (auto &i : count) {
            freq[i.second].push_back(i.first);
        }

        vector<int> res;
        for (int i = freq.size()-1; i > 0; i--) {
            for (int j = 0; j < freq[i].size(); j++) {
                res.push_back(freq[i][j]);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};


int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> ans;
    ans = Solution().topKFrequent(nums, k);
    for (auto &i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}