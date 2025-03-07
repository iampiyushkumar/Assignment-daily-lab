#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[46];
    int find(int n)
    {
        if (n == 0)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int onestep = 0;
        int twostep = 0;
        if (n - 1 >= 0)
            onestep = find(n - 1);
        if (n - 2 >= 0)
            twostep = find(n - 2);
        return dp[n] = onestep + twostep;
    }
    int climbStairs(int n)
    {
        memset(dp, -1, sizeof(dp));
        return find(n);
    }
};