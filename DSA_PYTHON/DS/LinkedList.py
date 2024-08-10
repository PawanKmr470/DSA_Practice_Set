class Node:
    def __init__(self, data, pnext=None):
        self.data = data
        self.pnext = pnext

    def __repr__(self):
        return "Node(data, pnext)"

    def __str__(self):
        return f"{self.data} {self.pnext}"


class LinkedList:
    """Singly Linked List"""
    def __init__(self):
        self.head = None
        # Take self.size = 0 variable to maintain size

    def create_list(self, nums):
        for num in nums:
            self.insert_end(num)

    def insert_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            cur_node = self.head
            while cur_node.pnext:
                cur_node = cur_node.pnext
            cur_node.pnext = new_node
        return None

    def insert_begin(self, data):
        new_node = Node(data)
        tmp_head = self.head
        self.head = new_node
        new_node.pnext = tmp_head

    def print_list(self):
        data_list = []
        cur_node = self.head
        while cur_node:
            data_list.append(cur_node.data)
            cur_node = cur_node.pnext
        return data_list

    def len_list(self):
        count = 0
        cur_node = self.head
        while cur_node:
            count += 1
            cur_node = cur_node.pnext
        return count

    def remove_end(self):
        cur_node = self.head
        if cur_node is None:
            print("No element in the list")
            return None

        tmp_node = None
        while cur_node.pnext:
            tmp_node = cur_node
            cur_node = cur_node.pnext

        tmp_node.pnext = None
        return cur_node.data

    # Reverse linked list recursive & non-recursive
    # Doubly linked list

def main():

    # n1 = Node(10)
    # print(n1)
    # t1 = BSTNode(20)
    # print(t1)

    l1 = LinkedList()
    l1.create_list([10, 20, 30, 40])
    print(l1.print_list())
    l1.insert_begin(5)
    print(l1.print_list())
    l1.insert_end(100)
    print(l1.print_list())
    print("remove from end")
    print(l1.print_list())
    print(l1.remove_end())
    print(l1.print_list())
    print(l1.remove_end())
    print(l1.print_list())

if __name__ == "__main__":
    main()