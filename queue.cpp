#include <iostream>
using namespace std;

// Structure for the Queue
struct Queue {
    int front;    // Index of the front element in the queue
    int rear;     // Index of the rear element in the queue
    int size;     // Maximum size of the queue
    int* Q;       // Dynamic array to hold the queue elements
};

// Function to create a queue with a given size
void create(Queue& q, int size) {
    q.size = size;
    q.front = q.rear = -1;
    q.Q = new int[q.size];
}

// Function to check if the queue is empty
bool isEmpty(Queue& q) {
    return q.front == q.rear;
}

// Function to check if the queue is full
bool isFull(Queue& q) {
    return q.rear == q.size - 1;
}

// Function to enqueue an element at the rear of the queue
void enqueue(Queue& q, int value) {
    if (isFull(q)) {
        cout << "Queue Overflow! Cannot enqueue " << value << ".\n";
        return;
    }
    q.Q[++q.rear] = value;  // Increment rear and insert value into the array
    cout << value << " enqueued to queue\n";
}

// Function to dequeue an element from the front of the queue
int dequeue(Queue& q) {
    if (isEmpty(q)) {
        cout << "Queue Underflow! Cannot dequeue from an empty queue.\n";
        return -1;  // Returning -1 to indicate the queue is empty
    }
    return q.Q[++q.front];  // Increment front and return the dequeued element
}

// Function to peek at the front element without removing it
int peek(Queue& q) {
    if (isEmpty(q)) {
        cout << "Queue is empty!\n";
        return -1;  // Returning -1 to indicate the queue is empty
    }
    return q.Q[q.front + 1];  // Return the front element
}

// Function to deallocate the dynamic array and clean up
void destroy(Queue& q) {
    delete[] q.Q;  // Free the dynamically allocated array memory
    q.Q = nullptr; // Set the pointer to nullptr to avoid dangling pointer issues
}

// Main function to test the queue operations
int main() {
    Queue q;
    int queueSize;

    // Ask user for the size of the queue
    cout << "Enter the size of the queue: ";
    cin >> queueSize;

    // Create the queue
    create(q, queueSize);

    // Perform some operations
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    // Peek the front element
    cout << "Front element is: " << peek(q) << endl;

    // Dequeue an element
    cout << "Dequeued element: " << dequeue(q) << endl;

    // Check the front element again
    cout << "Front element after dequeue is: " << peek(q) << endl;

    // Destroy the queue
    destroy(q);

    return 0;
}
