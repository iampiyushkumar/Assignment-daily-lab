
#include<bits/stdc++.h>
using namespace std;

  struct Node {
      int data;
      Node *left;
      Node *right;
      Node() : data(0), left(nullptr), right(nullptr) {}
      Node(int x) : data(x), left(nullptr), right(nullptr) {}
      Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
  };
void find(Node*root,int input,int &succ)
{
    if(root==NULL)
    return;
    
   if(root->data==input)
   {
       succ=root->data;
       return;
   }
   if(root->data>input)
   {    succ=root->data;
       find(root->left,input,succ);
   }
   
   else if(root->data<input)
   {           
       find(root->right,input,succ);

   }
}
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
 int succ=-1;
     find(root,input,succ);
     return succ;