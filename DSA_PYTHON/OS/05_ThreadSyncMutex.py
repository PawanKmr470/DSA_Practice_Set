import threading
from threading import Lock

mutex = Lock()
x = 0

def increment():
    global x
    mutex.acquire()
    x = x + 1   # critical section
    mutex.release()

def operation():
    for _ in range(1000000):
        increment()


t1 = threading.Thread(target=operation, name="Thread #1")
t2 = threading.Thread(target=operation, name="Thread #2")

t1.start()
t2.start()

t1.join()
t2.join()

print("Value of x : {}".format(x))

# expected result is 2000000 but without lock
# while thread 1 is incrementing value of x another thread may read value of x
# which is not incremented yet by the thread 1, and it increments it. so both
# threads incremented same value and happened multiple times hence the result : 1583383


# Re-entrant Lock

from threading import RLock

class Test:

    def __init__(self):
        self.num1 = 1
        self.num2 = 2
        self.mutex = RLock()

    def inc_first(self):
        with self.mutex:        # try + mutex.acquire() and finally + mutex.release()
            self.num1 += 1

    def inc_second(self):
        with self.mutex:
            self.num2 += 1

    def inc_both(self):
        with self.mutex:
            self.inc_first()
            self.inc_second()


