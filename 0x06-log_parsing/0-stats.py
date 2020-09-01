#!/usr/bin/python3
"""stats module
"""
from sys import stdin


if __name__ == '__main__':
    codes = {'200': 0, '301': 0, '400': 0, '401': 0,
             '403': 0, '404': 0, '405': 0, '500': 0}
    size = 0

    def print_info(codes, size):
        """print_info method print needed info

        Args:
            codes (dict): code status
            size (int): size of files
        """
        print("File size: {}".format(size))
        for key, val in sorted(codes.items()):
            if val > 0:
                print("{}: {}".format(key, val))

    try:
        for i, line in enumerate(stdin, 1):
            info = line.split()
            size += int(info[-1])
            if info[-2] in codes.keys():
                codes[info[-2]] += 1
            if not i % 10:
                print_info(codes, size)
    except KeyboardInterrupt:
        print_info(codes, size)
        raise
    print_info(codes, size)
