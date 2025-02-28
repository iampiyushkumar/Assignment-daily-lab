//Odd even level difference
//https://www.geeksforgeeks.org/problems/odd-even-level-difference/1
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
   Node(int x) : data(x), left(NULL), right(NULL) {}
};
class Solution{
    public:
  /*You are required to complete this function*/
      int getLevelDiff(Node *root)
      {
        queue<Node*>q;
        q.push(root);
        int evensum=0;
        int oddsum=0;
        int level=1;
        while(!q.empty()){
            int k=q.size();
            while(k--)
            {
                Node*node=q.front();
                if(level%2==0)
                 evensum+=node->data;
                 else
                 oddsum+=node->data;
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
                q.pop();
            }
            level++;
        }
      //  cout<<oddsum<<" "<<evensum<<endl;
        return oddsum-evensum;
      }
    };