// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int i=0,j=0;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize the top-left cell
        dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

        // Initialize the first column
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0){
                // compare with above rows value
                dp[i][0] = dp[i - 1][0];
            }
        }

        // Initialize the first row
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 0){
                // compare with left columns value
                dp[0][j] = dp[0][j - 1];
            }
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j]==0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];

    }

};