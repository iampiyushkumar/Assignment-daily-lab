#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    string find(string str1,string str2)
    {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1])
                 dp[i][j]=1+dp[i-1][j-1];
                     else
                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
         }
         string ans;
        int i=n;
        int j=m;
        while(i>0&&j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]) i--;
            else
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
        string shortestCommonSupersequence(string str1, string str2) {
            string lcs=find(str1,str2);
            cout<<lcs<<endl;
            int n=str1.size();
            int m=str2.size();
           int i=0;
           int j=0;
           int k=0;
           string res;
           while(k<lcs.size())
           {
               while(i<n&&lcs[k]!=str1[i])
                 {
                    res+=str1[i];
                    i++;
                 }
                 while(j<m&&lcs[k]!=str2[j])
                 {
                    res+=str2[j];
                    j++;
                 }
                 res+=lcs[k++];
                 i++;
                 j++;
           }
           res+=str1.substr(i)+str2.substr(j);
           return res;
        }
    };