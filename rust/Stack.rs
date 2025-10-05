use std::io::{self, Write};

/// Represents a generic Stack data structure.
/// It follows the Last-In, First-Out (LIFO) principle.
#[derive(Debug)]
struct Stack<T> {
    elements: Vec<T>,
}

impl<T> Stack<T> {
    /// Creates a new, empty stack.
    ///
    /// # Returns
    ///
    /// An empty `Stack<T>`.
    ///
    /// # Example
    ///
    /// ```
    /// let mut stack: Stack<i32> = Stack::new();
    /// ```
    fn new() -> Self {
        Stack {
            elements: Vec::new(),
        }
    }

    /// Pushes an element onto the top of the stack.
    ///
    /// # Arguments
    ///
    /// * `item` - The element to be pushed onto the stack.
    ///
    /// # Example
    ///
    /// ```
    /// let mut stack = Stack::new();
    /// stack.push(1);
    /// ```
    fn push(&mut self, item: T) {
        self.elements.push(item);
    }

    /// Removes and returns the top element of the stack.
    ///
    /// # Returns
    ///
    /// * `Some(T)` - The top element if the stack is not empty.
    /// * `None` - If the stack is empty.
    ///
    /// # Example
    ///
    /// ```
    /// let mut stack = Stack::new();
    /// stack.push(1);
    /// assert_eq!(stack.pop(), Some(1));
    /// assert_eq!(stack.pop(), None);
    /// ```
    fn pop(&mut self) -> Option<T> {
        self.elements.pop()
    }

    /// Returns a reference to the top element of the stack without removing it.
    ///
    /// # Returns
    ///
    /// * `Some(&T)` - A reference to the top element if the stack is not empty.
    /// * `None` - If the stack is empty.
    ///
    /// # Example
    ///
    /// ```
    /// let mut stack = Stack::new();
    /// stack.push(1);
    /// assert_eq!(stack.peek(), Some(&1));
    /// ```
    fn peek(&self) -> Option<&T> {
        self.elements.last()
    }

    /// Checks if the stack is empty.
    ///
    /// # Returns
    ///
    /// * `true` - If the stack contains no elements.
    /// * `false` - If the stack contains at least one element.
    fn is_empty(&self) -> bool {
        self.elements.is_empty()
    }

    /// Checks if the stack is "full".
    ///
    /// For a `Vec`-based stack, it can grow as long as there is memory.
    /// Therefore, it is never considered "full". This method always returns `false`.
    ///
    /// # Returns
    ///
    /// * `false` - Always, as the stack is dynamically sized.
    fn is_full(&self) -> bool {
        false // A Vec-based stack is never "full" in the traditional sense.
    }

    /// Returns the number of elements in the stack.
    ///
    /// # Returns
    ///
    /// The total number of elements as a `usize`.
    fn size(&self) -> usize {
        self.elements.len()
    }
}

/// Prints the menu of available actions to the user.
fn print_menu() {
    println!("\n--- Rust Stack Operations ---");
    println!("1. Push (add an element)");
    println!("2. Pop (remove the top element)");
    println!("3. Peek (view the top element)");
    println!("4. Size (get the number of elements)");
    println!("5. Is Empty? (check if the stack is empty)");
    println!("6. Is Full? (check if the stack is full)");
    println!("7. Print Stack");
    println!("8. Exit");
    print!("Please enter your choice: ");
    io::stdout().flush().unwrap();
}

/// Main function to provide an interactive CLI for the Stack.
fn main() {
    let mut stack: Stack<String> = Stack::new();

    loop {
        print_menu();

        let mut choice = String::new();
        io::stdin()
            .read_line(&mut choice)
            .expect("Failed to read line");

        match choice.trim().parse::<u32>() {
            Ok(1) => { // Push
                print!("Enter the element to push: ");
                io::stdout().flush().unwrap();
                let mut element = String::new();
                io::stdin()
                    .read_line(&mut element)
                    .expect("Failed to read line");
                stack.push(element.trim().to_string());
                println!("'{}' has been pushed to the stack.", element.trim());
            }
            Ok(2) => { // Pop
                match stack.pop() {
                    Some(element) => println!("Popped element: {}", element),
                    None => println!("Cannot pop, the stack is empty."),
                }
            }
            Ok(3) => { // Peek
                match stack.peek() {
                    Some(element) => println!("Top element is: {}", element),
                    None => println!("Cannot peek, the stack is empty."),
                }
            }
            Ok(4) => { // Size
                println!("The stack has {} elements.", stack.size());
            }
            Ok(5) => { // Is Empty
                if stack.is_empty() {
                    println!("The stack is empty.");
                } else {
                    println!("The stack is not empty.");
                }
            }
            Ok(6) => { // Is Full
                if stack.is_full() {
                    println!("The stack is full.");
                } else {
                    println!("The stack is not full (it can grow dynamically).");
                }
            }
            Ok(7) => { // Print
                 println!("Current stack: {:?}", stack);
            }
            Ok(8) => { // Exit
                println!("Exiting the program. Goodbye!");
                break;
            }
            _ => {
                println!("Invalid choice. Please enter a number between 1 and 8.");
            }
        }
    }
}

