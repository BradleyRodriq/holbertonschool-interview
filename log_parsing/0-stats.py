#!/usr/bin/python3
""" 0-stats.py
a script that reads stdin line by line and computes metrics
"""
import sys
import signal

# Initialize variables
TOTAL_FILE_SIZE = 0
status_code_counts = {
    200: 0,
    301: 0,
    400: 0,
    401: 0,
    403: 0,
    404: 0,
    405: 0,
    500: 0
}
LINE_COUNT = 0


def print_stats():
    """ Prints the total file size and counts for each status code """
    print(f"File size: {TOTAL_FILE_SIZE}")
    for code in sorted(status_code_counts):
        if status_code_counts[code] > 0:
            print(f"{code}: {status_code_counts[code]}")


def signal_handler():
    """ Handles keyboard interruption (CTRL + C) and prints statistics """
    print_stats()
    sys.exit(0)


signal.signal(signal.SIGINT, signal_handler)

try:
    for line in sys.stdin:
        try:
            parts = line.split()

            if len(parts) < 7:
                continue

            status_code = int(parts[-2])
            file_size = int(parts[-1])

            TOTAL_FILE_SIZE += file_size

            if status_code in status_code_counts:
                status_code_counts[status_code] += 1

            LINE_COUNT += 1

            if LINE_COUNT % 10 == 0:
                print_stats()

        except (ValueError, IndexError):
            continue

except KeyboardInterrupt:

    print_stats()
    sys.exit(0)
