// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size()-1;

        if(nums.size()==1) return 0;
        if(nums[low]>nums[low+1] ) return low;
        if(nums[high]>nums[high-1]) return high;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if((nums[mid-1] < nums[mid]) && (nums[mid] > nums[mid+1])){
                return mid;
            }
            
            // increasing side toh ofc right mai hoga bda
            if(nums[mid-1] < nums[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return -1;
    }
};