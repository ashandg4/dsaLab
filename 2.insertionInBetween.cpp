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

// Function to insert a new node in between two nodes (after a given position)
void insertInBetween(Node *&head, int position, int value)
{
    Node *newNode = new Node(); // Create a new node
    newNode->data = value;

    if (position == 0)
    {
        // Special case: insert at the beginning
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        int count = 0;

        // Traverse to the position just before where we want to insert
        while (temp != nullptr && count < position - 1)
        {
            temp = temp->next;
            count++;
        }

        // If temp is null, the position is beyond the current list length
        if (temp == nullptr)
        {
            cout << "Position out of bounds!" << endl;
            return;
        }

        // Insert the new node in between
        newNode->next = temp->next;
        temp->next = newNode;
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

    // Insert nodes at the end
    insert(head, 10);
    insert(head, 20);
    insert(head, 40);

    cout << "Before inserting in between: ";
    display(head); // Display the linked list

    // Insert a new node with value 30 between nodes 20 and 40 (at position 2)
    insertInBetween(head, 2, 30);

    cout << "After inserting in between: ";
    display(head); // Display the linked list

    return 0;
}
