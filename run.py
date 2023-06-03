#!/usr/bin/env python3

import subprocess
import sys
import os
import itertools

if len(sys.argv) < 3 or len(sys.argv) > 4:
    sys.stderr.write("Usage: ./run.py [hw1] [path_to_scanner]\n")
    sys.stderr.write("Usage: ./run.py [hw1] [path_to_scanner] [name_of_specific_testcase]\n")
    sys.stderr.write("Usage: ./run.py [hw2] [path_to_parser]\n")
    sys.stderr.write("Usage: ./run.py [hw2] [path_to_parser] [name_of_specific_testcase]\n")
    sys.exit(1)

hw = sys.argv[1]
path = sys.argv[2]

if len(sys.argv) == 3:
    os.system(f"python3 {hw}/run.py {path}")

if len(sys.argv) == 4:
    filename = sys.argv[3]
    os.system(f"python3 {hw}/run.py {path} {filename}")