#!/usr/bin/python3
""" minOperations module """


def minOperations(n):
    """ calculates the fewest number of operations needed to result in exactly n H characters in the file """
    if n <= 1:
        return 0
    operations = 0
    i = 2
    while i <= n:
        if n % i == 0:
            operations += i
            n = n / i
        else:
            i += 1
    return operations