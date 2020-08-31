#!/usr/bin/python3
from sys import stdin


codes = {'200': 0, '301': 0, '400': 0, '401': 0,
         '403': 0, '404': 0, '405': 0, '500': 0}
size = 0

def print_info(codes, size):
    print("File size: {}".format(size))
    for key, val in codes.items():
        if val > 0:
            print("{}: {}".format(key, val))

try:
    for i, line in enumerate(stdin, 1):
        line = line[-9:]
        info = line.split()
        if len(info) > 2 and info[1] in codes.keys():
            codes[info[1]] += 1
            size += int(info[2])
        if len(info) == 2 and info[0] in codes.keys():
            codes[info[0]] += 1
            size += int(info[1])
        if not i % 10:
            print_info(codes, size)
    print_info(codes, size)
except KeyboardInterrupt:
    print_info(codes, size)
    raise
