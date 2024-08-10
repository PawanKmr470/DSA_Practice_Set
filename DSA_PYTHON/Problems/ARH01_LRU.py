# REF : https://leetcode.com/problems/lru-cache/description/
# NOTES :
#       In python 2 ways -
#       Using OrderedDict from collections module
#           OrderedDict is internally implemented as Hashmap + Doubly Linked List
#       Using dict + doubly linked list directly
#       Why Hashmap + DLL
#           Hashmap can easily implement get & set methods for key value
#           but how do we know what is the least recently used element. Hashmap doesn't have order.
#           we need some data structure which can hold data in LRU fashion.
#           so DLL is good choice. In short -
#           DLL -> A DS for LRU logic
#           Hashmap -> To achieve get() & set() in O(1) as it will maintain addr of nodes with keys
#           In C++, only key was used in DLL. check it out.

# >>> cache = OrderedDict()
# >>> cache[1] = 1
# >>> cache[2] = 2
# >>> cache[3] = 3
# >>> cache[4] = 4
# >>> cache
# OrderedDict([(1, 1), (2, 2), (3, 3), (4, 4)])
# >>>
# >>> cache.move_to_end(1)
# >>> cache
# OrderedDict([(2, 2), (3, 3), (4, 4), (1, 1)])
# >>>
# >>> cache.popitem(last=False)
# (2, 2)
# >>> cache
# OrderedDict([(3, 3), (4, 4), (1, 1)])
# >>>

# T: O(1)
# S: O(n)
from collections import OrderedDict
class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        else:
            # self.cache[key] = self.cache.pop(key)     # manual way
            self.cache.move_to_end(key)             # Move it to end which makes if recently used.
            return self.cache[key]                  # and return it

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.move_to_end(key)             # If key is present then make it recently used
            self.cache[key] = value                 # and update the new value
        else:                                       # If key is not present
            if len(self.cache) == self.capacity:    # If capacity is full then pop the very first
                self.cache.popitem(last=False)      # item which was added.
            self.cache[key] = value                 # update the new value. This line can be optimized.


# T: O(1)
# S: O(n)
# Same logic but using dict & doubly linked list
class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None

class LRUCache2:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}

        self.head = Node(0,0)
        self.tail = Node(0,0)
        self.head.next = self.tail
        self.tail.prev = self.head

    # Remove the given node
    def remove(self, node):
        # node.prev.next = node.next
        # node.next.prev = node.prev
        p = node.prev
        n = node.next
        p.next = n
        n.prev = p

    # Insert at the end
    def insert(self, node):
        # self.tail.prev.next = node
        # p_backup = self.tail.prev  # Need to take backup before overriding it
        # self.tail.prev = node
        # node.next = self.tail
        # node.prev = p_backup

        p = self.tail.prev
        n = self.tail
        p.next = node
        n.prev = node
        node.prev = p
        node.next = n

    def get(self, key: int) -> int:
        if key in self.cache:
            self.remove(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].value
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.remove(self.cache[key])

        self.cache[key] = Node(key, value)
        self.insert(self.cache[key])

        if len(self.cache) > self.capacity:
            lru_node = self.head.next
            self.remove(lru_node)
            del self.cache[lru_node.key]


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

def main():
    return

if __name__ == "__main__":
    main()