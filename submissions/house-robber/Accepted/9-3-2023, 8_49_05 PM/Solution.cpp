// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,-1);

        dp[0] = nums[0];
        
        for(int ind=1; ind < n; ind++){
            int take = nums[ind];
            if(ind>1){
                take += dp[ind-2];
            }
            int nottake = 0 + dp[ind-1];
            dp[ind] = max(take,nottake);
        }
        
        
        return dp[n-1];
    }

};