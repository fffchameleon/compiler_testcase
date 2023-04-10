#!/usr/bin/env python3

import subprocess
import sys
import os
import itertools

GREEN = '\033[92m'
RED = '\033[91m'
RESET = '\033[0m'


if len(sys.argv) < 2 or len(sys.argv) > 3:
    sys.stderr.write("Usage: ./run.py [path_to_scanner]\n")
    sys.stderr.write("Usage: ./run.py [path_to_scanner] [name_of_specific_testcase]\n")
    sys.exit(1)

scanner = sys.argv[1]
golden_scanner = "golden_scanner"

if len(sys.argv) == 2:
    for root, dirs, files in os.walk("testcase"):
        for filename in files:
            output1 = subprocess.check_output(f"{scanner} < testcase/{filename}", shell=True)
            output2 = subprocess.check_output(f"{golden_scanner} < testcase/{filename}", shell=True)
            if output1 == output2:
                print(f"test {filename:<35} {GREEN}{'correct':>10}{RESET}")
            else:
                print(f"test {filename:<35} {RED}{'incorrect':>10}{RESET}")

if len(sys.argv) == 3:
    filename = sys.argv[2]
    output1 = subprocess.check_output(f"{scanner} < testcase/{filename}", shell=True)
    output2 = subprocess.check_output(f"{golden_scanner} < testcase/{filename}", shell=True)

    if output1 == output2:
        print(f"test {filename} {GREEN}correct{RESET}")
    else:
        print(f"test {filename} {RED}incorrect{RESET}")

    lines1 = output1.decode().splitlines()
    lines2 = output2.decode().splitlines()

    max_length = max(len(line) for line in lines1 + lines2)
    
    print(f"{scanner:<{max_length}}\t\t{golden_scanner:<{max_length}}")
    print("-" * max_length + "\t\t" + "-" * max_length)
    for line1, line2 in itertools.zip_longest(lines1, lines2):
        if line1 != line2:
            print(f'{RED}',end='')
        if not line1:
            print(f"{' ':<{max_length}}\t\t{line2:<{max_length}}")
        elif not line2:
            print(f"{line1:<{max_length}}\t\t{' ':<{max_length}}")
        else:
            print(f"{line1:<{max_length}}\t\t{line2:<{max_length}}")
        if line1 != line2:
            print(f'{RESET}',end='')
