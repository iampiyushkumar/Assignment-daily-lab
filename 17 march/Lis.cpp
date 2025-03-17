#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int n,m;
    int dp[1001][1001];
    int find(int idx1,int idx2,string &text1,string &text2)
    {
    
        if(idx1<0||idx2<0)
         return 0;
        int take=0;
        if(dp[idx1][idx2]!=-1)
        return dp[idx1][idx2];
        if(text1[idx1]==text2[idx2])
        {
            take=1+find(idx1-1,idx2-1,text1,text2);
        }
        int nottake=max(find(idx1-1,idx2,text1,text2),find(idx1,idx2-1,text1,text2));
        return dp[idx1][idx2]=max(take,nottake);
    }
        int longestCommonSubsequence(string text1, string text2) {
             n=text1.size();
             m=text2.size();
            memset(dp,-1,sizeof(dp));
          return  find(n-1,m-1,text1,text2);
        }
    };