// https://leetcode.com/problems/combination-sum

class Solution {
public:
    void generateCombinations(const vector<int>& candidates, int ind, int sum, vector<int>& currentCombination, vector<vector<int>>& result, int target) {
        if (sum>target) return;
        if (ind==candidates.size()) {
            if (sum == target) {
            result.push_back(currentCombination);
            }
            return;
        }
        
        if (sum + candidates[ind] <= target) {
            currentCombination.push_back(candidates[ind]);

            generateCombinations(candidates, ind, sum + candidates[ind], currentCombination, result, target);

            currentCombination.pop_back();
        }
        generateCombinations(candidates, ind+1, sum, currentCombination, result, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        
        generateCombinations(candidates, 0, 0, currentCombination, result, target);
        
        return result;
    }
};
