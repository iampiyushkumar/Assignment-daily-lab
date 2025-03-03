#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};
class Solution {
    public:
      // Function to find the nodes that are common in both BST.
      vector<int>in1;
      vector<int>in2;
      void inorder1(Node*root)
      {
          
          if(root==NULL)
          return;
          inorder1(root->left);
          in1.push_back(root->data);
          inorder1(root->right);
      }
      void inorder(Node*root)
      {
          if(root==NULL)
           return;
           inorder(root->left);
           in2.push_back(root->data);
           inorder(root->right);
      }
      vector<int> findCommon(Node *r1, Node *r2) {
        inorder1(r1);
        inorder(r2);
        vector<int>ans;
        int i=0;
        int j=0;
        while(i<in1.size()&&j<in2.size())
        {
            if(in1[i]==in2[j])
            {
                ans.push_back(in1[i]);
                i++;
                j++;
            }
            else if(in1[i]>in2[j])
              j++;
              else
              i++;
        }
        return ans;
      }
  };