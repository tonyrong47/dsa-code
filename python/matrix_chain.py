import sys

def matrix_chain_order(dims):
    n = len(dims) - 1
    
    # m[i][j] is the minimum number of scalar multiplications
    # needed to compute the matrix product A[i..j]
    m = [[0] * (n + 1) for _ in range(n + 1)]

    for length in range(2, n + 1):
        for i in range(1, n - length + 2):
            j = i + length - 1
            m[i][j] = sys.maxsize
            
            for k in range(i, j):
                # q = multiplications needed for A[i..k] * A[k+1..j]
                q = m[i][k] + m[k+1][j] + dims[i-1] * dims[k] * dims[j]
                
                if q < m[i][j]:
                    m[i][j] = q

    return m[1][n]

# Example
# dims[0...n] represents the dimensions of n matrices:
# Matrix 1: dims[0] x dims[1]
# Matrix 2: dims[1] x dims[2]
# ...
# Matrix n: dims[n-1] x dims[n]
p = [10, 30, 5, 60] 

# Corresponds to 3 matrices: (10x30), (30x5), (5x60)
min_ops = matrix_chain_order(p)
print(f"Matrix Chain Multiplication Min Operations: {min_ops}")