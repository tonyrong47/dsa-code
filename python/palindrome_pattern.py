"""Palindrome pattern generator

Provides a function `generate_palindrome_pattern(n)` which returns a list of
strings representing a numeric palindrome pyramid with `n` rows, and a small
CLI to print the pattern.

Example for n=4:

   1
  121
 12321
1234321

Each row has leading spaces so the pyramid is centered on the left edge.
"""
from typing import List


def generate_palindrome_pattern(n: int) -> List[str]:
    """Generate a palindrome number pattern with n rows.

    Args:
        n: number of rows (must be a positive integer)

    Returns:
        A list of strings, each string is one line of the pattern.

    Raises:
        ValueError: if n is not a positive integer.
    """
    if not isinstance(n, int) or n < 1:
        raise ValueError("n must be a positive integer (>=1)")

    lines: List[str] = []
    for row in range(1, n + 1):
        # leading spaces
        spaces = " " * (n - row)
        # increasing part 1..row
        inc = "".join(str(i) for i in range(1, row + 1))
        # decreasing part row-1..1
        dec = "".join(str(i) for i in range(row - 1, 0, -1))
        lines.append(f"{spaces}{inc}{dec}")

    return lines


def main() -> None:
    """Simple CLI: read an integer from command-line and print the pattern."""
    import argparse

    parser = argparse.ArgumentParser(description="Print palindrome number pattern")
    parser.add_argument("n", type=int, nargs="?", default=5, help="number of rows (default: 5)")
    args = parser.parse_args()

    for line in generate_palindrome_pattern(args.n):
        print(line)


if __name__ == "__main__":
    main()
