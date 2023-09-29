// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n < 2){
            return nums[0];
        }
        return max(rob_max(nums, 0, n - 1), rob_max(nums, 1, n));
    }

private:
    int rob_max(vector<int>& nums, int start, int end) {

        int prev1 = nums[start], prev2=0, curr=0;
        
        for(int ind=start+1; ind < end; ind++){
            int take = nums[ind];
            if(ind>1){
                take += prev2;
            }
            int nottake = 0 + prev1;

            curr = max(take,nottake);
            prev2=prev1;
            prev1=curr;
        }
        
        return prev1;
    }

};