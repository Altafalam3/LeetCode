// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int i=0,j=0;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // base case first row first cols =1 , exception when it has a obstacle
        for(int j=0; j<n; j++){
            if(obstacleGrid[0][j]==0){
                dp[0][j] = 1;
            }
        }

        for(int i=0; i<m; i++){
            if(obstacleGrid[i][0]==0){
                dp[i][0] = 1;
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