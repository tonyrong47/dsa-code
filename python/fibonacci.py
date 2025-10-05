def fibonacci_sequence(n):
    """
    Generate fibonacci sequence up to n terms
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return []
    elif n == 1:
        return [0]
    elif n == 2:
        return [0, 1]
    
    fib_sequence = [0, 1]
    
    for i in range(2, n):
        next_fib = fib_sequence[i-1] + fib_sequence[i-2]
        fib_sequence.append(next_fib)
    
    return fib_sequence

def fibonacci_recursive(n):
    """
    Calculate nth fibonacci number using recursion
    Time Complexity: O(2^n)
    Space Complexity: O(n)
    """
    if n <= 1:
        return n
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2)

def fibonacci_optimized(n):
    """
    Calculate nth fibonacci number using dynamic programming
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n <= 1:
        return n
    
    a, b = 0, 1
    for _ in range(2, n + 1):
        a, b = b, a + b
    
    return b

# Test the functions
if __name__ == "__main__":
    n = 10
    
    print(f"First {n} fibonacci numbers: {fibonacci_sequence(n)}")
    print(f"10th fibonacci number (recursive): {fibonacci_recursive(10)}")
    print(f"10th fibonacci number (optimized): {fibonacci_optimized(10)}")