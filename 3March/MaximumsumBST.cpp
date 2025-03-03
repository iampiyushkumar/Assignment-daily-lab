//MAXIMUM SUM IN BST

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
    int ans=0;
    //min,max,sum
    vector<int>find(TreeNode*root)
    {
        if(root==nullptr)
         return {INT_MAX,INT_MIN,0};
        vector<int>l=find(root->left);
        vector<int>r=find(root->right);
        if(root->val>l[1]&&root->val<r[0])
        {
             ans=max(ans,root->val+l[2]+r[2]);
             int mini=min(root->val,l[0]);
             int maxi=max(root->val, r[1]);
             return {mini,maxi,root->val+l[2]+r[2]};
        }
        return {INT_MIN,INT_MAX,root->val+max(l[2],r[2])};
    }
        int maxSumBST(TreeNode* root) {
            find(root);
            return ans;
        }
    };