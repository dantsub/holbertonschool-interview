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
    # check if boxes and sub boxes are a list
    if type(boxes) is not list or not all(type(box) is list for box in boxes):
        return False
    # check if first box is empty
    if not boxes[0] and len(boxes) > 1:
        return False
    # dictionary of all boxes, all boxes are lock here
    unlock = {k: False for k in range(len(boxes))}
    # unlock first box
    unlock[0] = True
    # List of all key's first box
    keys = [key for key in boxes[0]]
    # Process of unlock boxes
    while keys:
        new_k = []
        for key in keys:
            if unlock[key] is False:
                new_k += boxes[key]
            unlock[key] = True
        # If all boxes unlock return True
        if all(unlock.values()) and len(unlock) == len(boxes):
            return True
        # Change keys for the new keys to check
        keys = new_k
    return False
