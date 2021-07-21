import logging
import random
import threading
import time

c_ran = 0
id_run = 1
max_run = 50


def my_thread(name):
    global id_run, c_ran

    while True:
        #
        l_id = id_run
        id_run += 1

        if l_id > max_run:
            break

        # logging.info(str(name) + " - " + str(l_id))
        time.sleep(random.uniform(0.1, 0.4))
        c_ran += 1


def main():
    format = "%(asctime)s: %(message)s"
    logging.basicConfig(format=format, level=logging.INFO, datefmt="%H:%M:%S")

    threads = []
    for i in range(3):
        x = threading.Thread(target=my_thread, args=(i,))
        threads.append(x)

    for x in threads:
        x.start()

    while c_ran <= max_run:
        logging.info(c_ran)

        if c_ran == max_run:
            break


if __name__ == '__main__':
    main()
