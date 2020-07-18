#!/usr/bin/python3
"""canUnlockAll module
"""


def canUnlockAll(boxes):
    """canUnlockAll function to check if
    boxes unlock or not

    Args:
        boxes (list): list of boxes (list)
    Return: False if all boxes cannot unlock and True otherwise
    """
    keys = [0]
    for i in keys:
        for j in boxes[i]:
            if j not in keys:
                keys.append(j)
    if len(keys) == len(boxes):
        return True
    return False
