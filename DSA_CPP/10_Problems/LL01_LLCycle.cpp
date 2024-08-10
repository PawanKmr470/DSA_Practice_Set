#include <iostream>
#include <unordered_set>
using namespace std;

// REF : https://leetcode.com/problems/linked-list-cycle/description/
// NOTES :
//      1. Floyd cycle finding algorithm (slow & fast pointer) 
//          TO(n) SO(1)
//      2. Using Hash set
//          TO(n) SO(n)
//      3. By modifying the Node structure by adding visited flag
//          TO(n) SO(1)

// T: O(N)
// S: O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow != nullptr && fast != nullptr && \
                fast->next != nullptr) {
            
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

// T: O(N)
// S: O(N) due to hash set
class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        
        unordered_set<ListNode*> hashSet;
        ListNode* cur = head;

        while (cur->next != nullptr) {
            if (hashSet.find(cur->next) != hashSet.end())   // cycle is present if already present
                return true;
            hashSet.insert(cur->next);                      // add into hash set
            cur = cur->next;                                // go to next node
        }
        return false;
    }
};