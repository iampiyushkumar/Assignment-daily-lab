
//Bottom View of Binary Tree
//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

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
    map<int,Node*> mp;
    
    void mapkaro(Node* root) {
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        mp[0] = root;
        
        while(!q.empty()) {
            int k = q.size();
            while(k--) {
                Node* node = q.front().first;
                int val = q.front().second;
                
                if(node->left) {
                    mp[val - 1] = node->left;
                    q.push({node->left, val - 1});
                }
                
                if(node->right) {
                    mp[val + 1] = node->right;
                    q.push({node->right, val + 1});
                }
                
                q.pop();
            }
        }
    }
    
    vector<int> bottomView(Node* root) {
        int val = 0;
        mapkaro(root);
        vector<int> ans;
        
        for(auto x: mp) {
            ans.push_back(x.second->data);
        }
        
        return ans;
    }
};
