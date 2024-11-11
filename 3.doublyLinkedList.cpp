// #include <iostream>
// using namespace std;

// // Node structure for doubly linked list
// struct Node
// {
//     int data;   // Data to store
//     Node *prev; // Pointer to the previous node
//     Node *next; // Pointer to the next node

//     // Constructor to create a new node
//     Node(int value)
//     {
//         data = value;
//         prev = nullptr;
//         next = nullptr;
//     }
// };

// // Function to insert a new node at the end of the doubly linked list
// void insert(Node *&head, int value)
// {
//     Node *newNode = new Node(value); // Create a new node
//     if (head == nullptr)
//     {                   // If the list is empty
//         head = newNode; // New node becomes the head
//     }
//     else
//     {
//         Node *temp = head; // Traverse to the last node
//         while (temp->next != nullptr)
//         {
//             temp = temp->next;
//         }
//         temp->next = newNode; // Set the next of the last node
//         newNode->prev = temp; // Set the previous of the new node
//     }
// }

// // Function to display the doubly linked list from head to end
// void displayForward(Node *head)
// {
//     Node *temp = head; // Start from the head
//     while (temp != nullptr)
//     {
//         cout << temp->data << " <-> ";
//         temp = temp->next; // Move to the next node
//     }
//     cout << "NULL" << endl;
// }

// // Function to display the doubly linked list from end to head (reverse)
// void displayBackward(Node *head)
// {
//     if (head == nullptr)
//         return;

//     Node *temp = head;

//     // Traverse to the last node
//     while (temp->next != nullptr)
//     {
//         temp = temp->next;
//     }

//     // Now traverse backward
//     while (temp != nullptr)
//     {
//         cout << temp->data << " <-> ";
//         temp = temp->prev; // Move to the previous node
//     }
//     cout << "NULL" << endl;
// }

// // Main function
// int main()
// {
//     Node *head = nullptr; // Initialize the head as null

//     // Insert nodes at the end
//     insert(head, 10);
//     insert(head, 20);
//     insert(head, 30);
//     insert(head, 40);

//     // Display the list in forward direction
//     cout << "Doubly Linked List (Forward): ";
//     displayForward(head);

//     // Display the list in backward direction
//     cout << "Doubly Linked List (Backward): ";
//     displayBackward(head);

//     return 0;
// }

#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void add_at_start(node *&head, int data)
{
    node *temph = head;
    node *n1 = new node(data);
    n1->next = temph;
    temph->prev = n1;
    head = n1;
    return;
}

void forward_traversal(node *&head)
{
    node *temph = head;
    while (temph != NULL)
    {
        cout << temph->data << "-->";
        temph = temph->next;
    }
}

void backward_traversal(node *&head)
{
    node *tempt = head;
    while (tempt->next != NULL)
    {
        tempt = tempt->next;
    }
    while (tempt != NULL)
    {
        cout << tempt->data << "-->";
        tempt = tempt->prev;
    }
}

void add_at_end(node *head, int data)
{
    node *temph = head;
    node *n1 = new node(data);
    while (temph->next != NULL)
    {
        temph = temph->next;
    }
    temph->next = n1;
    n1->prev = temph;
}
void add_at_index(node *&head, int data)
{
    node *temph = head;
    node *tempt = temph->next;
    int index = 0;
    int req;
    cout << "enter the index you would like to insert the node to:-";
    cin >> req;
    while (index < req - 1)
    {
        temph = temph->next;
        tempt = tempt->next;
        index++;
    }
    node *n1 = new node(data);
    n1->prev = temph;
    temph->next = n1;
    n1->next = tempt;
    tempt->prev = n1;
}

void delet(node *&head)
{
    int rough = 0;
    int lenght = 0;
    int always = 0;
    node *l = head;
    node *m = l->next;
    node *r = m->next;
    int req;
    cout << "deletion ke liye enter kerde:-";
    cin >> req;
    if (always == 0)
    {
        node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            lenght++;
        }
    }

    if (req == 0)
    {
        m->prev = NULL;
        head = m;
        delete l;
        return;
    }
    if (req == 1)
    {
        l->next = r;
        r->prev = l;
        delete m;
        return;
    }

    if (req == lenght - 1)
    {
        while (r != NULL)
        {
            l = l->next;
            m = m->next;
            r = r->next;
        }
        l->next = NULL;
        delete m;
        return;
    }

    else
    {
        while (rough < req - 1)
        {
            l = l->next;
            m = m->next;
            r = r->next;
            rough++;
        }
        l->next = r;
        r->prev = l;
        delete m;
        return;
    }
}

int main()
{
    node *n1 = new node(50);
    node *head = n1;
    cout << head->data << endl;
    add_at_start(head, 40);
    add_at_start(head, 30);
    forward_traversal(head);
    cout << endl;
    backward_traversal(head);
    cout << endl;
    cout << endl;
    cout << endl;
    add_at_end(head, 60);
    forward_traversal(head);
    cout << endl;
    cout << endl;
    cout << endl;
    add_at_index(head, 100);
    forward_traversal(head);
    cout << endl;
    cout << endl;
    cout << endl;
    add_at_start(head, 99);
    add_at_start(head, 80);
    add_at_start(head, 70);
    add_at_start(head, 66);
    forward_traversal(head);
    cout << endl;
    cout << endl;
    cout << endl;
    delet(head);
    forward_traversal(head);
}