import time
import threading

def odd():
    for i in range(1,11):
        if i % 2 != 0:
            print("Thread odd : {}".format(i))
    time.sleep(0.1)

def even():
    for i in range(1, 11):
        if i % 2 == 0:
            print("Thread even : {}".format(i))
    time.sleep(0.1)


def main():

    t1 = threading.Thread(target=odd)
    t2 = threading.Thread(target=even)

    t1.start()
    t2.start()

    t1.join()
    t2.join()

    print("{} done.".format(threading.currentThread().getName()))


if __name__ == "__main__":
    main()
