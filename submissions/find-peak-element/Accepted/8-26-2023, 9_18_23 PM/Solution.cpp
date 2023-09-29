// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid + 1]) {
                // If the current element is greater than the next one,
                // it's a possible candidate for a peak element.
                high = mid;
            } else {
                // Otherwise, we move towards the increasing side
                // since the peak should be on the right side.
                low = mid + 1;
            }
        }

        // At this point, low and high are equal, and it's the index of the peak.
        return low;
    }
};
