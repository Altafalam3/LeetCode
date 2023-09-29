// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 2 pointer approach left side and right side
        int l=0, r=nums.size()-1;

        while(l<=r){
            if(nums[l]==val){
                swap(nums[l],nums[r]);
                r--;
            }
            else{
                l++;
            }
        }
        return l;
    }
};