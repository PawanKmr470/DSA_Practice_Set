import threading
import time
from threading import Semaphore

sem = Semaphore(5)
op_counter = 0

def compute():
    global op_counter

    sem.acquire()
    print("processing data...")
    op_counter += 1
    print("total started computations : {}".format(op_counter))
    time.sleep(1)
    print("processing done")
    sem.release()
    op_counter -= 1
    print("total completed computations : {}".format(op_counter))


while True:
    time.sleep(0.1)
    t = threading.Thread(target=compute)
    t.start()