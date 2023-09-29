// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for(int i=0; i< n; i++){
            for(int j=0; j<=i; j++){
                // base case
                if(i==0 && j==0){
                    dp[i][j] = triangle[i][j];
                }

                else{
                    int take1 = dp[i - 1][j];
                    
                    int take2 = ((j - 1) >= 0) ? dp[i - 1][j - 1] : INT_MAX;
                    dp[i][j] = min(take1, take2) + triangle[i][j];
                }
            }
        }

        int result = INT_MAX;
        for (int j = 0; j < n; j++) {
            result = min(result, dp[n - 1][j]);
        }

        return result;
    }
};
