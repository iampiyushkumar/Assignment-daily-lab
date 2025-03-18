#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
     int dp[21][21];
     bool find(string &s, string &p, int i, int j)
     {
        if(j>=p.size())
        return (i>=s.size());
       if(dp[i][j]!=-1)
       return dp[i][j];
    
        bool match=false;
        if(i<s.length()&&(p[j]=='.'||(s[i]==p[j])))
           match=true;
    
        if( ((j+1)<p.size())&&p[j+1]=='*')
        {
            bool nottake=find(s,p,i,j+2);
            bool take=match&&find(s,p,i+1,j);
            return dp[i][j]= take||nottake;
        }
        else
        return  dp[i][j]=match&&find(s,p,i+1,j+1);
     }
        bool isMatch(string s, string p) {
            memset(dp,-1,sizeof(dp));
          return  find(s,p,0,0);
    
        }
    };