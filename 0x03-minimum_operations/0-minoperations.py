#!/usr/bin/python3
"""minoperations module
"""


def minOperations(n):
    """minOperations is a method that calculates
    the fewest number of operations needed to result
    in exactly n H characters 

    Args:
        n (int): amount of H

    Return:
        minimum number of operations (an integer)
    """
    minOp = 0
    while isinstance(n, int) and n > 1:
        for div in range(2, n + 1):
            if not n % div:
                break
        minOp += div
        n = int(n / div)
    return minOp
