// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = rob_max(nums,nums.size()-1);
        return ans;
    }

private:
    int rob_max(vector<int>& nums,int ind){
        if(ind==0){
           return nums[ind];
        }
        if(ind<0){
           return 0;
        }
        
        int take = nums[ind] + rob_max(nums, ind-2);
        
        int nottake = 0 + rob_max(nums, ind-1);
        
        return max(take,nottake);
 
     }
};