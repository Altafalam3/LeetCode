// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int c=0,maxx=0;
        for(int i=0;i<nums.size();i++){
            c+=nums[i];
            if(c<0){
                c=0;
            }
            maxx=max(c,maxx);
        }
        return maxx;
    }
};