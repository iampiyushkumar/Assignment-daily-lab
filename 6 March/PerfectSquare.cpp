#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int dp[10001];
    int find(int n)
    {
        if(n==0)
        return 0;
        if(dp[n]!=-1)  return dp[n];
        int cnt=INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
           int take=1+find(n-(i*i));
            cnt=min(cnt,take);
        }
        return dp[n]=cnt;
    }
        int numSquares(int n) {
            memset(dp,-1,sizeof(dp));
         return   find(n);
        }
    };