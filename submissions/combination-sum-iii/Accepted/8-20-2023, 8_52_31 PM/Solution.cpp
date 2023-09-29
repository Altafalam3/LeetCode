// https://leetcode.com/problems/combination-sum-iii

class Solution {
public:
    void generateCombinations(const vector<int>& candidates, int ind, int sum, vector<int>& currentCombination, vector<vector<int>>& result, int target, int k) {
        if (sum > target || currentCombination.size() > k) return;
        if (currentCombination.size() == k) {
            if (sum == target) {
                result.push_back(currentCombination);
            }
            return;
        }
        
        if (ind < candidates.size()) {
            currentCombination.push_back(candidates[ind]);
            generateCombinations(candidates, ind + 1, sum + candidates[ind], currentCombination, result, target, k);
            currentCombination.pop_back();
            
            while (ind + 1 < candidates.size() && candidates[ind] == candidates[ind + 1]) {
                ind++;
            }
            
            generateCombinations(candidates, ind + 1, sum, currentCombination, result, target, k);
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates;
        for (int i = 1; i <= 9; ++i) {
            candidates.push_back(i);
        }
        vector<vector<int>> result;
        vector<int> currentCombination;
        
        generateCombinations(candidates, 0, 0, currentCombination, result, n, k);
        
        return result;
    }
};
