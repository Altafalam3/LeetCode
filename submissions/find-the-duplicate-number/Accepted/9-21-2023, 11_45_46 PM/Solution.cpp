// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            if (numSet.count(nums[i]) > 0) {
                return nums[i];
            }
            numSet.insert(nums[i]);
        }

        return -1;
    }
};