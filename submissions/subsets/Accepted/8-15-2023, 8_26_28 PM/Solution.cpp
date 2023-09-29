// https://leetcode.com/problems/subsets

class Solution {
public:
    void generateSubsets(vector<int> &nums,int ind, vector<int> &currentSubset, vector<vector<int>> &result){
        // base condition to stop when at most all are covered
        // push the subset to result 
        if(ind==nums.size()){
            result.push_back(currentSubset);
            return;
        }
        
        // take it (element)
        currentSubset.push_back(nums[ind]);
        generateSubsets(nums,ind+1,currentSubset,result);
        
        //dont take it (element)
        currentSubset.pop_back();
        generateSubsets(nums,ind+1,currentSubset,result);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {    
        vector<vector<int>> result;
        vector<int> currentSubset;
        
        generateSubsets(nums, 0, currentSubset, result);
        
        return result;
    }
};