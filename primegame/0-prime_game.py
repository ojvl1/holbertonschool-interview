def is_prime_sieve(n):
    """Returns a list of prime counts up to n using Sieve of Eratosthenes"""
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
    """Determines the winner of the prime game"""
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
