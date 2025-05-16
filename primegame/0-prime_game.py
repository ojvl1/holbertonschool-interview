#!/usr/bin/python3

def is_prime_sieve(n):
    """
    Generates a list of the number of prime numbers up to each number from 0 to n.

    Uses the Sieve of Eratosthenes algorithm to identify prime numbers and counts
    how many primes exist up to each index.

    Args:
        n (int): The maximum number up to which to generate prime counts.

    Returns:
        List[int]: A list where the value at each index i is the count of prime
                  numbers less than or equal to i.
    """
    sieve = [True] * (n + 1)
    sieve[0:2] = [False, False]
    count = 0
    prime_counts = [0] * (n + 1)

    for i in range(2, n + 1):
        if sieve[i]:
            count += 1
            for j in range(i * 2, n + 1, i):
                sieve[j] = False
        prime_counts[i] = count

    return prime_counts


def isWinner(x, nums):
    """
    Determines the winner of a series of prime number games.

    In each round, a set of consecutive integers from 1 to n is used. Players take
    turns choosing a prime number and removing it and its multiples from the set.
    The player who cannot make a move loses the round. Maria always goes first.

    Both players play optimally.

    Args:
        x (int): The number of rounds.
        nums (List[int]): An array of integers where each value represents n for a round.

    Returns:
        str or None: The name of the player who won the most rounds ("Maria" or "Ben").
                    If the number of wins is the same, returns None.
    """
    if x < 1 or not nums:
        return None

    max_n = max(nums)
    prime_counts = is_prime_sieve(max_n)

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if prime_counts[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None
