// https://leetcode.com/problems/find-in-mountain-array

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low=0, high=n-1;
        int peakIndex=0;

        // finding peak index 
        while(low<=high){
            int mid= low + (high-low)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                low = peakIndex = mid+1;
            }
            else{
                high = mid - 1;
            }
        }

        // search left of peak index increasing sort
        low=0, high= peakIndex;
        while(low<=high){
            int mid= low + (high-low)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        // search right of peak index decreasing sort
        low=peakIndex, high= n - 1;
        while(low<=high){
            int mid= low + (high-low)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return -1;

    }
};