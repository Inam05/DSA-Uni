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

    Node *deleteNode(Node *node, int value)
    {
        if (node == nullptr)
        {
            return node;
        }
        if (value < node->data)
        {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = deleteNode(node->right, value);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            Node *temp = node->right;
            while (temp->left != nullptr)
            {
                temp = temp->left;
            }

            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
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

    void deleteValue(int value)
    {
        root = deleteNode(root, value);
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
        tree.root = tree.insertRec(tree.root, value); // Directly using insertRec
    }

    cout << "\nInorder traversal of the tree: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    cout << "\nEnter a number to delete: ";
    cin >> value;
    tree.deleteValue(value);

    cout << "\nInorder traversal of the tree after deletion: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    return 0;
}
