// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;

        double ans = log2(n);
        int anss= (int)ans;
        return ans==anss;

    
    }
};