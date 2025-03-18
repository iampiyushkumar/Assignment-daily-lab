#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int n;
    
    int find(vector<int>&nums,int k)
    {  
        int l=0;
        int mini=INT_MAX;
        int sum=0;
        for(int i=0;i<k;i++)
        sum+=nums[i];
        mini=min(mini,sum);
        for(int i=k;i<n;i++)
        {
           sum+=nums[i];
           if((i-l+1)>k)
           {
            sum-=nums[l++];
           }
           mini=min(mini,sum);
        }
        return mini;
    
    }
        int maxScore(vector<int>& cardPoints, int k) {
             n=cardPoints.size();
           int mini=find(cardPoints,n-k);
           int sum=0;
           for(auto x:cardPoints)
           sum+=x;
           return sum-mini;
    
        }
    };