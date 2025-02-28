#include<bits/stdc++.h>
using namespace std;
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Codec {
    public:
    
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            if(root==nullptr)  return "null,";
        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
        }
    
        // Decodes your encoded data to tree.
     
     TreeNode* deslz(vector<string>&v,int &ind)
     {
        if(v[ind]=="null")
        {
            
            return nullptr;
        }
        TreeNode*root=new TreeNode(stoi(v[ind]));
        ind++;
        root->left=deslz(v,ind);
        ind++;
        root->right=deslz(v,ind);
        return root;
     }
        TreeNode* deserialize(string data) {
            int i=0;
            vector<string>v;
            string str;
            for(int i=0;i<data.size();i++)
            {
                if(data[i]==',')
                {
                    v.push_back(str);
                    str="";
                }
                else
                str+=data[i];
            }
            for(int i=0;i<v.size();i++)
              cout<<v[i]<<" ";
              int ind=0;
         return   deslz(v,ind);
        }
    };
    
    // Your Codec object will be instantiated and called as such:
    // Codec ser, deser;
    // TreeNode* ans = deser.deserialize(ser.serialize(root));