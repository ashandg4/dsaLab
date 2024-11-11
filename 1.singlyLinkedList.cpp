#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;   // Data to store
    Node *next; // Pointer to the next node
};

// Function to insert a new node at the end
void insert(Node *&head, int value)
{
    Node *newNode = new Node(); // Create a new node
    newNode->data = value;      // Set its value
    newNode->next = nullptr;    // New node points to null

    if (head == nullptr)
    { // If list is empty, new node becomes the head
        head = newNode;
    }
    else
    {
        Node *temp = head; // Traverse the list to find the last node
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode; // Link the last node to the new node
    }
}

// Function to display the linked list
void display(Node *head)
{
    Node *temp = head; // Start from the head
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next; // Move to the next node
    }
    cout << "NULL" << endl;
}

// Main function
int main()
{
    Node *head = nullptr; // Initialize the head as null

    insert(head, 0);
    insert(head, 20);
    insert(head, 30);

    display(head); // Display the linked list

    return 0;
}
