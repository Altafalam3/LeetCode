// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;

        while(low < high){
            int mid = low + (high-low)/2;

            if(mid * mid == x) return mid;
            if(mid * mid > x){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        if(low == high) return low-1;
        return high;
    }
};