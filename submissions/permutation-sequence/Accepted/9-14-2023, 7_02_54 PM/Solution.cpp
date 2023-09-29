// https://leetcode.com/problems/permutation-sequence

class Solution {
public:
    string getPermutation(int n, int k) {
        string nums;
        for(int i=1;i<=n; i++){
            nums += to_string(i);
        }

        while (k!=1){
            next_permutation(nums.begin(), nums.end());
            k--;
        }
        
        return nums;
    }
};