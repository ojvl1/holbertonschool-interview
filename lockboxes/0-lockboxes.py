#!/usr/bin/python3
"""Lockboxes Algorithm"""

def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""
    unlocked = [False] * len(boxes)
    unlocked[0] = True
    
    keys = [0]
    
    while keys:
        current_key = keys.pop(0)
        
        for key in boxes[current_key]:
            if key < len(boxes) and not unlocked[key]:
                unlocked[key] = True
                keys.append(key)
    
    return all(unlocked)