# REF : https://leetcode.com/problems/merge-k-sorted-lists/
# NOTES :
#       Sorting / minHeap + merge
#       range loop with 2 step iteration, dummy node
#       1-way : Brute force
#               add all lists and sort them (Tim sort - python way)
#               T: O(n*logn)
#               S: O(n)         for creating new LL and O(k) for in-place
#               compare (one by one) each node of list with each node of new LL
#               T: O(k*n)       merge 2 list method by k times
#               S: O(n)         for creating new LL and O(k) for in-place
#       2-way : using Merge technique (divide & conquer)
#               T: O(n*logk)    beacuse everytime k comparision getting half
#               S: O(n)         for creating new LL and O(k) for in-place
#       3-way : using minHeap
#               T: O(n*logk)    popping min (logn) for every node of lists
#               S: O(n+k) ~O(n) if new LL is created. OR O(k) is in-place LL creation

import heapq

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# using Merge logic
# working logic
class Solution:
    def mergeKLists(self, lists):
        if not lists:
            return None

        while len(lists) > 1:
            new_list = []
            for i in range(0, len(lists), 2):
                l1 = lists[i]
                l2 = lists[i + 1] if (i+1) < len(lists) else None
                new_list.append(self.mergeTwoLists(l1, l2))

            lists = new_list

        return lists[0]


    def mergeTwoLists(self, list1, list2):
        dummy = ListNode()
        tail = dummy

        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next

        if list1:
            tail.next = list1
        if list2:
            tail.next = list2

        return dummy.next


# using minHeap
# comparision operator not working.. need to fix it
class Solution2:
    def mergeKLists(self, lists):
        if not lists:
            return None

        dummy = ListNode()
        tail = dummy

        minHeap = []
        for l in lists:
            heapq.heappush(minHeap, (l.val, l))

        while len(minHeap):
            val, node = heapq.heappop(minHeap)
            tail.next = ListNode(val)
            tail = tail.next
            node = node.next
            if node:
                heapq.heappush(minHeap, (node.val, node))

        return dummy.next


# make list of all nodes of lists and sort it and create LL
# need to fix it
class Solution3:
    def mergeKLists(self, lists):
        nodes = []
        head = point = ListNode(0)
        for l in lists:
            while l:
                nodes.append(l.val)
                l = l.next
        for x in sorted(nodes):
            point.next = ListNode(x)
            point = point.next
        return head.next


def main():
    pass

if __name__ == "__main__":
    main()