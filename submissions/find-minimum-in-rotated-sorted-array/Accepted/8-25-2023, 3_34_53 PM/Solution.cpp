// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high-low)/2;

            //left side is sorted so 1st element low will be smallest
            if(nums[low] <= nums[mid]){
                ans = min(nums[low],ans);
                low = mid+1;
            }
            // mid will be smallest
            else{
                ans = min(nums[mid],ans);
                high = mid-1;
            }
        }
        return ans;
    }
};