import java.util.Scanner;

class Stack {
    private int top;    // Index of the top element
    private int size;   // Maximum size of the stack
    private int[] Q;    // Array to store stack elements

    // Constructor to create the stack with a given size
    public Stack(int size) {
        this.size = size;     // Set the size of the stack
        this.top = -1;        // Initialize top to -1 (stack is empty)
        this.Q = new int[size];  // Create the array to store elements
    }

    // Function to check if the stack is empty
    public boolean isEmpty() {
        return top == -1;
    }

    // Function to check if the stack is full
    public boolean isFull() {
        return top == size - 1;
    }

    // Function to push an element onto the stack
    public void push(int value) {
        if (isFull()) {
            System.out.println("Stack Overflow! Cannot push " + value);
            return;
        }
        Q[++top] = value;  // Increment top and insert the value into the array
        System.out.println(value + " pushed to stack");
    }

    // Function to pop the top element from the stack
    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack Underflow! Cannot pop from an empty stack.");
            return -1;  // Returning -1 to indicate stack is empty
        }
        return Q[top--];  // Return the top element and decrement the top index
    }

    // Function to peek at the top element without removing it
    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty!");
            return -1;  // Returning -1 to indicate stack is empty
        }
        return Q[top];  // Return the top element
    }

    // Function to print the current state of the stack
    public void printStack() {
        if (isEmpty()) {
            System.out.println("Stack is empty!");
            return;
        }
        System.out.print("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            System.out.print(Q[i] + " ");
        }
        System.out.println();
    }
}

// Main class to test the stack implementation
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Ask the user for the stack size
        System.out.print("Enter the size of the stack: ");
        int stackSize = sc.nextInt();

        // Create the stack
        Stack stack = new Stack(stackSize);

        // Perform some operations on the stack
        stack.push(10);
        stack.push(20);
        stack.push(30);

        // Print the top element
        System.out.println("Top element is: " + stack.peek());

        // Pop an element
        System.out.println("Popped element: " + stack.pop());

        // Print the top element again
        System.out.println("Top element after pop is: " + stack.peek());

        // Print the stack
        stack.printStack();
    }
}
