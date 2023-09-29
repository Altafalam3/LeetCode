// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(),nums.end());
        while(k!=1){
          pop_heap(nums.begin(),nums.end());
          nums.pop_back();
          k--;
        }
        return nums.front();
    }
};