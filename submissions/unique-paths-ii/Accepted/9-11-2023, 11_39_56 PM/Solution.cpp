// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // empty or the starting cell is blocked
        if (m == 0 || n == 0 || obstacleGrid[0][0] == 1) {
            return 0;
        }

        vector<int> dp(n, 0);
        // Initialize the first cell
        dp[0] = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    // Calculate the no of paths to current cell using prev[j] and dp[j-1]
                    if (j > 0) {
                        dp[j] += dp[j - 1];
                    }
                }

                else {
                    dp[j] = 0; // Reset dp[j] to 0 if an obstacle is encountered
                }
            }
        }

        return dp[n - 1];
    }
};
