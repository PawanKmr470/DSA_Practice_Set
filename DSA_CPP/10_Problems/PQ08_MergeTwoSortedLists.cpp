#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// REF : https://leetcode.com/problems/merge-two-sorted-lists/description/
// NOTES :
//      Compare node value and pick minimum
//      Modify lists' next addresses to point to new list.
//      Note : This is INPLACE merge

// Recursive
// T: O(n + m)
// S: O(n + m) from stack
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

// Iterative
// T: O(n + m)
// S: O(1)
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode *prehead = new ListNode(-1);
        ListNode *prev = prehead;               // To avoid edge cases. Dummy node.

        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                prev->next = list1;
                list1 = list1->next;
            }
            else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }

        // Here need to cover case -
        //  1. Either one of the two will be at null then append remaining one
        //  2. Both will be at null, then put null at prev->next
        if (list1)
            prev->next = list1;
        else
            // This else will append list + put null if both lists are at null
            prev->next = list2;

        return prehead->next;
    }
};