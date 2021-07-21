import subprocess
import os
import colorama
import multiprocessing
import time
import heapq
import sys

path = os.path.abspath(sys.argv[0])
base_dir = sys.argv[1]
main_file = sys.argv[2]
cmp = bool(int(sys.argv[3]))
gen_file = "gen.cpp"
good_file = "good.cpp"
command_execute = []
max_tries = int(input("Tries: "))
threads = []

with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "execute_command3.txt"), "r") as f:
    command_execute = f.readlines()
    f.close()


def compile(s, f):
    print(f"Compiling {s} ... ", end="")
    try:
        p = subprocess.Popen(command_execute[0].strip()
            .replace("%main-file%", os.path.join(base_dir, f))
            .replace("%execute-file%", os.path.join(base_dir, f.replace(".cpp", ".out"))).strip().split(
            " "),
        )

        p.communicate()
        if p.returncode != 0:
            sys.exit()

    except subprocess.CalledProcessError as e:
        sys.exit()

    print(colorama.Fore.GREEN + "Ok" + colorama.Fore.RESET)


def run(s, i=[]):
    try:
        p = subprocess.run(command_execute[1].strip()
                           .replace("%execute-file%", os.path.join(base_dir, s)), timeout=2,
                           universal_newlines=True, input="\n".join(i), stdout=subprocess.PIPE,
                           stderr=subprocess.PIPE, shell=True, check=True)

        output = [x.rstrip() for x in p.stdout.strip().splitlines()]

        return output
    except subprocess.TimeoutExpired as e:
        lock.acquire()

        if stop.value == 0:
            l = list()
            l.append(f"Case [{c_ran.value}/{max_tries}]")
            l.append(" " * (5 - len(str(c_ran.value))) + "| ")
            l.append(colorama.Fore.RED + "TLE" + colorama.Fore.RESET + "\n")
            l.append(colorama.Fore.YELLOW + "File: " + colorama.Fore.RESET + s)
            stop.value = 1
            ret.append([1000000, l])

        lock.release()
        return None
    except Exception as e:
        lock.acquire()

        if stop.value == 0:
            l = list()
            l.append(f"Case [{c_ran.value}/{max_tries}]")
            l.append(" " * (5 - len(str(c_ran.value))) + "| ")
            l.append(colorama.Fore.RED + "RE" + colorama.Fore.RESET)
            l.append(str(e))
            stop.value = 1
            ret.append([1000000, l])

        lock.release()
        return None


def my_thread():
    while True:
        lock.acquire()
        l_id = id_run.value
        id_run.value += 1
        lock.release()

        if l_id > max_tries:
            return

        input_gen = run(gen_file.replace(".cpp", ".out"))
        if cmp:
            output_good = run(good_file.replace(".cpp", ".out"), input_gen)
        else:
            output_good = []
        output_bad = run(main_file.replace(".cpp", ".out"), input_gen)

        lock.acquire()

        c_ran.value += 1
        if stop.value == 0 and c_ran.value <= max_tries:
            l = list()

            l.append(f"Case [{c_ran.value}/{max_tries}]")
            l.append(" " * (5 - len(str(c_ran.value))) + "| ")

            if output_good == output_bad or not cmp:
                l.append(colorama.Fore.GREEN + "Ok" + colorama.Fore.RESET)
            else:
                l.append(colorama.Fore.RED + "Wrong" + colorama.Fore.RESET + "\n")
                l.append(colorama.Fore.YELLOW + "INPUT: " + colorama.Fore.RESET + "\n")
                l.append("\n".join(input_gen) + "\n")
                l.append(colorama.Fore.YELLOW + "EXPECT OUTPUT: " + colorama.Fore.RESET + "\n")
                l.append("\n".join(output_good) + "\n")
                l.append(colorama.Fore.YELLOW + "YOUR OUTPUT: " + colorama.Fore.RESET + "\n")
                l.append("\n".join(output_bad) + "\n")

                stop.value = 1

            ret.append([c_ran.value, l])

        lock.release()


def main_thread():
    while c_ran.value <= max_tries and not stop.value:
        lock.acquire()

        p = len(ret) > 0
        heapq.heapify(ret[:])

        if p:
            t = heapq.nlargest(1, ret[:])[0]
            print("".join(t[1]))

        lock.release()
        time.sleep(0.1)

        if p:
            print(f"\033[A                      \033[A")

        if c_ran.value >= max_tries or stop.value != 0:
            if stop.value == 0:
                print(f"Case [{max_tries}/{max_tries}]", end="")
                print(" " * (5 - len(str(c_ran.value))) + "| ", end="")
                print(colorama.Fore.GREEN + "Ok" + colorama.Fore.RESET)
                return

            if len(ret) > 0:
                heapq.heapify(ret[:])
                print("".join(heapq.nlargest(1, ret[:])[0][1]))

            return


if __name__ == '__main__':
    print("---------------------------")
    compile("Bad", main_file)
    if cmp:
        compile("Good", good_file)
    compile("Gen", gen_file)
    print("---------------------------")

    manager = multiprocessing.Manager()

    lock = multiprocessing.Lock()
    id_run = manager.Value('i', 1)
    c_ran = manager.Value('i', 0)
    stop = manager.Value('i', 0)
    queue = manager.list()
    ret = manager.list()

    main = multiprocessing.Process(target=main_thread)
    main.start()

    for _ in range(3):
        x = multiprocessing.Process(target=my_thread)
        threads.append(x)

    for x in threads:
        x.start()

    main.join()

    for x in threads:
        x.terminate()
