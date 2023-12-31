// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size()-1;

        if(nums.size()==1) return 0;
        
        while(low<=high){
            int mid = low + (high-low)/2;

            if(( mid ==0 || (nums[mid-1] < nums[mid])) && (mid==nums.size()-1 || (nums[mid] > nums[mid+1]))){
                return mid;
            }
            

            // increasing side toh ofc left mai hoga bda
            if(nums[mid] > nums[mid+1]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return -1;
    }
};