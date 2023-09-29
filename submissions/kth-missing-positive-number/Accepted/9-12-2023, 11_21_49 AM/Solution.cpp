// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size()-1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Calculate how many missing numbers are before arr[mid]
            int missing = arr[mid] - mid - 1;
            
            if (missing < k) {
                // kth missing number is right of arr[mid]
                left = mid + 1;
            } else {
                // kth missing number is left of arr[mid]
                right = mid - 1;
            }
        }
        
        // end of the loop, 'left' is  position where kth missing number would be inserted,
        // and 'left' + k is the kth missing number.
        return left + k;
    }
};
