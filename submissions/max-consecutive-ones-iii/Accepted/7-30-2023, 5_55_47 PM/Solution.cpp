// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0,end=0,longest=0;
        int zeros=0;

        while(end<nums.size()){
            if(nums[end]==0){
                zeros++;
            }
            while(zeros>k){
                if(nums[start]==0){
                    zeros--;
                }
                start++;
            }
            longest=max(longest,end-start+1);
            end++;
        }

        return longest;
    }
};