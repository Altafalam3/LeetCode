// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0,end=0,maxx=0,longest=0;
        int zeros=0;

        while(end<nums.size()){
            if(zeros>k){
                if(nums[start]==0){
                    zeros--;
                }
                start++;
                maxx--;
            }
            else if(nums[end]==0){
                longest=max(longest,maxx);
                zeros++;
                maxx++;
                end++;
            }
            else if(nums[end]==1){
                longest=max(longest,maxx);
                maxx++;
                end++;
            }
        }
        return longest;
    }
};