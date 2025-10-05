def print_circular_array(arr):
    n = len(arr)
    for i in range(n):
        rotation = arr[i:] + arr[:i]
        print(' '.join(map(str, rotation)))

size = int(input("Enter array size: "))

if size <= 1 or size >= 11:
    print("Invalid Array Size")
else:
    arr = list(map(int, input("Enter array elements: ").split()))
    
    if len(arr) != size:
        print("Number of elements does not match the array size")
    else:
        print_circular_array(arr)
