// https://leetcode.com/problems/binary-search

class Solution {
public:
    int bin_search(vector<int>& nums, int target, int low, int high) {
      int mid=high - (high-low)/2;
      if(nums[mid]==target)
        return mid;
      else if(nums[mid]>target)
        return bin_search(nums,target,low,mid-1);
      else
        return bin_search(nums,target,mid+1,high);
      
    }
  
    int search(vector<int>& nums, int target) {
        int index= bin_search(nums, target,0,nums.size());
      return index;
    }
};