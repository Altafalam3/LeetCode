// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    void generateCombinations(const vector<int>& candidates, int ind, int sum, vector<int>& currentCombination, set<vector<int>>& result, int target) {
        if (sum > target) return;
        if (ind == candidates.size()) {
            if (sum == target) {
                sort(currentCombination.begin(),currentCombination.end());
                result.insert(currentCombination);
            }
            return;
        }
        
        currentCombination.push_back(candidates[ind]);

        generateCombinations(candidates, ind + 1, sum + candidates[ind], currentCombination, result, target);

        currentCombination.pop_back();
        
        generateCombinations(candidates, ind + 1, sum, currentCombination, result, target);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> resultSet;  // Using set to automatically handle duplicate removal
        vector<int> currentCombination;
        
        generateCombinations(candidates, 0, 0, currentCombination, resultSet, target);
        
        vector<vector<int>> result(resultSet.begin(), resultSet.end());
        return result;
    }
};
