# REF : https://leetcode.com/problems/merge-two-sorted-lists/
# NOTES :
#       Application of dummy node

# T: O(n + m)
# S: O(n + m)

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Iterative solution
class Solution:
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


# Recursive solution
class Solution2:
    def mergeTwoLists(self, list1, list2):
        if list1 is None:
            return list2
        if list2 is None:
            return list1

        if list1.val < list2.val:
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoLists(list1, list2.next)
            return list2


def main():
    pass

if __name__ == "__main__":
    main()