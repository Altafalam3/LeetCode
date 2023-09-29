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
                take += nums[ind-2];
            }
            int nottake = 0 + nums[ind-1];
            nums[ind] = max(take,nottake);
        }
        
        
        return nums[n-1];
    }

};