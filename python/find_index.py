# Defining a tuple with 8 elements
tuple_1 = (111, 256, 348, 789, 123, 456, 789, 1009)
# Displaying the elements of the tuple
print("The elements of Tuple are::\n", tuple_1, "\n")
counter = 0
index = 0
for items in tuple_1:
   counter += 1
   print("Value ", counter, " = ", items)

# Asking user to input an element to find its index in the tuple
item_index = int(input("\nEnter the element in the tuple of the element to find its index: "))

# Checking if the item exists in the tuple
if item_index in tuple_1:
   print("\nThe index of element ",item_index," in the tuple is: ",tuple_1.index(item_index))
else:
   print("\nElement ",item_index," does not exist in the tuple. Check your input and try again!!")