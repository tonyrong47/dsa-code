# List of tuples with three elements each
list_of_tuples = [(10, 20, 40), 
                  (40, 50, 60), 
                  (70, 80, 90)]
# Displaying the elements of the list of tuples
print("The elements of List of Tuples are::\n", list_of_tuples, "\n")
counter = 0
for items in list_of_tuples:
   counter += 1
   print("Tuple ", counter, " = ", items)

new_list = []

# Replacing the last values of each tuple into 100
for tuples in list_of_tuples:
   # Convert tuple to list to modify
   temp_list = list(tuples)

   # Replacing the last values to 100
   temp_list[-1] = 100

   # Convert back to tuple
   temp_tuples = tuple(temp_list)
   new_list.append(temp_tuples)

print("\nOUTPUT::\nThe modified list of tuuples is:",new_list)