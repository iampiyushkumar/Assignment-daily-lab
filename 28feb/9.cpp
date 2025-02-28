//513. Find Bottom Left Tree Value
//https://leetcode.com/problems/find-bottom-left-tree-value/

#include <bits/stdc++.h>
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
      pair<int,int>find(TreeNode*root,int n)
        {
            if(root==nullptr)
              return make_pair(-1,-1);
              if(root->left==nullptr&&root->right==nullptr)
                 return make_pair(n,root->val);
                 pair<int,int>left_result={-1,-1};
                 pair<int,int>right_result={-1,-1};
                 if(root->left!=nullptr)
                 left_result=find(root->left,n+1);
                 if(root->right!=nullptr)
                 right_result=find(root->right,n+1);
                 if(left_result.first>=right_result.first)
                    return left_result;
                    else
                    return right_result;
                  
        }
        int findBottomLeftValue(TreeNode* root) {
            if(root==nullptr)
              return -1;
            if(root->left==nullptr&&root->right==nullptr)
               return root->val;
               auto[left_depth,left_node]=find(root->left,0);
               auto[right_depth,right_node]=find(root->right,0);
               if(left_depth>=right_depth) 
                  return left_node;
                  else 
                  return right_node;
        }
    };