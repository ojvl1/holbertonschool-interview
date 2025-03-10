#!/usr/bin/python3

"""
Island Perimeter
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of the island in grid.

    Args:
        grid (List[List[int]]): A 2D grid where:
            - 0 represents water
            - 1 represents land

    Returns:
        int: The perimeter of the island
    """
    if not grid:
        return 0

    rows, cols = len(grid), len(grid[0])
    perimeter = 0

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                perimeter += 4

                if row > 0 and grid[row-1][col] == 1:
                    perimeter -= 1

                if row < rows-1 and grid[row+1][col] == 1:
                    perimeter -= 1

                if col > 0 and grid[row][col-1] == 1:
                    perimeter -= 1

                if col < cols-1 and grid[row][col+1] == 1:
                    perimeter -= 1

    return perimeter
