
arr = [
    [[1, 2, 3], [4, 5, 6]],
    [[7, 8, 9], [10, 11, 12]]
]


total_sum = 0
for layer in arr:
    for row in layer:
        for num in row:
            total_sum += num

print("Sum of all elements:", total_sum)
