// https://leetcode.com/problems/binary-search

class Solution {
public:
    int bin_search(vector<int>& nums, int target, int low, int high) {
      if(low<=high){
      int mid=low+ (high-low)/2;
      if(nums[mid]==target)
        return mid;
      else if(nums[mid]>target)
        return bin_search(nums,target,low,mid-1);
      else if(nums[mid]<target)
        return bin_search(nums,target,mid+1,high);
     }
      return -1;
      
    }
  
    int search(vector<int>& nums, int target) {
        int index= bin_search(nums, target,0,nums.size()-1);
      return index;
    }
};