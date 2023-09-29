// https://leetcode.com/problems/rearrange-array-elements-by-sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        int posIndex = 0, negIndex = 1;
        for (auto num : nums) {
            if (num > 0) {
                result[posIndex] = num;
                posIndex += 2;
            }
            if (num < 0) {
                result[negIndex] = num;
                negIndex += 2;
            }
        }
        return result;
    }
};
