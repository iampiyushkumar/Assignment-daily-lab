//LARGEST BST
//Given a binary tree, find the largest Binary Search Tree (BST), where largest means BST with largest number of nodes in it.


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

struct Info
{
    int size;
    int minVal;
    int maxVal;
    bool isBST;
};

Info largestBSTHelper(Node *root, int &maxSize)
{
    if (!root)
        return {0, INT_MAX, INT_MIN, true};

    Info left = largestBSTHelper(root->left, maxSize);
    Info right = largestBSTHelper(root->right, maxSize);

    Info current;
    current.size = left.size + right.size + 1;
    current.minVal = min(root->data, left.minVal);
    current.maxVal = max(root->data, right.maxVal);

    if (left.isBST && right.isBST && root->data > left.maxVal && root->data < right.minVal)
    {
        maxSize = max(maxSize, current.size);
        current.isBST = true;
    }
    else
    {
        current.isBST = false;
        current.size = max(left.size, right.size);
    }

    return current;
}

int largestBst(Node *root)
{
    int maxsize = 0;
    largestBSTHelper(root, maxsize);
    return maxsize;
}
