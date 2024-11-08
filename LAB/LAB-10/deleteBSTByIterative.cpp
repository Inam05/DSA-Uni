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

    void deleteNode(int value)
    {
        Node *parent = nullptr;
        Node *current = root;

        while (current != nullptr && current->data != value)
        {
            parent = current;
            if (value < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        if (current == nullptr)
        {
            return;
        }

        if (current->left == nullptr || current->right == nullptr)
        {
            Node *newChild;
            if (current->left != nullptr)
            {
                newChild = current->left;
            }
            else
            {
                newChild = current->right;
            }

            if (parent == nullptr)
            {
                root = newChild;
            }
            else if (parent->left == current)
            {
                parent->left = newChild;
            }
            else
            {
                parent->right = newChild;
            }

            delete current;
        }
        else
        {
            Node *successorParent = current;
            Node *successor = current->right;

            while (successor->left != nullptr)
            {
                successorParent = successor;
                successor = successor->left;
            }

            current->data = successor->data;

            if (successorParent->left == successor)
            {
                successorParent->left = successor->right;
            }
            else
            {
                successorParent->right = successor->right;
            }

            delete successor;
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
        {
            break;
        }
        tree.insert(value);
    }

    cout << "\nInorder traversal of the tree: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    cout << "\nEnter a number to delete: ";
    cin >> value;
    tree.deleteNode(value);

    cout << "\nInorder traversal of the tree after deletion: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    return 0;
}
