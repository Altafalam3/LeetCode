// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int c=0,maxx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            c+=nums[i];
            maxx=max(c,maxx);
            if(c<0){
                c=0;
            }
        }
        return maxx;
    }
};