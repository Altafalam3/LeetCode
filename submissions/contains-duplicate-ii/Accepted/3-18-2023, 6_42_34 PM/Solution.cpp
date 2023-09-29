// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> seen_at;
        for (int i  = 0; i < nums.size(); ++i) {
            auto itr = seen_at.find(nums[i]);
            if (itr != seen_at.end() && i - itr->second <= k)
                return true;
            seen_at[nums[i]] = i;
        }   
        return false;
    }

};