#include <bits/stdc++.h>
using namespace std;

class AVLTree
{
private:
    struct Node
    {
        int key;
        int height;
        int subtreeSize;
        Node *left;
        Node *right;

        Node(int key, Node *left = nullptr, Node *right = nullptr)
            : key(key), height(1), subtreeSize(1), left(left), right(right) {}
    };

    Node *root = nullptr;

    int getHeight(Node *node)
    {
        return node ? node->height : 0;
    }

    int getSubtreeSize(Node *node)
    {
        return node ? node->subtreeSize : 0;
    }

    int getBalanceFactor(Node *node)
    {
        return getHeight(node->left) - getHeight(node->right);
    }

    void updateHeightAndSize(Node *node)
    {
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        node->subtreeSize = 1 + getSubtreeSize(node->left) + getSubtreeSize(node->right);
    }

    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T = x->right;
        x->right = y;
        y->left = T;
        updateHeightAndSize(y);
        updateHeightAndSize(x);
        return x;
    }

    Node *rotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *T = y->left;
        y->left = x;
        x->right = T;
        updateHeightAndSize(x);
        updateHeightAndSize(y);
        return y;
    }

    Node *insert(Node *root, int key)
    {
        if (!root)
            return new Node(key);

        if (key < root->key)
            root->left = insert(root->left, key);
        else if (key > root->key)
            root->right = insert(root->right, key);
        else
            root->key = key;

        updateHeightAndSize(root);

        int balance = getBalanceFactor(root);

        if (balance > 1 && key < root->left->key)
            return rotateRight(root);

        if (balance < -1 && key > root->right->key)
            return rotateLeft(root);

        if (balance > 1 && key > root->left->key)
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        if (balance < -1 && key < root->right->key)
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

public:
    void insert(int key)
    {
        root = insert(root, key);
    }

    void printInorder()
    {
        printInorder(root);
        std::cout << "\n";
    }

    int findNthMinimum(int n)
    {
        return findNthMinimum(root, n);
    }

private:
    void printInorder(Node *node)
    {
        if (node)
        {
            printInorder(node->left);
            std::cout << node->key << " ";
            printInorder(node->right);
        }
    }

    int findNthMinimum(Node *root, int n)
    {
        if (!root || n > getSubtreeSize(root))
            return -1;

        int leftSubtreeSize = getSubtreeSize(root->left);
        if (leftSubtreeSize == n - 1)
            return root->key;
        else if (leftSubtreeSize >= n)
            return findNthMinimum(root->left, n);
        else
            return findNthMinimum(root->right, n - leftSubtreeSize - 1);
    }
};

int32_t main(){

    AVLTree avl;
    avl.insert(10);
    avl.insert(11);
    avl.insert(9);
    cout << avl.findNthMinimum(2) << endl;

    return 0;
}
