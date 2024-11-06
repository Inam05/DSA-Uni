#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        Node *current = root;
        Node *parent = nullptr;

        while (true)
        {
            parent = current;
            if (value < current->data)
            {
                if (current->left == nullptr)
                {
                    current->left = newNode;
                    return;
                }
                else
                {
                    current = current->left;
                }
            }
            else
            {
                if (current->right == nullptr)
                {
                    current->right = newNode;
                    return;
                }
                else
                {
                    current = current->right;
                }
            }
        }
    }

    bool search(int value)
    {
        Node *current = root;

        while (current != nullptr)
        {
            if (current->data == value)
            {
                return true;
            }
            else if (value < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        return false;
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
        {
            break;
        }
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
