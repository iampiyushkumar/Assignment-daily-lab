#include<bits/stdc++.h>
using namespace std;
 //Definition for a binary tree node.
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
    int prev=-1;
    void find(TreeNode*root,int &k)
    {
        if(root==nullptr)  return;
        
        find(root->left,k);
        k--;
        if(k==0&&prev==-1)
        {
            prev=root->val;
            return;
        }
        find(root->right,k);
    }
        int kthSmallest(TreeNode* root, int k) {
            find(root,k);
            return prev;
        }
    };