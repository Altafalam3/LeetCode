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

        vector<int> curr(n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    // base case, starting cell, set curr[j] to 1
                    if (i == 0 && j == 0) {
                        curr[j] = 1;
                    }
                    else {
                        // handle first row and first cols filling
                        curr[j] = (i > 0 ? curr[j] : 0) + (j > 0 ? curr[j - 1] : 0);
                    }
                }

                else {
                    curr[j] = 0; // Reset curr[j] to 0 if an obstacle is encountered
                }
            }
        }

        return curr[n - 1];
    }
};
