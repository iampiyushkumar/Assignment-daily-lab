//Level order traversal of a binary tree
//https://leetcode.com/problems/binary-tree-level-order-traversal/

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
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>>ans;
            if(!root)  return ans;
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty())
            {   vector<int>v;
                int k=q.size();
                while(k--)
                {
                    TreeNode*node=q.front();
                    v.push_back(node->val);
                    q.pop();
                    if(node->left)  q.push(node->left);
                    if(node->right)  q.push(node->right);
                }
                ans.push_back(v);
    
            }
            return ans;
        }
    };