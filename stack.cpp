#include <iostream>
using namespace std;

// Define a structure for the Stack
struct Stack {
    int top;      // Index of the top element in the stack
    int size;     // Maximum size of the stack
    int* Q;       // Dynamic array to hold the stack elements
};

// Function to create a stack with a given size
void create(Stack& s, int size) {
    s.size = size;         // Set the size of the stack
    s.top = -1;            // Initialize top to -1 (stack is empty)
    s.Q = new int[s.size];  // Dynamically allocate memory for the stack array
}

// Function to check if the stack is empty
bool isEmpty(Stack& s) {
    return s.top == -1;    // Stack is empty if top is -1
}

// Function to check if the stack is full
bool isFull(Stack& s) {
    return s.top == s.size - 1;  // Stack is full if top is at the last index
}

// Function to push an element onto the stack
void push(Stack& s, int value) {
    if (isFull(s)) {
        cout << "Stack Overflow! Cannot push " << value << ".\n";
        return;
    }
    s.Q[++s.top] = value;  // Increment top and insert value into the array
    cout << value << " pushed to stack\n";
}

// Function to pop the top element from the stack
int pop(Stack& s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow! Cannot pop from an empty stack.\n";
        return -1;  // Returning -1 to indicate the stack is empty
    }
    return s.Q[s.top--];  // Return the top element and decrement the top index
}

// Function to peek at the top element without removing it
int peek(Stack& s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!\n";
        return -1;  // Returning -1 to indicate stack is empty
    }
    return s.Q[s.top];  // Return the top element
}

// Function to deallocate the dynamic array and clean up
void destroy(Stack& s) {
    delete[] s.Q;      // Free the dynamically allocated array memory
    s.Q = nullptr;     // Set the pointer to nullptr to avoid dangling pointer issues
}

// Main function to test the stack operations
int main() {
    Stack s;
    int stackSize;

    // Ask user for the size of the stack
    cout << "Enter the size of the stack: ";
    cin >> stackSize;

    // Create the stack
    create(s, stackSize);

    // Perform some operations
    push(s, 10);
    push(s, 20);
    push(s, 30);

    // Peek the top element
    cout << "Top element is: " << peek(s) << endl;

    // Pop an element
    cout << "Popped element: " << pop(s) << endl;

    // Check the top element again
    cout << "Top element after pop is: " << peek(s) << endl;

    // Destroy the stack
    destroy(s);

    return 0;
}
