// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,-1);
        int ans = rob_max(nums,n-1,dp);
        return ans;
    }

private:
    int rob_max(vector<int>& nums,int ind,vector<int>& dp){
        if(ind==0){
           return nums[ind];
        }
        if(ind<0){
           return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        
        int take = nums[ind] + rob_max(nums, ind-2, dp);
        
        int nottake = 0 + rob_max(nums, ind-1, dp);
        
        return dp[ind] = max(take,nottake);
 
     }
};