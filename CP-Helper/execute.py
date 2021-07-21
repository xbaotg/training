import sys
import os
import subprocess
import colorama
import time

args = sys.argv[1:]

if len(args):
    path = os.path.abspath(args[0])
    name_file_main = args[1]
    custom_input = args[2]
    testcases_dir = os.path.join(path, "testcases")

    if (custom_input == "true") or (
            os.path.exists(testcases_dir) and os.path.exists(os.path.join(path, name_file_main))):
        command_execute = []
        path_file_execute = os.path.dirname(os.path.abspath(__file__))

        if custom_input == "false":
            with open(os.path.join(path_file_execute, "execute_command.txt"), "r") as f:
                command_execute = f.readlines()
                f.close()
        else:
            with open(os.path.join(path_file_execute, "execute_command2.txt"), "r") as f:
                command_execute = f.readlines()
                f.close()

        print("Compiling ... ", end="")

        main_file = os.path.join(path, name_file_main)
        modifiled = os.stat(main_file)[-2]
        ok = True

        with open("/home/tgbao2703/cphelper/modifiled", "r+") as f:
            old = f.readline()

            if str(modifiled).strip() == str(old).strip():
                ok = False

        # compile
        if ok:
            try:
                subprocess.check_call(command_execute[0].strip()
                                      .replace("%main-file%", os.path.join(path, name_file_main))
                                      .replace("%execute-file%", os.path.join(path, "main.out")).strip().split(" "))
            except subprocess.CalledProcessError as e:
                sys.exit()

        if ok:
            with open("/home/tgbao2703/cphelper/modifiled", "w+") as f:
                f.write(str(modifiled))

        print(colorama.Fore.GREEN + "Ok" + colorama.Fore.RESET)
        print("---------------------------")

        if custom_input == "true":
            path_execute_file = os.path.join(path, "main.out")

            try:
                p = subprocess.run(command_execute[1].strip()
                                   .replace("%execute-file%", path_execute_file), universal_newlines=True,
                                   stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True, check=True)
            except Exception as e:
                print(colorama.Fore.RED + "RE" + colorama.Fore.RESET)
                print(">> " + e.stderr)
                sys.exit(0)

            output = [x.rstrip() for x in p.stdout.strip().splitlines()]
            err = p.stderr.strip().splitlines()

            print(colorama.Fore.RESET)
            print(colorama.Fore.YELLOW + "OUTPUT: " + colorama.Fore.RESET)
            print("\n".join(output))

            if len(err):
                print(colorama.Fore.YELLOW + "MESSAGE: " + colorama.Fore.RESET)
                print("\n".join(err))

        else:
            for i in range(1, 100):
                if os.path.exists(os.path.join(testcases_dir, f"sample-input-{i}")):
                    print(f"Running TestCase #{i} ...", end=" ")

                    # running
                    path_execute_file = os.path.join(path, "main.out")
                    inputs = []
                    expect_output = []

                    with open(os.path.join(testcases_dir, f'sample-input-{i}')) as f:
                        inputs = [x.strip() for x in f.readlines()]

                    with open(os.path.join(testcases_dir, f'sample-output-{i}')) as f:
                        expect_output = [x.strip() for x in f.readlines()]

                    # try:
                    start_time = time.time()
                    try:
                        p = subprocess.run(command_execute[1].strip()
                                           .replace("%execute-file%", path_execute_file), timeout=2,
                                           universal_newlines=True, input="\n".join(inputs), stdout=subprocess.PIPE,
                                           stderr=subprocess.PIPE, shell=True, check=True)

                    except subprocess.TimeoutExpired as e:
                        print(colorama.Fore.RED + "TLE" + colorama.Fore.RESET)
                        break
                    except Exception as e:
                        print(colorama.Fore.RED + "RE" + colorama.Fore.RESET)
                        print(">> " + e.stderr)
                        break

                    end_time = time.time()

                    output = [x.rstrip() for x in p.stdout.strip().splitlines()]
                    err = p.stderr.strip().splitlines()

                    if output == expect_output:
                        print(colorama.Fore.GREEN + "Accept" + colorama.Fore.RESET + " - " + colorama.Fore.CYAN + str(
                            round((end_time - start_time) * 1000)) + "ms" + colorama.Fore.RESET)
                    else:
                        # print input
                        print(colorama.Fore.RED + "WA" + colorama.Fore.RESET)
                        print(colorama.Fore.CYAN + "==== Detail ====" + colorama.Fore.RESET)

                        print(colorama.Fore.YELLOW + "INPUT: " + colorama.Fore.RESET)
                        print("\n".join(inputs))
                        print(colorama.Fore.YELLOW + "EXPECT OUTPUT: " + colorama.Fore.RESET)
                        print("\n".join(expect_output))
                        print(colorama.Fore.YELLOW + "YOUR OUTPUT: " + colorama.Fore.RESET)
                        print("\n".join(output))

                        if len(err):
                            print(colorama.Fore.YELLOW + "MESSAGE: " + colorama.Fore.RESET)
                            print("\n".join(err))

                        break
                else:
                    break
    else:
        print("Problem's directory is invalid")
        sys.exit(0)

else:
    print("Input problem's directory")
    sys.exit(0)
