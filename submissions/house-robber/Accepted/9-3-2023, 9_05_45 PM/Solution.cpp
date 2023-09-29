// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();

        int prev1 = nums[0], prev2=0, curr=0;
        
        for(int ind=1; ind < n; ind++){
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