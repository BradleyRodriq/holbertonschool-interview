#!/usr/bin/python3
import sys

def print_board(board):
    """Print the board solution"""
    for row in board:
        print(" ".join("Q" if i == 1 else "." for i in row))

def is_safe(board, row, col, N):
    """Check if it's safe to place a queen at board[row][col]"""
    # Check the column
    for i in range(row):
        if board[i][col] == 1:
            return False
    # Check the upper-left diagonal
    for i, j in zip(range(row - 1, -1, -1), range(col - 1, -1, -1)):
        if board[i][j] == 1:
            return False
    # Check the upper-right diagonal
    for i, j in zip(range(row - 1, -1, -1), range(col + 1, N)):
        if board[i][j] == 1:
            return False
    return True

def solve_nqueens(board, row, N):
    """Solve the N Queens problem using backtracking"""
    if row == N:
        print_board(board)
        return True

    res = False
    for col in range(N):
        if is_safe(board, row, col, N):
            board[row][col] = 1
            res = solve_nqueens(board, row + 1, N) or res
            board[row][col] = 0  # backtrack
    return res

def main():
    """Main entry point"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    # Create an empty N x N board
    board = [[0 for _ in range(N)] for _ in range(N)]

    # Solve the N Queens problem
    solve_nqueens(board, 0, N)

if __name__ == "__main__":
    main()
