// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        int low = 0, high = nums.size()-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if (mid == 0 || mid == nums.size() - 1) {
                return nums[mid];
            }

            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]){
                return nums[mid];
                break;
            }

            if(mid%2 == 0){
                if(nums[mid]==nums[mid+1]){
                    low = mid+1; 
                }
                else{
                    high = mid-1;
                }
            }
            else{
                if(nums[mid-1]==nums[mid]){
                    low = mid+1; 
                }
                else{
                    high = mid-1;
                }
            }

        }
        return -1;
    }
};