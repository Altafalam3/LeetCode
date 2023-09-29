// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        bool res = searchR(nums, low, high, target);
        return res;
    }

private:
    bool searchR(vector<int>& nums,int low, int high, int target){
        if(low > high) return false;

        int mid = low + (high-low)/2;

        if(nums[mid]==target){
            return true;
        }

        // left side is sorted and right side is not sorted
        else if(nums[low] <= nums[mid]){
            if(nums[low] <= target &&  target < nums[mid]){
                return searchR(nums,low,mid-1,target);
            }
            else{
                return searchR(nums,mid+1,high,target);
            }
        }

        // right side is sorted since left side is not
        else{
            if(nums[mid] < target && target <= nums[high]){
                return searchR(nums,mid+1,high,target);
            }
            else{
                return searchR(nums,low,mid-1,target);
            }
        }
        return false;
    }
};