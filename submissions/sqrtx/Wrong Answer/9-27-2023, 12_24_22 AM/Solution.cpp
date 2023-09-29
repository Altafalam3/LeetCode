// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;
        if(x==0) return 0;
        int ans = 1;

        while(low < high){
            int mid = low + (high - low)/2;

            if (mid <= x/mid){
                low = mid +1;
                ans = mid;
            }
            else
                high = mid-1;
        }
        return ans;
    }
};