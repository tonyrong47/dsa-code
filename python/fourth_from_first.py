# Defining a tuple with 10 elements
tuple_1 = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
# # Displaying the elements of the tuple
print("The elements of Tuple are::\n", tuple_1, "\n")
counter = 0
for items in tuple_1:
   counter += 1
   print("Value ",counter," = ",items)

# Displaying the 4th element from first and last
print("\nOUTPUT::")
print("The 4th element from first is = ",tuple_1[3])
print("The 4th element from last is = ",tuple_1[-4])