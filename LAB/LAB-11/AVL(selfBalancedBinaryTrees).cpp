#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
{
public:
    Node *insert(Node *node, int key)
    {
        if (node == nullptr)
        {
            return new Node(key);
        }

        if (key < node->key)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, key);
        }
        else
        {
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // LL Case
        if (balance > 1 && key < node->left->key)
        {
            return rightRotate(node);
        }

        // RR Case
        if (balance < -1 && key > node->right->key)
        {
            return leftRotate(node);
        }

        // LR Case
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL Case
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void preOrder(Node *root)
    {
        if (root != nullptr)
        {
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    int getHeight(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        else
        {
            return node->height;
        }
    }

    int getBalance(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        else
        {
            return getHeight(node->left) - getHeight(node->right);
        }
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }
};

int main()
{
    AVLTree tree;
    Node *root = nullptr;
    int key;
    cout << "Enter keys to insert into AVL tree (-1 to stop): ";
    while (true)
    {
        cin >> key;
        if (key == -1)
        {
            break;
        }
        root = tree.insert(root, key);
    }
    cout << "Preorder traversal of AVL tree: ";
    tree.preOrder(root);
    return 0;
}
