#include <iostream>
using namespace std;

// Definition of a tree node
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize a node
    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function for Preorder Traversal (Root -> Left -> Right)
void preorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";      // Visit the root
    preorderTraversal(root->left);  // Traverse left subtree
    preorderTraversal(root->right); // Traverse right subtree
}

// Function for Inorder Traversal (Left -> Root -> Right)
void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorderTraversal(root->left);  // Traverse left subtree
    cout << root->data << " ";     // Visit the root
    inorderTraversal(root->right); // Traverse right subtree
}

// Function for Postorder Traversal (Left -> Right -> Root)
void postorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    postorderTraversal(root->left);  // Traverse left subtree
    postorderTraversal(root->right); // Traverse right subtree
    cout << root->data << " ";       // Visit the root
}

// Function to insert a node into the binary tree
TreeNode *insertNode(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return new TreeNode(value);
    }
    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}

int main()
{
    TreeNode *root = nullptr;
    int n, value;

    // Input the number of nodes
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Input the node values and construct the tree
    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insertNode(root, value);
    }

    // Display Preorder, Inorder, and Postorder traversals
    cout << "\nPreorder Traversal: ";
    preorderTraversal(root);

    cout << "\nInorder Traversal: ";
    inorderTraversal(root);

    cout << "\nPostorder Traversal: ";
    postorderTraversal(root);

    cout << endl;
    return 0;
}
