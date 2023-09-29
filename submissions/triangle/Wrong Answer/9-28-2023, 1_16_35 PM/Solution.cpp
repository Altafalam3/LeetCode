// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        // we are starting from last row to first row
        // so that we avoid traversing last row again for min

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=i; j++){
                // base case , last row
                if(i==n-1){
                    dp[i][j] = triangle[i][j];
                }

                else{
                    int take1 = dp[i + 1][j];
                    
                    int take2 = ((j + 1) <= i) ? dp[i + 1][j + 1] : INT_MAX;
                    dp[i][j] = min(take1, take2) + triangle[i][j];
                }
            }
        }

        return dp[0][0];
    }
};