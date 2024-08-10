class Node:
    def __init__(self, data, pnext=None):
        self.data = data
        self.pnext = pnext

    def __repr__(self):
        return "Node(data, pnext)"

    def __str__(self):
        return f"{self.data} {self.pnext}"


class Queue:
    """Queue using Linked List"""
    def __init__(self):
        self.front = self.rear = None
        # Take self.size = 0 variable to maintain size

    def enqueue(self, data):
        print(f"Enqueing element : {data}")
        new_node = Node(data)
        if self.is_empty():
            self.front = self.rear = new_node
            new_node.pnext = None
        else:
            # insert at the end of queue
            cur_node = self.front
            while cur_node.pnext:
                cur_node = cur_node.pnext
            cur_node.pnext = new_node
            self.rear = new_node
        return

    def dequeue(self):
        if self.is_empty():
            print("Queue is empty, Nothing to pop.")
        else:
            # remove from the start of queue
            tmp_node = self.front
            self.front = self.front.pnext
            if self.front is None:
                self.rear = None
            print(f"Deueuing element : {tmp_node.data}")

    def is_empty(self):
        if self.front is None and self.rear is None:
            return True
        else:
            return False

    def print_queue(self):
        print("Printing Queue : ")
        if self.is_empty():
            print("Queue is empty, Nothing to print.")
        else:
            cur_node = self.front
            while cur_node:
                print(cur_node.data)
                cur_node = cur_node.pnext
        return


def main():
    q = Queue()
    q.enqueue(5)
    q.enqueue(10)
    q.enqueue(15)
    q.enqueue(20)
    q.print_queue()
    q.dequeue()
    q.print_queue()
    q.enqueue(30)
    q.dequeue()
    q.dequeue()
    q.dequeue()
    q.dequeue()
    q.print_queue()

if __name__ == "__main__":
    main()