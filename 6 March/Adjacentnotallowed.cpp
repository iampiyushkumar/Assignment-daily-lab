#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    /*
     int dp[10001];
      int find(vector<vector<int>>&mat, int N, int i, int j)
      { 
           if(j>=N)
           return 0;
           if(dp[j]!=-1)
            return dp[j];
        int take=max(mat[i][j],mat[i+1][j])+find(mat,N,i,j+2);
        int nottake=find(mat,N,i,j+1);
        return dp[j]=max(take,nottake);
      }*/
        int maxSum(int N, vector<vector<int>> mat)
        {   vector<int>dp(N+1,0);
            dp[N]=0;
            dp[N-1]=max(mat[0][N-1],mat[1][N-1]);
            for(int j=N-2;j>=0;j--)
            {
              dp[j]=max(dp[j+1],max(mat[0][j],mat[1][j])+dp[j+2]);  
            }
            return dp[0];
        }
    };
    