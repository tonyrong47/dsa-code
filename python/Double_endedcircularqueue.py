import sys

# Define the maximum size of the deque
MAX = 10

class CircularDeque:
    def __init__(self, size=MAX):
        self.max_size = size
        # Initialize queue with None and pointers to -1 (empty state)
        self.queue = [None] * self.max_size
        self.l = -1  # Left/Front index
        self.r = -1  # Right/Rear index

    # --- Full Check ---
    def is_full(self):
        # Full condition from C code: (l == 0 and r == MAX - 1) or (l == r + 1)
        return (self.l == 0 and self.r == self.max_size - 1) or (self.l == self.r + 1)

    # --- Empty Check ---
    def is_empty(self):
        # Empty condition: l and r are both -1
        return self.l == -1 and self.r == -1

    # ========================================================
    # 1. ENQUEUE LEFT
    # ========================================================
    def enqueueleft(self):
        if self.is_full():
            print("\nQueue is Full\n")
            return

        # Case 1: Queue is empty (l == -1 and r == -1)
        if self.is_empty():
            self.l = 0
            self.r = 0
        # Case 2: Left pointer is at the start (0) -> Wrap around
        elif self.l == 0:
            self.l = self.max_size - 1
        # Case 3: Normal insert -> Decrement l
        else:
            self.l -= 1

        try:
            item = int(input("\nEnter an element: "))
            self.queue[self.l] = item
        except ValueError:
            print("\nInvalid input. Element not inserted.")
            # Optional: Rollback pointers if input was invalid, but we'll assume valid input for simplicity

    # ========================================================
    # 2. ENQUEUE RIGHT
    # ========================================================
    def enqueueright(self):
        if self.is_full():
            print("\nQueue is full\n")
            return

        # Case 1: Queue is empty (l == -1 and r == -1)
        if self.is_empty():
            self.l = 0
            self.r = 0
        # Case 2: Right pointer is at the end (MAX - 1) -> Wrap around
        elif self.r == self.max_size - 1:
            self.r = 0
        # Case 3: Normal insert -> Increment r
        else:
            self.r += 1

        try:
            item = int(input("\nEnter an element: "))
            self.queue[self.r] = item
        except ValueError:
            print("\nInvalid input. Element not inserted.")

    # ========================================================
    # 3. DEQUEUE LEFT
    # ========================================================
    def dequeueleft(self):
        if self.is_empty():
            print("\nQueue is empty\n")
            return

        deleted_item = self.queue[self.l]
        print(f"\nThe element to be deleted is: {deleted_item}\n")

        # Case 1: Only one element left (l == r)
        if self.l == self.r:
            self.l = -1
            self.r = -1
        # Case 2: Left pointer is at the end (MAX - 1) -> Wrap around
        elif self.l == self.max_size - 1:
            self.l = 0
        # Case 3: Normal delete -> Increment l
        else:
            self.l += 1
        
        return deleted_item

    # ========================================================
    # 4. DEQUEUE RIGHT
    # ========================================================
    def dequeueright(self):
        if self.is_empty():
            print("\nQueue is empty\n")
            return

        deleted_item = self.queue[self.r]
        print(f"\nThe element to be deleted is: {deleted_item}\n")

        # Case 1: Only one element left (l == r)
        if self.l == self.r:
            self.l = -1
            self.r = -1
        # Case 2: Right pointer is at the start (0) -> Wrap around
        elif self.r == 0:
            self.r = self.max_size - 1
        # Case 3: Normal delete -> Decrement r
        else:
            self.r -= 1
            
        return deleted_item

    # ========================================================
    # 5. DISPLAY
    # ========================================================
    def display(self):
        if self.is_empty():
            print("\nQueue is empty\n")
            return

        print("\nCurrent Queue Elements:")
        
        # Case 1: No wrap-around (Left <= Right)
        if self.l <= self.r:
            for i in range(self.l, self.r + 1):
                print(self.queue[i])
        # Case 2: Wrap-around (Left > Right)
        else:
            # Print from Left (l) to the end (MAX - 1)
            for i in range(self.l, self.max_size):
                print(self.queue[i])
            # Print from start (0) to the Right (r)
            for i in range(0, self.r + 1):
                print(self.queue[i])

# ========================================================
# Helper Functions (Menus)
# ========================================================
def enqueue_menu(dq):
    while True:
        print("\n--- ENQUEUE MENU ---")
        print("1. enqueueleft")
        print("2. enqueueright")
        print("3. stop")
        
        try:
            ch1 = int(input("Enter your choice: "))
        except ValueError:
            print("\nInvalid input! Please enter a number.")
            continue

        if ch1 == 1:
            dq.enqueueleft()
        elif ch1 == 2:
            dq.enqueueright()
        elif ch1 == 3:
            break
        else:
            print("\nInvalid input!\n")

def dequeue_menu(dq):
    while True:
        print("\n--- DEQUEUE MENU ---")
        print("1. dequeueleft")
        print("2. dequeueright")
        print("3. stop")
        
        try:
            ch2 = int(input("Enter your choice: "))
        except ValueError:
            print("\nInvalid input! Please enter a number.")
            continue

        if ch2 == 1:
            dq.dequeueleft()
        elif ch2 == 2:
            dq.dequeueright()
        elif ch2 == 3:
            break
        else:
            print("\nInvalid input!\n")


# ========================================================
# Main Execution (Equivalent to C's main)
# ========================================================
def main():
    dq = CircularDeque()
    
    while True:
        print("\n--- MAIN MENU ---")
        print("1. enqueue")
        print("2. dequeue")
        print("3. display")
        print("4. Exit")
        
        try:
            ch = int(input("Enter your choice: "))
        except ValueError:
            print("\nInvalid input! Please enter a number.")
            continue
            
        if ch == 1:
            enqueue_menu(dq)
        elif ch == 2:
            dequeue_menu(dq)
        elif ch == 3:
            dq.display()
        elif ch == 4:
            print("\nExiting. Bye Bye!\n")
            sys.exit(0) # Equivalent to C's exit(1) for successful termination
        else:
            print("\nInvalid input!\n")

if __name__ == "__main__":
    main()