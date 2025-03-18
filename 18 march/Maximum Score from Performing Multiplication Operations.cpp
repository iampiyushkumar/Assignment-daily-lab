#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int n;
    int m;
    int dp[301][301];
    int find(vector<int>&nums,vector<int>&mul,int i, int j)
    {
        if(j>=m)
        return 0;
       if(dp[i][j]!=-1)
       return dp[i][j];
        int first=nums[i]*mul[j]+find(nums,mul,i+1,j+1);
       
        int last=nums[n-1-(j-i)]*mul[j]+find(nums,mul,i,j+1);
        // int nottake=find(nums,mul,i+1,j,k),find(nums);
        return dp[i][j]=max(first,last);
    }
        int maximumScore(vector<int>& nums, vector<int>& multipliers) {
            n=nums.size();
            m=multipliers.size();
            memset(dp,-1,sizeof(dp));
            return find(nums,multipliers,0,0);
        }
    };