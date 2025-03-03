// Description: https://leetcode.com/problems/validate-binary-search-tree/
//VALIDATE BST
//Given the root of a binary tree, determine if it is a valid binary search tree (BST).

#include<bits/stdc++.h>
using namespace std;

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
    bool find(TreeNode*root, long long maxi, long long mini)
    {  
        if(root==nullptr)
          return true;
        if(root->val>=maxi||root->val<=mini)
        return false;
        return find(root->left,root->val,mini)&&find(root->right,maxi,root->val);
    }
        bool isValidBST(TreeNode* root) {
            if(root==nullptr)
             return true;
          return   find(root,LLONG_MAX,LLONG_MIN);
        }
    };