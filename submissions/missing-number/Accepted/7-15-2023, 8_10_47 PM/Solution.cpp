// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0,final=0;
        sum = accumulate(nums.begin(),nums.end(),sum);
        for(int i=1;i<nums.size()+1;i++){
            final+=i;
        }
        return final-sum;
    }
};