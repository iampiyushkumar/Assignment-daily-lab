#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int dp[501][501];
    int find(string &word1,string &word2,int i, int j)
    {
         if (i == word1.size()) return word2.size() - j; 
            if (j == word2.size()) return word1.size() - i;
            if(dp[i][j]!=-1)
            return dp[i][j];
        int inrt=INT_MAX;
        int dltk=INT_MAX;
        int rplc=INT_MAX;
        if(word1[i]!=word2[j])
        {
            inrt=1+find(word1,word2,i,j+1);
            dltk=1+find(word1,word2,i+1,j);
            rplc=1+find(word1,word2,i+1,j+1);
            return dp[i][j]= min({inrt,dltk,rplc});
        }
        return dp[i][j]=find(word1,word2,i+1,j+1);
    
    }
        int minDistance(string word1, string word2) {
            memset(dp,-1,sizeof(dp));
            return find(word1,word2,0,0);
        }
    };