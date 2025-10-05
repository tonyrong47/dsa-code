#!/usr/bin/env python3
#golixco

def sum_matrix(matrix):
    total = 0
    for row in matrix:
        total += sum(row)
    return total

def main():
    matrix = [[1, 2], [3, 4]]
    print(sum_matrix(matrix))

if __name__ == "__main__":
    main()
