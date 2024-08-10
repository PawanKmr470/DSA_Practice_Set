class Node:
    def __init__(self, data, pnext=None):
        self.data = data
        self.pnext = pnext

    def __repr__(self):
        return "Node(data, pnext)"

    def __str__(self):
        return f"{self.data} {self.pnext}"


class Stack:
    """Stack using list"""
    def __init__(self):
        self.head = None
        # Take self.size = 0 variable to maintain size

    def push(self, data):
        # insert at begining
        new_node = Node(data)
        if self.is_empty():
            self.head = new_node
            new_node.pnext = None
        else:
            tmp_node = self.head
            self.head = new_node
            new_node.pnext = tmp_node
        return None

    def pop(self):
        # remove from begining
        if self.is_empty():
            print("Stack is empty, Nothing to pop.")
        else:
            tmp_node = self.head
            self.head = self.head.pnext
            tmp_node.pnext = None
            return tmp_node.data

    def is_empty(self):
        return True if self.head is None else False

    def print_stack(self):
        if self.is_empty():
            print("Stack is empty, Nothing to print.")
        else:
            cur_node = self.head
            while cur_node:
                print(cur_node.data)
                cur_node = cur_node.pnext
        return None


def main():
    s1 = Stack()
    s1.push(2)
    s1.push(3)
    s1.push(4)
    print("Printing stack :")
    s1.print_stack()
    print("Poping last element")
    s1.pop()
    print("Printing stack :")
    s1.print_stack()


if __name__ == "__main__":
    main()
