// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        int result=0;

        while(low < high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                result = mid;
                return result;
            }

            else if(nums[mid]<target){
                low = mid+1;
            }
            else if(nums[mid]>target){
                high = mid;
            }
        }
        return nums[low] < target ? low + 1 : low;

    }
};