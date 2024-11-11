#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a node in the BST
Node *insert(Node *root, int value)
{
    // If the tree is empty, create a new node
    if (root == nullptr)
    {
        return new Node(value);
    }

    // Recur down the tree
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    // Return the unchanged root pointer
    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

// Main function
int main()
{
    Node *root = nullptr;
    int n, value;

    cout << "Enter the number of nodes: ";
    cin >> n;

    // Inserting values into the BST
    cout << "Enter the values to insert into BST: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    // Display the tree using different traversals
    cout << "\nInorder Traversal: ";
    inorderTraversal(root);

    cout << "\nPreorder Traversal: ";
    preorderTraversal(root);

    cout << "\nPostorder Traversal: ";
    postorderTraversal(root);

    return 0;
}
