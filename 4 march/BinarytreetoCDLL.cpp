#include<bits/stdc++.h>
using namespace std;
 //Definition for a binary tree node.
  struct Node {
      int val;
      Node *left;
      Node *right;
      Node() : val(0), left(nullptr), right(nullptr) {}
     Node(int x) : val(x), left(nullptr), right(nullptr) {}
     Node(int x) : val(x), left(nullptr), right(nullptr) {}
  };

class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    Node*prev=nullptr;
    Node*head=nullptr;
    void convert(Node*root)
    {
        if(root==nullptr)
        return;
        convert(root->left);
        if(prev==nullptr) head=root;
        else{
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        convert(root->right);
    }
    Node *bTreeToCList(Node *root)
    { if(root==nullptr)
    return root;
      convert(root);
      head->left=prev;
      prev->right=head;
      return head;
    }
};