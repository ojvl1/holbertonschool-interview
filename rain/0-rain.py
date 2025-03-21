#!/usr/bin/python3

"""
  This function calculate how many
  square units of water will be retained after it rains
"""


def rain(walls):
    if not walls:
        return 0
    n = len(walls)
    left_max = [0] * n
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i-1], walls[i])

    right_max = [0] * n
    right_max[-1] = walls[-1]
    for i in range(n-2, -1, -1):
        right_max[i] = max(walls[i], right_max[i+1])

    total = 0
    for i in range(n):
        total += max(0, min(left_max[i], right_max[i]) - walls[i])
    return total
