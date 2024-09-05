#!/usr/bin/python3

def canUnlockAll(boxes):

    open_box = 0
    keys = {}

    while boxes:
        boxes[0].append(keys)
        for i in boxes:
            for y in boxes:
                if keys == boxes[y]:
                    boxes[y] = open_box
                    open_box += 1
                    open_box.append(keys)
                    return True
                else:
                    return False
