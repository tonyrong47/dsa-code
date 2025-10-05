Max = 5
queue = [None] * Max
f = -1
r = -1

def insert():
    global f, r
    if (f == 0 and r == Max - 1) or (r + 1) % Max == f:
        print("\nQueue is Full")
        return
    
    val = int(input("Enter an element: "))
    
    if f == -1:  # Empty queue
        f = r = 0
    else:
        r = (r + 1) % Max
    
    queue[r] = val

def delete():
    global f, r
    if f == -1:
        print("\nQueue is Empty")
        return
    
    print(f"The element deleted is {queue[f]}")
    
    if f == r:  # Last element
        f = r = -1
    else:
        f = (f + 1) % Max

def display():
    if f == -1:
        print("\nQueue is Empty")
        return
    
    print("Queue elements are:", end=" ")
    
    i = f
    while True:
        print(queue[i], end=" ")
        if i == r:
            break
        i = (i + 1) % Max
    print()

def main():
    while True:
        print("\n1. Insert\n2. Delete\n3. Display\n4. Exit")
        ch = int(input("Enter your choice: "))
        
        if ch == 1:
            insert()
        elif ch == 2:
            delete()
        elif ch == 3:
            display()
        elif ch == 4:
            print("\nBye Bye!!")
            break
        else:
            print("\nInvalid Input!!")

if __name__ == "__main__":
    main()
