// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; 

        int writeIndex = 0; // Index for writing unique elements
        int count = 1;      // Count of occurrences for the current element

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                if (count < 2) {
                    count++;
                    nums[++writeIndex] = nums[i]; // Increment writeIndex and copy the element
                }
            }
            else {
                count = 1;
                nums[++writeIndex] = nums[i]; // Increment writeIndex and copy the element
            }
        }

        return writeIndex + 1; // Return the length of the modified array
    }
};
