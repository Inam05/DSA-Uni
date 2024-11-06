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

    void insert(int value)
    {
        root = insertRec(root, value);
    }

    Node *insertRec(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }
        if (value < node->data)
        {
            node->left = insertRec(node->left, value);
        }
        else
        {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    bool search(int value)
    {
        return searchRec(root, value);
    }

    bool searchRec(Node *node, int value)
    {
        if (node == nullptr)
        {
            return false;
        }
        if (node->data == value)
        {
            return true;
        }
        if (value < node->data)
        {
            return searchRec(node->left, value);
        }
        else
        {
            return searchRec(node->right, value);
        }
    }

    void inorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }
};

int main()
{
    BinaryTree tree;
    int value;

    cout << "Enter numbers to insert into the binary tree (enter -1 to quit):" << endl;
    while (true)
    {
        cout << "Enter a number: ";
        cin >> value;
        if (value == -1)
            break;
        tree.insert(value);
    }

    cout << "\nEnter a number to search: ";
    cin >> value;
    if (tree.search(value))
    {
        cout << "Value " << value << " found in the tree." << endl;
    }
    else
    {
        cout << "Value " << value << " not found in the tree." << endl;
    }

    cout << "\nInorder traversal of the tree: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    return 0;
}
