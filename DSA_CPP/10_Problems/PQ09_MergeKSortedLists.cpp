#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// REF : https://leetcode.com/problems/merge-k-sorted-lists/description/
// NOTES :
//      1. Brute force
//          Take an array and fill it with all LinkedLists' elements.
//          Sort the array.
//          Create new LinkedList from the array
//          T: O(m) + O(mlogm) + O(m)         m = n*k
//          S: O(m) array                     Note : Ignore new list space bcz it's the answer
//      2. Generalization of merge 2 lists
//          Ref : https://leetcode.com/problems/merge-two-sorted-lists/description/
//          Pick 2 lists, compare min and add it to new list and keep merging next list.
//          T: O(kn)
//          S: O(1)
//      3. Comparing heads of all LinkedLists, pick smallest one and add it to new LinkedList
//          and make sure to proceed in LinkedList from where the element has been picked up.
//          T: O(kn) becuase k times comparision
//          S: O(1)
//      4. Priority Queue
//          Same as 3rd approach but comparision will be done through Min Heap.
//          T: O(nlogk)
//          S: O(k) Min Heap
//      5. By Devide & Conquer (Merge sort)
//          Merge in pair of 2 using the merge 2 lists logic.
//          After the first pairing, k lists are merged into k/2 lists with average 2N/k length, 
//          then k/4, k/8 and so on.
//          T: O(nlogk) merge 2 lists take O(n)
//          S: O(1)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute force
// T: O(2n + nlogn) ~ O(nlogn)
// S: O(n)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nodes;

        for (ListNode* l : lists) {
            while (l) {
                nodes.push_back(l->val);
                l = l->next;
            }
        }

        sort(nodes.begin(), nodes.end());

        ListNode *head = new ListNode(0);       // Dummy node to avoid edge case of first node
        ListNode *cur = head;
        for (int &i : nodes) {
            cur->next = new ListNode(i);
            cur = cur->next;
        }

        return head->next;
    }
};


// Priority Queue
// T: O(nlogk)
// S: O(k) Min Heap
class cmp {
public:
    bool operator()(ListNode *l, ListNode *r) {
        return l->val > r->val;
    }
};
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (auto l : lists) {
            if (l)
                pq.push(l);
        }

        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        
        while (!pq.empty()) {
            cur->next = pq.top(); pq.pop();
            cur = cur->next;
            if (cur->next)
                pq.push(cur->next);
        }

        return head->next;
    }
};