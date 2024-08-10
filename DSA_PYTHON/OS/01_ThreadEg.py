import time
import threading

def square(num):
    result = num * num
    print("Thread 1 : square of {} : {}".format(num, result), end='\n')
    time.sleep(1)


def cube(num):
    result = num * num * num
    print("Thread 2 : cube of {} : {}".format(num, result), end='\n')
    time.sleep(1)


def test1():
    t1 = threading.Thread(target=square, args=(3,))
    t2 = threading.Thread(target=cube, args=(3,))

    t1.start()
    t2.start()

    t1.join()
    t2.join()

    print("{} done.".format(threading.currentThread().getName()))

    # create 10 threads with for loop
    # threads = []
    # for _ in range(10):
    #     t = threading.Thread(target=square, args=[3])
    #     t.start()
    #     threads.append(t)
    # similarly for joining

if __name__ == "__main__":
    test1()
