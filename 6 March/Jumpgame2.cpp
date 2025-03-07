#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int jump(vector<int>& nums) {
            int n=nums.size();
            int step=nums[0];
            int jump=1;
            int maxrange=nums[0];
            for(int i=1;i<n;i++)
            {
                if(i==n-1)
                  return jump;
              maxrange=max(maxrange,i+nums[i]);
              step--;
              if(step==0)
              {
                jump++;
                if(i==maxrange) return 0;
                step=maxrange-i;
              }
            }
            return 0;
        }
    };