import sys


URL = ""


def read_URL_from_input():
    return input("Link: ")


if len(sys.argv) > 1:
    URL = str(sys.argv[1])
else:
    URL = read_URL_from_input()


import requests
import os
from shutil import copyfile
import re
from bs4 import BeautifulSoup
import string
import pickle


INVALID_LINK = "Your link is invalid"


def throw_error(msg):
    print("------------------------")
    print(msg)
    print("------------------------")
    sys.exit(0)


def generate_data_dir(root_path, name_dir):
    """
    Generate data dir that contains testcases dir, and file code

    :param root_path:
    :return:
    """

    path_dir = os.path.join(root_path, name_dir)

    if not os.path.exists(path_dir):
        os.mkdir(path_dir)

    path_testcases = os.path.join(path_dir, "testcases")

    # create testcases folder if not exists
    if not os.path.exists(path_testcases):
        os.mkdir(path_testcases)

    return path_dir, path_testcases


def write_to_file(file, value):
    with open(file, "w+") as f:
        f.write(value)
        f.close()


def process():
    global URL

    # URL = "https://codeforces.com/problemset/problem/996/A"
    # URL = "https://atcoder.jp/contests/abc191/tasks/abc191_b"

    # if "codeforces.com" in URL:
        # import submit

        # session = requests.Session()
        # if not os.path.exists(os.path.join(os.path.dirname(__file__), "session")):
            # submit.login()

        # with open(os.path.join(os.path.dirname(__file__), "session"), 'rb') as f:
            # session.cookies.update(pickle.load(f))

        # response = session.get(URL)
    # else:
    response = requests.get(URL)

    if response.status_code != 200:
        throw_error(INVALID_LINK)

    # Base Setup
    text = response.text

    soup = BeautifulSoup(text, features="lxml")
    name_dir = ""
    root_dir = os.getcwd()
    data_input_output = []
    good_link = False

    if "spoj.com/problems"in URL:
        root_dir = os.getcwd()

        sp = URL.split("/")
        if sp[-1] == '':
            name_dir = sp[-2]
        else:
            name_dir = sp[-1]

        elem = soup.select('div[id="problem-body"] > pre')
        i = 0

        for e in list(elem):
            s = str(e)
            ok = -1

            if "input:" in s.lower() and "output:" in s.lower():
                for v in s.split("\n"):
                    if ok == -1 and "input:" in v.lower():
                        ok = 0
                    elif ok == 0 and "output:" in v.lower():
                        ok = 1
                    elif ok == 0:
                        if len(data_input_output) <= i:
                            data_input_output.append([])
                            data_input_output[i].append("")
                            data_input_output[i].append("")

                        data_input_output[i][0] = data_input_output[i][0] + v.strip() + "\n"
                    elif ok == 1:
                        if len(data_input_output) <= i:
                            continue

                        if "</pre>" in v:
                            continue

                        data_input_output[i][1] = data_input_output[i][1] + v.strip() + "\n"

                i = i + 1

        for i in range(len(data_input_output)):
            data_input_output[i][0] = data_input_output[i][0].strip()
            data_input_output[i][1] = data_input_output[i][1].strip()

        good_link = len(data_input_output) > 0

    elif "codeforces.com/contest" in URL:
        if "problem" in URL:
            try:
                sp = URL.split("/")

                contest_name = sp[-3]
                name_dir = sp[-1].lower()

                root_dir = os.path.join(os.getcwd(), contest_name)

                if not os.path.exists(root_dir):
                    os.mkdir(root_dir)

                # find elements
                sample_text_element = soup.find("div", {"class": "sample-test"})

                regex = re.compile(r"<br/?>", re.IGNORECASE)

                for index, input_element in enumerate(sample_text_element.find_all("div", {"class": "input"})):
                    input_value = str(input_element.find("pre"))[5:-6]
                    input_value = re.sub(regex, '\n', input_value).strip()
                    data_input_output.append([input_value])

                for index, output_element in enumerate(sample_text_element.find_all("div", {"class": "output"})):
                    output_value = str(output_element.find("pre"))[5:-6]
                    output_value = re.sub(regex, '\n', output_value).strip()
                    data_input_output[index].append(output_value)

                good_link = True

            except Exception as e:
                print(e)
                # print("Fail... Re Login")
                # submit.login()
                # process(URL)

                return
        else:
            count_problems = len(soup.select("table.problems > tr")) - 1
            tag_problems = string.ascii_uppercase

            if count_problems:
                for i in range(count_problems):
                    process(URL + f"/problem/{tag_problems[i]}")

    elif "codeforces.com/problemset/problem" in URL:
        try:
            contest_name = URL.split("/")[-2]
            name_dir = URL.split("/")[-1].lower()

            root_dir = os.path.join(os.getcwd(), contest_name)

            if not os.path.exists(root_dir):
                os.mkdir(root_dir)

            # find elements
            sample_text_element = soup.find("div", {"class": "sample-test"})

            regex = re.compile(r"<br/?>", re.IGNORECASE)

            for index, input_element in enumerate(sample_text_element.find_all("div", {"class": "input"})):
                input_value = str(input_element.find("pre"))[5:-6]
                input_value = re.sub(regex, '\n', input_value).strip()
                data_input_output.append([input_value])

            for index, output_element in enumerate(sample_text_element.find_all("div", {"class": "output"})):
                output_value = str(output_element.find("pre"))[5:-6]
                output_value = re.sub(regex, '\n', output_value).strip()
                data_input_output[index].append(output_value)

            good_link = True


        except Exception as e:
            print(e)
            # print("Fail... Re Login")
            # submit.login()
            # process(URL)

            return

    # AtCoder
    elif "atcoder.jp/contests/" in URL:
        try:
            contest_name = URL.split("/")[-3]
            name_dir = URL.split("/")[-1].replace(contest_name + "_", "")

            root_dir = os.path.join(os.getcwd(), contest_name)

            if not os.path.exists(root_dir):
                os.mkdir(root_dir)

            for idx, part in enumerate(soup.select('span[class="lang-en"] > div[class="part"] > section > pre')):
                value = part.get_text().strip()

                if idx % 2 == 0:
                    data_input_output.append([value])
                else:
                    data_input_output[idx // 2].append(value)

            good_link = True
        except:
            throw_error(INVALID_LINK)

    if good_link:
        data_dir, testcases_dir = generate_data_dir(root_dir, name_dir)

        for idx, x in enumerate(data_input_output, start=1):
            input_value, output_value = x[0], x[1]

            write_to_file(os.path.join(testcases_dir, f"sample-input-{idx}"), input_value)
            write_to_file(os.path.join(testcases_dir, f"sample-output-{idx}"), output_value)

        # create file from templates
        path_file_parser = os.path.dirname(os.path.abspath(__file__))
        copyfile(os.path.join(path_file_parser, "template.cpp"), os.path.join(data_dir, "main.cpp"))

        os.system(r'dat=`date "+%D %T"` && sed -i "s|\$DATE|${dat}|g" ' + os.path.abspath(os.path.join(data_dir, "main.cpp")))
        os.system(r'sed -i "s|\$LINK|' + URL  + r'|g" ' + os.path.abspath(os.path.join(data_dir, "main.cpp")))

        print("Created folder: " + os.path.abspath(data_dir))

        if len(sys.argv) > 2:
            if sys.argv[2] == "-o":
                os.system("vi " + os.path.abspath(os.path.join(data_dir, "main.cpp")))

process()

