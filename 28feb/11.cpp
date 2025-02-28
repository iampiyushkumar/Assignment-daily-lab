//INVERT TREE
//RECURSIVE SOLUTION
//https://leetcode.com/problems/invert-binary-tree/
// Definition for a binary tree node.
#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    public:
    void invert(TreeNode*root)
    {
        if(root==nullptr)  return;
        swap(root->left,root->right);
        invert(root->left);
        invert(root->right);
    }
        TreeNode* invertTree(TreeNode* root) {
            if(root==nullptr)  return nullptr;
            invert(root);
            return root;
        }
    };