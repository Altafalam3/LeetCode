// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set <int> s;
        for (auto i:nums){
            s.insert(i);
        }
        int i = 0;
        for (auto num : s) {
            nums[i] = num;
            i++;
        }
        return s.size();
    }
};