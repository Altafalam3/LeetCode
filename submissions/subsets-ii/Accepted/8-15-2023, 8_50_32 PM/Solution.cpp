// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    void generateSubsets(vector<int> &nums, int ind, vector<int> &currentSubset, vector<vector<int>> &result) {
        result.push_back(currentSubset);  // Always push the current subset
        
        for (int i = ind; i < nums.size(); ++i) {
            if (i > ind && nums[i] == nums[i - 1]) {
                continue;  // Skip duplicates to prevent duplicate subsets
            }
            // take and dont take method
            currentSubset.push_back(nums[i]);
            generateSubsets(nums, i + 1, currentSubset, result);
            currentSubset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort the input vector
        
        vector<vector<int>> result;
        vector<int> currentSubset;
        
        generateSubsets(nums, 0, currentSubset, result);
        
        return result;
    }
};
