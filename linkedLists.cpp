#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;         // Data part
    Node* next;       // Pointer to the next node
};

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node();  // Allocate new node
    newNode->data = newData;     // Put in the data
    newNode->next = head;        // Make next of new node as head
    head = newNode;              // Move the head to point to the new node
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node();  // Allocate new node
    newNode->data = newData;     // Put in the data
    newNode->next = nullptr;     // Make the next of new node as null

    // If the linked list is empty, then make the new node the head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Else traverse till the last node
    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }

    // Change the next of the last node
    last->next = newNode;
}

// Function to print the linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

// Main function to test the linked list operations
int main() {
    Node* head = nullptr;  // Initialize head pointer to nullptr

    // Insert elements at the beginning
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 30);

    // Insert elements at the end
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    // Print the linked list
    cout << "Linked List: ";
    printList(head);

    return 0;
}
