// https://leetcode.com/problems/permutations

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        do {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        
        return ans;
    }
};