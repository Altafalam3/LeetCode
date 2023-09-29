// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }

        int prev2=1,prev1=2,ans;
        for(int i = 3; i <= n; i++){
            ans=prev2+prev1;
            prev2=prev1;
            prev1=ans;
        }
        return ans;

    }
};