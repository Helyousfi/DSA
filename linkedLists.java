class LinkedList {

    // Node class to represent a node in the linked list
    static class Node {
        int data;      // Data part
        Node next;     // Pointer to the next node

        // Constructor to create a new node
        Node(int d) {
            data = d;
            next = null;
        }
    }

    // Head of the linked list
    Node head;

    // Function to insert a node at the beginning of the linked list
    public void insertAtBeginning(int newData) {
        Node newNode = new Node(newData); // Create a new node
        newNode.next = head;              // Make next of new node as head
        head = newNode;                   // Move the head to point to the new node
    }

    // Function to insert a node at the end of the linked list
    public void insertAtEnd(int newData) {
        Node newNode = new Node(newData); // Create a new node
        if (head == null) {               // If the linked list is empty, make the new node the head
            head = newNode;
            return;
        }

        Node last = head;                 // Traverse to the last node
        while (last.next != null) {
            last = last.next;
        }

        last.next = newNode;              // Change the next of the last node
    }

    // Function to print the linked list
    public void printList() {
        Node currentNode = head;
        while (currentNode != null) {
            System.out.print(currentNode.data + " -> ");
            currentNode = currentNode.next;
        }
        System.out.println("NULL");
    }

    // Main method to test the linked list operations
    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        // Insert elements at the beginning
        list.insertAtBeginning(10);
        list.insertAtBeginning(20);
        list.insertAtBeginning(30);

        // Insert elements at the end
        list.insertAtEnd(40);
        list.insertAtEnd(50);

        // Print the linked list
        System.out.print("Linked List: ");
        list.printList();
    }
}
