// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    void generateCombinations(const vector<int>& candidates, int ind, int sum, vector<int>& currentCombination, vector<vector<int>>& result, int target) {
        if (sum > target) return;
        if (ind == candidates.size()) {
            if (sum == target) {
                result.push_back(currentCombination);
            }
            return;
        }
        
        currentCombination.push_back(candidates[ind]);

        generateCombinations(candidates, ind + 1, sum + candidates[ind], currentCombination, result, target);

        currentCombination.pop_back();

        // Skip consecutive duplicate elements
        while (ind + 1 < candidates.size() && candidates[ind] == candidates[ind + 1]) {
            ind++;
        }
        
        generateCombinations(candidates, ind + 1, sum, currentCombination, result, target);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        
        sort(candidates.begin(), candidates.end());  // Sort candidates to handle duplicates
        generateCombinations(candidates, 0, 0, currentCombination, result, target);
        
        return result;
    }
};
