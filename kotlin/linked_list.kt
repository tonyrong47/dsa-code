/**
 * Represents a single node in the Linked List.
 */
data class Node<T>(
    var data: T,
    var next: Node<T>? = null // Reference to the next node
)

/**
 * Basic singly Linked List implementation.
 */
class LinkedList<T> {
    private var head: Node<T>? = null

    /**
     * Adds an element to the front of the list (Prepend).
     */
    fun addFirst(data: T) {
        val newNode = Node(data, head)
        head = newNode
    }

    /**
     * Adds an element to the end of the list (Append).
     */
    fun addLast(data: T) {
        val newNode = Node(data)
        if (head == null) {
            head = newNode
            return
        }
        var current = head
        while (current?.next != null) {
            current = current.next
        }
        current?.next = newNode
    }

    /**
     * Prints all elements in the list.
     */
    fun printList() {
        var current = head
        print("List: ")
        while (current != null) {
            print("${current.data} -> ")
            current = current.next
        }
        println("null")
    }
}

// --- Usage Example ---
fun runLinkedListExample() {
    println("\n--- Linked List ---")
    val list = LinkedList<Int>()
    list.addFirst(10)
    list.addFirst(5)
    list.addLast(20)
    list.addLast(30)
    list.printList() // Output: List: 5 -> 10 -> 20 -> 30 -> null
}
// runLinkedListExample()