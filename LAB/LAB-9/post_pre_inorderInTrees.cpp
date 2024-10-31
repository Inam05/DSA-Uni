#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree() : root(nullptr) {}

    Node *insertNode(Node *node, int data)
    {
        if (node == nullptr)
            return new Node(data);
        if (data <= node->data)
            node->left = insertNode(node->left, data);
        else
            node->right = insertNode(node->right, data);
        return node;
    }

    void preorder(Node *node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node *node)
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node *node)
    {
        if (node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void displayTraversal(int choice)
    {
        switch (choice)
        {
        case 1:
            cout << "Preorder traversal: ";
            preorder(root);
            break;
        case 2:
            cout << "Inorder traversal: ";
            inorder(root);
            break;
        case 3:
            cout << "Postorder traversal: ";
            postorder(root);
            break;
        default:
            cout << "Invalid choice." << endl;
        }
        cout << endl;
    }
};

int main()
{
    BinaryTree tree;
    int data;

    while (true)
    {
        cout << "Enter a number (-1 to stop): ";
        cin >> data;
        if (data == -1)
            break;
        if (tree.root == nullptr)
            tree.root = new Node(data);
        else
            tree.insertNode(tree.root, data);
    }

    int printChoice;
    cout << "\nChoose the traversal order for display:\n";
    cout << "1. Preorder\n";
    cout << "2. Inorder\n";
    cout << "3. Postorder\n";
    cout << "Enter choice: ";
    cin >> printChoice;
    tree.displayTraversal(printChoice);

    return 0;
}
