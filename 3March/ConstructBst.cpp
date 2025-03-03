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
    TreeNode*construct(vector<int>&nums,int start,int end)
    {
        if(start>end)
         return nullptr;
         int mid=start+(end-start)/2;
         TreeNode*root=new TreeNode(nums[mid]);
         root->left=construct(nums,start,mid-1);
         root->right=construct(nums,mid+1,end);
         return root;
    }
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            int n=nums.size();
            int start=0;
            int end=n-1;
            return construct(nums,start,end);
        }
    };