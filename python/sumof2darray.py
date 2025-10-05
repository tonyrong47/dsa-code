import numpy as np

my_2d_array_np = np.array([[10, 20],
                           [30, 40]])

# The .sum() method on a NumPy array, without an axis specified,
# sums up all elements in the entire array.
total_sum = my_2d_array_np.sum()

print(f"Total sum (NumPy): {total_sum}") # Output: Total sum (NumPy): 100