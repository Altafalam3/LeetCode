// https://leetcode.com/problems/combination-sum

class Solution {
public:
    void generateCombinations(const vector<int>& candidates, int ind, int sum, vector<int>& currentCombination, vector<vector<int>>& result, int target) {
        if(sum>target) return;
        if (sum == target) {
            result.push_back(currentCombination);
            return;
        }
        
        for (int i = ind; i < candidates.size(); i++) {
            if (sum + candidates[i] <= target) {
                currentCombination.push_back(candidates[i]);
                generateCombinations(candidates, i, sum + candidates[i], currentCombination, result, target);
                currentCombination.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        
        generateCombinations(candidates, 0, 0, currentCombination, result, target);
        
        return result;
    }
};
