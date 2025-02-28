
// 2. Vertical Order Traversal of a Binary Tree (Leetcode)
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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
    //yaha par col,row hai dhayan se
    map<int,map<int,vector<int>>>mp;
       void mapkaro(TreeNode*root)
       {
         queue<pair<TreeNode*,pair<int,int>>>q;
         q.push({root,{0,0}});
         mp[0][0].push_back(root->val);
         while(!q.empty())
         {
            int k=q.size();
            while(k--)
            {
                TreeNode*node=q.front().first;
                int row=q.front().second.first;
                int col=q.front().second.second;
                 q.pop();
                if(node->left)
                {
                    mp[col-1][row+1].push_back(node->left->val);
                    q.push({node->left,{row+1,col-1}});
                }
                if(node->right)
                {
                    mp[col+1][row+1].push_back(node->right->val);
                    q.push({node->right,{row+1,col+1}});
                }
               
            }
         }
       }
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            vector<vector<int>>ans;
            if(root==nullptr)
             return ans;
            mapkaro(root);
              
            for(auto x:mp)
            {
                vector<int>v;
                for(auto d:x.second)
                {
                    sort(d.second.begin(),d.second.end());
                    v.insert(v.end(),d.second.begin(),d.second.end());
                }
                ans.push_back(v);
            }
            return ans;
        }
    };