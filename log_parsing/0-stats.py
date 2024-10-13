#!/usr/bin/python3
"""This script reads lines from standard input and processes HTTP log entries to compute 
and display statistics.

The script maintains a running total of the file size and counts of various HTTP status 
codes. It prints these statistics every 10 lines and upon receiving a keyboard interruption 
(CTRL + C).

Global Variables:
    TOTAL_FILE_SIZE (int): Accumulates the total file size from the log entries.
    status_code_counts (dict): A dictionary that maps HTTP status codes to their respective counts.
    LINE_COUNT (int): Counts the number of processed log lines.

Functions:
    print_stats(): Prints the total file size and counts for each status code.
    signal_handler(sig, frame): Handles keyboard interruption (SIGINT) and prints statistics.

Usage:
    The script is intended to be run with input piped from a log file or another source of HTTP
    log entries."""

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
    """
    Prints the total file size and counts for each status code.

    This function prints the total file size stored in the global variable `TOTAL_FILE_SIZE`
    and the count of each HTTP status code stored in the global dictionary `status_code_counts`.
    The status codes are printed in ascending order, and only those with a count greater than zero are displayed.
    """
    print(f"File size: {TOTAL_FILE_SIZE}")
    for code in sorted(status_code_counts):
        if status_code_counts[code] > 0:
            print(f"{code}: {status_code_counts[code]}")


def signal_handler(sig, frame):
    """
    Handles keyboard interruption (CTRL + C) and prints statistics.

    Args:
        sig (int): Signal number.
        frame (FrameType): Current stack frame.

    This function is intended to be used as a signal handler for SIGINT.
    When invoked, it calls the `print_stats` function to display the current
    statistics and then exits the program with a status code of 0.
    """
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
