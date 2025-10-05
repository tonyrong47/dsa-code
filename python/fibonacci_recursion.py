def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)

# Example usage
n = 7
print(f"Fibonacci number at position {n} is {fibonacci(n)}")
