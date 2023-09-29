// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    void generateCombinations(const vector<int>& nums, int ind, vector<int>& currentCombination, vector<vector<int>>& result) {
        if (ind == nums.size()) {
            result.push_back(currentCombination);
            return;
        }
        
        currentCombination.push_back(nums[ind]);

        generateCombinations(nums, ind + 1,currentCombination, result);

        currentCombination.pop_back();

        // Skip consecutive duplicate elements
        while (ind + 1 < nums.size() && nums[ind] == nums[ind + 1]) {
            ind++;
        }
        
        generateCombinations(nums, ind + 1, currentCombination, result);
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        
        sort(nums.begin(), nums.end());  // Sort nums to handle duplicates
        generateCombinations(nums, 0, currentCombination, result);
        
        return result;
    }
};
