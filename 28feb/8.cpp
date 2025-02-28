//Top View of Binary Tree
//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
   Node(int x) : data(x), left(NULL), right(NULL) {}
};
class Solution {
    public:
      // Function to return a list of nodes visible from the top view
      // from left to right in Binary Tree.
      map<int,Node*>mp;
      void mapkaro(Node*root)
      {
          queue<pair<Node*,int>>q;
          q.push({root,0});
          mp[0]=root;
          while(!q.empty())
          {
              int k=q.size();
              while(k--)
              {
             Node*node=q.front().first;
              int val=q.front().second;
              q.pop();
               if(node->left)
               { if(mp.find(val-1)==mp.end())   mp[val-1]=node->left;
                   q.push({node->left,val-1});
               }
               
               if(node->right)
               {
                   if(mp.find(val+1)==mp.end())  mp[val+1]=node->right;
                   q.push({node->right,val+1});
               }
              }
          }
      }
      vector<int> topView(Node *root) {
          vector<int>ans;
          if(root==nullptr)
          return ans;
          mapkaro(root);
          for(auto x:mp)
          ans.push_back(x.second->data);
          return ans;
      }
    };