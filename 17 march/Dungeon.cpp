#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int calculateMinimumHP(vector<vector<int>>& dungeon) {
            int n=dungeon.size();
            int m=dungeon[0].size();
            vector<vector<int>>dp(n,vector<int>(m,0));
            //we are first calculating s for last index s means start and f means final
            dp[n-1][m-1] =max(1,1-dungeon[n-1][m-1]);
            for(int i=n-1;i>=0;i--)
            {
                for(int j=m-1;j>=0;j--)
                {
                    if(i==n-1&&j==m-1){
                        continue;
                    }
    
                    if(i==n-1)
                    {
                        int s=dp[i][j+1]-dungeon[i][j];
                        dp[i][j]=max(1,s);
                    }
                    else if(j==m-1)
                    {
                        int s=dp[i+1][j]-dungeon[i][j];
                        dp[i][j]=max(1,s);
                    }
                    else{
                        int f=min(dp[i+1][j],dp[i][j+1]);
                        int s=f-dungeon[i][j];
                        dp[i][j]=max(1,s);
                    }
                }
            }
          /*  for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cout<<dp[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;*/
            return dp[0][0];
        }
    };