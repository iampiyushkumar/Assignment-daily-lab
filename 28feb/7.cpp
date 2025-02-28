//Height of Binary tree
//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
#include<bits/stdc++.h> 
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    public:
      // Function to find the height of a binary tree.
      int height(Node* node) {
          if(!node)  return 0;
          if(node->left==nullptr&&node->right==nullptr)  return 0;
         return 1+max(height(node->left),height(node->right));
      }
  };